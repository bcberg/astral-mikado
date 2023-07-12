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
maxConvChecks = 10;
directory = ['mikadoNet_density',num2str(density),'_netnum',num2str(trial)];
mkdir(directory);

%% Generate network

% [nodes,springs,catalog,stickCross,basePoints,orient]
[nodes, springs, catalog, ~, ~, ~] = generateMikadoNetwork(Nstick,l,L);

% wasted length quantifier
% (length used in a spring) / (total length of all sticks)
useFraction = sum(springs(:,4)) / (Nstick * l);

%% Run Metropolis for many forces

forcesweep = [0, logspace(-1, 1, 7)];
save([directory,'/netStats.mat'])
parfor idx = 1:length(forcesweep)
    totForce = forcesweep(idx);
    kbT = 0.5;
    springK = 1;
    [convE, endState] = metropolisMikado_v5(nodes,springs,catalog, ...
        totForce, kbT, springK, maxConvChecks, directory);
    subdirectory = [directory,'/f',num2str(totForce)];
    filename = [subdirectory,'/endData.mat'];
    parsave(filename, convE, endState);
end

%% Saving function

function parsave(filename, convE, endState)
    save(filename, 'convE', 'endState')
end
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