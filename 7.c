clc;
clear all;
close all;
M = 4; 
no_of_data_points = 64; 
block_size = 8; 
cp_len = ceil(0.1*block_size); 
no_of_ifft_points = block_size; 
no_of_fft_points = block_size;
data_source = randsrc(1, no_of_data_points, 0:M-1);
figure(1)
stem(data_source);
grid on;xlabel('data points');
ylabel('transmitted data phase representation')
title('Transmitted Data "O"')
Bpsk_modulated_data = pskmod(data_source, M);
scatterplot(Bpsk_modulated_data);
title('bpsk modulated transmitted data')
num_cols=length(Bpsk_modulated_data)/block_size;
data_matrix = reshape(Bpsk_modulated_data, block_size, num_cols);
cp_start = block_size-cp_len;
cp_end = block_size;
for i=1:num_cols
ifft_data_matrix(:,i) = ifft((data_matrix(:,i)),no_of_ifft_points);
for j=1:cp_len
actual_cp(j,i) = ifft_data_matrix(j+cp_start,i);
end
ifft_data(:,i) = vertcat(actual_cp(:,i),ifft_data_matrix(:,i));
end
[rows_ifft_data cols_ifft_data]=size(ifft_data);
len_ofdm_data = rows_ifft_data*cols_ifft_data;
ofdm_signal = reshape(ifft_data, 1, len_ofdm_data);
figure(3)
plot(real(ofdm_signal));
xlabel('Time');
ylabel('Amplitude');
title('OFDM Signal');
grid on;
recvd_signal = ofdm_signal;
recvd_signal_matrix = reshape(recvd_signal,rows_ifft_data, cols_ifft_data);
recvd_signal_matrix(1:cp_len,:)=[];
for i=1:cols_ifft_data
fft_data_matrix(:,i) = fft(recvd_signal_matrix(:,i),no_of_fft_points);
end
recvd_serial_data = reshape(fft_data_matrix, 1,(block_size*num_cols));
Bpsk_demodulated_data = pskdemod(recvd_serial_data,M);
scatterplot(Bpsk_modulated_data);title('Received Bpsk modulated data')
figure(5)
stem(Bpsk_demodulated_data,'rx');
grid on;xlabel('data points');
ylabel('received data phase representation');
title('Received Data "X"')
