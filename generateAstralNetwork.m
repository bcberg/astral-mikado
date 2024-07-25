function [network,crossings,asters] = generateAstralNetwork(numAsters,l,D,astralNum)
% GENERATEASTRALNETWORK Constructs an astral network and reports properties
%   Inputs:
%       numAsters (scalar): (whole) number of asters to distribute
%       l (scalar): length of individual filament
%       D (scalar): domain size; asters are distributed in a square of size
%       length D
%       astralNum (scalar): (whole) number of filaments per aster
%   Outputs:
%       network (struct): has fields 'nodes', 'springs', 'catalog', 'ends'
%           'nodes': see findNodes auxiliary function
%           'springs': see defineSprings auxiliary function
%           'catalog': see springsByNode auxiliary function
%           'ends': see defineSprings auxiliary function
%       crossings (struct): has fields 'stickCross' and 'centerCross'
%           'filCross': see findNodes auxiliary function
%           'centerCross': see findNodes auxiliary function
%       asters (struct): has fields 'centers', 'orients'
%           'centers': (x,y) coordinates of astral centers
%           'orients': angles giving each filament's orientation about its
%           astral center
asters.centers = D * rand([numAsters,2]);
asters.orients = 2 * pi * rand([numAsters,astralNum]);

numFil = numAsters * astralNum;
% each row in 'centerCross' field records the filaments belonging to that aster
% aster idx 1 groups filaments 1,2,...,astralNum; and so on
crossings.centerCross = transpose(reshape(1:numFil,[astralNum,numAsters]));

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
%       crossings (excluding astral centers)
%       filCross (numNodes x 2 double): list of pairs of filament indices
%       corresponding to the filaments that cross at a particular node;
%       listed so that filCross(idx,1) < filCross(idx,2)
[~, astralNum] = size(orients);
numFil = numel(orients);
nodes = [];
filCross = [];
if astralNum == 1
    % routine for "Classical Mikado" networks
    for idx = 1:(numFil-1)
        for jdx = (idx+1):numFil
            A = [cos(orients(idx)), - cos(orients(jdx));
                sin(orients(idx)), - sin(orients(jdx))];
            denom = det(A);
            b = 1/l * [centers(jdx,1) - centers(idx,1);
                centers(jdx,2) - centers(idx,2)];
            t1 = det([b,A(:,2)]) / denom;
            t2 = det([A(:,1),b]) / denom;
            if (abs(t1 - 0.5) <= 0.5) && (abs(t2 - 0.5) <= 0.5)
                nodeX = centers(idx,1) + l * cos(orients(idx)) * t1;
                nodeY = centers(idx,2) + l * sin(orients(idx)) * t1;
                nodes = [nodes; nodeX, nodeY];
                filCross = [filCross; idx, jdx];
            end
        end
    end
else
    % routine for "Astral Mikado" networks
    for idx = 1:(numFil-1)
        for jdx = (idx+1):numFil
            asterIdx = 1 + floor((idx-1)/astralNum);
            asterJdx = 1 + floor((jdx-1)/astralNum);
            % skip this filament if it's on the same aster
            if asterIdx == asterJdx
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
                nodeX = centers(asterIdx,1) + l * cos(orients(asterIdx,filSubIdx)) * t1;
                nodeY = centers(asterIdx,2) + l * sin(orients(asterIdx,filSubIdx)) * t1;
                nodes = [nodes; nodeX, nodeY];
                filCross = [filCross; idx, jdx];
            end
        end
    end
end
end

function nodeOrdering = sortNodes(filIdx,nodes,filCross,centers,astralNum)
% SORTNODES orders the node indices along a filament
%   Inputs:
%       filIdx (scalar): filament index (see note in findNodes for details)
%       nodes (numNodes x 2 double): list of (x,y) coordinates of filament
%       crossings (excluding astral centers)
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

function [springs,ends] = defineSprings(nodes,filCross,centers,astralNum)
% DEFINESPRINGS partitions filaments into mechanically productive
% sub-segments (springs) and dangling ends
%   Inputs:
%       nodes (numNodes x 2 double): list of (x,y) coordinates of filament
%       crossings (excluding astral centers)
%       filCross (numNodes x 2 double): list of pairs of filament indices
%       corresponding to the filaments that cross at a particular node;
%       listed so that filCross(idx,1) < filCross(idx,2)
%       centers (numAsters x 2 double): (x,y) coordinates of astral centers
%       astralNum (scalar): number of filaments per aster
%   Outputs:
%       springs (numSprings x 4 double): descriptions of mechanically
%       productive segments, each row has the structure
%           (1) lesser node index at one end of the spring
%           (2) greater node index at the other end of the spring
%           (3) filament index (which filament is the spring on)
%           (4) the original distance between the nodes
%       ends (numFil x 2 double): lengths of segments on the ends of each 
%       filament. ends(:,1) lists the "right" dangling ends, distal to the
%       astral center. ends(:,2) lists the "left" dangling ends, proximal
%       to the astral center; these are all 0 if astralNum >= 2.
numAsters = size(centers,1);
numFil = numAsters * astralNum;
springs = [];
for idx = 1:numFil
    thisOrder = sortNodes(idx,nodes,filCross,centers,astralNum);
    if isempty(thisOrder)
        % this filament doesn't touch any other asters!
    elseif isscalar(thisOrder)
        % this filament may mechanically productive if astralNum >= 2
    else
        % there are certainly springs along this filament
    end
end
end