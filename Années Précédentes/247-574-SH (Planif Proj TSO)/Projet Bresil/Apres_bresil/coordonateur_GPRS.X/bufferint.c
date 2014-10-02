#include "bufferint.h"

void readbuffer()
{
    char br1 = '\0';
    char br2 = '\0';
    if(buffer1Write != buffer1Read)
    {
        buffer1Read  ++;

        if(buffer1Read>= 128)
        {
           buffer1Read = 0;
        }
        br1 = bufferint1[buffer1Read];
//        while(Busy2USART());
//        Write2USART(br1);
       switch(br1) // valeur ASCII du caractere appuye
        {
            case SOH: // touche DEL
                VSOH = true;
                break;
            case SOL: // touche DEL
                if(VSOH)
                {
                    VSOH = false;
                    VSOok = 1;
                    nbOfChar = 0;
                }
                break;
            default:
                    if(VSOok == 1)
                    {
                        checksumtoChesck = 0;
                        dataLenghtoReceived = (int)br1 <<8;
                        VSOok = 2;
                    }
                    else if(VSOok == 2)
                    {
                        dataLenghtoReceived += (int)br1 & 0x0FF;
                        VSOok = 3;
                    }
                    else if(VSOok == 3)
                    {
                        idReceived = (int)br1;
                        checksumtoChesck = (int)br1;
                        nbOfChar = 0;
                        VSOok = 4;
                    }
                    else if(VSOok == 4)
                    {
                        if(nbOfChar<=dataLenghtoReceived-1)
                        {
                            trameToParse[nbOfChar] = br1;
                            checksumtoChesck += (int)br1;
                        }
                        else
                        {
                            trameToParse[nbOfChar] = br1;
                            checksumtoChesck += (int)br1;
                            VSOok = 5;
                        }
                        //? pas enctrameToParse[nbOfChar] = br1;
                        nbOfChar ++;
                    }
                    else if(VSOok == 5)
                    {

                        ChecksumReceived = br1 <<8;
                        VSOok = 6;
                    }
                    else if(VSOok == 6)
                    {
                        ChecksumReceived += br1 & 0x0FF;
                        VSOok = 0;

                        if(checksumtoChesck == ChecksumReceived)
                        {
                          //  trameToParse[0] = '\0';
                            VtrameReceived = true;
                        }
                        else
                        {
                            trameToParse[0] = '\0';
                            idReceived = 0;
                            VtrameReceived = false;
                        }

                    }

                break;
        };
    }
    else if(buffer2Write != buffer2Read)
    {
        buffer2Read  ++;
        if(buffer2Read>= 128)
        {
           buffer2Read = 0;
        }
        br2 = bufferint2[buffer2Read];
        while(Busy1USART());
        Write1USART(br2);
        if(howtimeIsIt)
        {
            if(br2=='+')
            {
                takeTime =true;
                Ctime = 0;
            }

            if(takeTime)
            {
                timeReceived[Ctime] = br2;
                Ctime++;
                timeReceived[Ctime] = '\0';
            }
            
            if(br2=='"')
            {
                virguleRecu++;
            }
            
            if(virguleRecu>1)
            {
                howtimeIsIt = false;
                takeTime = false;
                timeRE  = true;
                Ctime = 0;
                virguleRecu = 0;
            }

        }
        else
        {
            if(br2=='K'&&VO)
            {
                br2='\0';
                VOK = true;
                VO = false;
            }
            else if(br2=='O')
            {
                br2='\0';
                VO = true;
            }
            else if(br2=='A'&&VO)
            {
                br2='\0';
                VKA = true;
                VO = false;
            }
            else if(br2 =='D'&&VKA)
            {
                br2='\0';
                VOK = true;
                VO = false;
                VKA = false;
            }
            else if(br2=='e')
            {
                br2='\0';
                Vstarte = true;
            }
            else if(br2=='a'&& Vstarte)
            {
                br2='\0';
                Vstarta = true;
                Vstarte = false;
            }
            else if(br2=='d'&&Vstarta)
            {
                br2='\0';
                Vstartd = true;
                Vstarte = false;
                Vstarta = false;
            }
            else if(br2=='y'&& Vstartd)
            {
                br2='\0';
                VstartReady = true;
                Vstarte = false;
                Vstarta = false;
                Vstartd = false;
            }
            else if(br2=='E')
            {
                br2='\0';
                VERROR_E = true;
            }
            else if(br2=='R'&& (VERROR_E||VERROR_O||VERROR_R))
            {
                br2='\0';
                VERROR_R = true;
                VERROR_E = false;
                if(VERROR_O&&mcPostGSM > 0)
                {
                    mcPostGSM = 10;
                    nbFrameDO = 0 ;
                    nbFramePH = 0 ;
                    nbFrameEC = 0 ;
                    nbFrameTDS = 0 ;
                    for(int g = 0;g <= 50; g++)
                    {
                        for(int erase =0;erase<=strlen(my_FrameReceived[g].receivedFrameDO)-1;erase++)
                        {
                            my_FrameReceived[g].receivedFrameDO[erase] = '\0';
                        }
                        my_FrameReceived[g].receivedDataTimeDO = 0;

                        for(int erase =0;erase<=strlen(my_FrameReceived[g].receivedFramePH)-1;erase++)
                        {
                            my_FrameReceived[g].receivedFramePH[erase] = '\0';
                        }
                        my_FrameReceived[g].receivedDataTimePH = 0;
                        for(int erase =0;erase<=strlen(my_FrameReceived[g].receivedFrameEC)-1;erase++)
                        {
                            my_FrameReceived[g].receivedFrameEC[erase] = '\0';
                        }
                        my_FrameReceived[g].receivedDataTimeEC = 0;
                        for(int erase =0;erase<=strlen(my_FrameReceived[g].receivedFrameTDS)-1;erase++)
                        {
                            my_FrameReceived[g].receivedFrameTDS[erase] = '\0';
                        }
                        my_FrameReceived[g].receivedDataTimeTDS = 0;
                    }
                    nbFrameDO = 0 ;
                    nbFramePH = 0 ;
                    nbFrameEC = 0 ;
                    nbFrameTDS = 0 ;
                    Vq = false;
                }
            }
            else if(br2=='0'&& VERROR_R)
            {
                br2='\0';
                VERROR_O = true;
                VERROR_E = false;
                VERROR_R = false;
            }


            else
            {
                VO = false;
                VKA = false;
                Vstarte = false;
                Vstarta = false;
                Vstartd = false;
                //VOK = false;
            }
        }
    }
}
void executeBuffer()
{
    int w=0;
    int y=0;
    if(idReceived == 0x10)
    {
        w=0;
        y=0;
        for(w=0;w<=strlen(trameToParse)-1;w++)
        {

            my_FrameReceived[nbFramePH].receivedFramePH[y] = trameToParse[y];
            y++;
            if(trameToParse[y]==';')
            {
                w=30;
            }
        }

        my_FrameReceived[nbFramePH].receivedDataTimePH = (int)trameToParse[y+1] << 8;
        my_FrameReceived[nbFramePH].receivedDataTimePH += (int)trameToParse[y+2] & 0x0FF;
        nbFramePH ++;
        idReceived = 0;
    }
    else if(idReceived == 0x11)
    {
        w=0;
        y=0;
        for(w=0;w<=strlen(trameToParse)-1;w++)
        {
            my_FrameReceived[nbFrameDO].receivedFrameDO[y] = trameToParse[y];
            y++;
            if(trameToParse[y]==';')
            {
                w=30;
            }
        }

        my_FrameReceived[nbFrameDO].receivedDataTimeDO = (int)trameToParse[y+1] << 8;
        my_FrameReceived[nbFrameDO].receivedDataTimeDO += (int)trameToParse[y+2] & 0x0FF;
        nbFrameDO ++;
        idReceived = 0;
    }
    else if(idReceived == 0x12)
    {
        w=0;
        y=0;
        for(w=0;w<=strlen(trameToParse)-1;w++)
        {
            my_FrameReceived[nbFrameEC].receivedFrameEC[y] = trameToParse[y];
            y++;
            if(trameToParse[y]==';')
            {
                w=30;
            }
        }
        my_FrameReceived[nbFrameEC].receivedDataTimeEC = (int)trameToParse[y+1] << 8;
        my_FrameReceived[nbFrameEC].receivedDataTimeEC += (int)trameToParse[y+2] & 0x0FF;
        nbFrameEC ++;
        idReceived = 0;
    }
    else if(idReceived == 0x13)
    {
        w=0;
        y=0;
        for(w=0;w<=strlen(trameToParse)+2;w++)
        {
            my_FrameReceived[nbFrameTDS].receivedFrameTDS[y] = trameToParse[y];
            y++;
            if(trameToParse[y]==';')
            {
                w=30;
            }
        }
        my_FrameReceived[nbFrameTDS].receivedDataTimeTDS = (int)trameToParse[y+1] << 8;
        my_FrameReceived[nbFrameTDS].receivedDataTimeTDS+= (int)trameToParse[y+2] & 0x0FF;
        nbFrameTDS ++;
        idReceived = 0;
    }
    else if(idReceived == 0x21)
    {
        switch(trameToParse[0]) // valeur ASCII du caractere appuye
        {
            case 'p': // touche DEL
                if(VpowerSensor)
                {
                    PORTCbits.RC3 = 1;
                    while(Busy1USART());
                    Write1USART('1');
                    VpowerSensor=false;
                }
                else
                {
                    PORTCbits.RC3 = 0;
                    while(Busy1USART());
                    Write1USART('0');
                    VpowerSensor=true;
                }
                break;
            case 'o':
                Vo = true;
                break;
            case 'g': // touche DEL
                Vg = true;
                VOK = false;
                VPH = false;
                VFC = false;
                VPOST = false;
                Vy = false;
                break;
            case 'u': // touche DEL
                Vu = true;
                break;
            case 'y': // touche DEL
                Vy = true;
                Vg = false;
                VOK = false;
                VPH = false;
                VFC = false;
                VPOST = false;
                mcStartGSM = 20;
                mcPostGSM = 0;
                VstartReady = false;
                break;
            case 'q': // touche DEL
                Vq = true;
                break;

            default:

                break;

        };

        idReceived = 0;
    }

    

}
