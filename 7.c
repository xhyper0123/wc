clc;
clear all;
close all;
%Parameters setting
M = 2; % BPSK signal constellation
no_of_data_points = 64; % have 64 data points
block_size = 8; % size of each ofdm block
cp_len = ceil(0.1*block_size); % length of cyclic prefix
no_of_ifft_points = block_size; % 8 points for the FFT/IFFT
no_of_fft_points = block_size;
%Transmitter
% Generate data points
data_source = randsrc(1, no_of_data_points, 0:M-1);
figure(1)
stem(data_source);
grid on;xlabel('data points');
ylabel('transmitted data phase representation')
title('Transmitted Data "O"')
% Perform BPSK modulation
Bpsk_modulated_data = pskmod(data_source, M);
scatterplot(Bpsk_modulated_data);
title('bpsk modulated transmitted data')
% Do IFFT on each block
num_cols=length(Bpsk_modulated_data)/block_size;
data_matrix = reshape(Bpsk_modulated_data, block_size, num_cols);
% Create empty matix to put the IFFT'd data
cp_start = block_size-cp_len;
cp_end = block_size;
% Operate columnwise & do CP
for i=1:num_cols
ifft_data_matrix(:,i) = ifft((data_matrix(:,i)),no_of_ifft_points);
% Compute and append Cyclic Prefix
for j=1:cp_len
actual_cp(j,i) = ifft_data_matrix(j+cp_start,i);
end
% Append the CP to the existing block to create the actual OFDM block
ifft_data(:,i) = vertcat(actual_cp(:,i),ifft_data_matrix(:,i));
end
% Convert to serial stream for transmission
[rows_ifft_data cols_ifft_data]=size(ifft_data);
len_ofdm_data = rows_ifft_data*cols_ifft_data;
% OFDM signal to be transmitted
ofdm_signal = reshape(ifft_data, 1, len_ofdm_data);
figure(3)
plot(real(ofdm_signal));
xlabel('Time');
ylabel('Amplitude');
title('OFDM Signal');
grid on;
%Receiver
%Pass the ofdm signal through the channel
recvd_signal = ofdm_signal;
%Convert Data back to "parallel" form to perform FFT
recvd_signal_matrix = reshape(recvd_signal,rows_ifft_data, cols_ifft_data);
%Remove CP
recvd_signal_matrix(1:cp_len,:)=[];
%Perform FFT
for i=1:cols_ifft_data
fft_data_matrix(:,i) = fft(recvd_signal_matrix(:,i),no_of_fft_points);
end
%Convert to serial stream
recvd_serial_data = reshape(fft_data_matrix, 1,(block_size*num_cols));
%Demodulate the data
Bpsk_demodulated_data = pskdemod(recvd_serial_data,M);
scatterplot(Bpsk_modulated_data);title('Received Bpsk modulated data')
figure(5)
stem(Bpsk_demodulated_data,'rx');
grid on;xlabel('data points');
ylabel('received data phase representation');
title('Received Data "X"')