% stick_drop_v2.m
% Brady Berg

clear
close all
format compact
set(0,'defaultTextInterpreter','latex')
set(0,'defaultAxesTickLabelInterpreter','latex')

%% Elementary parameters

l0 = 1e-6;  % length scale = 1um
r = 4e-9/l0;    % stick radius = 4nm
alpha = 1e-3;    % aspect ratio alpha = r/l in (1e-4, 1e-2)
l = r/alpha;    % stick length becomes r/alpha
L = 10e-6/l0;   % region 10um x 10um
Nstick = 300;

%% Stick placement

basePoints = L * rand([Nstick,2]);  % uniform draw of (bx_i,by_i) from [0,L]
orient = 2 * pi * rand([Nstick,1]); % uniform draw of theta_i from [0,2*pi]
% stick plot
figure(1)
set(1,'visible','on')
hold on
for idx = 1:Nstick
    plot(basePoints(idx,1) + l * cos(orient(idx)) * (0:1), ...
        basePoints(idx,2) + l * sin(orient(idx)) * (0:1), '-b.')
end
xlim([-0.2*L,1.2*L])
ylim([-0.2*L,1.2*L])
hold off
% histogram of orientations
figure(2)
set(2,'visible','off')
histogram(orient,'BinWidth',pi/4)

% highlighting nodes
[nodes, stickCross] = findNodes(basePoints,orient,l);
figure(1)
hold on
plot(nodes(:,1), nodes(:,2), 'or')
hold off

%% Building spring network

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
            restLength = sqrt(sum( (nodes(idx,:) - nodes(nodeNum_plus,:)).^2 ));
            springs = [springs; ...
                node1, node2, stick1, restLength];
        end
    end

    if ~isempty(nodeNum_minus)
        node1 = min(idx, nodeNum_plus);
        node2 = max(idx, nodeNum_plus);
        if isNewSpring(node1, node2, springs)
            restLength = sqrt(sum( (nodes(idx,:) - nodes(nodeNum_plus,:)).^2 ));
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
            restLength = sqrt(sum( (nodes(idx,:) - nodes(nodeNum_plus,:)).^2 ));
            springs = [springs; ...
                node1, node2, stick2, restLength];
        end
    end

    if ~isempty(nodeNum_minus)
        node1 = min(idx, nodeNum_plus);
        node2 = max(idx, nodeNum_plus);
        if isNewSpring(node1, node2, springs)
            restLength = sqrt(sum( (nodes(idx,:) - nodes(nodeNum_plus,:)).^2 ));
            springs = [springs; ...
                node1, node2, stick2, restLength];
        end
    end
end

%% Drawing spring network

figure(3)
hold on
for idx = 1:size(springs,1)
    nodeA = springs(idx,1);
    nodeB = springs(idx,2);
    coords = [nodes(nodeA,:); nodes(nodeB,:)];
    plot(coords(:,1), coords(:,2), '.b-')
end
xlim([-0.2*L,1.2*L])
ylim([-0.2*L,1.2*L])
hold off

% wasted length quantifier
% (length used in a spring) / (total length of all sticks)
useFraction = sum(springs(:,4)) / (Nstick * l);

%% Functions

fh = localfunctions;

function [nodes, association] = findNodes(basePoints,orient,l)
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
                nodes = [nodes; nodeX, nodeY];
                association = [association; idx, jdx];
            end
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
%   If there are only nodes to one side of nodeNum, nodeNum_minus = [].
    if isempty(checkNums)
        nodeNum_plus = [];
        nodeNum_minus = [];
    else
        z0 = nodes(nodeNum, :); % z0 = (x0,y0) of base node
        % (arbitrarily) use the first node to define an orientation vector
        ref = nodes(checkNums(1),:);
        z0ref = (ref - z0) ./ sqrt(sum( (ref - z0).^2 ));

        nodeNum_plus = checkNums(1);    % winner unless unseated
        dotProd_plus = dot(z0ref, ref - z0);
        nodeNum_minus = [];     % phantom winner until node on "other side" found
        dotProd_minus = -100;
        for idx = 2:length(checkNums)
            currentNode = nodes(checkNums(idx),:);
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