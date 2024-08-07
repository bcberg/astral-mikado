% astralPercol.m
% Brady Berg
clear; close all;
format long; format compact;
set(0,'defaultTextInterpreter','latex')
set(0,'defaultAxesTickLabelInterpreter','latex')
set(0,'defaultLegendInterpreter','latex')

%% Parameters

sampPerDensity = 200;
l = 5;
D = 50;
densityRange = linspace(2,20,20);
numFilRange = densityRange * D^2 / l;
astralNum = 1;

%% Percolation probability plot

numAsterVals = round(numFilRange/astralNum);
percProbs = zeros(size(densityRange));
pool = parpool(8);
parfor idx = 1:length(densityRange)
    connCount = 0;
    for jdx = 1:sampPerDensity
        [~,crossings,~] = generateAstralNetwork_mex(numAsterVals(idx), ...
            l, D, astralNum);
        [connTF,~] = connCheck(crossings);
        if connTF
            connCount = connCount + 1;
        end
    end
    percProbs(idx) = connCount / sampPerDensity;
end
delete(pool);

actualDensities = numAsterVals * (astralNum * l / D^2);
fig1 = figure(1);
plot(actualDensities,percProbs)
xlabel('Filament density [$\mu m ^{-1}]$')
ylabel('Percolation probability')
title(sprintf('$n_{AST} = %i $',astralNum))
exportgraphics(fig1,'~/Documents/AstralMikadoCYM/data/perc50_nAST01.png', ...
    'Resolution',300)