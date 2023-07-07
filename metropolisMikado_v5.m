function [convergedE, state] = metropolisMikado_v5(nodes,springs,springCatalog, ...
    totForce, kbT, springK, maxConvChecks, directory)
% METROPOLISMIKADO_V5 executes the Metropolis-Hastings algorithm on a spring
% network (legacy version, works with metropolis_v5.m script)
%   Arguments:
%
%   Returns:

ntCheck = 5e5;
% ntMax = 3^maxConvChecks * ntCheck;
ntAdmit = 2.5e4;
epsilonBulk = 1;
epsilonTop = 1;

% E = zeros(3*ntCheck,1);
% idx = 1;    % separate index for energy vector
E = 0;
converged = false;
nt = 1;
downsampleFactor = 2.5e3;
bytesPerDouble = 8;

numAcceptsBulk = 0;
numAcceptsTop = 0;
numVisitsTop = 0;

subdirectory = [directory,'/f',num2str(totForce)];
mkdir(subdirectory);
filename = [subdirectory,'/energyLog.bin'];
fileID = fopen(filename,'w');
fwrite(fileID,E,'double');
fclose(fileID);
fileID = fopen(filename,'a');
frame = 1;

state = nodes;
movingNodes = find(nodes(:,3) == 1);    % returns indices of moving nodes
numMovingNodes = length(movingNodes);
topNodes = find(nodes(:,4) == 1);       % returns indices of "top" nodes
force = totForce / length(topNodes);
convergedE = [];
checksCompleted = 0;

while ~converged && checksCompleted < maxConvChecks
    alteredNode = movingNodes(randi(numMovingNodes));
    if any(topNodes == alteredNode)
        numVisitsTop = numVisitsTop + 1;
        newPosition = state(alteredNode,1:2) + epsilonTop * (2*rand(1,2) - 1);
        deltaE = getEnergyChange(alteredNode, newPosition, state, springs, ...
            springCatalog, force, springK);
        if rand < exp(-deltaE/kbT)
            state(alteredNode,1:2) = newPosition;
            % E(idx+1) = E(idx) + deltaE;
            E = E + deltaE;
            numAcceptsTop = numAcceptsTop + 1;
%         else
            % do not accept the perturbation (i.e., don't move the node)
            % E(idx+1) = E(idx);
            % E = E; (don't need to 'do nothing')
        end
    else
        newPosition = state(alteredNode,1:2) + epsilonBulk * (2*rand(1,2) - 1);
        deltaE = getEnergyChange(alteredNode, newPosition, state, springs, ...
            springCatalog, force, springK);
        if rand < exp(-deltaE/kbT)
            state(alteredNode,1:2) = newPosition;
            % E(idx+1) = E(idx) + deltaE;
            E = E + deltaE;
            numAcceptsBulk = numAcceptsBulk + 1;
%         else
            % do not accept the perturbation (i.e., don't move the node)
            % E(idx+1) = E(idx);
        end
    end

    % record energy value
    fwrite(fileID,E,'double');

    % snapshot recordings
    if mod(nt,1e7) == 0
        label = [subdirectory,'/frame',num2str(frame),'.mat'];
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
        numVisitsTop = 0;
        numAcceptsTop = 0;
        numAcceptsBulk = 0;
    end

    % convergence check
    if nt == 3 * ntCheck
        fclose('all');
        if checksCompleted == 0
            ksstat = 1; % automatically fail first check
        else
            fileID = fopen(filename,'r');
            whereToRead = bytesPerDouble * ntCheck;
            fseek(fileID, whereToRead, 'bof');
            skip = bytesPerDouble * (downsampleFactor - 1); % read an element at multiples of 'downsampleFactor'
            twoThirdsE = fread(fileID,'double',skip);
            fclose(fileID);

            midpt = floor(length(twoThirdsE)/2);
            E1 = twoThirdsE(1:midpt);
            E2 = twoThirdsE(midpt+1:end);
            [~,~,ksstat] = kstest2(E1,E2);
        end
        
        if ksstat >= 0.01
            % if null hypothesis that E1 and E2 are same is rejected
            ntCheck = 3 * ntCheck;
            downsampleFactor = 3 * downsampleFactor;
%           all of this is unnecessary, no longer storing E in memory
%             % toss first third of E to save memory
%             E = E(idx + 1);
%             E = zeros(2*ntCheck,1);
%             idx = 0;
%             E(idx+1) = E;
        else
            % null hypothesis not rejected -> distributions similar enough
            fileID = fopen(filename,'r');
            fseek(fileID, whereToRead, 'bof');
            skip = (1e5 - 1) * bytesPerDouble;
            convergedE = fread(fileID,'double',skip);
            fclose(fileID);
            converged = true;
        end
        fileID = fopen(filename,'a');
        checksCompleted = checksCompleted + 1;
    end
    nt = nt + 1;
    % idx = idx + 1;
end
fclose(fileID);
end

function deltaE = getEnergyChange(alteredNode, movedHere, ...
    nodes, springs, catalog, force, springK)
% GETENERGYCHANGE returns the change in energy due to perturbing a single
% node
%   position is a 1x2 array [x_new, y_new]
    alteredSprings = catalog(alteredNode,:);
    alteredSprings = alteredSprings(alteredSprings ~= 0);
    prevPosition = nodes(alteredNode, 1:2);
    % note: don't alter state here, alter in the main metropolis loop
    deltaE = 0;
    % idx iterates over the *spring* index of each altered spring
    for idx = 1:length(alteredSprings)
        altSpringIdx = alteredSprings(idx);
        springNodes = springs(altSpringIdx,1:2);
        otherNode = springNodes(springNodes ~= alteredNode);
        otherEnd = nodes(otherNode, 1:2);
        restL = springs(altSpringIdx, 4);
        oldE = 0.5 * springK * (norm(prevPosition - otherEnd) - restL) ^ 2;
        newE = 0.5 * springK * (norm(movedHere - otherEnd) - restL) ^ 2;
        if nodes(alteredNode, 4) == 1
            oldE = oldE - force * prevPosition(1);
            newE = newE - force * movedHere(1);
        end
        deltaE = deltaE + newE - oldE;
    end
end