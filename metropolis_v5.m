% metropolis_v5.m
% Brady Berg

clear
close all
format compact
set(0,'defaultTextInterpreter','latex')
set(0,'defaultAxesTickLabelInterpreter','latex')

%% Workflow setup

l = 5;      % 5um stick length
L = 75;     % 75um x 75um world size
density = 2.5;
Nstick = round(L^2 * density / l);

trial = 1;
maxConvChecks = 8;
directory = ['mikadoNet_density',num2str(density),'_netnum',num2str(trial)];
mkdir(directory);

%% Generate network

[nodes, springs, catalog, ~] = generateMikadoNetwork(Nstick,l,L);

% wasted length quantifier
% (length used in a spring) / (total length of all sticks)
useFraction = sum(springs(:,4)) / (Nstick * l);

%% Run Metropolis

totForce = 1;
kbT = 0.5;
springK = 1;
[convE, endState] = metropolisMikado(nodes,springs,catalog, ...
    totForce, kbT, springK, maxConvChecks, directory);
save([directory,'/workspace.mat'])

%% Post-analysis

% subdirectory = [directory,'/f',num2str(totForce)];

% figure(1)
% set(1,'Position',[100,200,1000,400])
% subplot(1,2,1)
% hold on
% for idx = 1:size(springs,1)
%     nodeA = springs(idx,1);
%     nodeB = springs(idx,2);
%     coords = [nodes(nodeA,:); nodes(nodeB,:)];
%     plot(coords(:,1), coords(:,2), '.b-')
% end
% hold off
% title('Original')
% 
% subplot(1,2,2)
% hold on
% for idx = 1:size(springs,1)
%     nodeA = springs(idx,1);
%     nodeB = springs(idx,2);
%     coords = [state(nodeA,:); state(nodeB,:)];
%     plot(coords(:,1), coords(:,2), '.b-')
% end
% title('Deformed')
% saveas(gcf,[directory,'/networkshape.png'])

% E = readmatrix([subdirectory,'/energyLog.txt']);
% figure(2)
% plot(E)
% saveas(gcf,[directory,'/energy.png'])