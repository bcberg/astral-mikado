function curve = getPercCurve(l,D,astralNum,densSpec,saveDirectory)
%GETPERCCURVE Computes a percolation probability curve for astral networks
%   Inputs:
%       l (scalar): length of individual filament
%       D (scalar): domain size; asters are distributed in the square
%       with corners at (0,0) and (D,D)
%       astralNum (scalar): (whole) number of filaments per aster
%       densSpec (1x3 double): specifies density sweep range and number of
%       log-spaced points; range is 10.^densSpec(1:2), number of points is
%       densSpec(3)
%       saveDirectory (char vector or string): name of folder in which to 
%       save simulation data
%   Outputs:
%       curve (2 x numUniqueDensVals double): curve(1,:) gives line density
%       values, curve(2,:) gives percolation probability estimates
% Example call from command line
% matlab -nodesktop -r "getPercCurve(1,20,5,[0,log10(50)],'$TMPDIR')"

filename = sprintf("percProbs_l%02i_D%02i_an%02i",l,D,astralNum);

%%%%%%%%%%%%%% Sampling parameters %%%%%%%%%%%%%%
% at smaller l/D, probabilities are 0 until higher densities
% manually adjust densSpec to capture the transition
densityRange = logspace(densSpec(1),densSpec(2),densSpec(3));
% Note: there may be fewer density values in certain percolation curves due
% to requiring integer numbers of asters (density resolution is coarser at
% higher astral number)
Nsamp = 2e3;

%%%%%%%%%%%%%% Percolation probability estimation %%%%%%%%%%%%%%

numFilRange = densityRange * D^2 / l;
numAstersRange = round(numFilRange / astralNum);
numAstersUsed = unique(numAstersRange);
numUniqueDensVals = length(numAstersUsed);
actualDensities = numAstersUsed * (astralNum * l / D^2);
percProbs = zeros(1,numUniqueDensVals);

pool = parpool(8);  % adjust depending on machine
useMEX = false;      % adjust depending on machine
addAttachedFiles(pool,{'generateAstralNetwork.m','percCheck.m', ...
    'estPercProb.m'})
F = parallel.FevalFuture.empty(numUniqueDensVals,0);
for idx = 1:numUniqueDensVals
    F(idx) = parfeval(pool,@estPercProb,1, ...
        numAstersUsed(idx),l,D,astralNum,Nsamp,useMEX);
end
for idx = 1:numUniqueDensVals
    [completedIdx,p] = fetchNext(F);
    percProbs(completedIdx) = p;
    fprintf('Completed %02i/%02i densities\n',idx,numUniqueDensVals)
end
delete(pool)
clear('F')

curve = [actualDensities; percProbs];
fileToSave = string(saveDirectory) + "/" + filename + ".mat";
save(fileToSave)    % saves all variables, including function call args
end