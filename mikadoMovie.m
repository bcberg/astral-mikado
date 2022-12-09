% mikadoMovie.m
% Brady Berg

clear
close all
format compact
set(0,'defaultTextInterpreter','latex')
set(0,'defaultAxesTickLabelInterpreter','latex')

%% Where's the data?

directory = 'smallnet1.25_f10';
numFrames = 109;
%%%%%%%%%%
%%% Method 1: call spring network, initial config from end-of-sim data file
% load([directory,'/data.mat'],'nodes','springs','L')

%%% Method 2: call spring network, initial config from starting config file
load('smalltestNetwork_1.25e3stick.mat','nodes','springs','L')
%%%%%%%%%%
state = nodes;
save([directory,'/frame0.mat'],'state')

clear nodes state

%% Create the movie

v = VideoWriter([directory,'/movie.avi']);
v.FrameRate = 10; % adjust manually
open(v);
message = ['Compiling movie... (0/',num2str(numFrames),')'];
f = waitbar(0,message);
for idx = 0:numFrames
    message = ['Compiling movie... (', num2str(idx),'/',num2str(numFrames),')'];
    waitbar(idx/numFrames,f,message)
    frame = renderFrame(directory,idx,springs,L);
    writeVideo(v,frame);
end
close(f);
close(v);

%% Functions

function frame = renderFrame(directory,idx,springs,L)
    filename = [directory,'/frame',num2str(idx),'.mat'];
    load(filename,'state')
    fig = figure('visible','off');
    hold on
    for idx = 1:size(springs,1)
        nodeA = springs(idx,1);
        nodeB = springs(idx,2);
        coords = [state(nodeA,:); state(nodeB,:)];
        plot(coords(:,1), coords(:,2), '.b-')
    end
    xlim([-0.25*L, 4*L]) % adjust manually
    ylim([-0.25*L, 1.1*L])
    frame = getframe(fig);
    clf
end