samples=input('enter no of samples to be considered');
signal=samples*8;
PCM=randi([0,1],24,signal);
figure(1);
for i=1:24
    subplot(24,1,i);
    stem(pcm(i,:));
    title('pcm signal');
end
xlabel('bits');
ylabel('amplitude');
title('PCM signal');
figure(2);
T1_signal=reshape(PCM,1,24*length(PCM));
stem(T1_signal);
title('T1 bit stream');
xlabel('bits');
ylabel('amplitude')
