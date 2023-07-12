function [pValue,KSstat] = convergenceCheck(energyLogFile,hyparam)
% CONVERGENCECHECK uses the K-S test to compare the last two thirds of an
% energy log against each other
%   Inputs:
%       energyLogFile (char vector): address of energyLog.bin relative to
%           working directory
%       hyparam (1 x 1 struct): algorithm parameters; has fields nt, E,
%           ntCheck, maxConvChecks, ntAdmit, pAdmit, epsilonBulk, 
%           epsilonTop, ksSamples, ntWrite, ntWriteFrame, nextFrame
%   Outputs:
%       pValue (double): asymptotic P-value testing the null hypothesis
%       that the last two thirds come from the same continuous distribution
%       (i.e., if pValue > 0.05, same distribition with 5% significance)
%       KSstat (double): max absolute difference between the two empirical
%       cumulative distributions tested
writesUntilntCheck = hyparam.ntCheck / hyparam.ntWrite;
fileID = fopen(energyLogFile,'r');
bytesPerDouble = 8;
whereToRead = bytesPerDouble * writesUntilntCheck;
fseek(fileID, whereToRead, 'bof');
allE1 = fread(fileID, writesUntilntCheck, 'double');
whereToRead = 2 * whereToRead;
fseek(fileID, whereToRead, 'bof');
allE2 = fread(fileID, writesUntilntCheck, 'double');
fclose(fileID);

E1 = randsample(allE1, hyparam.ksSamples);
E2 = randsample(allE2, hyparam.ksSamples);
[~, pValue, KSstat] = kstest2(E1,E2);
end