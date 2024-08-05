pt=500;
d=0:100:1000;
gt=1;
gr=1;
w=100;
do=0:50:500
x=4
n=2
pr=pt*gt*gr*(w^2)./(((4*pi)^2)*(d.^2));
pl_do=10*(pt./pr);
pl_d=pl_do+10*n*log10(d./do)+x;
figure(1);
plot(d,pl_d);
xlabel('distance');
ylabel('path loss');
title('log normal shadowing');
