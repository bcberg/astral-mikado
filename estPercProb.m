function p = estPercProb(numAsters,l,D,astralNum,Nsamp,useMEX)
%ESTPERCPROB uses Monte Carlo sampling to estimate percolation
%probabilities of astral networks
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
%       p (scalar): estimated one-sided percolation probability for astral
%       networks with the given parameters
percCount = 0;
numFil = numAsters * astralNum;     % mex gets slow if numFil too high
if useMEX && numFil < 1e4
    for idx = 1:Nsamp
        [network,crossings,~] = generateAstralNetwork_mex(numAsters,l,D,...
            astralNum, true);
        [percTF,~] = percCheck(crossings,network.nodes,D);
        if percTF(1) || percTF(2)
            percCount = percCount + 1;
        end
    end
else
    for idx = 1:Nsamp
        [network,crossings,~] = generateAstralNetwork(numAsters,l,D, ...
            astralNum, true);
        [percTF,~] = percCheck(crossings,network.nodes,D);
        if percTF(1) || percTF(2)
            percCount = percCount + 1;
        end
    end
end
p = percCount / Nsamp;
end