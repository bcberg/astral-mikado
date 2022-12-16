% metropolis_v1.m
% Brady Berg

clear
close all
format compact
set(0,'defaultTextInterpreter','latex')
set(0,'defaultAxesTickLabelInterpreter','latex')

%% Metropolis-Hastings setup

load('testNetwork_2.5e3stick.mat')
kbT = 1e-2;
numNodes = size(nodes, 1);
state = nodes;
totalForce = 1;
numTopNodes = sum(nodes(:,4));
force = totalForce / numTopNodes;
springK = 1;

%% Run Metropolis-Hastings

ntMax = 1e6;
ntCheck = 3e5;
ntAdmit = 1e4;
epsilon = 3e-1;
E = zeros(ntMax,1);
converged = false;
nt = 1;
numAccepts = 0;
while ~converged && nt < ntMax
    alteredNode = randi(numNodes);
    % avoid bottom nodes!
    newPosition = state(alteredNode,1:2) + epsilon * rand(1,2);
    deltaE = getEnergyChange(alteredNode, newPosition, nodes, springs, force, springK);
%     if deltaE < 0
%         break
%     end
    if rand < exp(-deltaE/kbT)
        state(alteredNode,1:2) = newPosition;
        E(nt+1) = E(nt) + deltaE;
        numAccepts = numAccepts + 1;
    else
        % do not accept the perturbation (i.e., don't move the node)
        E(nt+1) = E(nt);
    end
    
    % adaptive step size
    if mod(nt,ntAdmit) == 0 && nt < ntCheck
        if numAccepts == 0
            epsilon = epsilon/100;
        else
            epsilon = epsilon * (numAccepts / ntAdmit) / 0.44;
        end
        numAccepts = 0;
    end
    % convergence check
    if mod(nt,ntCheck) == 0
        %?
    end
    nt = nt + 1;
end


%% Visualizing network

figure(3)
hold on
for idx = 1:size(springs,1)
    nodeA = springs(idx,1);
    nodeB = springs(idx,2);
    coords = [nodes(nodeA,:); nodes(nodeB,:)];
    plot(coords(:,1), coords(:,2), '.b-')
end
xlim([-0.1*L,1.1*L])
ylim([-0.1*L,1.1*L])
hold off

figure(4)
hold on
for idx = 1:size(springs,1)
    nodeA = springs(idx,1);
    nodeB = springs(idx,2);
    coords = [state(nodeA,:); state(nodeB,:)];
    plot(coords(:,1), coords(:,2), '.b-')
end
xlim([-0.1*L,1.1*L])
ylim([-0.1*L,1.1*L])
hold off

%% Functions

fh = localfunctions;

function springIdxs = getConnectedSprings(node, springs)
    firstpass = find(springs(:,1) == node);
    secondpass = find(springs(:,2) == node);
    springIdxs = [firstpass; secondpass];
end

function deltaE = getEnergyChange(alteredNode, position, nodes, springs, force, springK)
% GETENERGYCHANGE returns the change in energy due to perturbing a single
% node
%   position is a 1x2 array [x_new, y_new]
    alteredSprings = getConnectedSprings(alteredNode, springs);
    prevPosition = nodes(alteredNode, 1:2);
    % note: don't alter nodes here, alter nodes in the main metropolis loop
    deltaE = 0;
    % idx iterates over the *spring* index of each altered spring
    for idx = 1:length(alteredSprings)
        altSpringIdx = alteredSprings(idx);
        springNodes = springs(altSpringIdx,1:2);
        otherNode = springNodes(springNodes ~= alteredNode);
        otherEnd = nodes(otherNode, 1:2);
        restL = springs(altSpringIdx, 4);
        oldE = 0.5 * springK * (norm(prevPosition - otherEnd) - restL) ^ 2;
        newE = 0.5 * springK * (norm(position - otherEnd) - restL) ^ 2;
        if nodes(alteredNode, 4) == 1
            oldE = oldE - force * prevPosition(1);
            newE = newE - force * position(1);
        end
        deltaE = deltaE + newE - oldE;
    end
end