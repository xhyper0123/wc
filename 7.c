clc;
clear all;
close all;
M=4; 
N=2^M-1; 
x=input('Enter the initial states of LFSR: ');
x1=x(1);
x2=x(2);
x3=x(3);
x4=x(4);
states=[];
PN_sequence=[];
for j=1:N
 states=[states;x1(j) x2(j) x3(j) x4(j)];
 x1(j+1)=xor(x3(j),x4(j));
 x2(j+1)=x1(j);
 x3(j+1)=x2(j);
 x4(j+1)=x3(j);
 PN_sequence=[PN_sequence x4(j)];
end
figure(1);
stem(PN_sequence);
title('PN sequence');
xlabel('time------->');
ylabel('Amplitude-------------->');
for i=1:N
    if PN_sequence(i)==1
 PN_sequence(i)=-1;
 elseif PN_sequence(i)==0
 PN_sequence(i)=1;
 end
end
ac=[];
for lag=-1:N+1
 p=circshift(PN_sequence,lag);
 acf=sum(PN_sequence.*p)/N;
 ac=[ac acf];
end
figure(2);
plot(-1:N+1,ac,'r-');
title('Autocorrreation function');
xlabel('lag------->');
ylabel('Amplitude-------------->');
