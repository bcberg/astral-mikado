function [network,crossings,asters] = generateAstralNetwork(numAsters,l,D,astralNum)
% GENERATEASTRALNETWORK Constructs an astral network and reports properties
%   Inputs:
%       numAsters (scalar): (whole) number of asters to distribute
%       l (scalar): length of individual filament
%       D (scalar): domain size; asters are distributed in a square of size
%       length D
%       astralNum (scalar): (whole) number of filaments per aster
%   Outputs:
%       network (struct): has fields 'nodes', 'augNodes', 'springs', 'ends'
%           'nodes': see findNodes auxiliary function
%           'augNodes': see defineSprings auxiliary function
%           'springs': see defineSprings auxiliary function
%           'ends': see defineSprings auxiliary function
%       crossings (struct): has fields 'filCross' and 'centerCross'
%           'filCross': see findNodes auxiliary function
%           'centerCross': which filaments cross at each astral center;
%           each row represents a center
%       asters (struct): has fields 'centers', 'orients'
%           'centers': (x,y) coordinates of astral centers
%           'orients': angles giving each filament's orientation about its
%           astral center
%   Note: currently no boundary/edge is constructed, and the implementation
%   does not store/compile information for running Metropolis-Hastings
asters.centers = D * rand([numAsters,2]);
asters.orients = 2 * pi * rand([numAsters,astralNum]);

[nodes, filCross] = findNodes(asters.centers,asters.orients,l);
[augNodes, springs, ends] = defineSprings(nodes,filCross,asters.centers, ...
    l,astralNum);

numFil = numAsters * astralNum;
% aster idx 1 groups filaments 1,2,...,astralNum; and so on
crossings.centerCross = transpose(reshape(1:numFil,[astralNum,numAsters]));
crossings.filCross = filCross;

network.nodes = nodes;
network.augNodes = augNodes;
network.springs = springs;
network.ends = ends;
end

%% Auxiliary functions

function [nodes, filCross] = findNodes(centers,orients,l)
% FINDNODES identifies where filaments cross and records which filaments
% crossed 
% (Note: filaments are indexed as one would read left to right across the
% rows of 'orients', and each row represents an aster. This function does
% NOT search for intersections between filaments on the same aster)
%   Inputs:
%       centers (numAsters x 2 double): (x,y) coordinates of astral centers
%       orients (numAsters x astralNum double): angles giving each 
%       filament's orientation about its astral center
%       l (scalar): length of individual filament
%       centerCross (numAsters x astralNum double): filament indices
%       grouped by each aster
%   Outputs:
%       nodes (numNodes x 2 double): list of (x,y) coordinates of filament
%       crossings (EXCLUDING astral centers)
%       filCross (numNodes x 2 double): list of pairs of filament indices
%       corresponding to the filaments that cross at a particular node;
%       listed so that filCross(idx,1) < filCross(idx,2)
[~, astralNum] = size(orients);
numFil = numel(orients);
numNodesGuess = round(numFil^2 / 10);
nodes = zeros(numNodesGuess,2);
filCross = zeros(numNodesGuess,2);
nodeCount = 0;
if astralNum == 1
    % routine for "Classical Mikado" networks
    for idx = 1:(numFil-1)
        for jdx = (idx+1):numFil
            % if filaments are too far apart, don't look for intersections
            sepDistSQR = sum( (centers(jdx,:) - centers(idx,:)).^2 );
            if sepDistSQR > (2*l)^2
                continue
            end
            A = [cos(orients(idx)), - cos(orients(jdx));
                sin(orients(idx)), - sin(orients(jdx))];
            denom = det(A);
            b = 1/l * [centers(jdx,1) - centers(idx,1);
                centers(jdx,2) - centers(idx,2)];
            t1 = det([b,A(:,2)]) / denom;
            t2 = det([A(:,1),b]) / denom;
            if (abs(t1 - 0.5) <= 0.5) && (abs(t2 - 0.5) <= 0.5)
                nodeCount = nodeCount + 1;
                nodeX = centers(idx,1) + l * cos(orients(idx)) * t1;
                nodeY = centers(idx,2) + l * sin(orients(idx)) * t1;
                nodes(nodeCount,1:2) = [nodeX, nodeY];
                filCross(nodeCount,1:2) = [idx,jdx];
            end
        end
    end
elseif astralNum >= 2
    % routine for "Astral Mikado" networks
    for idx = 1:(numFil-1)
        for jdx = (idx+1):numFil
            asterIdx = 1 + floor((idx-1)/astralNum);
            asterJdx = 1 + floor((jdx-1)/astralNum);
            % skip this filament if it's on the same aster
            if asterIdx == asterJdx
                continue
            elseif sum((centers(asterJdx,:) - centers(asterIdx,:)).^2) > (2*l)^2
                % skip if astral centers (& filaments) are too far apart
                continue
            end
            % otherwise, check for intersection
            filSubIdx = mod(idx,astralNum) + astralNum * (mod(idx,astralNum)==0);
            filSubJdx = mod(jdx,astralNum) + astralNum * (mod(jdx,astralNum)==0);
            A = [cos(orients(asterIdx,filSubIdx)), - cos(orients(asterJdx,filSubJdx));
                sin(orients(asterIdx,filSubIdx)), - sin(orients(asterJdx,filSubJdx))];
            denom = det(A);
            b = 1/l * [centers(asterJdx,1) - centers(asterIdx,1);
                centers(asterJdx,2) - centers(asterIdx,2)];
            t1 = det([b,A(:,2)]) / denom;
            t2 = det([A(:,1),b]) / denom;
            if (abs(t1 - 0.5) <= 0.5) && (abs(t2 - 0.5) <= 0.5)
                nodeCount = nodeCount + 1;
                nodeX = centers(asterIdx,1) + l * cos(orients(asterIdx,filSubIdx)) * t1;
                nodeY = centers(asterIdx,2) + l * sin(orients(asterIdx,filSubIdx)) * t1;
                nodes(nodeCount,1:2) = [nodeX, nodeY];
                filCross(nodeCount,1:2) = [idx,jdx];
            end
        end
    end
end
if nodeCount == 0
    nodes = zeros(0,2);
    filCross = zeros(0,2);
elseif nodeCount >= 1
    nodes = nodes(1:nodeCount,:);
    filCross = filCross(1:nodeCount,:);
end
end

function nodeOrdering = sortNodes(filIdx,nodes,filCross,centers,astralNum)
% SORTNODES orders the node indices along a filament
%   Inputs:
%       filIdx (scalar): filament index (see note in findNodes for details)
%       nodes (numNodes x 2 double): list of (x,y) coordinates of filament
%       crossings (EXCLUDING astral centers)
%       filCross (numNodes x 2 double): list of pairs of filament indices
%       corresponding to the filaments that cross at a particular node;
%       listed so that filCross(idx,1) < filCross(idx,2)
%       centers (numAsters x 2 double): (x,y) coordinates of astral centers
%       astralNum (scalar): number of filaments per aster
%   Outputs:
%       nodeOrdering (double vector): sorted list of node indices appearing
%       on the specified filament. First element is the node closest to the
%       astral center. If there are no nodes on this filament, returns [].
[nodesOnFil,~] = find(filCross == filIdx);
if isempty(nodesOnFil)
    nodeOrdering = [];
    return
elseif isscalar(nodesOnFil)
    nodeOrdering = nodesOnFil;
    return
end
numNodesOnFil = length(nodesOnFil);
nodeCoordsOnFil = nodes(nodesOnFil,:);
asterIdx = 1 + floor((filIdx-1)/astralNum);
r0 = centers(asterIdx,:);
refNode = nodeCoordsOnFil(1,:);
direction = (refNode - r0) ./ sqrt(sum((refNode - r0).^2));
% next two lines find dot product "direction * (node - r0)" for all nodes
nodePointers = nodeCoordsOnFil - repmat(r0,[numNodesOnFil,1]);
dotProducts = dot(repmat(direction,[numNodesOnFil,1]),nodePointers,2);
% now sort the dot products in increasing order and sort the node indices
% using the same permutation
[~,I] = sort(dotProducts);
nodeOrdering = nodesOnFil(I);
end

function [augNodes,springs,ends] = defineSprings(nodes,filCross,centers, ...
    l,astralNum)
% DEFINESPRINGS partitions filaments into node-bounded sub-segments 
% (springs) and dangling ends
%   Inputs:
%       nodes (numNodes x 2 double): list of (x,y) coordinates of filament
%       crossings (EXCLUDING astral centers)
%       filCross (numNodes x 2 double): list of pairs of filament indices
%       corresponding to the filaments that cross at a particular node;
%       listed so that filCross(idx,1) < filCross(idx,2)
%       centers (numAsters x 2 double): (x,y) coordinates of astral centers
%       l (scalar): length of individual filament
%       astralNum (scalar): number of filaments per aster
%   Outputs:
%       augNodes (numAsters+numNodes x 2 double)**: conditionally augmented 
%       node list; if astralNum >= 2, rows 1:numAsters contain (x,y) 
%       coordinates of astral centers, remaining rows contain (x,y) 
%       coordinates of inter-aster nodes
%       **NOTE: if astralNum == 1, augNodes is the same as nodes (centers
%       are fictitious), so its size is (numNodes x 2)
%       springs (numSprings x 4 double): descriptions of segments bounded 
%       by nodes at each end, each row has the structure
%           (1) lesser augNode index at one end of the spring
%           (2) greater augNode index at the other end of the spring
%           (3) filament index (which filament is the spring on)
%           (4) the original distance between the nodes
%       ends (numFil x 2 double): lengths of segments on the ends of each 
%       filament. ends(:,2) lists the "right" dangling ends, distal to the
%       astral center. ends(:,1) lists the "left" dangling ends, proximal
%       to the astral center; these are all 0 if astralNum >= 2.
numAsters = size(centers,1);
numFil = numAsters * astralNum;
numSpringsGuess = 10 * size(nodes,1);
springs = zeros(numSpringsGuess,4);
ends = zeros(numFil,2);
springCount = 0;
augNodes = zeros(0,2);
if astralNum == 1
    % routine for "Classical Mikado" networks
    augNodes = nodes;   % centers are fictitious
    for idx = 1:numFil
        thisOrder = sortNodes(idx,nodes,filCross,centers,astralNum);
        asterIdx = idx;
        if isempty(thisOrder)
            % 0 nodes = filament doesn't touch any other asters!
            ends(idx,2) = l;    % treat unused filament as "right" dangling end
        elseif isscalar(thisOrder)
            % 1 node + astralNum == 1 -> two dangling ends
            r0 = centers(asterIdx,:);
            nodeCoords = nodes(thisOrder(1),:);
            ends(idx,1) = sqrt(sum( (nodeCoords - r0).^2 ));
            ends(idx,2) = l - ends(idx,2);
        elseif ~isscalar(thisOrder) && isvector(thisOrder)
            % >=2 nodes = there are certainly springs along this filament
            r0 = centers(asterIdx,:);
            totSpringLength = 0;
            % pair adjacent nodes to form springs
            for jdx = 1:(length(thisOrder)-1)
                springCount = springCount + 1;
                nodeIdxL = thisOrder(jdx);
                nodeL = nodes(nodeIdxL,:);
                nodeIdxR = thisOrder(jdx+1);
                nodeR = nodes(nodeIdxR,:);
                springLength = sqrt(sum( (nodeL - nodeR).^2 ));
                newSpring = [min([nodeIdxL,nodeIdxR]), ...
                    max([nodeIdxL,nodeIdxR]), idx, springLength];
                springs(springCount,:) = newSpring;
                totSpringLength = totSpringLength + springLength;
            end
            proxNode = nodes(thisOrder(1),:);
            ends(idx,1) = sqrt(sum( (proxNode - r0).^2 ));
            ends(idx,2) = l - totSpringLength - ends(idx,1);
        end
    end
elseif astralNum >= 2
    % routine for "Astral Mikado" networks
    augNodes = [centers; nodes];
    for idx = 1:numFil
        thisOrder = sortNodes(idx,nodes,filCross,centers,astralNum);
        asterIdx = 1 + floor((idx-1)/astralNum);
        if isempty(thisOrder)
            % 0 nodes = filament doesn't touch any other asters!
            ends(idx,2) = l;    % treat unused filament as "right" dangling end
        elseif isscalar(thisOrder)
            % 1 node + astralNum >=2 -> spring between astral center & node
            springCount = springCount + 1;
            r0 = centers(asterIdx,:);
            nodeCoords = nodes(thisOrder(1),:);
            springLength = sqrt(sum( (nodeCoords - r0).^2 ));
            newSpring = [asterIdx, numAsters+thisOrder, idx, springLength];
            springs(springCount,:) = newSpring;
            ends(idx,2) = l - springLength;
        elseif ~isscalar(thisOrder) && isvector(thisOrder)
            % >=2 nodes = there are certainly springs along this filament
            r0 = centers(asterIdx,:);
            totSpringLength = 0;
            % like "Classical", but proximal segment to center is spring
            % also need to account for augmented node indices
            for jdx = 1:(length(thisOrder)-1)
                springCount = springCount + 1;
                nodeIdxL = thisOrder(jdx);
                nodeL = nodes(nodeIdxL,:);
                nodeIdxR = thisOrder(jdx+1);
                nodeR = nodes(nodeIdxR,:);
                springLength = sqrt(sum( (nodeL - nodeR).^2 ));
                newSpring = [numAsters+min([nodeIdxL,nodeIdxR]), ...
                    numAsters+max([nodeIdxL,nodeIdxR]), idx, springLength];
                springs(springCount,:) = newSpring;
                totSpringLength = totSpringLength + springLength;
            end
            % recording proximal segment as spring
            springCount = springCount + 1;
            proxNode = nodes(thisOrder(1),:);
            springLength = sqrt(sum( (proxNode - r0).^2 ));
            newSpring = [asterIdx, numAsters+thisOrder(1), idx, springLength];
            springs(springCount,:) = newSpring;
            totSpringLength = totSpringLength + springLength;
            ends(idx,2) = l - totSpringLength;
        end
    end
end
if springCount == 0
    springs = zeros(0,4);
elseif springCount >= 1
    springs = springs(1:springCount,:);
end
end