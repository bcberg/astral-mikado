% percMCRG.m
% Brady Berg
clear; close all;
format long; format compact;
set(0,'defaultTextInterpreter','latex')
set(0,'defaultAxesTickLabelInterpreter','latex')
set(0,'defaultLegendInterpreter','latex')

%% Importing data

% Ubuntu path
saveDir = "~/Documents/AstralMikadoCYM/data";
% Windows path
% saveDir = "C:\Users\bcber\Documents\AstralMikadoCYM\data";
filePattern = "percProbs_l%02i_D%02i";

l = 1;
Dlist = [5,10,15];
numD = numel(Dlist);
allCurves = cell(1,numD);
for idx = 1:numD
    load(fullfile(saveDir,sprintf(filePattern,l,Dlist(idx))),'curves', ...
        'astralNumList')
    allCurves{idx} = curves;
    clear curves
end
numNetTypes = length(astralNumList);

%% Overplotting different system sizes (family of curves)

percTypes = {"Top-to-Bottom (TB)", "Left-to-Right (LR)", "TB OR LR", ...
    "TB AND LR", "Single connected component"};
numPercTypes = length(percTypes); % i.e., = 5
cmap = colormap(turbo(numD));
fig1 = figure(1);
for idx = 1:numNetTypes
    set(fig1,'units','inches','Position',[1,1,8.5,11],'visible','off', ...
        'defaultLineLineWidth',0.6)
    fig1 = tiledlayout(3,2,'TileSpacing','compact');
    netLabel = sprintf('an%02i',astralNumList(idx));
    tileIdx = 1;
    for jdx = 1:numPercTypes
        nexttile(fig1,tileIdx)
        hold on
        for kdx = 1:numD
            curves = allCurves{kdx};
            plot(curves.(netLabel)(1,:),curves.(netLabel)(1+jdx,:), ...
                'DisplayName',sprintf('D=%2.1f',Dlist(kdx)))
        end
        hold off
        xscale('log')
        xlabel('Filament density [$\mu m^{-1}$]')
        ylabel('Percolation probability')
        title(percTypes{jdx})
        if jdx == 1
            lg = legend('FontSize',12);
            lg.Layout.Tile = 6;
        end
        tileIdx = tileIdx + 1;
    end
    title(fig1,netLabel)
    if idx == 1
        % export first page
        exportgraphics(fig1,fullfile(saveDir,'percMCRG_curves.pdf'), ...
            'Resolution',300)
        fig1 = clf(fig1);
    else
        % export next pages
        exportgraphics(fig1,fullfile(saveDir,'percMCRG_curves.pdf'), ...
            'Resolution',300,'Append',true)
        fig1 = clf(fig1);
    end
end