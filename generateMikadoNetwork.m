function [nodes,springs,catalog,stickCross] = generateMikadoNetwork(Nstick,l,L)
%GENERATEMIKADONETWORK generates a network of springs from randomly placed
%sticks
%   Detailed explanation goes here

basePoints = L * rand([Nstick,2]);  % uniform draw of (bx_i,by_i) from [0,L]
orient = 2 * pi * rand([Nstick,1]); % uniform draw of theta_i from [0,2*pi]

[nodes, stickCross] = findNodes(basePoints,orient,l);
[boundaryNodes, boundaryCross] = findBoundaryNodes(basePoints, orient, l, L, Nstick);

nodes = [nodes; boundaryNodes];
stickCross = [stickCross; boundaryCross];
clear boundaryNodes boundaryCross
springs = defineSprings(nodes, stickCross);
catalog = springsByNode(springs, size(nodes,1));
end

%% Auxiliary functions

function [nodes, association] = findNodes(basePoints,orient,l)
% FINDNODES finds the (x,y) coordinates where sticks cross and returns both
% a list of where crossings are (nodes) and a list of which sticks are
% crossing for each detected node
% nodes is a Nnodes x 4 array where each row contains the following
% information:
%   (1) x coordinate of crossing
%   (2) y coordinate of crossing
%   (3) the number "1" (true), indicating that this is a node which should
%   be perturbed later in the Metropolis algorithm
%   (4) the number "0" (false), indicating that this is a node which is not
%   subjected to an external force
    nodes = [];
    association = [];
    n = length(basePoints);
    for idx = 1:(n-1)
        for jdx = (idx+1):n
            A = [cos(orient(idx)), - cos(orient(jdx));
                sin(orient(idx)), - sin(orient(jdx))];
            denom = det(A);
            b = 1/l * [basePoints(jdx,1) - basePoints(idx,1); 
                basePoints(jdx,2) - basePoints(idx,2)];
            t1 = det([b,A(:,2)]) / denom;
            t2 = det([A(:,1),b]) / denom;
            if (abs(t1 - 0.5) <= 0.5) && (abs(t2 - 0.5) <= 0.5)
                nodeX = basePoints(idx,1) + l * cos(orient(idx)) * t1;
                nodeY = basePoints(idx,2) + l * sin(orient(idx)) * t1;
                nodes = [nodes; nodeX, nodeY, 1, 0];
                association = [association; idx, jdx];
            end
        end
    end
end

function [nodes, association] = findBoundaryNodes(basePoints, orient, l, L, Nstick)
%   FINDBOUNDARYNODES defines nodes where sticks cross either
%       (i) the top boundary stick (0,L) -- (L,L) or
%       (ii) the bottom boundary stick (0,0) -- (L,0)
%   Later, in Metropolis:
%       the top stick will be sheared; its nodes are movable & subject to
%       an applied force
%       the bottom stick is fixed; its nodes will not be allowed to move
%   nodes is a Nnodes x 4 array where each row contains the following
%   information:
%       (1) x coordinate of crossing
%       (2) y coordinate of crossing (either L or 0)
%       (3) boolean 0 or 1, describing whether this is a node which
%       should be perturbed later in the Metropolis algorithm
%       (4) boolean 0 or 1, describing whether this node requires a
%       fictitious potential term when calculating energy
    nodes = [];
    association = [];
    topStick = Nstick + 1;
    bottomStick = Nstick + 2;
    for idx = 1:Nstick
        % does stick cross the top boundary?
        tTop1 = (L - basePoints(idx,2)) / (l * sin(orient(idx)));
        % tTop2 = basePoints(idx,1) / L + (1 - basePoints(idx,2) / L) * cot(orient(idx));
        if abs(tTop1 - 0.5) <= 0.5 % && abs(tTop2 - 0.5) <= 0.5
            nodeX = basePoints(idx,1) + l * cos(orient(idx)) * tTop1;
            % nodeY = basePoints(idx,2) + l * sin(orient(idx)) * tTop1;
            nodes = [nodes; nodeX, L, 1, 1];
            association = [association; idx, topStick];
        end
        % does stick cross the bottom boundary?
        tBot1 = -basePoints(idx,2) / (l * sin(orient(idx)));
        % tBot2 = basePoints(idx,1) / L - (basePoints(idx,2) / L) * cot(orient(idx));
        if abs(tBot1 - 0.5) <= 0.5 % && abs(tBot2 - 0.5) <= 0.5
            nodeX = basePoints(idx,1) + l * cos(orient(idx)) * tBot1;
            % nodeY = basePoints(idx,2) + l * sin(orient(idx)) * tBot1;
            nodes = [nodes; nodeX, 0, 0, 0];
            association = [association; idx, bottomStick];
        end
    end
end

function [nodeNums] = nodesAlongStick(stickNum, avoidSelf, stickCross)
%   NODESALONGSTICK returns the node numbers for all nodes that lie along a
%   particular stick, skipping the node specified by avoidSelf
    [candidateNodeNums, ~] = find(stickCross == stickNum);
    avoidThese = candidateNodeNums == avoidSelf; %this only works if avoidNums is scalar - that's all we need, right?
    nodeNums = candidateNodeNums(~avoidThese);
end


function [nodeNum_plus, nodeNum_minus] = closestNodes(nodeNum, checkNums, nodes)
%   CLOSESTNODE returns the index/indices of (up to two) neighbor node(s)
%   This index/these indices will refer to the nodes which are closest to
%   nodeNum, and must be on opposite sides of nodeNum
%   checkNums lists indices of nodes which fall along one of the sticks
%   that defines the node nodeNum
%   If there are only nodes to one side of nodeNum, nodeNum_minus = [].
    if isempty(checkNums)
        nodeNum_plus = [];
        nodeNum_minus = [];
    elseif numel(checkNums) == 1
        nodeNum_plus = checkNums;
        nodeNum_minus = [];
    else
        z0 = nodes(nodeNum, 1:2); % z0 = (x0,y0) of base node
        % (arbitrarily) use the first node to define an orientation vector
        ref = nodes(checkNums(1), 1:2);
        z0ref = (ref - z0) ./ sqrt(sum( (ref - z0).^2 ));

        nodeNum_plus = checkNums(1);    % winner unless unseated
        dotProd_plus = dot(z0ref, ref - z0);
        nodeNum_minus = [];     % phantom winner until node on "other side" found
        dotProd_minus = -100;
        
        for idx = 2:length(checkNums)
            currentNode = nodes(checkNums(idx),1:2);
            thisDot = dot(z0ref, currentNode - z0);
            if 0 < thisDot && thisDot < dotProd_plus
                % if this node is closer in the + dir. than the current
                % winner in the + dir., replace winner
                nodeNum_plus = checkNums(idx);
                dotProd_plus = thisDot;
            elseif thisDot < 0 && thisDot > dotProd_minus
                % if this node is closer in the - dir. than the current
                % winner (or the phantom winner) in - dir., replace winner
                nodeNum_minus = checkNums(idx);
                dotProd_minus = thisDot;
            end
        end
    end
end

function bool = isNewSpring(node1, node2, springList)
%   ISNEWSPRING returns a boolean value that indicates whether a spring
%   connecting node1 and node2 is new (i.e., hasn't been recorded yet)
%   node1, node2 are indices which specify nodes
%   Note: must use convention that node1 < node2
    if isempty(springList)
        bool = true;
    else
        bool = true;
        currentNumSprings = size(springList,1); % number of rows in springList
        for idx = 1:currentNumSprings
            if springList(idx,1) ~= node1
                continue
            elseif springList(idx,1) == node1 && springList(idx,2) ~= node2
                continue
            else
                bool = false;
                break
            end
        end
    end
end

function springs = defineSprings(nodes, stickCross)
% DEFINESPRINGS takes the information about where sticks cross and defines
% a list of springs between all adjacent nodes
% springs is a Nsprings x 4 array, each row contains the following
% information:
%   (1) lesser node index that defines one end of the spring
%   (2) greater node index that defines the other end of the spring
%   (3) stick index of which stick this spring is a segment of
%   (4) rest length of the spring (the original distance between the nodes)

    %   idx iterates over each node number
    springs = [];
    for idx = 1:length(nodes)
        stick1 = stickCross(idx,1);
        stick2 = stickCross(idx,2);

        % first check for springs along stick1
        avoidSelf = idx;
        nodeNums = nodesAlongStick(stick1, avoidSelf, stickCross);
        [nodeNum_plus, nodeNum_minus] = closestNodes(idx, nodeNums, nodes);
        if ~isempty(nodeNum_plus)
            node1 = min(idx, nodeNum_plus);
            node2 = max(idx, nodeNum_plus);
            if isNewSpring(node1, node2, springs)
                restLength = sqrt(sum( (nodes(idx,1:2) - nodes(nodeNum_plus,1:2)).^2 ));
                springs = [springs; ...
                    node1, node2, stick1, restLength];
            end
        end

        if ~isempty(nodeNum_minus)
            node1 = min(idx, nodeNum_minus);
            node2 = max(idx, nodeNum_minus);
            if isNewSpring(node1, node2, springs)
                restLength = sqrt(sum( (nodes(idx,1:2) - nodes(nodeNum_minus,1:2)).^2 ));
                springs = [springs; ...
                    node1, node2, stick1, restLength];
            end
        end

        % now check for springs along stick2
        nodeNums = nodesAlongStick(stick2, avoidSelf, stickCross);
        [nodeNum_plus, nodeNum_minus] = closestNodes(idx, nodeNums, nodes);
        if ~isempty(nodeNum_plus)
            node1 = min(idx, nodeNum_plus);
            node2 = max(idx, nodeNum_plus);
            if isNewSpring(node1, node2, springs)
                restLength = sqrt(sum( (nodes(idx,1:2) - nodes(nodeNum_plus,1:2)).^2 ));
                springs = [springs; ...
                    node1, node2, stick2, restLength];
            end
        end

        if ~isempty(nodeNum_minus)
            node1 = min(idx, nodeNum_minus);
            node2 = max(idx, nodeNum_minus);
            if isNewSpring(node1, node2, springs)
                restLength = sqrt(sum( (nodes(idx,1:2) - nodes(nodeNum_minus,1:2)).^2 ));
                springs = [springs; ...
                    node1, node2, stick2, restLength];
            end
        end
    end
end

function catalog = springsByNode(springs,numNodes)
    catalog = zeros(numNodes,4);
    for idx = 1:numNodes
        connectedSprings1 = find(springs(:,1) == idx);
        connectedSprings2 = find(springs(:,2) == idx);
        connectedSprings = [connectedSprings1; connectedSprings2]';
        catalog(idx, 1:length(connectedSprings)) = connectedSprings;
    end
end