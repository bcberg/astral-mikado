function [state,energyLogFile,resumeInfo] = metropolisMikado(nodes, ...
    springs, springCatalog, param, hyparam, directories, startOrResume)
% METROPOLISMIKADO perturbs a spring network using Metropolis-Hastings
%   Inputs:
%       nodes (Nnodes x 4 double): node information, each row has
%           (1) x coordinate of crossing
%           (2) y coordinate of crossing
%           (3) boolean 0 or 1 indicating whether to allow node to move;
%               0 indicates fixed
%           (4) boolean 0 or 1 indicating whether node directly experiences
%               external force; 1 indicates yes
%       springs (Nsprings x 4 double): spring information, each row has
%           (1) lesser node index that defines one end of the spring
%           (2) greater node index that defines the other end of the spring
%           (3) stick index of which stick this spring is a segment of
%           (4) rest length of the spring (set to initial distance between
%               the nodes)
%       springCatalog (Nnodes x 4 double): list of spring indices connected
%           to a particular node; for stick-based networks a max. of 4 
%           springs can be connected to a single node, filler zeros added
%           as necessary
%       param (1 x 1 struct): biophysical parameters; has fields totForce,
%           kBT, springK
%       hyparam (1 x 1 struct): algorithm parameters; has fields nt, E,
%           ntCheck, maxConvChecks, ntAdmit, pAdmit, epsilonBulk, 
%           epsilonTop, ksSamples, ntWrite, ntWriteFrame, nextFrame
%       directories (1 x 1 struct): locations for storing network configs,
%           energy logs; has fields dir, subdir
%       startOrResume (char vector): 'start' or 'resume' network
%           perturbations
%   Outputs:
%       state (Nnodes x 4 double): node positions after 3*ntCheck
%           iterations; same format as input `nodes`
%       energyLogFile (char vector): address of energyLog.bin relative to
%           working directory
%       resumeInfo (1 x 1 struct): other information needed to resume
%           perturbing network after a convergence check; has fields nt, E,
%           epsilonBulk, epsilonTop, nextFrame
movingNodes = find(nodes(:,3) == 1);    % returns indices of moving nodes
numMovingNodes = length(movingNodes);
topNodes = find(nodes(:,4) == 1);       % returns indices of "top" nodes
force = param.totForce / length(topNodes);
switch startOrResume
    case 'start'    % start perturbing network from initial configuration
        nt = hyparam.nt;    % should be initialized at 0  
        E = hyparam.E;      % should be initialized at 0
        state = nodes;
        % write initial energy to disk
        energyLogFile = [directories.subdir,'/energyLog.bin'];
        fileID = fopen(energyLogFile,'w');
        fwrite(fileID,E,'double');
        fclose(fileID);
        % write initial network config to disk
        frameFile = [directories.subdir,'/frame0.bin'];
        frameFileID = fopen(frameFile,'w');
        fwrite(frameFileID,state(:,1:2),'double');
        fclose(frameFileID);

        % adaptive step size counters
        numAcceptsBulk = 0;
        numAcceptsTop = 0;
        numVisitsTop = 0;

        % prepare for perturbation loop
        fileID = fopen(energyLogFile,'a');
        frame = hyparam.nextFrame;  % should be initialized at 1
        epsTop = hyparam.epsilonTop;
        epsBulk = hyparam.epsilonBulk;

        ntPause = 3 * hyparam.ntCheck;
        while nt < ntPause
            alteredNode = movingNodes(randi(numMovingNodes));
            if any(topNodes == alteredNode)
                numVisitsTop = numVisitsTop + 1;
                newPosition = state(alteredNode,1:2) + ...
                    epsTop * (2*rand(1,2) - 1);
                deltaE = getEnergyChange(alteredNode, newPosition, state, ...
                    springs, springCatalog, force, param.springK);
                if rand < exp(-deltaE/param.kBT)
                    state(alteredNode,1:2) = newPosition;
                    E = E + deltaE;
                    numAcceptsTop = numAcceptsTop + 1;
                % else
                    % do not accept the perturbation (i.e., don't move
                    % the node)
                end
            else
                newPosition = state(alteredNode,1:2) + ...
                    epsBulk * (2*rand(1,2) - 1);
                deltaE = getEnergyChange(alteredNode, newPosition, state, ...
                    springs, springCatalog, force, param.springK);
                if rand < exp(-deltaE/param.kBT)
                    state(alteredNode,1:2) = newPosition;
                    E = E + deltaE;
                    numAcceptsBulk = numAcceptsBulk + 1;
                % else
                    % do not accept the perturbation (i.e., don't move
                    % the node)
                end
            end
            nt = nt + 1;

            % writing to disk
            if mod(nt,hyparam.ntWrite) == 0
                fwrite(fileID,E,'double');
            end
            if mod(nt,hyparam.ntWriteFrame) == 0
                frameFile = [directories.subdir,'/frame',num2str(frame),'.bin'];
                frameFileID = fopen(frameFile,'w');
                fwrite(frameFileID,state(:,1:2),'double');
                fclose(frameFileID);
                frame = frame + 1;
            end

            % adaptive step size
            if mod(nt,hyparam.ntAdmit) == 0
                % adjust epsilonTop
                if numVisitsTop > 0
                    prob = numAcceptsTop/numVisitsTop;
                    if prob == 0
                        epsTop = epsTop/100;
                    else
                        epsTop = epsTop * prob / hyparam.pAdmit;
                    end
                end
                % adjust epsilonBulk
                numVisitsBulk = hyparam.ntAdmit - numVisitsTop;
                if numVisitsBulk > 0
                    prob = numAcceptsBulk/numVisitsBulk;
                    if prob == 0
                        epsBulk = epsBulk/100;
                    else
                        epsBulk = epsBulk * prob / hyparam.pAdmit;
                    end
                end
                numVisitsTop = 0;
                numAcceptsTop = 0;
                numAcceptsBulk = 0;
            end
        end
        fclose('all');
        resumeInfo.nt = nt;
        resumeInfo.E = E;
        resumeInfo.epsilonTop = epsTop;
        resumeInfo.epsilonBulk = epsBulk;
        resumeInfo.nextFrame = frame;

    case 'resume'   % resume perturbing network after convergence check
        nt = hyparam.nt;
        E = hyparam.E;
        state = nodes;
        energyLogFile = [directories.subdir,'/energyLog.bin'];
        % prepare for perturbation loop
        fileID = fopen(energyLogFile,'a');
        frame = hyparam.nextFrame;
        epsTop = hyparam.epsilonTop;
        epsBulk = hyparam.epsilonBulk;

        ntPause = 3 * hyparam.ntCheck;
        while nt < ntPause
            alteredNode = movingNodes(randi(numMovingNodes));
            if any(topNodes == alteredNode)
                newPosition = state(alteredNode,1:2) + ...
                    epsTop * (2*rand(1,2) - 1);
                deltaE = getEnergyChange(alteredNode, newPosition, state, ...
                    springs, springCatalog, force, param.springK);
                if rand < exp(-deltaE/param.kBT)
                    state(alteredNode,1:2) = newPosition;
                    E = E + deltaE;
                % else
                    % do not accept the perturbation (i.e., don't move
                    % the node)
                end
            else
                newPosition = state(alteredNode,1:2) + ...
                    epsBulk * (2*rand(1,2) - 1);
                deltaE = getEnergyChange(alteredNode, newPosition, state, ...
                    springs, springCatalog, force, param.springK);
                if rand < exp(-deltaE/param.kBT)
                    state(alteredNode,1:2) = newPosition;
                    E = E + deltaE;
                % else
                    % do not accept the perturbation (i.e., don't move
                    % the node)
                end
            end
            nt = nt + 1;

            % writing to disk
            if mod(nt,hyparam.ntWrite) == 0
                fwrite(fileID,E,'double');
            end
            if mod(nt,hyparam.ntWriteFrame) == 0
                frameFile = [directories.subdir,'/frame',num2str(frame),'.bin'];
                frameFileID = fopen(frameFile,'w');
                fwrite(frameFileID,state(:,1:2),'double');
                fclose(frameFileID);
                frame = frame + 1;
            end
        end
        fclose('all');
        resumeInfo.nt = nt;
        resumeInfo.E = E;
        resumeInfo.epsilonTop = epsTop;
        resumeInfo.epsilonBulk = epsBulk;
        resumeInfo.nextFrame = frame;
end

end

function deltaE = getEnergyChange(alteredNode, movedHere, ...
    state, springs, catalog, force, springK)
% GETENERGYCHANGE returns the energy change due to perturbing a single node
%   Inputs: 
%       alteredNode (integer): index of node that was moved
%       movedHere (1 x 2 double): position vector [x_perturb, y_perturb]
%       state (Nnodes x 4 double): node information before perturbation;
%           same format as nodes from above
%       springs (Nsprings x 4 double): spring information; same format as
%           above
%       catalog (Nnodes x 4 double): list of spring indices connected
%           to a particular node; for stick-based networks a max. of 4 
%           springs can be connected to a single node
%       force (double): amount of force applied to a single node, if forced
%       springK (double): Hookean spring constant
%   Outputs:
%       deltaE (double): change in energy due to perturbation
alteredSprings = catalog(alteredNode,:);
% if <4 springs are connected to a node, alteredSprings has filler zeros
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