% metropolis_v3.m
% Brady Berg

clear
close all
format compact
set(0,'defaultTextInterpreter','latex')
set(0,'defaultAxesTickLabelInterpreter','latex')

%{
Look at timeseries (movie, plot of rightmost node's x coord)
split perturbation sizes for top (forced) nodes vs bulk nodes
    -different adaptations! (hope-> top node perturbation size << bulk
    perturbation)
    -to investigate, try stealing perturbation size from F=0 and not
    adapting it for F > 0

Matlab/SSH notes
- <MATLABPATH> -nodesktop -nojvm <mfile>
- look up SCREEN and NOHUP for running programs w/o terminal open
%}

%% Get network, set parameters

load('smalltestNetwork_1.25e3stick.mat')
totForce = 1;
kbT = 0.5;
springK = 1;
maxConvChecks = 4;

%% Run Metropolis

monitor = false;
[E, convergedE, state] = metropolisMikado(nodes, springs, springCatalog,...
    totForce, kbT, springK, maxConvChecks, monitor);

save('data.mat')

%% Plot figures

figure(1)
set(1,'Position',[100,200,1000,400])
subplot(1,2,1)
hold on
for idx = 1:size(springs,1)
    nodeA = springs(idx,1);
    nodeB = springs(idx,2);
    coords = [nodes(nodeA,:); nodes(nodeB,:)];
    plot(coords(:,1), coords(:,2), '.b-')
end
hold off
title('Original')

subplot(1,2,2)
hold on
for idx = 1:size(springs,1)
    nodeA = springs(idx,1);
    nodeB = springs(idx,2);
    coords = [state(nodeA,:); state(nodeB,:)];
    plot(coords(:,1), coords(:,2), '.b-')
end
title('Deformed')
saveas(gcf,'networkshape.png')

figure(2)
plot(E)
saveas(gcf,'energy.png')
