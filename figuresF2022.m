% figuresF2022.m
% Brady Berg

clear;
close all;
format compact;
set(0,'defaultTextInterpreter','latex')
set(0,'defaultAxesTickLabelInterpreter','latex')

%% Network generation

load("C:\Users\bcber\Documents\1-UCI\Q1\Allard-Rotation\mikadoNet_density2.5_netnum1\netStats.mat");

% [nodes,springs,catalog,stickCross,basePoints,orient] = generateMikadoNetwork(Nstick,l,L);
% save('netGenExample.mat')
load('netGenExample.mat')
% stick plot
figure(1)
hold on
for idx = 1:Nstick
    plot(basePoints(idx,1) + l * cos(orient(idx)) * (0:1), ...
        basePoints(idx,2) + l * sin(orient(idx)) * (0:1), '-b.')
end
hold off
xlim([30,50])
ylim([30,50])
saveas(gcf,"C:\Users\bcber\Documents\LaTeX files\figures\astral-mikado_baseSticks.png")

% highlight nodes
figure(1)
hold on
plot(nodes(:,1), nodes(:,2), 'ro')
hold off
saveas(gcf,"C:\Users\bcber\Documents\LaTeX files\figures\astral-mikado_baseSticks+nodes.png")

% draw spring network
figure(2)
hold on
for idx = 1:size(springs,1)
    nodeA = springs(idx,1);
    nodeB = springs(idx,2);
    coords = [nodes(nodeA,1:2); nodes(nodeB,1:2)];
    plot(coords(:,1), coords(:,2), '.b-')
end
xlim([30,50])
ylim([30,50])
hold off
saveas(gcf,"C:\Users\bcber\Documents\LaTeX files\figures\astral-mikado_springZoom.png")
xlim([-0.1*L,1.1*L])
ylim([-0.1*L,1.1*L])
saveas(gcf,"C:\Users\bcber\Documents\LaTeX files\figures\astral-mikado_springWhole.png")
clear

%% Analyzing f0

bytesPerDouble = 8;
filename = "C:\Users\bcber\Documents\1-UCI\Q1\Allard-Rotation\mikadoNet_density2.5_netnum1\f0\energyLog.bin";
fileID = fopen(filename,'r');
whereToRead = 0;
fseek(fileID, whereToRead, 'bof');
skip = bytesPerDouble * (1e6 - 1); % read an element at multiples of 'downsampleFactor'
E0 = fread(fileID,'double',skip);
fclose(fileID);

figure(3)
plot(E0)

directory = "C:\Users\bcber\Documents\1-UCI\Q1\Allard-Rotation\mikadoNet_density2.5_netnum1\f0";
lastFrame = 657;
centerofmass = zeros(lastFrame,2);
for idx = 1:lastFrame
    load([directory,'/frame',num2str(idx)],'state')
    centerofmass(idx,:) = mean(state(:,1:2));
end
figure(4)
plot(centerofmass)
legend('$x$ coordinate', '$y$ coordinate')