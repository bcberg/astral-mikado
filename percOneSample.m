function samp = percOneSample(numAsters,l,D,astralNum,useMEX)
%PERCONESAMPLE Generates one astral network and checks if it is percolated
%   Inputs:
%       numAsters (scalar): (whole) number of asters to distribute
%       l (scalar): length of individual filament
%       D (scalar): domain size; asters are distributed in the square
%       with corners at (0,0) and (D,D)
%       astralNum (scalar): (whole) number of filaments per aster
%       Nsamp (scalar): integer number of networks to sample
%       useMEX (boolean): passing true allows use of MEX function for
%       network generation, passing false uses pure Matlab function
%   Outputs:
%       samp (1x1 logical): true if generated network passes percCheck,
%       false otherwise
samp = false;
numFil = numAsters * astralNum;     % mex gets slow if numFil too high
if useMEX && numFil < 1e4
    [network,crossings,~] = generateAstralNetwork_mex(numAsters,l,D,...
        astralNum, true);
    [percTF,~] = percCheck(crossings,network.nodes,D);
    if percTF(1) || percTF(2)
        samp = true;
    end
else
    [network,crossings,~] = generateAstralNetwork(numAsters,l,D, ...
        astralNum, true);
    [percTF,~] = percCheck(crossings,network.nodes,D);
    if percTF(1) || percTF(2)
        samp = true;
    end
end
end