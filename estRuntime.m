function runtime = estRuntime(l,D,astralNum,densSpec,Nsamp,Nworkers)
%ESTRUNTIME Estimates CPU hours needed to compute a percolation curve
%   Inputs:
%       l (scalar): length of individual filament
%       D (scalar): domain size; asters are distributed in the square
%       with corners at (0,0) and (D,D)
%       astralNum (scalar): (whole) number of filaments per aster
%       densSpec (1x3 double): specifies density sweep range and number of
%       log-spaced points; range is 10.^densSpec(1:2), number of points is
%       densSpec(3)
%       Nsamp (scalar): number of networks to sample per density value
%       Nworkers (scalar): number of CPU cores allotted to job
%   Outputs:
%       runtime (duration): estimated number of CPU hours needed to run
%       getPercCurve with given parameters
densityRange = logspace(densSpec(1),densSpec(2),densSpec(3));
numFilRange = densityRange * D^2 / l;
numAstersRange = round(numFilRange / astralNum);
numAstersUsed = unique(numAstersRange);
numUniqueDensVals = length(numAstersUsed);
timings = zeros(numUniqueDensVals,1);
useMEX = false;
for idx = 1:numUniqueDensVals
    thisTime = tic;
    % record time used to generate 10 networks and check for percolation
    estPercProb(numAstersUsed(idx),l,D,astralNum,10,useMEX);
    timings(idx) = toc(thisTime);
end
runtime = seconds(Nsamp/10 * sum(timings));
runtime.Format = "hh:mm:ss";
disp("Estimated CPU hrs: " + string(runtime))
parallelMsg = "If ideally parallel on %i cores: " + ...
    string(runtime/Nworkers) + "\n";
fprintf(parallelMsg, Nworkers);
end