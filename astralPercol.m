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
    astralNumList = (1:48)';
    densSpec = [0,2,50];
    Nsamp = 2000;
    Ncores = 8;
else
    % load a particular existing dataset
    D = 5;
    l = 1;
end
% Ubuntu path
saveDirectory = "~/Documents/AstralMikadoCYM/data";
% Windows path
% saveDirectory = "C:\Users\bcber\Documents\AstralMikadoCYM\data";
filename = sprintf("percProbs_l%02i_D%02i",l,D);

%% Percolation probability estimation

if recompute
    curves = getAllPercCurves(l,D,astralNumList,densSpec,Nsamp,Ncores, ...
        saveDirectory);
end

%% Plotting

load(fullfile(saveDirectory,filename + ".mat"))

% fig1 = figure(1);
% set(fig1,'defaultLineLineWidth',0.75)
% cmap = colormap(turbo(numNetTypes));
% hold on
% for idx = 1:numNetTypes
%     plot(actualDensities{idx},percProbs{idx},'DisplayName', ...
%         sprintf('nAST%02i',astralNumList(idx)),'Color',cmap(idx,:))
% end
% hold off
% xscale('log')    % 'linear' or 'log'
% legend('Location','eastoutside','NumColumns',2)
% xlabel('Filament density [$\mu m^{-1}$]')
% ylabel('Percolation probability')
% title(sprintf('Domain size: %2.1f, Filament length: %1.1f',D,l))
% exportgraphics(fig1,fullfile(saveDirectory,filename + "_curves.png"), ...
%     'Resolution',300)
% 
% %% Heatmap
% 
% % For heatmap, need to interpolate values at each value of densityRange
% % Currently using cubic splines
% numDensVals = length(densityRange);
% percProbsHeatmap = zeros(numNetTypes,numDensVals);
% for idx = 1:numNetTypes
%     percProbsHeatmap(idx,:) = spline(actualDensities{idx}, ...
%         percProbs{idx},densityRange);
% end
% 
% fig2 = figure(2);
% pcolor(densityRange,astralNumList,percProbsHeatmap)
% xscale('log')
% xlabel('Filament density [$\mu m^{-1}$]')
% ylabel('Astral number')
% title(sprintf('Domain size: %2.1f, Filament length: %1.1f',D,l))
% exportgraphics(fig2,fullfile(saveDirectory,filename + "_heat.png"), ...
%     'Resolution',300)

%% Curves for all percolation definitions

thisFig = figure(99);
set(thisFig,'Position',[200,200,300*8.5,300*11],'visible','on', ...
    'defaultLineLineWidth',0.75)
thisFig = tiledlayout(3,2,'TileSpacing','compact');

percTypes = {"Top-to-Bottom (TB)", "Left-to-Right (LR)", "TB OR LR", ...
    "TB AND LR", "Single connected component"};
numPercTypes = length(percTypes); % i.e., = 5
cmap = colormap(turbo(numNetTypes));
for pdx = 1:numPercTypes
    nexttile(thisFig,mod(pdx,6) + 6 * (mod(pdx,6)==0))
    hold on
    for idx = 1:numNetTypes
        plot(actualDensities{idx},percProbs{idx}(pdx,:),'DisplayName', ...
            sprintf('an%02i',astralNumList(idx)),'Color',cmap(idx,:))
    end
    hold off
    xscale('log')    % 'linear' or 'log'
    xlabel('Filament density [$\mu m^{-1}$]')
    ylabel('Percolation probability')
    title(percTypes{pdx})
    if pdx == 1
        lg = legend('Location','NumColumns',2);
        lg.Layout.Tile = 6;
    end
end
title(thisFig,sprintf('Domain size: %2.1f, Filament length: %1.1f',D,l))
% for idx = 1:length(nFilPerAsterList)
%     nexttile(thisFig,mod(idx,6) + 6 * (mod(idx,6)==0))
%     nFilPerAster = nFilPerAsterList(idx);
%     networkLabel = sprintf('n_{AST}=%i',nFilPerAster);
% 
%     h = histogram(displacements(idx,:),'Normalization','probability');
%     h.BinWidth = 0.1;
%     xlim([0,5])
%     ylim([0,0.5])
%     xlabel('x-Displacement [{\mu}m]')
%     ylabel('Empirical probability')
%     title([networkLabel,sprintf(', mean = %.3f',meandisps(idx))])
% 
%     if 0 == mod(idx,6) && idx == 6
%         % export first page
%         % Ubuntu path
%         exportgraphics(thisFig,'~/Documents/AstralMikadoCYM/data/displace_distr_shear_50x50.pdf', ...
%             'Resolution',300)
%         % Windows path
%         % exportgraphics(thisFig,'C:\Users\bcber\Documents\AstralMikadoCYM\data\displace_distr_shear_50x50.pdf', ...
%         %     'Resolution',300)
%         thisFig = clf(thisFig);
%         set(thisFig,'Position',[200,200,300*8.5,300*11],'visible','off', ...
%             'defaultLineLineWidth',0.75)
%         thisFig = tiledlayout(3,2,'TileSpacing','compact');
%     elseif 0 == mod(idx,6) && idx > 6
%         % export next pages, append to first file
%         % Ubuntu path
%         exportgraphics(thisFig,'~/Documents/AstralMikadoCYM/data/displace_distr_shear_50x50.pdf', ...
%             'Resolution',300,'Append',true)
%         % Windows path
%         % exportgraphics(thisFig,'C:\Users\bcber\Documents\AstralMikadoCYM\data\displace_distr_shear_50x50.pdf', ...
%         %     'Resolution',300,'Append',true)
%         thisFig = clf(thisFig);
%         set(thisFig,'Position',[200,200,300*8.5,300*11],'visible','off', ...
%             'defaultLineLineWidth',0.75)
%         thisFig = tiledlayout(3,2,'TileSpacing','compact');
%     else
%         legend('off')
%     end
% end