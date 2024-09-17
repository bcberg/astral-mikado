function runtime = estRuntime(l,D,astralNum,densRange,numDensVals,Nsamp)
%ESTRUNTIME Estimates CPU hours needed to compute a percolation curve
%   Inputs:
%       l (scalar): length of individual filament
%       D (scalar): domain size; asters are distributed in the square
%       with corners at (0,0) and (D,D)
%       astralNum (scalar): (whole) number of filaments per aster
%       densRange (1x2 double): specifies densities to sample; range is
%       set as 10.^densRange
%       numDensVals (scalar): number of log-spaced points to sample from 
%       10.^densRange
%       Nsamp (scalar): number of networks to sample per density value
%   Outputs:
%       runtime (duration): estimated number of CPU hours needed to run
%       getPercCurve with given parameters
densityRange = logspace(densRange(1),densRange(2),numDensVals);
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
runtime.Format = "dd:hh:mm:ss";
disp("Estimated CPU hrs: " + string(runtime))
end