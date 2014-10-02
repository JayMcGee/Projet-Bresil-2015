#include "usart.h"



void send_cr()
{
    while(Busy2USART());
    Write2USART(cr);
}

void send_char1USART(char text1)
{
    while(Busy1USART());
    Write1USART(text1);
}

void send_char2USART(char text2)
{
    while(Busy2USART());
    Write2USART(text2);
}

void writeUsart2(char *datas)
{
    int lengh = 0 ;
    for(lengh = 0;lengh <= strlen(datas)-1;lengh++ )
    {
        while(Busy2USART());
        Write2USART(datas[lengh]);
    }
}

void writeUsart1(char *datas1)
{
    int lengh = 0 ;

    if(strlen(datas1)-1<= 1000)
    {
        for(lengh = 0;lengh <= strlen(datas1)-1;lengh++ )
        {
            while(Busy1USART());
            Write1USART(datas1[lengh]);
        }
    }
}

void writeUsart1Trame(char *datas2,unsigned int datatime,int id)
{
    int dataLengh = 0;
    int checksum = 0;
    send_char1USART((char)SOH);
    send_char1USART((char)SOL);
     switch(id) // valeur ASCII du caractere appuye
    {
        case PH:
            send_char1USART(PH_lenghINT >>8);
            send_char1USART(PH_lenghINT & 0x0FF);
            dataLengh = PH_lenghINT;
            break;
        case DO:
            send_char1USART(DO_lenghINT >>8);
            send_char1USART(DO_lenghINT & 0x0FF);
            dataLengh = DO_lenghINT;

            break;
        case EC:
            send_char1USART(EC_lenghINT >>8);
            send_char1USART(EC_lenghINT & 0x0FF);
            dataLengh = EC_lenghINT;
            break;
        case TDS:
            send_char1USART(TDS_lenghINT >>8);
            send_char1USART(TDS_lenghINT & 0x0FF);
            dataLengh = TDS_lenghINT;
        case ResetTimer:
            send_char1USART(ResetTimer_lengh >>8);
            send_char1USART(ResetTimer_lengh & 0x0FF);
            dataLengh = ResetTimer_lengh;
            break;
        case CommandeManuel:
            send_char1USART(CommandeManuel_lengh >>8);
            send_char1USART(CommandeManuel_lengh & 0x0FF);
            dataLengh = CommandeManuel_lengh;
            break;
        default:
            send_char1USART(emptyINT >>8);
            send_char1USART(emptyINT & 0x0FF);
            dataLengh = emptyINT;
            break;
    };
    send_char1USART((char)id);
    checksum += id;

    for(int lengh = 0;lengh <= dataLengh-3;lengh++ )
    {
        send_char1USART(datas2[lengh]);
        checksum += ((int)datas2[lengh]);
    }
    send_char1USART(datatime >>8);
    checksum += datatime >>8;
    send_char1USART(datatime & 0x0FF);
    checksum +=datatime & 0x0FF;
    send_char1USART(checksum >>8);
    send_char1USART(checksum & 0x0FF);

}
