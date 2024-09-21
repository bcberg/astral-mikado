function runtime = estRuntime(l,D,astralNum,densSpec,Nsamp,Ncores)
%ESTRUNTIME Estimates CPU hours needed to compute a percolation curve
%   Inputs:
%       l (scalar): length of individual filament
%       D (scalar): domain size; asters are distributed in the square
%       with corners at (0,0) and (D,D)
%       astralNum (scalar): (whole) number of filaments per aster
%       densSpec (1x3 double): specifies density sweep range and number of
%       log-spaced points; range is 10.^densSpec(1:2), number of points is
%       densSpec(3)
%       Nsamp (scalar): desired number of networks per density value
%       Ncores (scalar): number of CPU cores allotted to job
%   Outputs:
%       runtime (duration): estimated number of CPU hours needed to run
%       getPercCurve with given parameters
tinySample = 10;
tic;
curve = getPercCurve(l,D,astralNum,densSpec,tinySample,Ncores,[]);
timing = toc;
runtime = seconds(Nsamp/tinySample * timing);
runtime.Format = "hh:mm:ss";
msg = "Time estimate in parallel w/ %i workers: " + string(runtime) + "\n";
billmsg = "Billable CPU hours: " + string(runtime*Ncores);
fprintf(msg,Ncores);
disp(billmsg);
end