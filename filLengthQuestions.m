% filLengthQuestions.m
% Brady Berg
clear; close all;
format long; format compact;
set(0,'defaultTextInterpreter','latex')
set(0,'defaultAxesTickLabelInterpreter','latex')
set(0,'defaultLegendInterpreter','latex')

%% At a given astral number, is there a difference between fewer+larger
% asters and more+smaller asters, fixing overall filament density?

astralNum = 1;
D = 50;
numRatioVals = 4;
lOverD = transpose(logspace(-3,0,numRatioVals));
numDensVals = 50;
densityRange = logspace(-1,1,numDensVals);
% Note: values in numAstersArray may not be unique, especially for high l/D
% repackage them in a cell array later
numAstersArray = round(repmat(densityRange*D/astralNum, ...
    [numRatioVals,1]) ./ repmat(lOverD,[1,numDensVals]));
sampPerDensity = 2000;

numAstersUsed = cell(numRatioVals,1);
actualDensities = cell(numRatioVals,1);
percProbs_oneclass = cell(numRatioVals,1);
pool = parpool(4); % or 8 if running on desktop
parfor idx = 1:length(lOverD)
    thisLength = lOverD(idx) * D;
    thisNumAsterRange = unique(numAstersArray(idx,:));
    thisNumDensVals = length(thisNumAsterRange);
    thesePercProbs = zeros(1,thisNumDensVals)
    for jdx = 1:thisNumDensVals
        percCount = 0;
        for kdx = 1:sampPerDensity
            [network,crossings,~] = generateAstralNetwork(thisNumAsterRange(jdx), ...
                thisLength,D,astralNum,true);
            [percTF,~] = percCheck(crossings,network.nodes,D);
            if percTF(1) || percTF(2)
                percCount = percCount + 1;
            end
        end
        thesePercProbs(jdx) = percCount / sampPerDensity;
    end
    numAstersUsed{idx} = thisNumAsterRange;
    actualDensities{idx} = astralNum*thisNumAsterRange * lOverD(idx) / D;
    percProbs_oneclass{idx} = thesePercProbs;
end
delete(pool);

% plotting
fig1 = figure(1);
set(fig1,'defaultLineLineWidth',0.75)
hold on
for idx = 1:numRatioVals
    plot(actualDensities{idx},percProbs_oneclass{idx},'DisplayName', ...
        sprintf('$l/D = %1.3f$',lOverD(idx)));
end
hold off
xscale('log')
xlabel('Filament density [$\mu m^{-1}$]')
ylabel('Percolation probability')
title(sprintf('$a_n = %i$',astralNum))
legend('Location','west')
% Windows path
exportgraphics(fig1,['C:\Users\bcber\Documents\AstralMikadoCYM\data\', ...
    sprintf('lOverD_nAST%02i',astralNum), '.png'],'Resolution',300)

%% How does the ratio l/D matter at each astral number?
% and is there an l << D regime where it doesn't matter much?

% astralNumList = 1:24;