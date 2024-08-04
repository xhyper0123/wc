clc;close all;clear all;
d=0:100:1000
pt=200
gt=1
gr=1
w=50
pr=(pt*gt*gr*(w^2))./((4*pi.*d).^2);
figure;
subplot(2,1,1);

plot(d,pr);
xlabel('Distance');
ylabel('Power');
title('Recived power');
pl=10*log10(((4*pi.*d).^2)/(w^2));

subplot(2,1,2);
plot(d, pl)
xlabel('Distance');
ylabel('Pathloss');
title('Free space pathloss');
