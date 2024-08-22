% astralPercol.m
% Brady Berg
clear; close all;
format long; format compact;
set(0,'defaultTextInterpreter','latex')
set(0,'defaultAxesTickLabelInterpreter','latex')
set(0,'defaultLegendInterpreter','latex')

%% Parameters

numDensVals = 50;
sampPerDensity = 200;
l = 5;
D = 50;
densityRange = linspace(2,25,numDensVals);
numFilRange = densityRange * D^2 / l;
astralNumList = 1:25;
numNetTypes = length(astralNumList);

%% Percolation probability estimation

% actualDensities = zeros([numNetTypes, numDensVals]);
% percProbs = zeros([numNetTypes, numDensVals]);
% pool = parpool(8);
% parfor idx = 1:numNetTypes
%     astralNum = astralNumList(idx);
%     numAsterVals = round(numFilRange/astralNum);
%     actualDensities(idx,:) = numAsterVals * (astralNum * l / D^2);
%     theseProbs = zeros(1,numDensVals);
%     for jdx = 1:numDensVals
%         connCount = 0;
%         for kdx = 1:sampPerDensity
%             [~,crossings,~] = generateAstralNetwork_mex(numAsterVals(jdx), ...
%                 l, D, astralNum);
%             [connTF,~] = connCheck(crossings);
%             if connTF
%                 connCount = connCount + 1;
%             end
%         end
%         theseProbs(jdx) = connCount / sampPerDensity;
%     end
%     percProbs(idx,:) = theseProbs;
%     fprintf('Astral number %i finished\n',astralNum)
% end
% delete(pool);
% save('~/Documents/AstralMikadoCYM/data/percProbs_D50.mat')

%% Plotting

% Ubuntu path
% load('~/Documents/AstralMikadoCYM/data/percProbs_D50.mat')
% Windows path
load("C:\Users\bcber\Documents\AstralMikadoCYM\data\percProbs_D50.mat")
fig1 = figure(1);
set(fig1,'defaultLineLineWidth',0.75)
cmap = colormap(turbo(numNetTypes));
hold on
for idx = 1:numNetTypes
    plot(actualDensities(idx,:),percProbs(idx,:),'DisplayName', ...
        sprintf('nAST%02i',astralNumList(idx)),'Color',cmap(idx,:))
end
hold off
xscale('linear')    % 'linear' or 'log'
legend('Location','eastoutside')
xlabel('Line density [$\mu m^{-1}$]')
ylabel('Percolation probability')
% exportgraphics(fig1,'~/Documents/AstralMikadoCYM/data/percProbs_D50.png', ...
%     'Resolution',300)

%% heatmap

figure(2)
pcolor(percProbs)