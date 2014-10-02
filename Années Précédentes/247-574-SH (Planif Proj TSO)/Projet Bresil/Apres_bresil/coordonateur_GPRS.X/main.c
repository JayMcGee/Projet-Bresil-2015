/*
 * File:   main.c
 * Author: Maxime
 *
 * Created on 7 février 2014, 11:49
 */
#include "commun.h"
/*
 *
 */
void usartConfig();
void usartConfig2();
void firstStartGSM();
void ClearMemory();
void dort();




/*
*
*/
int main(int argc, char** argv)
{

    commun_initialisationRegistres();
    initialisation_ActiverTimer0();
    usartConfig();
    usartConfig2();
    RtccInitClock();    
    writeUsart1((char*)dep);
    firstStartGSM();

    while(1)
    {
        if(buffer1Write == buffer1Read && buffer2Write == buffer2Read)
        {
            if(readingTime>heure2)
            {
                readingTime = 0;
                sendGSM();
            }
            if(VtrameReceived)
            {
               executeBuffer();
               VtrameReceived = false;
            }
            if(Vg)
            {
                 Vy = false;
                VPOST = true;
                Vg = false;
                VOK = false;
                VPH = false;
                VFC = false;
                mcPostGSM =9;
                mcStartGSM = 0;
                compteurTimer0 = 0;
            }
            else if(Vq)
            {
                ClearMemory();
                Vq = false;
            }

            if(Vy)
            {
                startGSM();
            }
            if(VPOST)
            {
                POST();
            }
            if(Vo)
            {
                sendGSM();
            }

            if(Vu)
            {
               usartConfig2();
            }
        }
        else
        {
            readbuffer();
        }

    }
    return (EXIT_SUCCESS);

}
//For init USART1 (at pin RX1 1 and TX1 44)
void usartConfig()
{
    unsigned char USART1config = 0;
    unsigned char baudRate = 25;   //25 = 9600 Bauds at 4Mhz //103 = 9600 Bauds at 16 Mhz
    //initialise la communication uart
    TRISCbits.TRISC6= 0; //TX output
    TRISCbits.TRISC7 = 1; //RX input
    USART1config = USART_TX_INT_OFF & USART_RX_INT_ON &
            USART_ASYNCH_MODE & USART_EIGHT_BIT & USART_BRGH_HIGH;
    Open1USART(USART1config,baudRate); //Open EUSART and set the parameter
}
//For init USART1 (at pin RX1 14 and TX1 15)
void usartConfig2()
{
    unsigned char USART2config = 0;
    unsigned char baudRate = 25;//il ne faut pas oublier de configurer le board de covertion
    //25 = 9600 Bauds at 4Mhz //103 = 9600 Bauds at 16 Mhz
    //initialise la communication uart
    PPSCON = 0x00;
    RPINR16 = 0x07;
    RPOR8 = 0x06;
    PPSCON = 0x01;
    ANCON0bits.PCFG0 = 1;
    TRISAbits.TRISA1 = 0; //TX input
    TRISAbits.TRISA0 = 1; //RX output
    USART2config = USART_TX_INT_OFF & USART_RX_INT_ON &
            USART_ASYNCH_MODE & USART_EIGHT_BIT & USART_BRGH_HIGH;
    Open2USART(USART2config,baudRate); //Open EUSART and set the parameter
}

//Pour écrire:
void firstStartGSM()
{
    Vy = true;
    Vg = false;
    VOK = false;
    VPH = false;
    VFC = false;
    VPOST = false;
    mcStartGSM = 20;
    mcPostGSM = 0;
    VstartReady = false;
}

void ClearMemory()
{
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

