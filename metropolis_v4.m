% metropolis_v4.m
% Brady Berg

clear
close all
format compact
set(0,'defaultTextInterpreter','latex')
set(0,'defaultAxesTickLabelInterpreter','latex')

%{
Matlab/SSH notes
- <MATLABPATH> -nodesktop -nojvm <mfile>
- look up SCREEN and NOHUP for running programs w/o terminal open

Shift to writing E line-by-line
also record KS statistic & corresponding nt (can use .mat for ease)

Shear modulus
-try center of mass (avg of node locations)
-for validation, try rightmost point of largest connected set of nodes
--find using tarjan algorithm
-logspace for getting shear profile

kbT within order of magnitude of springK
%}

%% Get network, set parameters

load('smalltestNetwork_1.25e3stick.mat')
totForce = input('Total force: ');
kbT = 0.5;
springK = 1;
maxConvChecks = input('Max number of convergence checks: ');

%% Run Metropolis

monitor = true;
% [E, convergedE, state] = metropolisMikado(nodes, springs, springCatalog,...
%    totForce, kbT, springK, maxConvChecks, monitor);

directory = ['smallnet1.25_f',num2str(totForce)];
mkdir(directory)
label = [directory,'/data.mat'];
save(label)

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
saveas(gcf,[directory,'/networkshape.png'])

figure(2)
plot(E)
saveas(gcf,[directory,'/energy.png'])

exit