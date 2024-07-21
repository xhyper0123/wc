clc;close all;clear all;
data_pattern=randi([0,1],1,4);
m=4;
n=2^m-1;
x=input('enter the initial states of lfsr:');
x1=x(1);
x2=x(2);
x3=x(3);
x4=x(4);
states=[];
pn_sequence=[];
for i=1:n
 states=[states;x1(i) x2(i) x3(i) x4(i)];
 x1(i+1)=xor(x3(i),x4(i));
 x2(i+1)=x1(i);
 x3(i+1)=x2(i);
 x4(i+1)=x3(i);
 pn_sequence=[pn_sequence x4(i)];
end
figure(1)
stem(data_pattern);
axis([-1 4 -2 2])
title('Original bit sequence');
figure(2);
stem(pn_sequence);
axis([-1 15 -2 2])
title('Pseudorandom bit sequence');
for i=1:m
 new_pattern(i,:)=repmat(data_pattern(i),1,15);
end
for i=1:m
 dsss_bitsequence(i,:)=xor(new_pattern(i,:),pn_sequence);
end
Length=size(dsss_bitsequence);
dsss_bitsequence=reshape(dsss_bitsequence',1,Length(1)*Length(2));
figure(3);
stem(dsss_bitsequence);
title('DSSS bit sequence');
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
plot(length(dsss_sig),dsss_sig)
axis([-1 length(dsss_sig) -2 2])
title('DSSS signal')
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
axis([-1 length(dsss_sig) -2 2])
title('DSSS signal');
