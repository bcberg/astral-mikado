% astralPercol.m
% Brady Berg
clear; close all;
format long; format compact;
set(0,'defaultTextInterpreter','latex')
set(0,'defaultAxesTickLabelInterpreter','latex')
set(0,'defaultLegendInterpreter','latex')

%% Parameters

numDensVals = 50;
sampPerDensity = 500;
l = 5;
D = 50;
densityRange = logspace(-1,1,numDensVals);
numFilRange = densityRange * D^2 / l;
astralNumList = 1:25;
numNetTypes = length(astralNumList);

%% Percolation probability estimation

actualDensities = zeros([numNetTypes, numDensVals]);
percProbs = zeros([numNetTypes, numDensVals]);
pool = parpool(8);
addAttachedFiles(pool,'percCheck.m')
parfor idx = 1:numNetTypes
    astralNum = astralNumList(idx);
    numAsterRange = round(numFilRange/astralNum);
    actualDensities(idx,:) = numAsterRange * (astralNum * l / D^2);
    theseProbs = zeros(1,numDensVals);
    for jdx = 1:numDensVals
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
    percProbs(idx,:) = theseProbs;
    fprintf('Astral number %i finished\n',astralNum)
end
delete(pool);
save('~/Documents/AstralMikadoCYM/data/percProbs_D50.mat')

%% Plotting

% Ubuntu path
load('~/Documents/AstralMikadoCYM/data/percProbs_D50.mat')
% Windows path
% load("C:\Users\bcber\Documents\AstralMikadoCYM\data\percProbs_D50.mat")
fig1 = figure(1);
set(fig1,'defaultLineLineWidth',0.75)
cmap = colormap(turbo(numNetTypes));
hold on
for idx = 1:numNetTypes
    plot(actualDensities(idx,:),percProbs(idx,:),'DisplayName', ...
        sprintf('nAST%02i',astralNumList(idx)),'Color',cmap(idx,:))
end
hold off
xscale('log')    % 'linear' or 'log'
legend('Location','eastoutside')
xlabel('Line density [$\mu m^{-1}$]')
ylabel('Percolation probability')
exportgraphics(fig1,'~/Documents/AstralMikadoCYM/data/percProbs_D50.png', ...
    'Resolution',300)

%% heatmap

% figure(2)
% pcolor(percProbs)