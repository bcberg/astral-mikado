% danglingEnds.m
% Brady Berg
clear; close all;
format long; format compact;
set(0,'defaultTextInterpreter','latex')
set(0,'defaultAxesTickLabelInterpreter','latex')
set(0,'defaultLegendInterpreter','latex')

%% Parameters

rho = 5;
l = 5;
D = 50;
targetFilNum = rho * D^2 / l;

%% Dangling end distributions

allNets = struct();
labelPat = 'nAST%02i';
nASTlist = 1:24;

thisFig = figure(99);
set(thisFig,'Position',[200,200,1600,1600],'visible','off')
thisFig = tiledlayout(2,2,'TileSpacing','compact');
tilesPerPage = 4;

for idx = 1:length(nASTlist)
    nexttile(thisFig,mod(idx,tilesPerPage) + tilesPerPage * (mod(idx,tilesPerPage)==0))
    astralNum = nASTlist(idx);
    networkLabel = sprintf(labelPat,astralNum);
    numAsters = round(targetFilNum/astralNum,TieBreaker="tozero");
    % (attempt to match Python rounding behavior)
    [allNets.(networkLabel),~,~] = generateAstralNetwork(numAsters,l,D,astralNum);

    if astralNum == 1
        histogram(allNets.(networkLabel).ends,'Normalization', ...
            'probability','BinWidth',0.2)
    elseif astralNum >= 2
        histogram(allNets.(networkLabel).ends(:,2),'Normalization', ...
            'probability','BinWidth',0.2)
    end
    xlabel('Dangling end length [arb. units]')
    ylabel('Empirical probability')
    title(networkLabel)

    if 0 == mod(idx,tilesPerPage) && idx == tilesPerPage
        % export first page
        exportgraphics(thisFig,'~/Documents/AstralMikadoCYM/data/endsDistr.pdf', ...
            'Resolution',300)
        thisFig = clf(thisFig);
        set(thisFig,'Position',[200,200,1600,1600],'visible','off')
        thisFig = tiledlayout(2,2,'TileSpacing','compact');
    elseif 0 == mod(idx,tilesPerPage) && idx > tilesPerPage
        % export next pages, append to first file
        exportgraphics(thisFig,'~/Documents/AstralMikadoCYM/data/endsDistr.pdf', ...
            'Resolution',300,'Append',true)
        thisFig = clf(thisFig);
        set(thisFig,'Position',[200,200,1600,1600],'visible','off')
        thisFig = tiledlayout(2,2,'TileSpacing','compact');
    end
end

%% Mean and total dangling ends

meanEnds = zeros(size(nASTlist));
useFraction = zeros(size(nASTlist));
for idx = 1:length(nASTlist)
    astralNum = nASTlist(idx);
    networkLabel = sprintf(labelPat,astralNum);
    numAsters = round(targetFilNum/astralNum,TieBreaker="tozero");
    % (attempt to match Python rounding behavior)
    realFilNum = numAsters * astralNum;
    meanEnds(idx) = mean(allNets.(networkLabel).ends,"all");
    useFraction(idx) = 1 - (sum(allNets.(networkLabel).ends,"all") / ...
        (realFilNum * l));
end
fig1 = figure(1);
set(1,'defaultLineLineWidth',0.75)
yyaxis left
plot(nASTlist,meanEnds)
ylabel('Mean dangling end length [arb.]')
yyaxis right
plot(nASTlist,useFraction)
ylabel('Use fraction')
xlabel('Astral number')
exportgraphics(fig1,'~/Documents/AstralMikadoCYM/data/endsSummary.png', ...
    'Resolution',300)

