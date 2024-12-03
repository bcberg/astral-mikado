% danglingEnds.m
% Brady Berg
clear; close all;
format long; format compact;
set(0,'defaultTextInterpreter','latex')
set(0,'defaultAxesTickLabelInterpreter','latex')
set(0,'defaultLegendInterpreter','latex')

%% Parameters

rho = 7.5;
l = 1;
D = 10;
targetFilNum = rho * D^2 / l;

% Ubuntu path
% saveDirectory = '~/Documents/AstralMikadoCYM/data';
% Windows path
saveDirectory = 'C:\Users\bcber\Documents\AstralMikadoCYM\data\';
filename = 'danglingEnds_241203';
summaryfilename = 'endsSummary_241203';

%% Dangling end distributions

allNets = struct();
labelPat = 'an%02i';
nFilPerAsterList = 1:24;

thisFig = figure(99);
set(thisFig,'Position',[200,200,1600,1600],'visible','off')
thisFig = tiledlayout(2,2,'TileSpacing','compact');
tilesPerPage = 4;

for idx = 1:length(nFilPerAsterList)
    nexttile(thisFig,mod(idx,tilesPerPage) + tilesPerPage * (mod(idx,tilesPerPage)==0))
    astralNum = nFilPerAsterList(idx);
    networkLabel = sprintf(labelPat,astralNum);
    numAsters = round(targetFilNum/astralNum,TieBreaker="tozero");
    % (attempt to match Python rounding behavior)
    [allNets.(networkLabel),~,~] = generateAstralNetwork(numAsters,l,D, ...
        astralNum,false);

    if astralNum == 1
        histogram(allNets.(networkLabel).ends,'Normalization', ...
            'probability','BinWidth',0.1)
    elseif astralNum >= 2
        histogram(allNets.(networkLabel).ends(:,2),'Normalization', ...
            'probability','BinWidth',0.1)
    end
    xlabel('Dangling end length [arb. units]')
    ylabel('Empirical probability')
    title(networkLabel)

    if 0 == mod(idx,tilesPerPage) && idx == tilesPerPage
        % export first page
        exportgraphics(thisFig,fullfile(saveDirectory,[filename,'.pdf']), ...
            'Resolution',300)
        thisFig = clf(thisFig);
        set(thisFig,'Position',[200,200,1600,1600],'visible','off')
        thisFig = tiledlayout(2,2,'TileSpacing','compact');
    elseif 0 == mod(idx,tilesPerPage) && idx > tilesPerPage
        % export next pages, append to first file
        exportgraphics(thisFig,fullfile(saveDirectory,[filename,'.pdf']), ...
            'Resolution',300,'Append',true)
        thisFig = clf(thisFig);
        set(thisFig,'Position',[200,200,1600,1600],'visible','off')
        thisFig = tiledlayout(2,2,'TileSpacing','compact');
    end
end

%% Mean and total dangling ends

meanEnds = zeros(size(nFilPerAsterList));
meanEndsTrunc = zeros(size(nFilPerAsterList));
useFraction = zeros(size(nFilPerAsterList));
for idx = 1:length(nFilPerAsterList)
    astralNum = nFilPerAsterList(idx);
    networkLabel = sprintf(labelPat,astralNum);
    numAsters = round(targetFilNum/astralNum,TieBreaker="tozero");
    % (attempt to match Python rounding behavior)
    realFilNum = numAsters * astralNum;
    if astralNum == 1
        theseEnds = allNets.(networkLabel).ends;
        meanEndsTrunc(idx) = mean(theseEnds(theseEnds < l),"all");
        meanEnds(idx) = mean(theseEnds,"all");
    elseif astralNum >= 2
        theseEnds = allNets.(networkLabel).ends(:,2);
        meanEndsTrunc(idx) = mean(theseEnds(theseEnds < l));
        meanEnds(idx) = mean(theseEnds);
    end
    useFraction(idx) = 1 - (sum(allNets.(networkLabel).ends,"all") / ...
        (realFilNum * l));
end
fig1 = figure(1);
set(1,'defaultLineLineWidth',0.75)
yyaxis left
hold on
plot(nFilPerAsterList,meanEndsTrunc,'-b')
plot(nFilPerAsterList,meanEnds,'--b')
hold off
ylabel('Mean dangling end length [arb.]')
yyaxis right
plot(nFilPerAsterList,useFraction)
ylabel('Use fraction')
xlabel('Astral number')
legend('Truncated mean','Raw mean','Raw use','Location','south')
exportgraphics(fig1,fullfile(saveDirectory,[summaryfilename,'.emf']), ...
    'ContentType','vector')
save(fullfile(saveDirectory,filename),'allNets','D','l','rho','meanEnds', ...
    'meanEndsTrunc','useFraction','nFilPerAsterList')

