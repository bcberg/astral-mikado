% astralNetExamples.m
% Brady Berg
clear; close all;

%% Save directories & graphics parameters

% Ubuntu path
% saveDir = "~/Documents/astral-mikado-data";
% Windows path
saveDir = "C:\Users\bcber\Documents\astral-mikado-data";

filename = "astralNetEx250422";

dataSubfolder = "mat_files";
figSubfolder = "subfigures";
figFiletype = ".pdf";

boundaryWidth = 4;
filamentWidth = 1.5;
springYellow = [255,215,0]/255;

%% Network parameters

regenerate = true;
if regenerate
    rho = 6.5;
    l = 1;
    D = 4;
    targetFilNum = rho * D^2 / l;

    an_classic = 1;
    [net_classic,crossings_classic,asters_classic] = generateAstralNetwork( ...
        targetFilNum,l,D,an_classic,false);

    an_low = 2;
    numAsters_low = round(targetFilNum/an_low,TieBreaker="tozero"); % attempt to match Python rounding behavior
    [net_low,crossings_low,asters_low] = generateAstralNetwork(numAsters_low, ...
        l,D,an_low,false);

    an_hi = 8;
    numAsters_hi = round(targetFilNum/an_hi,TieBreaker="tozero"); % attempt to match Python rounding behavior
    [net_hi,crossings_hi,asters_hi] = generateAstralNetwork(numAsters_hi, ...
        l,D,an_hi,false);

    save(fullfile(saveDir,dataSubfolder,filename + ".mat"),'rho','l','D', ...
        'targetFilNum','an_low','numAsters_low','net_low', ...
        'crossings_low','asters_low','an_hi','numAsters_hi','net_hi', ...
        'crossings_hi','asters_hi','an_classic','net_classic', ...
        'crossings_classic','asters_classic')
else
    load(fullfile(saveDir,dataSubfolder,filename + ".mat"),'rho','l','D', ...
        'targetFilNum','an_low','numAsters_low','net_low', ...
        'crossings_low','asters_low','an_hi','numAsters_hi','net_hi', ...
        'crossings_hi','asters_hi','an_classic','net_classic', ...
        'crossings_classic','asters_classic')
end

%% Example at low astral number

anlowEx = figure(1); clf;
set(gca,'Color','k')
hold on
plot([0,D],[0,0],'-','LineWidth',4,'Color','blue')
plot([0,D],[D,D],'-','LineWidth',4,'Color','blue')
for idx = 1:numAsters_low
    for jdx = 1:an_low
        plot(asters_low.centers(idx,1) + l * cos(asters_low.orients(idx,jdx)) * (0:1), ...
            asters_low.centers(idx,2) + l * sin(asters_low.orients(idx,jdx)) * (0:1), ...
            '-','LineWidth',filamentWidth,'Color','w')
    end
end
for idx = 1:size(net_low.springs,1)
    augNodeA = net_low.springs(idx,1);
    augNodeB = net_low.springs(idx,2);
    coords = [net_low.augNodes(augNodeA,1:2);
        net_low.augNodes(augNodeB,1:2)];
    plot(coords(:,1),coords(:,2),'.','MarkerSize',16,'LineWidth', ...
        filamentWidth,'Color',springYellow)
    % OPTION A: plot astral centers only if they are also a spring boundary
    % if augNodeA <= numAsters_low && an_low >= 2
    %     % i.e., if augNodeA is an astral center
    %     plot(net_low.augNodes(augNodeA,1),net_low.augNodes(augNodeA,2), ...
    %         '.r','MarkerSize',24)
    % elseif augNodeB <= numAsters_low && an_low >= 2
    %     % likewise for augNodeB
    %     plot(net_low.augNodes(augNodeB,1),net_low.augNodes(augNodeB,2), ...
    %         '.r','MarkerSize',24)
    % end
end
% OPTION B: plot all astral centers
if an_low >= 2
    plot(asters_low.centers(:,1),asters_low.centers(:,2),'.r', ...
        'MarkerSize',20)
    % could use "scatter" to enable transparency for center marks
end
hold off
xlim('tight')
xl = xlim;
xlim(max(abs(xl - D/2)) * [-1,1] + D/2)
xticks([])
ylim('tight')
yl = ylim;
ylim(max(abs(yl - D/2)) * [-1,1] + D/2)
yticks([])
h = gca;
h.XAxis.Visible = 'off';
h.YAxis.Visible = 'off';
exportgraphics(anlowEx,fullfile(saveDir,figSubfolder,"anlowEx" + ...
    figFiletype),'ContentType','vector')

%% Example at high astral number

anhiEx = figure(2); clf;
set(gca,'Color','k')
hold on
plot([0,D],[0,0],'-','LineWidth',4,'Color','blue')
plot([0,D],[D,D],'-','LineWidth',4,'Color','blue')
for idx = 1:numAsters_hi
    for jdx = 1:an_hi
        plot(asters_hi.centers(idx,1) + l * cos(asters_hi.orients(idx,jdx)) * (0:1), ...
            asters_hi.centers(idx,2) + l * sin(asters_hi.orients(idx,jdx)) * (0:1), ...
            '-','LineWidth',filamentWidth,'Color','w')
    end
end
for idx = 1:size(net_hi.springs,1)
    augNodeA = net_hi.springs(idx,1);
    augNodeB = net_hi.springs(idx,2);
    coords = [net_hi.augNodes(augNodeA,1:2);
        net_hi.augNodes(augNodeB,1:2)];
    plot(coords(:,1),coords(:,2),'.','MarkerSize',16,'LineWidth', ...
        filamentWidth,'Color',springYellow)
    % OPTION A: plot astral centers only if they are also a spring boundary
    % if augNodeA <= numAsters_hi && an_hi >= 2
    %     % i.e., if augNodeA is an astral center
    %     plot(net_hi.augNodes(augNodeA,1),net_hi.augNodes(augNodeA,2), ...
    %         '.r','MarkerSize',24)
    % elseif augNodeB <= numAsters_hi && an_hi >= 2
    %     % likewise for augNodeB
    %     plot(net_hi.augNodes(augNodeB,1),net_hi.augNodes(augNodeB,2), ...
    %         '.r','MarkerSize',24)
    % end
end
% OPTION B: plot all astral centers
if an_hi >= 2
    plot(asters_hi.centers(:,1),asters_hi.centers(:,2),'.r', ...
        'MarkerSize',20)
    % could use "scatter" to enable transparency for center marks
end
hold off
xlim('tight')
xl = xlim;
xlim(max(abs(xl - D/2)) * [-1,1] + D/2)
xticks([])
ylim('tight')
yl = ylim;
ylim(max(abs(yl - D/2)) * [-1,1] + D/2)
yticks([])
h = gca;
h.XAxis.Visible = 'off';
h.YAxis.Visible = 'off';
exportgraphics(anhiEx,fullfile(saveDir,figSubfolder,"anhiEx" + ...
    figFiletype),'ContentType','vector')

%% Non-astral example

anclassicEx = figure(3); clf;
set(gca,'Color','k')
hold on
plot([0,D],[0,0],'-','LineWidth',4,'Color','blue')
plot([0,D],[D,D],'-','LineWidth',4,'Color','blue')
for idx = 1:targetFilNum
    for jdx = 1:an_classic
        plot(asters_classic.centers(idx,1) + l * cos(asters_classic.orients(idx,jdx)) * (0:1), ...
            asters_classic.centers(idx,2) + l * sin(asters_classic.orients(idx,jdx)) * (0:1), ...
            '-','LineWidth',filamentWidth,'Color','w')
    end
end
for idx = 1:size(net_classic.springs,1)
    augNodeA = net_classic.springs(idx,1);
    augNodeB = net_classic.springs(idx,2);
    coords = [net_classic.augNodes(augNodeA,1:2);
        net_classic.augNodes(augNodeB,1:2)];
    plot(coords(:,1),coords(:,2),'.','MarkerSize',16,'LineWidth', ...
        filamentWidth,'Color',springYellow)
    % OPTION A: plot astral centers only if they are also a spring boundary
    % if augNodeA <= numAsters_classic && an_classic >= 2
    %     % i.e., if augNodeA is an astral center
    %     plot(net_classic.augNodes(augNodeA,1),net_classic.augNodes(augNodeA,2), ...
    %         '.r','MarkerSize',24)
    % elseif augNodeB <= numAsters_classic && an_classic >= 2
    %     % likewise for augNodeB
    %     plot(net_classic.augNodes(augNodeB,1),net_classic.augNodes(augNodeB,2), ...
    %         '.r','MarkerSize',24)
    % end
end
% OPTION B: plot all astral centers
if an_classic >= 2
    plot(asters_classic.centers(:,1),asters_classic.centers(:,2),'.r', ...
        'MarkerSize',20)
    % could use "scatter" to enable transparency for center marks
end
hold off
xlim('tight')
xl = xlim;
xlim(max(abs(xl - D/2)) * [-1,1] + D/2)
xticks([])
ylim('tight')
yl = ylim;
ylim(max(abs(yl - D/2)) * [-1,1] + D/2)
yticks([])
h = gca;
h.XAxis.Visible = 'off';
h.YAxis.Visible = 'off';
exportgraphics(anclassicEx,fullfile(saveDir,figSubfolder,"anclassicEx" + ...
    figFiletype),'ContentType','vector')
