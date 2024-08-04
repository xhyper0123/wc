m1=15;
m2=10;
t=0:0.01:2;
sig1=15*sin(m1*t)
sig2=10*cos(m2*t);
figure(1);
subplot(3,1,1)
plot(t,sig1,'r')
xlabel('time')
ylabel('amplitude')
title('signal1')

subplot(3,1,2)
plot(t,sig2,'b')
xlabel('time')
ylabel('amplitude')
title('signal2')
l1=length(sig1);
l2=length(sig2);
for i=1:l1
    sig(1,i)=sig1(i);
    sig(2,i)=sig2(i);
end
tdmsig= reshape(sig,1,2*l1);
subplot(3,1,3)
xlabel('time')
ylabel('amplitude')

plot(tdmsig)
title('tdmsignal')
demux=reshape(tdm,2,l1)
for i=1:l1
    s3(i)=demux(1,i);
    s4(i)=demux(2,i);
end
figure (2);
subplot(2,1,1)
plot(tdm)
plot(t,s3)
xlabel('time')
ylabel('amplitude')
title('recoverd signal-1')
subplot(2,1,2)
plot(tdm)
plot(t,s4)
xlabel('time')
ylabel('amplitude')
title('recover signal2')
