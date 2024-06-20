clc;
close all;
clear all;
% Signal generation
fs=input('Enter the sampling frequency in Hz:');
%am=input('Enter the ampitude of the signal');
t=0:1/fs:1-(1/fs);
Freq = linspace(-fs/2, fs/2, numel(t));
sig1=0.9*sin(2*pi*100*t)-0.2*sin(2*pi*20*t); % Generate 1st signal
%l=length(sig1);
f1=150;
sig2=0.5*sin(2*pi*f1*t)+0.9*sin(2*pi*130*t); % Generate 2nd Sigal
fft_sig1=fft(sig1);
fft_sig2=fft(sig2);
% Display of sinusoidal Signal
figure(1);
subplot(4,1,1);
plot(t,sig1);
title('Signal 1');
ylabel('Amplitude--->');
xlabel('Time--->');
subplot(4,1,2);
stem(sig1);
title('Sampled Signal 1');
ylabel('Amplitude--->');
xlabel('Time--->');
subplot(4,1,3);
stem(Freq,fftshift(abs(fft_sig1))); % Magnitude of Fourier
title('Signal 1 Magnitude in Frequency Domain');
ylabel('Amplitude--->');
xlabel('Frequency--->');
subplot(4,1,4);
stem(Freq,fftshift(unwrap(angle(fft_sig1)))); % Phase of Fourier
title('Signal 1 Phase in Frequency Domain');
ylabel('Phase--->');
xlabel('Frequency--->');
figure(2);
subplot(4,1,1);
plot(t,sig2);
title('Signal 2');
ylabel('Amplitude--->');
xlabel('Time--->');
subplot(4,1,2);
stem(sig2);
title('Sampled Signal 2');
ylabel('Amplitude--->');
xlabel('Time--->');
subplot(4,1,3);
stem(Freq,fftshift(abs(fft_sig2))); % Magnitude of Fourier
title('Signal 2 Magnitude in Frequency Domain');
ylabel('Amplitude--->');
xlabel('Frequency--->');
subplot(4,1,4);
stem(Freq,fftshift(unwrap(angle(fft_sig2)))); % Phase of Fourier
title('Signal 2 Phase in Frequency Domain');
ylabel('Phase--->');
xlabel('Frequency--->');
l1=length(sig1);
l2=length(sig2);
for i=1:l1
 sig(1,i)=sig1(i); % Making Both row vector to a matrix
 sig(2,i)=sig2(i);
end
% TDM of both quantize signal
tdmsig=reshape(sig,1,2*l1);
% Display of TDM Signal
fft_tdmsig=fft(tdmsig);
figure(3);
subplot(3,1,1);
stem(tdmsig);
title('TDM Signal');
ylabel('Amplitude--->');
xlabel('Time--->');
subplot(3,1,2);
stem(fftshift(abs(fft_tdmsig))); % Magnitude of Fourier
title('TDM signal Magnitude in Frequency Domain');
ylabel('Amplitude--->');
xlabel('Frequency--->');
subplot(3,1,3);
stem(fftshift(unwrap(angle(fft_tdmsig))));
title('TDM signal Phase in Frequency Domain');
ylabel('Phase--->');
xlabel('Frequency--->');
% Demultiplexing of TDM Signal
demux=reshape(tdmsig,2,l1);
for i=1:l1
 sig3(i)=demux(1,i); % Converting The matrix into row vectors
 sig4(i)=demux(2,i);
end
% display of demultiplexed signal
figure(4);
subplot(2,1,1);
plot(sig3);
title('Recovered Signal 1');
ylabel('Amplitude--->');
xlabel('Time--->');
subplot(2,1,2);
plot(sig4);
title('Recovered Signal 2');
ylabel('Amplitude--->');
xlabel('Time--->');
