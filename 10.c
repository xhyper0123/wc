k=4;
M =2^k;
nFFT= 128;
cplen = 8; 
Txaymbols= randi ([0 M-1], nFFT, 1);
txgrid= qammod (txsymbols, M, UnitAverage Power=true); 
txout=ifft (txgrid, nFFT); 
txout=txout(:);
txcp =txout(nFFT-cplen+1:nFFT);
txout =[txcp; txout];
Fs=20e3 *nFFT/2;
 Ts= 1/Fs:
Tend =Ts *(length (txout)-1);
subplot (211) ;
hold off;
plot (0: Ts: Tend, real (txout)," * ");
title("Real component of transmitter output")
nFFTUP=3* FFT;
fftgrid =[txgrid(1:nFFT/2);
txgrid((nFFT/2+1): nFFT)];
txout =3 *ifft (fftgrid, nFFTUP);
txout =txout(:);
cplenUp =cplen *3; 
txcp =txout (nFFTUp-cplenUp+1:nFFTUp);
txout= [txcp; txout]; 
Ts=1/(3*Fs);
Tend= Ts *(length (txout)-1);
subplot(211)
hold on
plot (0:Ts: Tend, real (txout))
legend ("Original", "Upsampled", "Location","southeast")
