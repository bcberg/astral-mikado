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
Dlist = [5,10,15,20];
numD = numel(Dlist);
allCurves = cell(1,numD);
allAstralNums = [];
for idx = 1:numD
    load(fullfile(saveDir,sprintf(filePattern,l,Dlist(idx))),'curves', ...
        'astralNumList')
    allCurves{idx} = curves;
    allAstralNums = union(allAstralNums,astralNumList);
    clear curves
end
numNetTypes = length(allAstralNums);

%% Overplotting different system sizes (family of curves)

percTypes = {"Top-to-Bottom (TB)", "Left-to-Right (LR)", "TB OR LR", ...
    "TB AND LR", "Single connected component"};
numPercTypes = length(percTypes); % i.e., = 5
fig1 = figure('units','inches','Position',[1,1,8.5,11]);
set(fig1,'visible','off','defaultLineLineWidth',0.6)
for idx = 1:numNetTypes
    fig1 = tiledlayout(3,2,'TileSpacing','compact');
    netLabel = sprintf('an%02i',allAstralNums(idx));
    tileIdx = 1;
    for jdx = 1:numPercTypes
        nexttile(fig1,tileIdx)
        hold on
        for kdx = 1:numD
            curves = allCurves{kdx};
            if isfield(curves,netLabel)
                plot(curves.(netLabel)(1,:),curves.(netLabel)(1+jdx,:), ...
                    'DisplayName',sprintf('D=%2.1f',Dlist(kdx)))
            end
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
    set(fig1,'units','inches','Position',[1,1,8.5,11],'visible','off', ...
        'defaultLineLineWidth',0.6)
end

%% Fit logistic models for a particular astral number

% default logistic model has form f(x) = a / (1+e^{-b*(x-c)})
% Currently fixing a=1

logisFits_v0 = cell(1,numPercTypes,numD);
fitopts = fitoptions('Method','NonlinearLeastSquares','Lower', ...
    [1,-Inf,-Inf],'Upper',[1,Inf,Inf],'StartPoint',[1,1,10]);
an = 1;
fig2 = figure('units','inches','Position',[1,1,8.5,11]);
set(fig2,'defaultLineLineWidth',0.5,'defaultLineMarkerSize',4)
fig2 = tiledlayout(3,2,'TileSpacing','compact');
C = colororder("gem");
netLabel = sprintf('an%02i',an);
tileIdx = 1;
for jdx = 1:numPercTypes
    nexttile(fig2,tileIdx)
    hold on
    for kdx = 1:numD
        curves = allCurves{kdx};
        if isfield(curves,netLabel)
            x = transpose(curves.(netLabel)(1,:));
            y = transpose(curves.(netLabel)(1+jdx,:));
            % plot(x,y,'*','DisplayName',sprintf('D=%2.1f',Dlist(kdx)), ...
            %     'MarkerSize',4,'Color',C(kdx,:))
            logisFits_v0{1,jdx,kdx} = fit(x,y,'logistic',fitopts);
            % l = plot(logisFits_v0{1,jdx,kdx});
            l = plot(logisFits_v0{1,jdx,kdx},x,y,'*');
            [l.Color] = deal(C(kdx,:));
        end
    end
    hold off
    xscale('log')
    xlabel('Filament density [$\mu m^{-1}$]')
    ylabel('Percolation probability')
    title(percTypes{jdx})
    if jdx == 1
        lg = legend('FontSize',12);
        lg.Layout.Tile = 6;
    else
        legend('off')
    end
    tileIdx = tileIdx + 1;
end
title(fig2,netLabel)