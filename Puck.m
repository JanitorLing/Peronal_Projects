clear; clc;

%% Load information:

load 'pucks.mat'
% An array taken in from the EF website

%% Initialize Variables

nominalHeight = 1; % inch
nominalDiameter = 3; % inches
nPucks = size(puckMeasurements, 1); % Total number of pucks
% information found on the 'MATLAB Practical Quiz' sheet.

%% Calculations 

heightTol = nominalHeight * 0.005; % Height Total
diameterTol = nominalDiameter * 0.005;
nBothOutOfSpec = 0;
% information found on the 'MATLAB Practical Quiz' sheet.

%% Looping Starts Here

nDiameterOutOfSpec = 0;
nHeightOutOfSpec = 0;
nBothOutOfSpec = 0;

% Above is setting the iterations to zero so we can count properly. Below
% is recognizing the information from the uploaded data so we can sort
% them.

for puckIdx = 1:nPucks
    puckDiameter = puckMeasurements(puckIdx, 1);
    puckHeight = puckMeasurements(puckIdx, 2);

    if (puckDiameter - nominalDiameter) > diameterTol && (puckHeight - nominalHeight) <= heightTol
    nDiameterOutOfSpec = nDiameterOutOfSpec + 1;
    end

    if (puckDiameter - nominalDiameter) > diameterTol && (puckHeight - nominalHeight) <= heightTol
        nDiameterOutOfSpec = nDiameterOutOfSpec + 1;
    end
  
 % Above is a 'if' statement that iterates if the diameter does not match
 % parameters. This happens using a && operator.
 % Basically it's suppose to recognize the allowed diameter range and then
 % compare it to what the data shows. Both should show true, if it doesn't
 % then it iterates. This follows the idea of the flow chart presented on
 % the sheet given. 

%% Output
fprintf('%d out of the %d pucks do not meet specification\n', nBothOutOfSpec, nPucks);
fprintf('%d pucks have only their diameter out fo specification\n', nDiamterOutOfSpec);
fprintf('%d pucks have only their diameter out fo specification\n', nHeightOutOfSpec);
fprintf('%d pucks have both their height and diameter out of specification', nBothOutOfSpec);

% I'm pretty sure this is right, but I'll give an explanation. This is a
% print statement that shows the output, as seen above %d is meant to be
% where the variables that were initalized earlier. And following the
% purple text (at least on my screen) is the variable names that will be
% inputted. 
