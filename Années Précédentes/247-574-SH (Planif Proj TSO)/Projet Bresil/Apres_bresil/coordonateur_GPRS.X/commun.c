#include "commun.h"

/**
 * @brief Fonction contenant les configurations de depart des differents registres
 *
 */
void commun_initialisationRegistres(void)
{
    //enable the interupt
    RCONbits.IPEN   = 1; // ENABLE interrupt priority
    INTCONbits.GIE  = 1; // ENABLE interrupts
    INTCONbits.PEIE = 1; // ENable peripheral interrupts.
    TRISBbits.TRISB3 = 0; //GSM RST output
    PORTBbits.RB3 = 0;

    TRISBbits.TRISB2 = 0; //Xbee Sleep output
    PORTBbits.RB2 = 0; //ON Xbee input

    TRISCbits.TRISC4 = 0; //Xbee Sleep output
    PORTCbits.RC4 = 0; //ON Xbee input

    TRISCbits.TRISC3 = 0; //GSM RST output
    PORTCbits.RC3 = 0;
    TRISCbits.TRISC1 = 0; //GSM RST output
    PORTCbits.RC1 = 0;
    
}



/**
 * @brief Fonction utilitaire pour permettre d'avoir des delais > 500 msec
 * @param ms valeur en ms du delai voulu (precision au 10 msec)
 */
void commun_delaiMS(unsigned int ms)
{
    unsigned i;

    for(i=0;i< (ms/10);i++)
        __delay_ms(10);
}
void initialisation_ActiverTimer0(void)
{
    // configuration timer0
    T0CON               = 0x00;
    T0CONbits.TMR0ON    = true;
    T0CONbits.T08BIT    = false; // mode 16 bits
    T0CONbits.T0PS      = 0b011; //1:16 Prescale value
    T0CONbits.PSA       = false;
    INTCONbits.TMR0IE   = true;
    INTCONbits.TMR0IF   = false;
    INTCON2bits.TMR0IP  = true; // haute priorite
    // ajustement du temps
//    TMR0L               = 0xF6;     // valeur pour forcer le delai d'une seconde
//    TMR0H               = 0xC2;

    TMR0L = 0xED;               // valeur pour forcer le delai de 0.5 secondes
    TMR0H = 0x85;

    //OSCCON = OSCCON & 0xEF; // en forcant un 0 sur ce bit Fosc passe a 500 khz au lieu de 1mhz
}


