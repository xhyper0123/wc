clc;
clear all;
close all;
d=1:10:1000;
while(1)
 Model_Type=input('Enter Propagation model Type:-1:Free space model\n 2:Two-ray model\n
3:Okumura model\n 4: Hata model\n 5:exit\n');

 if Model_Type == 1
 fc=input('Enter the operating frequency');
 Gt=input('Enter the transmitting antenna gain');
 Gr=input('Enter the receiving antenna gain');
 pt=input('Enter the Transmitted Power in watts');
 lamda=3*10^8/fc;
 recieved_power_FSM=10*log10(pt)+10*log10(Gt*Gr)-20*log10((4*pi*d/lamda));
 figure(1);
 plot(d,recieved_power_FSM);
 title(‘Free space channel model');
 ylabel('Received power in dB--->');
 xlabel('Distance in Km--->');
 elseif Model_Type == 2
 fc=input('Enter the operating frequency');
 Gt=input('Enter the transmitting antenna gain');
 Gr=input('Enter the receiving antenna gain');
 pt=input('Enter the Transmitted Power in watts');
 ht=input('Enter the hight of transmitting antenna');
hr=input('Enter the hight of receiving antenna');

 received_power_TRM=10*log10(pt)+10*log10(Gt*Gr)+20*log10(ht*hr)-40*log10(d);
 figure(2);
 plot(d,received_power_TRM);
 title('Two-Ray channel model');
 ylabel('Received power in dB--->');
 xlabel('Distance in Km--->');
 elseif Model_Type == 3
 fc=input('Enter the operating frequency(Range:150-1500MHz)');
 Gt=input('Enter the transmitting antenna gain');
 Gr=input('Enter the receiving antenna gain');
 pt=input('Enter the Transmitted Power in watts');
 ht=input('Enter the hight of transmitting antenna(range applicable:30-100m)');
 hr=input('Enter the hight of receiving antenna(applicable range:3-10m)');
 A=input('Enter the median attenuation(Applicable range: 15-60dB'));
 GAREA=input('Enter the Gain from Environment(applicable range:5-30dB)');
 lamda=3*10^8/fc;
Ght=20*log10(ht/200);
 if hr<=3
 Ghr=10*log10(hr/3);
 else
 Ghr=20*log10(hr/3);
 end
 received_power_OKM=10*log10(pt)+Ght+Ghr+10*log10(GAREA)-
20*log10((4*pi*d/lamda))-A;
 figure(3);
 plot(d,received_OKM);
 title('Received_power Vs Distance in Okumura channel model');
 ylabel('Received power in dB--->');
 xlabel('Distance in Km--->');
 elseif Model_Type==4
 fc=input('Enter the operating frequency(Range:150-1500MHz)');
 Gt=input('Enter the transmitting antenna gain');
 Gr=input('Enter the receiving antenna gain');
 pt=input('Enter the Transmitted Power in watts');
 ht=input('Enter the hight of transmitting antenna');
 hr=input('Enter the hight of receiving antenna');
 K=input('Enter the value of K(35.94 (countryside) to 40.94 (desert)');
 ahr=3.2*(log10(11.75*hr))^2-4.97;
 received_HM_Urban=10*log10(pt)+10*log10(Gt)+10*log10(Gr)-(69.55+26.16*log10(fc)-
13.82*log10(ht)-ahr+(44.9-6.55*log10(ht))*log10(d));
 received_HM_Suburban=received_HM_Urban-2*(log10(fc/28))^2-5.4;
 received_HM_Rural=received_HM_Urban-4.78*(log10(fc))^2 + 18.33*log10(fc)-K;
 figure(4);
 plot(d,received_HM_Urban,'r',d,received_HM_Suburban,'b',d,received_HM_Rural,'g');
 title('Received_power Vs Distance in Hata channel model');
ylabel('Received power in dB--->');
 xlabel('Distance in Km--->');
 legend('recieved_HM_Urban','recieved_HM_Suburban','recieved_HM_Rural');
 elseif Model_Type==5
 break;
 else

 disp('Enter the right choice');
 end
end
