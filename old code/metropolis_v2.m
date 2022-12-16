% metropolis_v2.m
% Brady Berg

clear
close all
format compact
set(0,'defaultTextInterpreter','latex')
set(0,'defaultAxesTickLabelInterpreter','latex')

%% Metropolis-Hastings setup

load('testNetwork_5e3stick.mat')
kbT = 0.5;
state = nodes;
totalForce = 25;
numTopNodes = sum(nodes(:,4));
force = totalForce / numTopNodes;
springK = 1;


%% Run Metropolis-Hastings

ntCheck = 1e5;
ntMax = 3^7 * ntCheck;
ntAdmit = 5e4;
epsilon = 1;
E = zeros(3*ntCheck,1);
converged = false;
downsampleFactor = 1e3;
nt = 1;
numAccepts = 0;

movingNodes = find(nodes(:,3) == 1);
while ~converged && nt < ntMax
    alteredNode = randsample(movingNodes,1);
    newPosition = state(alteredNode,1:2) + epsilon * (2*rand(1,2) - 1);
    deltaE = getEnergyChange(alteredNode, newPosition, state, springs, ...
        springCatalog, force, springK);
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
            lastAcceptProb = numAccepts/ntAdmit;
            epsilon = epsilon * lastAcceptProb / 0.44;
        end
        numAccepts = 0;
    end

    % convergence check
    if nt == 3 * ntCheck
        E1 = downsample(E(ntCheck : 2*ntCheck),downsampleFactor);
        E2 = downsample(E(2*ntCheck + 1 : end),downsampleFactor);
        if kstest2(E1,E2,'Alpha',0.05)
            % if null hypothesis that E1 and E2 are same is rejected
            ntCheck = 3 * ntCheck;
            downsampleFactor = 3 * downsampleFactor;
            E = [E; zeros(2*ntCheck,1)];
        else
            % null hypothesis not rejected -> distributions similar enough
            convergedE = E(ntCheck : end);
            converged = true;
        end
    end

%     if mod(nt, 10000) == 0
%         figure(5)
%         clf
%         hold on
%         for idx = 1:size(springs,1)
%             nodeA = springs(idx,1);
%             nodeB = springs(idx,2);
%             coords = [state(nodeA,:); state(nodeB,:)];
%             plot(coords(:,1), coords(:,2), '.b-')
%         end
%         xlim([-0.1*L,1.1*L])
%         ylim([-0.1*L,1.1*L])
%         hold off
%         pause
%     end
    nt = nt + 1;
end


%% Visualizing network & energy over iterations

figure(1)
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

figure(2)
hold on
for idx = 1:size(springs,1)
    nodeA = springs(idx,1);
    nodeB = springs(idx,2);
    coords = [state(nodeA,:); state(nodeB,:)];
    plot(coords(:,1), coords(:,2), '.b-')
end
axis tight
hold off

figure(3)
plot(E)

%% Functions

fh = localfunctions;

function deltaE = getEnergyChange(alteredNode, movedHere, ...
    state, springs, catalog, force, springK)
% GETENERGYCHANGE returns the change in energy due to perturbing a single
% node
%   position is a 1x2 array [x_new, y_new]
    alteredSprings = catalog(alteredNode,:);
    alteredSprings = alteredSprings(alteredSprings ~= 0);
    prevPosition = state(alteredNode, 1:2);
    % note: don't alter state here, alter in the main metropolis loop
    deltaE = 0;
    % idx iterates over the *spring* index of each altered spring
    for idx = 1:length(alteredSprings)
        altSpringIdx = alteredSprings(idx);
        springNodes = springs(altSpringIdx,1:2);
        otherNode = springNodes(springNodes ~= alteredNode);
        otherEnd = state(otherNode, 1:2);
        restL = springs(altSpringIdx, 4);
        oldE = 0.5 * springK * (norm(prevPosition - otherEnd) - restL) ^ 2;
        newE = 0.5 * springK * (norm(movedHere - otherEnd) - restL) ^ 2;
        if state(alteredNode, 4) == 1
            oldE = oldE - force * prevPosition(1);
            newE = newE - force * movedHere(1);
        end
        deltaE = deltaE + newE - oldE;
    end
end