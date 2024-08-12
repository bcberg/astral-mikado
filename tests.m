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

rho = 5;
astralNum = 5;
l = 5;
D = 50;
numAsters = round(rho * D^2 / (l * astralNum));
tic
[network,crossings,asters] = generateAstralNetwork(numAsters,l,D,astralNum);
matTime = toc;
tic
[network2,crossings2,asters2] = generateAstralNetwork_mex(numAsters,l,D,astralNum);
mexTime = toc;