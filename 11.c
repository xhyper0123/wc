snr_threshold_dB = 10;
snr_threshold = 10^(snr_threshold_dB / 10);
outage_prob = 1 - marcumq(sqrt(snr_threshold), 1, 1);
disp('outage probability:')
disp(outage_prob)
