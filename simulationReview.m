% simulationReview.m
% Brady Berg
clear; close all;
format long; format compact;
set(0,'defaultTextInterpreter','latex')
set(0,'defaultAxesTickLabelInterpreter','latex')
set(0,'defaultLegendInterpreter','latex')

%% Load simulation data

% manually adjust
lookHere = 'C:\Users\bcber\OneDrive\Documents\MATLAB\thermalMikado_dens2.5_trial1';
load([lookHere,'\initNetStats.mat'])
% manually adjust
thisSim = [lookHere,'\f1'];
fileID = fopen([thisSim,'\energyLog.bin'],'r');
fseek(fileID,0,'bof');
E = fread(fileID,'double');
fclose(fileID);

%% Plot energy history

fig1 = figure(1);
plot(hyparam.ntWrite * (1:length(E)), E)
xlabel('$nt$')
ylabel('$E$')
exportgraphics(fig1,[thisSim,'\energyLog.png'],'Resolution',300);
clear E

%% Make a movie

framesToRender = 0:1:5904;  % adjust manually
numFrames = length(framesToRender);
f = parallel.FevalFuture.empty(numFrames,0);
for idx = 1:numFrames
    f(idx) = parfeval(@renderFrame, 1, thisSim, framesToRender(idx), ...
        springs, L, [node_rows, node_cols]);
end
finishedFrames = cell(numFrames,1);
numFinished = 0;
message = ['Retrieving frames... (0/',num2str(numFrames),')'];
w = waitbar(0,message);
for idx = 1:numFrames
    % fetchNext blocks until more results are available, and
    % returns the index into f that is now complete, as well
    % as the value computed by f.
    [completedIdx, value] = fetchNext(f);
    finishedFrames{completedIdx} = value;
    numFinished = numFinished + 1;
    message = ['Retrieving frames... (', num2str(numFinished), ...
        '/', num2str(numFrames), ')'];
    waitbar(numFinished/numFrames,w,message)
end
v = VideoWriter([thisSim,'\movie.avi']);
v.FrameRate = 30; % adjust manually
open(v);
for idx = 1:numFrames
    writeVideo(v,finishedFrames{idx});
end
close(w);
close(v);

%% Functions

function frame = renderFrame(directory,frameIdx,springs,L,nodeDims)
frameLabel = sprintf('/frame%04d.bin',int32(frameIdx));    
filename = [directory,frameLabel];
nodeRows = nodeDims(1);
nodeCols = nodeDims(2);
fileID = fopen(filename,'r');
state = fread(fileID,[nodeRows,nodeCols],'double');
fclose(fileID);
fig = figure('visible','off');
hold on
for idx = 1:size(springs,1)
    nodeA = springs(idx,1);
    nodeB = springs(idx,2);
    coords = [state(nodeA,:); state(nodeB,:)];
    plot(coords(:,1), coords(:,2), '.b-')
end
xlim([-0.25*L, 1.25*L]) % adjust manually (1.25 for f1, 2.25 for f10)
ylim([-0.25*L, 1.25*L])
frame = getframe(fig);
clf
end
