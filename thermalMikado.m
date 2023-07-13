% thermalMikado.m
% Brady Berg
clear; close all;
format long; format compact;
set(0,'defaultTextInterpreter','latex')
set(0,'defaultAxesTickLabelInterpreter','latex')
set(0,'defaultLegendInterpreter','latex')

%% Specifying simulation

% network generation parameters
l = 5;      % 5um stick length
L = 75;     % 75um x 75um world size
density = 2.5;
Nstick = round(L^2 * density / l);

% Biophysical parameters
param.totForce = 1;     % adjust this to sweep over external forces
param.kBT = 0.5;
param.springK = 1;

% Metropolis algorithm hyperparameters
hyparam.nt = 0;
hyparam.E = 0;          % start E = 0, adjust after each convergence check
hyparam.ntCheck = 1e6;      % run 3*ntCheck iters., compare last 2 thirds
hyparam.maxConvChecks = 10;
hyparam.ntAdmit = 2.5e4;    % num. of steps used to estimate pAdmit
hyparam.pAdmit = 0.4;      % target probability that a step is accepted
hyparam.epsilonBulk = 1;
hyparam.epsilonTop = 1;
hyparam.ksSamples = 5e2;    % num. of samples (per third) to use in kstest2
hyparam.ntWrite = 2e3;      % write every ntWrite value of E to disk
hyparam.ntWriteFrame = 1e7; % write current network config less frequently
hyparam.nextFrame = 1;      % frame number of next network config write

%% Directory structure

trial = 1;
directories.dir = ['thermalMikado_dens',num2str(density),'_trial',num2str(trial)];
mkdir(directories.dir);
% when sweeping, the below needs to happen in a loop
directories.subdir = [directories.dir,'/f',num2str(param.totForce)]; 
mkdir(directories.subdir);

%% Generate network, specify applied force values

% [nodes,springs,catalog,stickCross,basePoints,orient]
[nodes, springs, catalog, ~, ~, ~] = generateMikadoNetwork(Nstick,l,L);
node_rows = size(nodes,1);
node_cols = 2;      % node coordinates are (x,y) pairs

% wasted length quantifier
% (length used in a spring) / (total length of all sticks)
useFraction = sum(springs(:,4)) / (Nstick * l);

% forcesweep = [0, logspace(-1,1,7)];

save([directories.dir,'/initNetStats.mat'])
%% Run simulation(s)

convChecksDone = 0;
converged = false;
startOrResume = 's';
while convChecksDone < hyparam.maxConvChecks && ~converged
    % before mex acceleration, 5.5 hrs -> 331*10^7 iterations
    % after mex acceleration, 5 hrs -> 5.9049*10^10 iterations
    [state, energyLogFile, resumeInfo] = metropolisMikado_mex(nodes, springs, ...
        catalog, param, hyparam, directories, startOrResume);
    % read energyLogFile to check for convergence
    [pValue, KSstat] = convergenceCheck(energyLogFile,hyparam);
    display(KSstat)
    if KSstat >= 0.01
        % reject null hypothesis that distributions are the same
        % transfer info for resuming perturbations
        nodes = state;
        hyparam.nt = resumeInfo.nt;
        hyparam.E = resumeInfo.E;
        hyparam.ntCheck = 3 * hyparam.ntCheck;
        hyparam.epsilonTop = resumeInfo.epsilonTop;
        hyparam.epsilonBulk = resumeInfo.epsilonBulk;
        hyparam.nextFrame = resumeInfo.nextFrame;
        startOrResume = 'r';
    else
        % null hypothesis not rejected, i.e. distributions similar enough
        converged = true;
        % record converged energy samples
        fileID = fopen(energyLogFile,'r');
        bytesPerDouble = 8;
        whereToRead = bytesPerDouble * hyparam.ntCheck;
        fseek(fileID, whereToRead, 'bof');
        convergedE = fread(fileID, 2 * hyparam.ntCheck, 'double');
    end
    convChecksDone = convChecksDone + 1;
end
save([directories.dir,'/endNetStats.mat'])
