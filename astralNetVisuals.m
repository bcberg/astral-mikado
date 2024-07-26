% astralNetVisuals.m
% Brady Berg
clear; close all;
format long; format compact;
set(0,'defaultTextInterpreter','latex')
set(0,'defaultAxesTickLabelInterpreter','latex')
set(0,'defaultLegendInterpreter','latex')

%% testing generation

astralNum = 2;
rho = 5;
l = 5;
D = 50;
targetFilNum = rho * D^2 / l;
numAsters = round(targetFilNum/astralNum,TieBreaker="tozero");  % attempt to match Python rounding behavior;
[network,crossings,asters] = generateAstralNetwork(numAsters,l,D,astralNum);

%% visualizing

% % stick plot
% figure(1)
% hold on
% for idx = 1:Nstick
%     plot(basePoints(idx,1) + l * cos(orient(idx)) * (0:1), ...
%         basePoints(idx,2) + l * sin(orient(idx)) * (0:1), '-b.')
% end
% hold off
% xlim([30,50])
% ylim([30,50])
% saveas(gcf,"C:\Users\bcber\Documents\LaTeX files\figures\astral-mikado_baseSticks.png")
% 
% % highlight nodes
% figure(1)
% hold on
% plot(nodes(:,1), nodes(:,2), 'ro')
% hold off
% saveas(gcf,"C:\Users\bcber\Documents\LaTeX files\figures\astral-mikado_baseSticks+nodes.png")
% 
% % draw spring network
% figure(2)
% hold on
% for idx = 1:size(springs,1)
%     nodeA = springs(idx,1);
%     nodeB = springs(idx,2);
%     coords = [nodes(nodeA,1:2); nodes(nodeB,1:2)];
%     plot(coords(:,1), coords(:,2), '.b-')
% end
% xlim([30,50])
% ylim([30,50])
% hold off
% saveas(gcf,"C:\Users\bcber\Documents\LaTeX files\figures\astral-mikado_springZoom.png")
% xlim([-0.1*L,1.1*L])
% ylim([-0.1*L,1.1*L])
% saveas(gcf,"C:\Users\bcber\Documents\LaTeX files\figures\astral-mikado_springWhole.png")