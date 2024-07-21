clc;
clear all;
close all;
DATA_pattern=randi([0,1],1,4);
M=4; 
N=2^M-1; 
x=input('Enter the initial states of LFSR: ');
x1=x(1);
x2=x(2);
x3=x(3);
x4=x(4);
states=[];
PN_sequence=[];
 for i=1:N
 states=[states;x1(i) x2(i) x3(i) x4(i)];
 x1(i+1)=xor(x3(i),x4(i));
 x2(i+1)=x1(i);
 x3(i+1)=x2(i);
 x4(i+1)=x3(i);
 PN_sequence=[PN_sequence x4(i)];
 end
figure(1);
stem(DATA_pattern);
axis([-1 4 -2 2]);
title('Original Bit Sequence');
figure(2);
stem(PN_sequence);
axis([-1 15 -2 2]);
title('Pseudorandom Bit Sequence');
for i=1:M
 Newpattern(i,:)=repmat(DATA_pattern(i),1,15);
end
for i=1:M
dsss_bitsequence(i,:)=xor(Newpattern(i,:),PN_sequence);
end
Length=size(dsss_bitsequence);
dsss_bitsequence=reshape(dsss_bitsequence',1,Length(1)*Length(2));
figure(3);
stem(dsss_bitsequence);
axis([-1 length(dsss_bitsequence) -2 2]);
title('DSSS Bit Sequence');
dsss_sig=[];
t=[0:2*pi/256:2*pi-(pi/256)]; 
c1=cos(t);
c2=cos(t+pi);
for k=1:length(dsss_bitsequence)
 if dsss_bitsequence(1,k)==0
 sig=c1;
 else
 sig=c2;
 end
 dsss_sig=[dsss_sig sig];
end
figure(4);
plot([1:length(dsss_sig)],dsss_sig);
axis([-1 length(dsss_sig) -2 2]);
title('DSSS Signal');
figure(5);
plot([1:length(dsss_sig)],abs(fft(dsss_sig)));
title('Magnitude Spectrum');
