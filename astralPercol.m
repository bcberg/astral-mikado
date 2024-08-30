% astralPercol.m
% Brady Berg
clear; close all;
format long; format compact;
set(0,'defaultTextInterpreter','latex')
set(0,'defaultAxesTickLabelInterpreter','latex')
set(0,'defaultLegendInterpreter','latex')

%% Parameters

recompute = input("Recompute percolation probabilities (1=yes, 0=no)? ");
numDensVals = 50;
% Note: there may be fewer density values in certain percolation curves due
% to requiring integer numbers of asters (density resolution is coarser at
% higher astral number)
sampPerDensity = 2000;
l = 5;
if recompute
    D = input("Enter system size:");
else
    % load a particular existing dataset
    D = 50;
end
filename = sprintf('percProbs_D%02i',D);
densityRange = logspace(-1,1,numDensVals);
astralNumList = 1:48;
numNetTypes = length(astralNumList);

%% Percolation probability estimation

if recompute
    numFilRange = densityRange * D^2 / l;
    numAstersUsed = cell(numNetTypes,1);
    actualDensities = cell(numNetTypes,1);
    percProbs = cell(numNetTypes,1);
    pool = parpool(8);
    addAttachedFiles(pool,'percCheck.m')
    parfor idx = 1:numNetTypes
        astralNum = astralNumList(idx);
        numAsterRange = unique(round(numFilRange/astralNum));
        thisNumDensVals = length(numAsterRange);
        theseProbs = zeros(1,thisNumDensVals);
        for jdx = 1:thisNumDensVals
            percCount = 0;
            for kdx = 1:sampPerDensity
                [network,crossings,~] = generateAstralNetwork_mex(numAsterRange(jdx), ...
                    l, D, astralNum, true);
                [percTF,~] = percCheck(crossings,network.nodes,D);
                if percTF(1) || percTF(2)
                    percCount = percCount + 1;
                end
            end
            theseProbs(jdx) = percCount / sampPerDensity;
        end
        numAstersUsed{idx} = numAsterRange;
        actualDensities{idx} = numAsterRange * (astralNum * l / D^2);
        percProbs{idx} = theseProbs;
        fprintf('Astral number %i finished\n',astralNum)
    end
    delete(pool);
    save(['~/Documents/AstralMikadoCYM/data/',filename,'.mat'])
end

%% Plotting

% Ubuntu path
load(['~/Documents/AstralMikadoCYM/data/', filename, '.mat'])
% Windows path
% load(['C:\Users\bcber\Documents\AstralMikadoCYM\data\', filename, '.mat'])
fig1 = figure(1);
set(fig1,'defaultLineLineWidth',0.75)
cmap = colormap(turbo(numNetTypes));
hold on
for idx = 1:numNetTypes
    % plot(actualDensities(idx,:),percProbs(idx,:),'DisplayName', ...
    %     sprintf('nAST%02i',astralNumList(idx)),'Color',cmap(idx,:))
    plot(actualDensities{idx},percProbs{idx},'DisplayName', ...
        sprintf('nAST%02i',astralNumList(idx)),'Color',cmap(idx,:))
end
hold off
xscale('log')    % 'linear' or 'log'
legend('Location','eastoutside','NumColumns',2)
xlabel('Filament density [$\mu m^{-1}$]')
ylabel('Percolation probability')
% Ubuntu path
exportgraphics(fig1,['~/Documents/AstralMikadoCYM/data/', ...
    filename, '_curves.png'], 'Resolution',300)
% Windows path
% exportgraphics(fig1,['C:\Users\bcber\Documents\AstralMikadoCYM\data\', ...
%     filename, '_curves.png'], 'Resolution',300)

%% heatmap

% For heatmap, need to interpolate values at each value of densityRange
% Currently using cubic splines

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
title(sprintf('Domain size: %i',D))
% Ubuntu path
exportgraphics(fig2,['~/Documents/AstralMikadoCYM/data/', ...
    filename, '_heat.png'], 'Resolution',300)
% Windows path
% exportgraphics(fig2,['C:\Users\bcber\Documents\AstralMikadoCYM\data\', ...
%     filename, '_heat.png'], 'Resolution',300)