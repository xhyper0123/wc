k=4;
M =2^k;
nFFT= 128;
k = 4;
M = 2^k; 
nFFT = 128; 
cplen = 8; 
txsymbols= randi ([0 M-1], nFFT, 1);
txgrid = qammod (txsymbols, M, UnitAveragePower=true); 
txout=ifft (txgrid, nFFT); 
txout=txout(:);
txcp =txout(nFFT-cplen+1:nFFT);
txout =[txcp; txout];
Fs=20e3 *nFFT/2;
 Ts= 1/Fs;
Tend =Ts *(length (txout)-1);
subplot (211) ;
hold off;
plot (0: Ts: Tend, real (txout)," * ");
txsymbols = randi([0 M-1],nFFT,1);
txgrid = qammod(txsymbols,M,UnitAveragePower=true);
txout = ifft(txgrid,nFFT);
txout = txout(:); 
 
txcp = txout(nFFT-cplen+1:nFFT);
txout = [txcp; txout];
Fs = 20e3 * nFFT/2; 
Ts = 1 / Fs; 
Tend = Ts * (length(txout)-1);
subplot(2 ,1, 1)
hold off
plot(0:Ts:Tend,real(txout),"*")
title("Real component of transmitter output")
nFFTUp= 3*nFFT;
fftgrid =[txgrid(1:nFFT/2);
txgrid((nFFT/2+1): nFFT)];
txout =3 *ifft (fftgrid, nFFTUp);
txout =txout(:);
cplenUp =cplen *3; 
txcp= txout (nFFTUp -cplenUp+ 1 : nFFTUp);
txout= [txcp; txout]; 
Ts=1/(3*Fs);
Tend= Ts *(length (txout)-1);
nFFTUp=3 * nFFT;
fftgrid = [txgrid(1:nFFT/2);
 txgrid((nFFT/2+1):nFFT)];
txout = 3 *ifft(fftgrid,nFFTUp);
txout = txout(:);
cplenUp = cplen * 3;
txcp = txout(nFFTUp-cplenUp+1:nFFTUp);
txout = [txcp; txout];
Ts = 1 / (3*Fs);
Tend = Ts * (length(txout)-1);
subplot(2,1,2)
hold on
plot (0:Ts: Tend, real(txout))
title('unsampled trasmitted output')
legend ("Original", "Upsampled", "Location","southeast")
