% stick_drop_v1.m
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
Nstick = 50;

%% Stick placement

basePoints = L * rand([Nstick,2]);  % uniform draw of (bx_i,by_i) from [0,L]
% "semi-uniform" draw of theta_i from [0,2pi]
% while constraining sticks to lie inside [0,L]^2
orient = pickOrientations(basePoints,l,L);
% stick plot
figure(1)
set(1,'visible','on')
hold on
for idx = 1:Nstick
    plot(basePoints(idx,1) + l * cos(orient(idx)) * (0:1), ...
        basePoints(idx,2) + l * sin(orient(idx)) * (0:1), '-b.')
end
xlim([0,L])
ylim([0,L])
hold off
% histogram of orientations
figure(2)
set(2,'visible','on')
histogram(orient,'BinWidth',pi/4)

% highlighting nodes
[nodes, stickCross] = findNodes(basePoints,orient,l);
figure(1)
hold on
plot(nodes(:,1), nodes(:,2), 'or')
hold off

%% Building spring network

springs = [];
%   idx iterates over each node number

% for idx = 1:length(nodes)
%     stick1 = stickCross(idx,1);
%     stick2 = stickCross(idx,2);
%     
%     % first check for springs along stick1
%     avoidNums = idx;
%     nodeNums = nodesAlongStick(stick1, avoidNums, stickCross);
%     if ~isEmpty(nodeNums)
%         for jdx = 1:length(nodeNums)
% 
%         end
%     end
% 
%     % now check for springs along stick2
% 
% end

%% Functions

fh = localfunctions;
function orient = pickOrientations(basePoints,l,L)
    n = length(basePoints); % returns max(size(basePoints))
    orient = 2 * pi * rand([n,1]);
    for idx = 1:n
        failX = abs(basePoints(idx,1) + l * cos(orient(idx)) - L/2) > L/2;
        failY = abs(basePoints(idx,2) + l * sin(orient(idx)) - L/2) > L/2;
        while failX || failY
            orient(idx) = 2 * pi * rand();
            failX = abs(basePoints(idx,1) + l * cos(orient(idx)) - L/2) > L/2;
            failY = abs(basePoints(idx,2) + l * sin(orient(idx)) - L/2) > L/2;
        end
    end
end

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
    association = uint32(association);
end

function [nodeNums] = nodesAlongStick(stickNum, avoidNums, stickCross)
%   NODESALONGSTICK returns the node numbers for all nodes that lie along a
%   particular stick, skipping any nodes specified by avoidNums
    [candidateNodeNums, ~] = find(stickCross == stickNum);
    avoidThese = candidateNodeNums == avoidNums;
    nodeNums = candidateNodeNums(~avoidThese);
end


function [closeNodeNum] = closestNode(nodeNum, checkNums, nodes)
%   CLOSESTNODE returns the node index of whichever node is closest to the
%   specified node over all nodes specified by checkNums
    if isempty(checkNums)
        closeNodeNum = [];
    else
        z0 = nodes(nodeNum, :); % z0 = (x0,y0) of base node
        checkCoords = nodes(checkNums,:);
        dist_sq = sum((checkCoords - z0).^2, 1);
        [~, minIdx] = min(dist_sq);
        closeNodeNum = checkNums(minIdx);
    end
end