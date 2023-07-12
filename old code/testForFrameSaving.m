% testForFrameSaving.m
% Brady Berg
clear; close all;
format long; format compact;
set(0,'defaultTextInterpreter','latex')
set(0,'defaultAxesTickLabelInterpreter','latex')
set(0,'defaultLegendInterpreter','latex')

%% Generate a network to save

% network generation parameters
l = 5;      % 5um stick length
L = 75;     % 75um x 75um world size
density = 2.5;
Nstick = round(L^2 * density / l);
[nodes, springs, catalog, ~, ~, ~] = generateMikadoNetwork(Nstick,l,L);

% Biophysical parameters
param.totForce = 1;     % adjust this to sweep over external forces
param.kBT = 0.5;
param.springK = 1;

%% Directory structure

trial = 0;
directory = ['thermalMikado_dens',num2str(density),'_trial',num2str(trial)];
mkdir(directory);
subdirectory = [directory,'/f',num2str(param.totForce)];
mkdir(subdirectory);

%% Save and load nodes array
% note: springs array can still be saved in initNetStats.mat

frameFile = [subdirectory,'/frame0.bin'];
fileID = fopen(frameFile,'w');
fwrite(fileID,nodes,'double');
fclose(fileID);

% to read file in correctly, need to know dimensions of nodes
Nnodes = size(nodes(:,1:2),1);     % determine this from initNetStats.mat
Ncols = 2;
fileID = fopen(frameFile,'r');
readInNodes = fread(fileID,[Nnodes,Ncols],'double');
fclose(fileID);

display(all(nodes(:,1:2) == readInNodes))
