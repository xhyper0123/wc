clc;
close all;
Bits_persignal=8;
samples=8;
PCM_signal=randi([0,1], 24,Bits_persignal*samples);
figure(1);
for i=1:24
    subplot(24,1,i);
    stem(PCM_signal(i,:));
    title('PCM signal');
end
xlabel('bits');
ylabel('amplitude');
title('PCM signal');
figure(2);
T1_signal=reshape(PCM_signal, 1,24*length(PCM_signal));
stem(T1_signal);
xlabel('bits');
ylabel('amplitude');
title('t1 bit stream');
