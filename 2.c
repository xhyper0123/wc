d=0:100:1000;
while(1)
    select=input('enter a number from 1-4: 1-okumura model, 2-hata model, 3-log normal shadowing, 4-exit:');
    if select==1
        disp('okumura model');
        f=input('enter frequency from 150MHz to 1920MHz:');
        c=3*10^8;
        ht=input('enter transmitter height from 30-1000m:');
        hr=input('enter reciever hright from 1-10m:');
        ga=20;
        a=20;
        w=f/c;
        lf=10*log10(((4*pi.*d).^2)/(w^2));
        gt=20*log10(ht/200);
        if hr<=3
            gr=10*log10(hr/3);
        else
            gr=20*log10(hr/3);
        end
        L50=lf+a-gt-gr-ga;
        figure(1);
        plot(d,L50);
        xlabel('distance');
        ylabel('L50');
        title('okumura model');
    elseif select==2
        disp('hata model');
        fc=input('enter frequency ranging between 150Mhz-1500Mhz:');
        ht=input('enter transmitted height from 30-200m:');
        hr=input('enter reciever height from 1-10m:');
        if fc<=300*10^6
        a(hr)=8.29*((log(1.54*hr))^2)-1.1;
        else
        a(hr)=3.2*((log(11.75*hr))^2)-4.97;
        end
        Lu=69.55+26.16*log10(fc)-13.82*log10(ht)-a(hr)+(44.9-(6.55*log10(ht))).*log10(d);
        Ls=Lu-2*((log10(fc/28))^2)-5.4;
        Lr=Lu-4.78*((log10(fc))^2)+18.33*(log10(fc))-40.95;
        figure(2);
        plot(d,Lu,'r',d,Ls,'b',d,Lr,'m');
        xlabel('distance');
        ylabel('path loss');
        title('hata model');
    elseif select==3
        disp('log normal shadowing');
        pt=input('enter transmitter power:');
        gt=1;
        gr=1;
        w=input('enter wavelength value:');
        d=0:50:500
        x=4
        n=2
        d0=100;
        pr=pt*gt*gr*(w^2)./((4*pi.*d).^2);
        pl_d0=10*log10(pt./pr);
        pl_d=pl_d0+10*n*log10(d./d0)+x;
        figure(3);
        plot(d,pl_d);
        xlabel('distance');
        ylabel('path loss');
        title('log normal shadowing');
    elseif select==4
        break;
    else
        disp('enter right choice:');
    end
end
