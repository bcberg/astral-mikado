function curves = getAllPercCurves(l,D,astralNumList,densSpec,Nsamp, ...
    Ncores,saveDirectory)
%GETALLPERCCURVES Computes many percolation probability curves for astral
%networks
%   Inputs:
%       l (scalar): length of individual filament
%       D (scalar): domain size; asters are distributed in the square
%       with corners at (0,0) and (D,D)
%       astralNumList (double vector): (whole) number of filaments per
%       aster, function computes a curve for each value in this list
%       densSpec (1x3 double): specifies density sweep range and number of
%       log-spaced points; range is 10.^densSpec(1:2), number of points is
%       densSpec(3)
%       Nsamp (scalar): number of networks to sample per density value
%       Ncores (scalar): number of CPU cores allotted to job
%       saveDirectory (char vector or string): name of folder in which to 
%       save simulation data; pass empty value to skip writing .mat file
%   Outputs:
%       curves (struct): curves.an%02i(1,:) gives line density values,
%       curves.an%02i(2,:) gives percolation probability estimates (replace
%       %02i with desired astral number)
filename = sprintf("percProbs_l%02i_D%02i",l,D);

%%%%%%%%%%%%%% Sampling notes %%%%%%%%%%%%%%
% (1) At smaller l/D, probabilities are 0 until higher densities.
% Manually adjust densSpec to capture the transition
% (2): There may be fewer density values in certain percolation curves due
% to requiring integer numbers of asters (density resolution is coarser at
% higher astral number, larger l/D)

%%%%%%%%%%%%%% Percolation probability estimation %%%%%%%%%%%%%%
densityRange = logspace(densSpec(1),densSpec(2),densSpec(3));
numFilRange = densityRange * D^2 / l;
numNetTypes = length(astralNumList);
astralNumList = reshape(astralNumList,[numNetTypes,1]);
numAstersArray = round(repmat(numFilRange,[numNetTypes,1]) ./ ...
    repmat(astralNumList,[1,densSpec(3)]));
numAstersUsed = cell(numNetTypes,1);
numUniqueDensVals_byrow = zeros(numNetTypes,1);
actualDensities = cell(numNetTypes,1);
percProbs = cell(numNetTypes,1);
for idx = 1:numNetTypes
    numAstersUsed{idx} = unique(numAstersArray(idx,:));
    numAstersUsed{idx} = numAstersUsed{idx}(numAstersUsed{idx}>0);
    numUniqueDensVals_byrow(idx) = numel(numAstersUsed{idx});
    actualDensities{idx} = astralNumList(idx)*numAstersUsed{idx}*l/D^2;
    percProbs{idx} = zeros(1,numUniqueDensVals_byrow(idx));
end

pool = parpool(Ncores);
useMEX = true;      % adjust depending on machine
addAttachedFiles(pool,{'generateAstralNetwork.m','percCheck.m', ...
    'percOneSample.m'})
F = cell(numNetTypes,max(numUniqueDensVals_byrow));
for idx = 1:numNetTypes
    for jdx = 1:numUniqueDensVals_byrow(idx)
        F{idx,jdx} = parallel.FevalFuture.empty(Nsamp,0);
        for kdx = 1:Nsamp
            F{idx,jdx}(kdx) = parfeval(pool,@percOneSample,1, ...
                numAstersUsed{idx}(jdx),l,D,astralNumList(idx),useMEX);
        end
    end
end

for idx = 1:numNetTypes
    for jdx = 1:numUniqueDensVals_byrow(idx)
        samples = fetchOutputs(F{idx,jdx});
        percProbs{idx}(jdx) = sum(samples) / Nsamp;
    end
    fprintf('Completed astral number %02i\n',astralNumList(idx))
    netLabel = sprintf('an%02i',astralNumList(idx));
    curves.(netLabel) = [actualDensities{idx}; percProbs{idx}];
end
clear('F')
delete(pool)

if ~isempty(saveDirectory)
    fileToSave = fullfile(saveDirectory,filename + ".mat");
    save(fileToSave)    % saves all variables, including function call args
end
end