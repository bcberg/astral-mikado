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
% saveDirectory = '~/Documents/astral-mikado-data/';
% Windows path
saveDirectory = 'C:\Users\bcber\Documents\astral-mikado-data\';
datafilename = 'danglingEnds_250211';
histfilename = 'endsHist_250211';
summaryfilename = 'endsSummary_250211';
filetype = '.eps';

uciBlue = [0,100,164]/255;

%% Dangling end distributions

endsHists = figure(99);
set(endsHists,'units','centimeters','Position',[1,1,15,15],'visible','on')
endsHists = tiledlayout(2,2,'TileSpacing','compact');
tilesPerPage = 4;

generateNew = false;
if generateNew
    allNets = struct();
    labelPat = 'an%02i';
    nFilPerAsterList = 1:24;
    for idx = 1:length(nFilPerAsterList)
        astralNum = nFilPerAsterList(idx);
        networkLabel = sprintf(labelPat,astralNum);
        numAsters = round(targetFilNum/astralNum,TieBreaker="tozero");
        % (attempt to match Python rounding behavior)
        [allNets.(networkLabel),~,~] = generateAstralNetwork(numAsters,l,D, ...
            astralNum,false);
    end
else
    load(fullfile(saveDirectory,'mat_files',datafilename),'allNets','D','l', ...
    'rho','meanEnds','meanEndsTrunc','useFraction','nFilPerAsterList')
    labelPat = 'an%02i';
end

selectedAstralNums = [1,4,8,16];
for idx = 1:length(selectedAstralNums)
    nexttile(endsHists,mod(idx,tilesPerPage) + tilesPerPage * (mod(idx,tilesPerPage)==0))
    astralNum = selectedAstralNums(idx);
    networkLabel = sprintf(labelPat,astralNum);
    if astralNum == 1
        h = histogram(allNets.(networkLabel).ends,'Normalization', ...
            'probability','BinWidth',0.1);
        yl_an1 = ylim;
    elseif astralNum >= 2
        h = histogram(allNets.(networkLabel).ends(:,2),'Normalization', ...
            'probability','BinWidth',0.1);
        ylim(yl_an1)
    end
    h.FaceColor = uciBlue;
    h.FaceAlpha = 1;
    title(sprintf('$a_n = %i$',astralNum))
    set(gca,'FontName','Cambria Math','FontSize',18)
    xlabel(endsHists,'Dangling end length [$\mu\rm{m}$]','Interpreter', ...
        'latex','FontSize',18,'FontName','Cambria Math')
    ylabel(endsHists,'Probability','Interpreter','latex','FontSize',18, ...
        'FontName','Cambria Math')
    % fixing bug in vertical axis limits
    nexttile(1)
    ylim(yl_an1)

    if 0 == mod(idx,tilesPerPage) && idx == tilesPerPage
        % export first page
        exportgraphics(endsHists,fullfile(saveDirectory,'subfigures',...
            [histfilename,filetype]),'Resolution',300)
        % thisFig = clf(thisFig);
        % set(thisFig,'units','centimeters','Position',[1,1,15,15],'visible','on')
        % thisFig = tiledlayout(2,2,'TileSpacing','compact');
    % elseif 0 == mod(idx,tilesPerPage) && idx > tilesPerPage
    %     % export next pages, append to first file
    %     exportgraphics(thisFig,fullfile(saveDirectory,[histfilename,filetype]), ...
    %         'Resolution',300,'Append',true)
    %     thisFig = clf(thisFig);
    %     set(thisFig,'Position',[200,200,1600,1600],'visible','off')
    %     thisFig = tiledlayout(2,2,'TileSpacing','compact');
    end
end

%% Mean and total dangling ends

if generateNew
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
end

fig1 = figure(1);
set(1,'defaultLineLineWidth',2)
yyaxis left
hold on
plot(nFilPerAsterList,meanEnds,'-','Color',uciBlue)
plot(nFilPerAsterList,meanEndsTrunc,'--','Color',uciBlue)
hold off
yl = ylim;
ylim([0,yl(2)])
ylabel('Dangling end length [$\mu\rm{m}$]')
yyaxis right
plot(nFilPerAsterList,useFraction)
ylim([0,1])
ylabel('Use fraction')
xlabel('Astral number $a_n$')
legend('Mean (all ends)','Mean (ends $<\ell$)','Use fraction','Location','south')
set(gca,'FontName','Cambria Math','FontSize',18)
exportgraphics(fig1,fullfile(saveDirectory,'subfigures', ...
    [summaryfilename,filetype]),'ContentType','vector')
save(fullfile(saveDirectory,'mat_files',datafilename),'allNets','D','l', ...
    'rho','meanEnds','meanEndsTrunc','useFraction','nFilPerAsterList')

