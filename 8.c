clc;
close all;
clear all;
pi = 3.141592; 
sqrpi = pi^2; 
gmsk = []; 
xaxis = [];

for i = 1:1000 
    f = i / 100; 
    xaxis = [xaxis, f]; 
    ymsk = 16 / sqrpi * ((cos(6.2832 * f))^2 )/ (1 - 16 * (f^2))^2; 
    gmsk = [gmsk, 10 * log10(ymsk)];
end

plot(xaxis, gmsk, 'r');
axis([0 10 -60 10]);
ylabel('Spectral power level in dB');
xlabel('Frequency offset/bit rate');
