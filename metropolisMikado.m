function [state,resumeInfo] = metropolisMikado(nodes, springs, ...
    springCatalog, param, hyparam, directory, startOrResume)
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
%           springs can be connected to a single node
%       param (1 x 1 struct): biophysical parameters; has fields totForce,
%           kBT, springK, E
%       hyparam (1 x 1 struct): algorithm parameters; has fields nt,
%           ntCheck, maxConvChecks, ntAdmit, pAdmit, epsilonBulk, 
%           epsilonTop, ksSamples, ntWrite, nextFrame
%       directory (char vector): directory for storing network configs,
%           energy logs
%       startOrResume (char vector): 'start' or 'resume' network
%           perturbations
%   Outputs:
%       state (Nnodes x 4 double): node positions after 3*ntCheck
%           iterations; same format as input `nodes`
%       resumeInfo (1 x 1 struct): other information needed to resume
%           perturbing network after a convergence check; has fields nt, E,
%           epsilonBulk, epsilonTop, nextFrame
movingNodes = find(nodes(:,3) == 1);    % returns indices of moving nodes
numMovingNodes = length(movingNodes);
topNodes = find(nodes(:,4) == 1);       % returns indices of "top" nodes
force = totForce / length(topNodes);
switch startOrResume
    case 'start'    % start perturbing network from initial configuration
        E = 0;
        nt = 1;
        % set up directories
        subdirectory = [directory,'/f',num2str(totForce)];
        mkdir(subdirectory);
        filename = [subdirectory,'/energyLog.bin'];
        fileID = fopen(filename,'w');
        fwrite(fileID,E,'double');
        fclose(fileID);
        fileID = fopen(filename,'a');
        frame = 1;

        ntPause = 3 * hyparam.ntCheck;

    case 'resume'   % resume perturbing network after convergence check
        E = param.E;
        nt = hyparam.nt;
        subdirectory = [directory,'/f',num2str(totForce)];
        filename = [subdirectory,'/energyLog.bin'];
        fileID = fopen(filename,'a');
        frame = hyparam.nextFrame;
end
outputArg1 = inputArg1;
outputArg2 = inputArg2;
end