function curve = getPercCurve(l,D,astralNum,densRange,saveDirectory)
%GETPERCCURVE Computes a percolation probability curve for astral networks
%   Inputs:
%       l (scalar): length of individual filament
%       D (scalar): domain size; asters are distributed in the square
%       with corners at (0,0) and (D,D)
%       astralNum (scalar): (whole) number of filaments per aster
%       densRange (1x2 double): specifies densities to sample; range is
%       set as 10.^densRange
%       saveDirectory (char vector or string): name of folder in which to 
%       save simulation data
%   Outputs:
%       curve (2 x numUniqueDensVals double): curve(1,:) gives line density
%       values, curve(2,:) gives percolation probability estimates
% Example call from command line
% matlab -nodesktop -r "getPercCurve(1,20,5,[0,log10(50)],'$TMPDIR')"

filename = sprintf("percProbs_l%02i_D%02i_an%02i",l,D,astralNum);

%%%%%%%%%%%%%% Sampling parameters %%%%%%%%%%%%%%
numDensVals = 50;
% at smaller l/D, probabilities are 0 until higher densities
% manually adjust densRange to capture the transition
densityRange = logspace(densRange(1),densRange(2),numDensVals);
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
addAttachedFiles(pool,'generateAstralNetwork.m','percCheck.m', ...
    'estPercProb.m')
F = parallel.FevalFuture.empty(numUniqueDensVals,0);
for idx = 1:numUniqueDensVals
    F(idx) = parfeval(pool,@estPercProb,1, ...
        numAstersUsed(idx),l,D,astralNum,Nsamp,useMEX);
end
for idx = 1:Njobs
    [completedIdx,p] = fetchNext(F);
    percProbs(completedIdx) = p;
end
delete(pool)
clear('F')

curve = [actualDensities; percProbs];
fileToSave = string(saveDirectory) + "/" + filename + ".mat";
save(fileToSave)    % saves all variables, including function call args
end