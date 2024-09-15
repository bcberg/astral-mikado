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
else
    % load a particular existing dataset
    D = 50;
    l = 5;
end
filename = sprintf('percProbs_D%02i_l%02i',D,l);
numDensVals = 50;
% Note: there may be fewer density values in certain percolation curves due
% to requiring integer numbers of asters (density resolution is coarser at
% higher astral number)
sampPerDensity = 2e3;
% at smaller l/D, probabilities are 0 until higher densities
% manually adjust densityRange to capture the transition
densityRange = logspace(0,log10(50),numDensVals);
astralNumList = (1:48)';
numNetTypes = length(astralNumList);

%% Percolation probability estimation

if recompute
    numFilRange = densityRange * D^2 / l;
    numAstersArray = round(repmat(numFilRange,[numNetTypes,1]) ./ ...
        repmat(astralNumList,[1,numDensVals]));
    numAstersUsed = cell(numNetTypes,1);
    numUniqueDensVals_byrow = zeros(numNetTypes,1);
    actualDensities = cell(numNetTypes,1);
    percProbs = cell(numNetTypes,1);
    for idx = 1:numNetTypes
        numAstersUsed{idx} = unique(numAstersArray(idx,:));
        numUniqueDensVals_byrow(idx) = numel(numAstersUsed{idx});
        actualDensities{idx} = astralNumList(idx)*numAstersUsed{idx}*l/D^2;
        percProbs{idx} = zeros(1,numUniqueDensVals_byrow(idx));
    end
    
    Njobs = sum(numUniqueDensVals_byrow);
    pool = parpool(8);  % adjust depending on machine
    useMEX = true;      % adjust depending on machine
    addAttachedFiles(pool,'estPercProb.m')
    F = parallel.FevalFuture.empty(Njobs,0);
    F_partition = zeros(Njobs,2);
    job_idx = 1;
    for idx = 1:numNetTypes
        for jdx = 1:numUniqueDensVals_byrow(idx)
            F(job_idx) = parfeval(pool,@estPercProb,1, ...
                numAstersUsed{idx}(jdx),l,D,astralNumList(idx), ...
                sampPerDensity,useMEX);
            F_partition(job_idx,1) = idx;  % record this future's ratio idx
            F_partition(job_idx,2) = jdx;  % record density sub-index, too
            job_idx = job_idx + 1;
        end
    end
    waitMessage = 'Waiting for FevalFutures to complete... (%4i/%4i)';
    h = waitbar(0,sprintf(waitMessage,0,Njobs));
    for idx = 1:Njobs
        [completedIdx,p] = fetchNext(F);
        whereToStore = F_partition(completedIdx,:);
        percProbs{whereToStore(1)}(whereToStore(2)) = p;
        waitbar(idx/Njobs,h,sprintf(waitMessage,idx,Njobs));
    end
    delete(pool)
    delete(h)
    clear('F')
    % Ubuntu path
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
    plot(actualDensities{idx},percProbs{idx},'DisplayName', ...
        sprintf('nAST%02i',astralNumList(idx)),'Color',cmap(idx,:))
end
hold off
xscale('log')    % 'linear' or 'log'
legend('Location','eastoutside','NumColumns',2)
xlabel('Filament density [$\mu m^{-1}$]')
ylabel('Percolation probability')
title(sprintf('Domain size: %2.1f, Filament length: %1.1f',D,l))
% Ubuntu path
exportgraphics(fig1,['~/Documents/AstralMikadoCYM/data/', ...
    filename, '_curves.png'], 'Resolution',300)
% Windows path
% exportgraphics(fig1,['C:\Users\bcber\Documents\AstralMikadoCYM\data\', ...
%     filename, '_curves.png'], 'Resolution',300)

%% Heatmap

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
title(sprintf('Domain size: %2.1f, Filament length: %1.1f',D,l))
% Ubuntu path
exportgraphics(fig2,['~/Documents/AstralMikadoCYM/data/', ...
    filename, '_heat.png'], 'Resolution',300)
% Windows path
% exportgraphics(fig2,['C:\Users\bcber\Documents\AstralMikadoCYM\data\', ...
%     filename, '_heat.png'], 'Resolution',300)