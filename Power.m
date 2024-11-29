clear; clc; 

%% Initailize Knowns

load runners.mat
g = 9.81; % (g) [m/s^2]
d = 100; % (d) [m]

%%Calculate

v = d ./ time;
Work = 0.5 .* mass .* v.^2;
Power = Work ./ (time);

%Output

 maxPower=max(Power);
    sectolast=Power(end-1);

    fprintf("The Max Power = "+maxPower)
    fprintf('\n')
    fprintf("Power for second to last value = "+sectolast)
