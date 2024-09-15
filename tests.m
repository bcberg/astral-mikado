% tests.m
% Brady Berg
clear; close all;
format long; format compact;
set(0,'defaultTextInterpreter','latex')
set(0,'defaultAxesTickLabelInterpreter','latex')
set(0,'defaultLegendInterpreter','latex')

%% Solving linear systems

rho = 5;
astralNum = 5;
l = 5;
D = 50;
numAsters = round(rho * D^2 / (l * astralNum));

centers = D * rand([numAsters,2]);
orients = 2 * pi * rand([numAsters,astralNum]);
numFil = numel(orients);
% 
% % Cramer's rule inside double for loop
% tic
% cosines = cos(orients);
% sines = sin(orients);
% for idx = 1:(numFil-1)
%     asterIdx = 1 + floor((idx-1)/astralNum);
%     for jdx = (1 + asterIdx*astralNum):numFil
%         asterJdx = 1 + floor((jdx-1)/astralNum);
%         if sum((centers(asterJdx,:) - centers(asterIdx,:)).^2) > (2*l)^2
%             % skip if astral centers (& filaments) are too far apart
%             continue
%         end
%         % otherwise, check for intersection
%         filSubIdx = mod(idx,astralNum) + astralNum * (mod(idx,astralNum)==0);
%         filSubJdx = mod(jdx,astralNum) + astralNum * (mod(jdx,astralNum)==0);
%         A = [cosines(asterIdx,filSubIdx), - cosines(asterJdx,filSubJdx);
%             sines(asterIdx,filSubIdx), - sines(asterJdx,filSubJdx)];
%         denom = det(A);
%         b = 1/l * [centers(asterJdx,1) - centers(asterIdx,1);
%             centers(asterJdx,2) - centers(asterIdx,2)];
%         t1 = det([b,A(:,2)]) / denom;
%         t2 = det([A(:,1),b]) / denom;
%     end
% end
% cramer = toc;

% vectorizing inner for loop
% tic
% for idx = 1:(numFil-1)
%     asterIdx = 1 + floor((idx-1)/astralNum);
%     otherFils = (1 + asterIdx * astralNum):numFil;
%     if isempty(otherFils)
%         continue
%     end
%     otherAsters_filBins = 1 + floor((otherFils - 1)/astralNum);
%     otherAsters_indexOnly = otherAsters_filBins(1):otherAsters_filBins(end);
%     numOtherAsters = numel(otherAsters_indexOnly);
%     centerSepSQR = sum((repmat(centers(asterIdx,:),[numOtherAsters,1]) - ...
%         centers(otherAsters_indexOnly,:)).^2, 2);
%     closeEnough = otherAsters_indexOnly(centerSepSQR <= (2*l)^2);
% end
% toc

%% astral network generation

rho = 1;
astralNum = 1;
l = 1;
D = 100;
numAsters = round(rho * D^2 / (l * astralNum));
tic
[network1,crossings1,asters1] = generateAstralNetwork(numAsters,l,D, ...
    astralNum,true);
matTime100_1 = toc;
tic
[network2,crossings2,asters2] = generateAstralNetwork_mex(numAsters,l,D, ...
    astralNum,true);
mexTime100_1 = toc;

% 2024.08.28 build, l=5, D=50 (mex is C-based)
%           matTime vs. mexTime
% rho = 1:  0.0054s     0.0022s
% rho = 5:  0.0409s     0.0300s
% rho = 10: 0.1253s     0.1318s

%% 2 x 2 determinants

numIter = 1e4;
A = rand([2,2,numIter]);
b = rand([2,numIter]);

tic
for idx = 1:numIter
    t1 = det([b(:,idx), A(:,2,idx)]);
    t2 = det([A(:,1,idx), b(:,idx)]);
    d = det(A(:,:,idx));
end
detTime = toc;

tic
for idx = 1:numIter
    t1p = b(1,idx)*A(2,2,idx) - b(2,idx)*A(1,2,idx);
    t2p = A(1,1,idx)*b(2,idx) - A(2,1,idx)*b(1,idx);
    dp = A(1,1,idx)*A(2,2,idx) - A(1,2,idx)*A(2,1,idx);
end
aritTime = toc;

%% algorithm to check for percolation

rho = 5;
astralNum = 5;
l = 5;
D = 50;
numAsters = round(rho * D^2 / (l * astralNum));
[network,crossings,asters] = generateAstralNetwork(numAsters,l,D, ...
    astralNum,true);

if astralNum == 1
    G = graph(crossings.filCross(:,1),crossings.filCross(:,2));
elseif astralNum >= 2
    edgesPerCenter = nchoosek(astralNum,2);
    centerEdges = zeros([numAsters * nchoosek(astralNum,2), 2]);
    for idx = 1:numAsters
        centerEdges((1+(idx-1)*edgesPerCenter):idx*edgesPerCenter,:) = ...
            nchoosek(crossings.centerCross(idx,:),2);
    end
    edges = [crossings.filCross; centerEdges];
    G = graph(edges(:,1),edges(:,2));
end

[bins,binsizes] = conncomp(G);

% identify nodes that fall outside of (0,0)--(D,0)--(D,D)--(0,D)--(0,0)
% each node is due to a filCross between two filaments idx and jdx
% --> these two filaments are in the same connected component compidx
%       (use bins(idx) to identify compidx)

% note: a node may satisfy two of the below conditions (e.g., above AND to
% the right)
nodesAbove = find(network.nodes(:,2) > D);
filsAbove = reshape(crossings.filCross(nodesAbove,:),1,[]);
compsAbove = unique(bins(filsAbove));

nodesBelow = find(network.nodes(:,2) < 0);
filsBelow = reshape(crossings.filCross(nodesBelow,:),1,[]);
compsBelow = unique(bins(filsBelow));

nodesLeft = find(network.nodes(:,1) < 0);
filsLeft = reshape(crossings.filCross(nodesLeft,:),1,[]);
compsLeft = unique(bins(filsLeft));

nodesRight = find(network.nodes(:,1) > D);
filsRight = reshape(crossings.filCross(nodesRight,:),1,[]);
compsRight = unique(bins(filsRight));

percTB = any(intersect(compsAbove,compsBelow));
percLR = any(intersect(compsLeft,compsRight));

%% parfeval tests

pool = parpool(4);
F = parallel.FevalFuture.empty(10,0);
for idx = 1:10
    F(idx) = parfeval(pool,@round,1,idx+0.1);
end
out = fetchOutputs(F);
delete(pool);
% verdict: out(idx) = round(idx+0.1), as hoped!