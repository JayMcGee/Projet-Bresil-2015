


#include <xc.h>
#include "commun.h"

/******************************************************************************/
/* Interrupt Routines                                                         */
/******************************************************************************/
char rx;
char rx2;

/* High-priority service */
void interrupt high_isr(void)
{
    /* Determine which flag generated the interrupt */
    if(PIR1bits.RCIF == 1)
    {
        rx = Read1USART();
        buffer1Write ++;
        if(buffer1Write>= 128)
        {
           buffer1Write = 0;
        }
        bufferint1[buffer1Write] = rx;
        PIR1bits.RCIF = 0; // clear rx flag
    }

    if(PIR3bits.RC2IF == 1)
    {
        rx2 = Read2USART();
        buffer2Write ++;
        if(buffer2Write>= 128)
        {
           buffer2Write = 0;
        }
        bufferint2[buffer2Write] = rx2;
        PIR3bits.RC2IF = 0; // clear rx flag
    }

    if (INTCONbits.TMR0IF) // timer 0
    {
            INTCONbits.TMR0IF   = false;    // baisser l'indication de l'interruption
//            TMR0L               = 0xF6;     // valeur pour forcer le delai d'une seconde
//            TMR0H               = 0xC2;
            TMR0L               = 0xED;     // valeur pour forcer le delai de deux secondes
            TMR0H               = 0x85;
            readingTime++;
//            writeUsart1((char *)"T0");//uncomment to see the speed of timer 0
            if(compteurTimer0 > 9)
            {
               compteurTimer0++;
            }
    }

}
/* Low-priority interrupt routine */
void low_priority interrupt low_isr(void)
{
}
