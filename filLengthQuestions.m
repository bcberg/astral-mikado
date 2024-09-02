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
lOverD = [1e-3; 5e-3; 1e-2; 5e-2; 1e-1; 2e-1; 4e-1; 1];
numRatioVals = length(lOverD);
numDensVals = 50;
densityRange = logspace(-1,1,numDensVals);
% Note: values in numAstersArray may not be unique, especially for high l/D
% repackage them in a cell array later
numAstersArray = round(repmat(densityRange*D/astralNum, ...
    [numRatioVals,1]) ./ repmat(lOverD,[1,numDensVals]));
sampPerDensity = 2000;

allF = cell(numRatioVals,1);
numAstersUsed = cell(numRatioVals,1);
actualDensities = cell(numRatioVals,1);
percProbs_oneclass = cell(numRatioVals,1);
pool = parpool(8);  % adjust depending on machine
useMEX = true;      % adjust depending on machine
for idx = 1:numRatioVals
    thisNumAsterRange = unique(numAstersArray(idx,:));
    thisNumDensVals = length(thisNumAsterRange);
    allF{idx} = parallel.FevalFuture.empty(thisNumDensVals,0);
    for jdx = 1:thisNumDensVals
        allF{idx}(jdx) = parfeval(pool,@estPercProb,1,...
            thisNumAsterRange(jdx),lOverD(idx)*D,D,astralNum, ...
            sampPerDensity,useMEX);
    end
    numAstersUsed{idx} = thisNumAsterRange;
    actualDensities{idx} = astralNum*thisNumAsterRange * lOverD(idx) / D;
end
% or format as one long vector and reshape output <- would be great if had
% same number of density samples per network type, but not always true

for idx = 1:numRatioVals
    thesePercProbs = fetchOutputs(allF{idx});
    percProbs_oneclass{idx} = reshape(thesePercProbs, ...
        [1,length(thesePercProbs)]);
end
delete(pool)
% Ubuntu path
save(['~/Documents/AstralMikadoCYM/data/', ...
    sprintf('lOverD_nAST%02i',astralNum),'.mat']);

% to stop evaluation of parfeval futures, run:
% for idx = 1:numRatioVals
%     cancel(allF{idx})
% end

% plotting
fig1 = figure(1);
set(fig1,'defaultLineLineWidth',0.75)
cmap = colormap(turbo(numRatioVals));
hold on
for idx = 1:numRatioVals
    plot(actualDensities{idx},percProbs_oneclass{idx},'DisplayName', ...
        sprintf('$l/D = %1.3f$',lOverD(idx)),'Color',cmap(idx,:));
end
hold off
xscale('log')
xlabel('Filament density [$\mu m^{-1}$]')
ylabel('Percolation probability')
title(sprintf('$a_n = %i$',astralNum))
legend('Location','west')
% Ubuntu path
exportgraphics(fig1,['~/Documents/AstralMikadoCYM/data/', ...
    sprintf('lOverD_nAST%02i',astralNum),'.png'],'Resolution',300)
% Windows path
% exportgraphics(fig1,['C:\Users\bcber\Documents\AstralMikadoCYM\data\', ...
%     sprintf('lOverD_nAST%02i',astralNum), '.png'],'Resolution',300)

%% How does the ratio l/D matter at each astral number?
% and is there an l << D regime where it doesn't matter much?
% e.g., in Lee & Torquato 1990, used l = 1 and smallest system D = 5 (up to
% D = 40)

% astralNumList = 1:24;