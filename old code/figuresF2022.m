% figuresF2022.m
% Brady Berg

clear;
close all;
format compact;
set(0,'defaultTextInterpreter','latex')
set(0,'defaultAxesTickLabelInterpreter','latex')
set(0,'defaultLegendInterpreter','latex')

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
filename = 'C:\Users\bcber\Documents\1-UCI\Q1\Allard-Rotation\mikadoNet_density2.5_netnum1\f0\energyLog.bin';
fileID = fopen(filename,'r');
whereToRead = 0;
fseek(fileID, whereToRead, 'bof');
skip = bytesPerDouble * (1e6 - 1); % read an element at multiples of 'downsampleFactor'
E0 = fread(fileID,'double',skip);
fclose(fileID);

% figure(3)
% plot(E0)
% xlabel('$\times 10^6$ iterations')
% ylabel('Energy')


directory = 'C:\Users\bcber\Documents\1-UCI\Q1\Allard-Rotation\mikadoNet_density2.5_netnum1\f0';
lastFrame = 657;
centerofmass = zeros(lastFrame,2);
for idx = 1:lastFrame
    load([directory,'/frame',num2str(idx)],'state')
    centerofmass(idx,:) = mean(state(:,1:2));
end
figure(4)
plot(centerofmass)
legend('$x$ coordinate', '$y$ coordinate','Location','east')
xlabel('$\times 10^7$ iterations')
ylabel('Position')
xlim([0,lastFrame])
ylim([0,45])
title('Total Force $=0$')
saveas(gcf,"C:\Users\bcber\Documents\LaTeX files\figures\astral-mikado_centerTrackf0.png")

%% Analyzing f1

bytesPerDouble = 8;
filename = 'C:\Users\bcber\Documents\1-UCI\Q1\Allard-Rotation\mikadoNet_density2.5_netnum1\f1\energyLog.bin';
fileID = fopen(filename,'r');
whereToRead = 0;
fseek(fileID, whereToRead, 'bof');
skip = bytesPerDouble * (1e6 - 1); % read an element at multiples of 'downsampleFactor'
E1 = fread(fileID,'double',skip);
fclose(fileID);

% figure(5)
% plot(E1)

directory = 'C:\Users\bcber\Documents\1-UCI\Q1\Allard-Rotation\mikadoNet_density2.5_netnum1\f1';
lastFrame = 648;
centerofmass = zeros(lastFrame,2);
for idx = 1:lastFrame
    load([directory,'/frame',num2str(idx)],'state')
    centerofmass(idx,:) = mean(state(:,1:2));
end
figure(6)
plot(centerofmass)
legend('$x$ coordinate', '$y$ coordinate','Location','east')
xlabel('$\times 10^7$ iterations')
ylabel('Position')
xlim([0,lastFrame])
ylim([0,50])
title('Total Force $=1$')
saveas(gcf,"C:\Users\bcber\Documents\LaTeX files\figures\astral-mikado_centerTrackf1.png")

% superdirectory = 'C:\Users\bcber\Documents\1-UCI\Q1\Allard-Rotation\mikadoNet_density2.5_netnum1';
% totForce = 1; 
% load([superdirectory,'/netStats.mat'])
% figure(7)
% hold on
% for idx = 1:size(springs,1)
%     nodeA = springs(idx,1);
%     nodeB = springs(idx,2);
%     coords = [state(nodeA,1:2); state(nodeB,1:2)];
%     plot(coords(:,1), coords(:,2), '.b-')
% end

%% Analyzing f10

bytesPerDouble = 8;
filename = 'C:\Users\bcber\Documents\1-UCI\Q1\Allard-Rotation\mikadoNet_density2.5_netnum1\f10\energyLog.bin';
fileID = fopen(filename,'r');
whereToRead = 0;
fseek(fileID, whereToRead, 'bof');
skip = bytesPerDouble * (1e6 - 1); % read an element at multiples of 'downsampleFactor'
E10 = fread(fileID,'double',skip);
fclose(fileID);

% figure(8)
% plot(E10)

directory = 'C:\Users\bcber\Documents\1-UCI\Q1\Allard-Rotation\mikadoNet_density2.5_netnum1\f10';
lastFrame = 661;
centerofmass = zeros(lastFrame,2);
for idx = 1:lastFrame
    load([directory,'/frame',num2str(idx)],'state')
    centerofmass(idx,:) = mean(state(:,1:2));
end
figure(9)
plot(centerofmass)
legend('$x$ coordinate', '$y$ coordinate','Location','east')
xlabel('$\times 10^7$ iterations')
ylabel('Position')
xlim([0,lastFrame])
ylim([0,115])
title('Total Force $=10$')
saveas(gcf,"C:\Users\bcber\Documents\LaTeX files\figures\astral-mikado_centerTrackf10.png")

% superdirectory = 'C:\Users\bcber\Documents\1-UCI\Q1\Allard-Rotation\mikadoNet_density2.5_netnum1';
% totForce = 10; 
% load([superdirectory,'/netStats.mat'])
% figure(10)
% hold on
% for idx = 1:size(springs,1)
%     nodeA = springs(idx,1);
%     nodeB = springs(idx,2);
%     coords = [state(nodeA,1:2); state(nodeB,1:2)];
%     plot(coords(:,1), coords(:,2), '.b-')
% end

%% Generating centers of mass

superdirectory = 'C:\Users\bcber\Documents\1-UCI\Q1\Allard-Rotation\mikadoNet_density2.5_netnum1'; 
load([superdirectory,'/netStats.mat'],'nodes','forcesweep')
refCenter = mean(nodes(:,1:2));
centers = zeros(length(forcesweep),2);
lastFrames = [657; 653; 661; 663; 648; 657; 661; 661];
for idx = 1:length(forcesweep)
    totForce = forcesweep(idx);
    startframe = lastFrames(idx) - 50;
    directory = ['C:\Users\bcber\Documents\1-UCI\Q1\Allard-Rotation\mikadoNet_density2.5_netnum1\f',num2str(totForce)];
    centerofmass = zeros(50,2);
    for jdx = 1:50
        load([directory,'/frame',num2str(startframe+jdx)],'state')
        centerofmass(jdx,:) = mean(state(:,1:2));
    end
    centers(idx,:) = mean(centerofmass);
end
figure(11)
plot(centers(:,1) - refCenter(1),forcesweep,'*b')
xlabel('Displacement of $x$ center of mass')
ylabel('Total force')
ylim([0,10])
saveas(gcf,"C:\Users\bcber\Documents\LaTeX files\figures\astral-mikado_stressStrain.png")

%% Plotting energy histories

figure(12)
hold on
plot(E0)
plot(E1)
plot(E10)
xlabel('$\times 10^6$ iterations')
ylabel('Energy')
legend('$F = 0$', '$F = 1$', '$F = 10$', 'Location', 'east')
saveas(gcf,"C:\Users\bcber\Documents\LaTeX files\figures\astral-mikado_energyHistories.png")