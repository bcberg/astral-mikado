function [E, convergedE, state] = metropolisMikado(nodes,springs,springCatalog, ...
    totForce, kbT, springK, maxConvChecks, monitor)
%METROPOLISMIKADO executes the Metropolis-Hastings algorithm on a spring
%network
%   Arguments:
%
%   Returns:

ntCheck = 5e5;
ntMax = 3^maxConvChecks * ntCheck;
ntAdmit = 2.5e4;
epsilonBulk = 1;
epsilonTop = 1;
E = zeros(3*ntCheck,1);
converged = false;
downsampleFactor = 1e3;
nt = 1;
numAcceptsBulk = 0;
numAcceptsTop = 0;
numVisitsTop = 0;

if monitor
    directory = ['smallnet1.25_f',num2str(totForce)];
    mkdir(directory)
    frame = 1;
end


state = nodes;
movingNodes = find(nodes(:,3) == 1);    % returns indices of moving nodes
numMovingNodes = length(movingNodes);
topNodes = find(nodes(:,4) == 1);       % returns indices of "top" nodes
force = totForce / length(topNodes);
convergedE = [];

while ~converged && nt < ntMax
    alteredNode = movingNodes(randi(numMovingNodes));
    if any(topNodes == alteredNode)
        numVisitsTop = numVisitsTop + 1;
        newPosition = state(alteredNode,1:2) + epsilonTop * (2*rand(1,2) - 1);
        deltaE = getEnergyChange(alteredNode, newPosition, state, springs, ...
            springCatalog, force, springK);
        if rand < exp(-deltaE/kbT)
            state(alteredNode,1:2) = newPosition;
            E(nt+1) = E(nt) + deltaE;
            numAcceptsTop = numAcceptsTop + 1;
        else
            % do not accept the perturbation (i.e., don't move the node)
            E(nt+1) = E(nt);
        end
    else
        newPosition = state(alteredNode,1:2) + epsilonBulk * (2*rand(1,2) - 1);
        deltaE = getEnergyChange(alteredNode, newPosition, state, springs, ...
            springCatalog, force, springK);
        if rand < exp(-deltaE/kbT)
            state(alteredNode,1:2) = newPosition;
            E(nt+1) = E(nt) + deltaE;
            numAcceptsBulk = numAcceptsBulk + 1;
        else
            % do not accept the perturbation (i.e., don't move the node)
            E(nt+1) = E(nt);
        end
    end

    % snapshot recordings
    if monitor && mod(nt,1e7) == 0
        label = [directory,'/frame',num2str(frame),'.mat'];
        save(label, 'state')
        frame = frame + 1;
    end

    % adaptive step size
    if mod(nt,ntAdmit) == 0 && nt < ntCheck
        % adjust epsilonTop
        if numVisitsTop ~= 0
            prob = numAcceptsTop/numVisitsTop;
            if prob == 0
                epsilonTop = epsilonTop/100;
            else
                epsilonTop = epsilonTop * prob / 0.44;
            end
        end

        % adjust epsilonBulk
        numVisitsBulk = ntAdmit - numVisitsTop;
        if numVisitsBulk ~= 0
            prob = numAcceptsBulk/numVisitsBulk;
            if prob == 0
                epsilonBulk = epsilonBulk/100;
            else
                epsilonBulk = epsilonBulk * prob / 0.44;
            end
        end
%         display(epsilonTop)
%         display(epsilonBulk)
        numVisitsTop = 0;
        numAcceptsTop = 0;
        numAcceptsBulk = 0;
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
    nt = nt + 1;
end
end

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