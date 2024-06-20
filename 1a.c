clc;
close all;
clear all;
f = input('Enter carrier frequency:');
c = 3*10^8;
%Calculate Wavelength
lamda=c/f;
D=input('Enter the diameter of the Transmitting Antenna in meter:');
df=2*D^2/lamda;
d = 0:1:10000;
if d>=df
 Lp =(4*pi*d/lamda).^2;
else
 Lp=0;
end
subplot(2,1,1);
plot(d,Lp,'b');
xlabel('x--> d (distance in Km)');
ylabel('y--> Lp (path loss)');
title('Free space model'); 
grid on;
subplot(2,1,2);
plot(d,10*log(Lp),'r');
xlabel('x--> d (distance in Km)');
ylabel('y--> Lp (Path loss in dB)');
title('Free space model');
grid on;
