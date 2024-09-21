function curve = getPercCurve(l,D,astralNum,densSpec,Nsamp,Ncores, ...
    saveDirectory)
%GETPERCCURVE Computes a percolation probability curve for astral networks
%   Inputs:
%       l (scalar): length of individual filament
%       D (scalar): domain size; asters are distributed in the square
%       with corners at (0,0) and (D,D)
%       astralNum (scalar): (whole) number of filaments per aster
%       densSpec (1x3 double): specifies density sweep range and number of
%       log-spaced points; range is 10.^densSpec(1:2), number of points is
%       densSpec(3)
%       Nsamp (scalar): number of networks to sample per density value
%       Ncores (scalar): number of CPU cores allotted to job
%       saveDirectory (char vector or string): name of folder in which to 
%       save simulation data; pass empty value to skip writing .mat file
%   Outputs:
%       curve (2 x numUniqueDensVals double): curve(1,:) gives line density
%       values, curve(2,:) gives percolation probability estimates
% Example call from command line
% matlab -nodesktop -r "getPercCurve(1,20,5,[0,log10(50),50],2000,24,'$TMPDIR')"

filename = sprintf("percProbs_l%02i_D%02i_an%02i",l,D,astralNum);

%%%%%%%%%%%%%% Sampling notes %%%%%%%%%%%%%%
% (1) At smaller l/D, probabilities are 0 until higher densities.
% Manually adjust densSpec to capture the transition
% (2): There may be fewer density values in certain percolation curves due
% to requiring integer numbers of asters (density resolution is coarser at
% higher astral number, larger l/D)

%%%%%%%%%%%%%% Percolation probability estimation %%%%%%%%%%%%%%
densityRange = logspace(densSpec(1),densSpec(2),densSpec(3));
numFilRange = densityRange * D^2 / l;
numAstersRange = round(numFilRange / astralNum);
numAstersUsed = unique(numAstersRange);
numUniqueDensVals = length(numAstersUsed);
actualDensities = numAstersUsed * (astralNum * l / D^2);
percProbs = zeros(1,numUniqueDensVals);

pool = parpool(Ncores);
useMEX = false;      % adjust depending on machine
addAttachedFiles(pool,{'generateAstralNetwork.m','percCheck.m', ...
    'percOneSample.m'})
F = cell(1,numUniqueDensVals);
for idx = 1:numUniqueDensVals
    F{idx} = parallel.FevalFuture.empty(Nsamp,0);
    for jdx = 1:Nsamp
        F{idx}(jdx) = parfeval(pool,@percOneSample,1, ...
            numAstersUsed(idx),l,D,astralNum,useMEX);
    end
end

for idx = 1:numUniqueDensVals
    samples = fetchOutputs(F{idx});
    percProbs(idx) = sum(samples) / Nsamp;
    fprintf('Completed %02i/%02i densities\n',idx,numUniqueDensVals)
end
clear('F')
delete(pool)

curve = [actualDensities; percProbs];
if ~isempty(saveDirectory)
    fileToSave = string(saveDirectory) + "/" + filename + ".mat";
    save(fileToSave)    % saves all variables, including function call args
end
end