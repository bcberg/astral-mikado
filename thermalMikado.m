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
param.E = 0;            % start E = 0, adjust after each convergence check

% Metropolis algorithm hyperparameters
hyparam.ntCheck = 5e5;      % run 3*ntCheck iters., compare last 2 thirds
hyparam.maxConvChecks = 10;
hyparam.ntAdmit = 2.5e4;    % num. of steps used to estimate pAdmit
hyparam.pAdmit = 0.44;      % target probability that a step is accepted
hyparam.epsilonBulk = 1;
hyparam.epsilonTop = 1;
hyparam.ksSamples = 5e3;    % num. of samples (per third) to use in kstest2
hyparam.ntWrite = 1e2;      % write every ntWrite value of E to disk
                            % (also write current network config)

% directory structure
trial = 1;
directory = ['thermalMikado_dens',num2str(density),'_trial',num2str(trial)];

%% Generate network, specify applied force values

% [nodes,springs,catalog,stickCross,basePoints,orient]
[nodes, springs, catalog, ~, ~, ~] = generateMikadoNetwork(Nstick,l,L);

% wasted length quantifier
% (length used in a spring) / (total length of all sticks)
useFraction = sum(springs(:,4)) / (Nstick * l);

forcesweep = [0, logspace(-1,1,7)];

save([directory,'/initNetStats.mat'])
%% Run simulation(s)

convChecksDone = 0;
while convChecksDone < hyparam.maxConvChecks
    [state, resumeInfo] = metropolisMikado(nodes, springs, catalog, ...
        param, hyparam, directory, 'start');

    % transfering info for resuming
    hyparam.nt = resumeInfo.nt;
end
