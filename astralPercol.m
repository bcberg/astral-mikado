% astralPercol.m
% Brady Berg
clear; close all;
format long; format compact;
set(0,'defaultTextInterpreter','latex')
set(0,'defaultAxesTickLabelInterpreter','latex')
set(0,'defaultLegendInterpreter','latex')

%% Parameters

recompute = input("Recompute percolation probabilities (1=yes, 0=no)? ");
if recompute
    D = input("Enter system size: ");
    l = input("Enter filament length: (default = 1)");
    if isempty(l)
        l = 1;
    end
    astralNumList = (1:48)';
    densSpec = [-1,1,50];
    Nsamp = 2000;
    Ncores = 8;
else
    % load a particular existing dataset
    D = 50;
    l = 1;
end
% Ubuntu path
saveDirectory = "~/Documents/AstralMikadoCYM/data";
% Windows path
% saveDirectory = "C:\Users\bcber\Documents\AstralMikadoCYM\data";
filename = sprintf("percProbs_l%02i_D%02i",l,D);

%% Percolation probability estimation

if recompute
    curves = getAllPercCurves(l,D,astralNumList,densSpec,Nsamp,Ncores, ...
        saveDirectory);
end

%% Plotting

load(fullfile(saveDirectory,filename + ".mat"))

fig1 = figure(1);
set(fig1,'defaultLineLineWidth',0.75)
cmap = colormap(turbo(numNetTypes));
hold on
for idx = 1:numNetTypes
    plot(actualDensities{idx},percProbs{idx},'DisplayName', ...
        sprintf('nAST%02i',astralNumList(idx)),'Color',cmap(idx,:))
end
hold off
xscale('log')    % 'linear' or 'log'
legend('Location','eastoutside','NumColumns',2)
xlabel('Filament density [$\mu m^{-1}$]')
ylabel('Percolation probability')
title(sprintf('Domain size: %2.1f, Filament length: %1.1f',D,l))
exportgraphics(fig1,fullfile(saveDirectory,filename + "_curves.png"), ...
    'Resolution',300)

%% Heatmap

% For heatmap, need to interpolate values at each value of densityRange
% Currently using cubic splines
numDensVals = length(densityRange);
percProbsHeatmap = zeros(numNetTypes,numDensVals);
for idx = 1:numNetTypes
    percProbsHeatmap(idx,:) = spline(actualDensities{idx}, ...
        percProbs{idx},densityRange);
end

fig2 = figure(2);
pcolor(densityRange,astralNumList,percProbsHeatmap)
xscale('log')
xlabel('Filament density [$\mu m^{-1}$]')
ylabel('Astral number')
title(sprintf('Domain size: %2.1f, Filament length: %1.1f',D,l))
exportgraphics(fig1,fullfile(saveDirectory,filename + "_heat.png"), ...
    'Resolution',300)