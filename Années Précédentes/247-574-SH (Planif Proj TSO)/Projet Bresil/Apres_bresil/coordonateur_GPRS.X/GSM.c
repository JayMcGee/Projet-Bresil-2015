#include "GSM.h"



void sendGSM()
{
    
        mcPostGSM =9;
        writeUsart1Trame((char*)"b",0xFFFF,CommandeManuel);
        writeUsart1Trame((char*)"a",0xFFFF,CommandeManuel);
        writeUsart1Trame((char*)"r",0xFFFF,CommandeManuel);
        commun_delaiMS(1000);
        Vg = true;
        Vo = false;
    
}
//Ative the post to send the Json on the Net
void POST()
{
    if(mcPostGSM ==9)
    {
        send_cr();
        howtimeIsIt =true;
        writeUsart2((char*)"AT+CCLK?");
        send_cr();

        mcPostGSM =10;
        compteurTimer0 = 10;

    }
    if(mcPostGSM ==10 && compteurTimer0 >= 14)
    {
        send_cr();
        timetoPost[0]='2';
        timetoPost[1]='0';
        timetoPost[2]=timeReceived[8];
        timetoPost[3]=timeReceived[9];
        timetoPost[4]='-';
        timetoPost[5]=timeReceived[11];
        timetoPost[6]=timeReceived[12];
        timetoPost[7]='-';
        timetoPost[8]=timeReceived[14];
        timetoPost[9]=timeReceived[15];
        timetoPost[10]=' ';
        timetoPost[11]=timeReceived[17];
        timetoPost2[0]=timeReceived[17];
        timetoPost[12]=timeReceived[18];
        timetoPost2[1]=timeReceived[18];
        timetoPost[13]=':';
        timetoPost2[2]=':';
        timetoPost[14]=timeReceived[20];
        timetoPost2[3]=timeReceived[20];
        timetoPost[15]=timeReceived[21];
        timetoPost2[4]=timeReceived[21];
        timetoPost[16]=':';
        timetoPost2[5]=':';
        timetoPost[17]=timeReceived[23];
        timetoPost2[6]=timeReceived[23];
        timetoPost[18]=timeReceived[24];
        timetoPost2[7]=timeReceived[24];
        timetoPost[19]='\0';
        timetoPost2[8]='\0';
        virguleRecu = 0;
        timeRE  = false;
        CtoS[0] = 'h';
        writeUsart1Trame(CtoS,0xFFFF,CommandeManuel);
        mcPostGSM = 11;
        compteurTimer0 = 10;
        timeRE = false;
                
    }
    if(mcPostGSM ==11 && compteurTimer0 >= 14)
    {
        send_cr();
        CtoS[0] = 'k';
        writeUsart1Trame(CtoS,0xFFFF,CommandeManuel);//
        mcPostGSM =12;
        compteurTimer0 = 10;
    }
    if(mcPostGSM ==12 && compteurTimer0 >= 14)
    {
        send_cr();
        CtoS[0] = 'l';
        writeUsart1Trame(CtoS,0xFFFF,CommandeManuel);//
        mcPostGSM =1;
        compteurTimer0 = 10;
    }
    if(mcPostGSM ==1 && compteurTimer0 >= 14)
    {
        compteurTimer0 = 0;
        VOK = false;
        mcPostGSM =2;
        char STrLenghC[4]="\0";
        sendJsonDO();
        int STrLenghI = 0;
        STrLenghI = strlen(dataToSend);
        STrLenghI += -2;
        itoa(STrLenghC,STrLenghI,10);
        VPH = false;
        writeUsart2((char*)G11_POST);
        commun_delaiMS((int)delayTest);
        writeUsart2(STrLenghC);
        commun_delaiMS((int)delayTest);
        send_char2USART(',');
        commun_delaiMS(50);
        writeUsart2((char*)timeOfTransfert);
        commun_delaiMS((int)delayTest);
        send_cr();
        compteurTimer0 = 10;
    }
    else if(mcPostGSM ==2 && VOK && compteurTimer0 >= 11)
    {
        VOK = false;
        mcPostGSM =3;


        writeUsart2(dataToSend);
        compteurTimer0 = 10;
    }
    else if(mcPostGSM ==3 && VOK && compteurTimer0 >= 11)
    {
        compteurTimer0 = 0;
        VOK = false;
        mcPostGSM =0;
        Vo=0;
        VPOST = false;
        writeUsart2((char*)G12_POST);
        commun_delaiMS((int)delayTest);
        send_cr();
        for(int v = 0;v>25;v++)
        {
            timeReceived[v]='\0';
            timetoPost[v]='\0';
        }
        for(int erase =0;erase<=1500-1;erase++)
        {
            dataToSend[erase] = '\0';
        }
    }
}
//Build and send the Json in one time
void sendJsonDO()
{
    int nbdataI = 0;
    int boardDO = 0;
    int nbdataIPH = 0;
    int boardPH = 0;
    int nbdataIEC = 0;
    int boardEC = 0;
    int nbdataITDS = 0;
    int boardTDS = 0;
    unsigned char bufferTEMPO[10] = "\0";
    dataToSend[0] = '\0';
    dataToSend[1] = '\0';
    dataToSend[2] = '\0';
    dataToSend[3] = '\0';
//    writeUsart2((char*)headerS1);
    sprintf(dataToSend,"%s%s",dataToSend,headerS1);
//    writeUsart2((char*)headerS2);
    sprintf(dataToSend,"%s%s",dataToSend,headerS2);
    sprintf(dataToSend,"%s%s",dataToSend,timetoPost);
    sprintf(dataToSend,"%s%s",dataToSend,headerS4);
    sprintf(dataToSend,"%s%s",dataToSend,staID);
    sprintf(dataToSend,"%s%s",dataToSend,headerS4_1);
    sprintf(dataToSend,"%s%s",dataToSend,regularReading);
    sprintf(dataToSend,"%s%s",dataToSend,headerS5);
    
    if(nbFrameDO!=0)
    {
        sprintf(dataToSend,"%s%s",dataToSend,headerV6);
        sprintf(dataToSend,"%s%s",dataToSend,senC_ID_DO);
        sprintf(dataToSend,"%s%s",dataToSend,headerV6_1);

        for(int l = 0;l <= nbFrameDO-1; l++)
        {
            sprintf(dataToSend,"%s%s",dataToSend,headerV7);
            sprintf(dataToSend,"%s%s",dataToSend,IDDO);
            sprintf(dataToSend,"%s%s",dataToSend,headerV8);
            sprintf(dataToSend,"%s%s",dataToSend,timetoPost2);
//            itoa(bufferTEMPO,my_FrameReceived[boardDO].receivedDataTimeDO,10);
//            sprintf(dataToSend,"%s%s",dataToSend,bufferTEMPO);
            my_FrameReceived[boardDO].receivedDataTimeDO = 0;
            sprintf(dataToSend,"%s%s",dataToSend,headerV9);
            sprintf(dataToSend,"%s%s",dataToSend,valuetype);
            sprintf(dataToSend,"%s%s",dataToSend,headerV10);
            sprintf(dataToSend,"%s%s",dataToSend, my_FrameReceived[boardDO].receivedFrameDO);
            for(int erase =0;erase<=5;erase++)
            {
                my_FrameReceived[boardDO].receivedFrameDO[erase] = '\0';
            }
            boardDO ++;
            sprintf(dataToSend,"%s%s",dataToSend,headerV11);
        }
    }


    if(nbFramePH!=0)
    {
        if(nbFrameDO!=0)
        {
            sprintf(dataToSend,"%s]},",dataToSend);
        }
        sprintf(dataToSend,"%s%s",dataToSend,headerV6);
        sprintf(dataToSend,"%s%s",dataToSend,senC_ID_PH);
        sprintf(dataToSend,"%s%s",dataToSend,headerV6_1);
        for(int l = 0;l <= nbFramePH-1; l++)
        {
            sprintf(dataToSend,"%s%s",dataToSend,headerV7);
            sprintf(dataToSend,"%s%s",dataToSend,IDPH);
            sprintf(dataToSend,"%s%s",dataToSend,headerV8);
            sprintf(dataToSend,"%s%s",dataToSend,timetoPost2);
//            itoa(bufferTEMPO,my_FrameReceived[boardPH].receivedDataTimePH,10);
//            sprintf(dataToSend,"%s%s",dataToSend,bufferTEMPO);
            my_FrameReceived[boardPH].receivedDataTimePH = 0;
            sprintf(dataToSend,"%s%s",dataToSend,headerV9);
            sprintf(dataToSend,"%s%s",dataToSend,valuetype);
            sprintf(dataToSend,"%s%s",dataToSend,headerV10);
            sprintf(dataToSend,"%s%s",dataToSend,my_FrameReceived[boardPH].receivedFramePH);
            for(int erase =0;erase<=4;erase++)
            {
                my_FrameReceived[boardPH].receivedFramePH[erase] = '\0';
            }
            boardPH++;
            sprintf(dataToSend,"%s%s",dataToSend,headerV11);
        }
    }

    if(nbFrameEC!=0||nbFrameTDS!=0)
    {
        if(nbFrameDO!=0||nbFramePH!=0)
        {
            sprintf(dataToSend,"%s]},",dataToSend);
        }
                sprintf(dataToSend,"%s%s",dataToSend,headerV6);
                sprintf(dataToSend,"%s%s",dataToSend,senC_ID_EC_TDS);
                sprintf(dataToSend,"%s%s",dataToSend,headerV6_1);
        for(int l = 0;l <= nbFrameEC -1; l++)
        {
            send_cr();
            sprintf(dataToSend,"%s%s",dataToSend,headerV7);
            sprintf(dataToSend,"%s%s",dataToSend,IDEC);
            sprintf(dataToSend,"%s%s",dataToSend,headerV8);
            sprintf(dataToSend,"%s%s",dataToSend,timetoPost2);
//            itoa(bufferTEMPO,my_FrameReceived[boardEC].receivedDataTimeEC,10);
//            sprintf(dataToSend,"%s%s",dataToSend,bufferTEMPO);
//            commun_delaiMS(20);
            my_FrameReceived[boardEC].receivedDataTimeEC = 0;
            sprintf(dataToSend,"%s%s",dataToSend,headerV9);
            sprintf(dataToSend,"%s%s",dataToSend,valuetype);
            sprintf(dataToSend,"%s%s",dataToSend,headerV10);
            sprintf(dataToSend,"%s%s",dataToSend,my_FrameReceived[boardEC].receivedFrameEC);
            for(int erase =0;erase<=5;erase++)
            {
                my_FrameReceived[boardEC].receivedFrameEC[erase] = '\0';
            }
            boardEC++;
            sprintf(dataToSend,"%s%s",dataToSend,headerV11);
        }

        for(int l = 0;l <= nbFrameTDS-1; l++)
        {
            sprintf(dataToSend,"%s%s",dataToSend,headerV7);
            sprintf(dataToSend,"%s%s",dataToSend,IDTDS);
            sprintf(dataToSend,"%s%s",dataToSend,headerV8);
            sprintf(dataToSend,"%s%s",dataToSend,timetoPost2);
//            itoa(bufferTEMPO,my_FrameReceived[boardTDS].receivedDataTimeTDS,10);
//            sprintf(dataToSend,"%s%s",dataToSend,bufferTEMPO);
            my_FrameReceived[boardTDS].receivedDataTimeTDS = 0;
            sprintf(dataToSend,"%s%s",dataToSend,headerV9);
            sprintf(dataToSend,"%s%s",dataToSend,valuetype);
            sprintf(dataToSend,"%s%s",dataToSend,headerV10);
            sprintf(dataToSend,"%s%s",dataToSend,my_FrameReceived[boardTDS].receivedFrameTDS);
            for(int erase =0;erase<=4;erase++)
            {
                my_FrameReceived[boardTDS].receivedFrameTDS[erase] = '\0';
            }
            boardTDS++;
            sprintf(dataToSend,"%s%s",dataToSend,headerV11);
        }
    }
    sprintf(dataToSend,"%s]}",dataToSend);
    sprintf(dataToSend,"%s%s",dataToSend,headerVF);
    nbFrameDO = 0 ;
    nbdataI = 0;
    boardDO = 0;
    nbFramePH = 0 ;
    nbdataIPH = 0;
    boardPH = 0;
    nbFrameEC = 0 ;
    nbdataIEC = 0;
    boardEC = 0;
    nbFrameTDS = 0 ;
    nbdataITDS = 0;
    boardTDS = 0;
}

int STrLengh()
{
    int lenghOfMessages = 0;
    unsigned char bufferTEMPO[10] = "\0";
    lenghOfMessages += 157;

    if(nbFrameDO>=0)
    {
        lenghOfMessages += 63*nbFrameDO;//121= entete 50= envois avec les donné
        for(int l = 0;l <= (nbFrameDO+1); l++)
        {
            itoa(bufferTEMPO,my_FrameReceived[l].receivedDataTimeDO,10);
            lenghOfMessages += strlen(my_FrameReceived[l].receivedFrameDO) + strlen(bufferTEMPO);
        }
    }

    if(nbFramePH>=0)
    {
        lenghOfMessages += 63*nbFramePH;//121= entete 50= envois avec les donné
        for(int o = 0;o <= (nbFramePH+1); o++)
        {
            itoa(bufferTEMPO,my_FrameReceived[o].receivedDataTimePH,10);
            lenghOfMessages += strlen(my_FrameReceived[o].receivedFramePH) + strlen(bufferTEMPO);
        }
    }

    if(nbFrameEC>=0)
    {
        lenghOfMessages += 63*nbFrameEC;//121= entete 50= envois avec les donné
        for(int p = 0;p <= (nbFrameEC+1); p++)
        {
            itoa(bufferTEMPO,my_FrameReceived[p].receivedDataTimeEC,10);
            lenghOfMessages += strlen(my_FrameReceived[p].receivedFrameEC) + strlen(bufferTEMPO);
        }
    }

    if(nbFrameTDS>=0)
    {
        lenghOfMessages += 63*nbFrameTDS;//121= entete 50= envois avec les donné
        for(int p = 0;p <= (nbFrameTDS+1); p++)
        {
            itoa(bufferTEMPO,my_FrameReceived[p].receivedDataTimeTDS,10);
            lenghOfMessages += strlen(my_FrameReceived[p].receivedFrameTDS) + strlen(bufferTEMPO);
        }
    }

    return lenghOfMessages;

}

void startGSM()
{
    if(mcStartGSM ==20)
    {
        VstartReady = false;
        VOK = false;
        mcStartGSM =2;
        writeUsart2((char*)ATbd);
        commun_delaiMS((int)delayTest);
        send_cr();
        mcStartGSM =10;
        compteurTimer0 = 10;

    }
    if(mcStartGSM ==10 && compteurTimer0 >= 14)
    {
        VstartReady = false;
        PORTCbits.RC3 = 0;
        while(Busy1USART());
        Write1USART('0');
        mcStartGSM =13;
        compteurTimer0 = 15;

    }
    if(mcStartGSM ==10 && VOK)
    {
        VstartReady = false;
        PORTCbits.RC3 = 0;
        while(Busy1USART());
        Write1USART('0');
        mcStartGSM =11;
        compteurTimer0 = 10;

    }
    else if(mcStartGSM ==11 && compteurTimer0 >= 11)
    {
        PORTCbits.RC3 = 1;
        while(Busy1USART());
        Write1USART('1');
        mcStartGSM =12;
        compteurTimer0 = 10;
        

    }
    else if(mcStartGSM ==12 && compteurTimer0 >= 12)
    {
        PORTCbits.RC3 = 0;
        while(Busy1USART());
        Write1USART('0');
        mcStartGSM =13;
        compteurTimer0 = 10;

    }
    else if(mcStartGSM ==13 && compteurTimer0 >= 19)
    {
        PORTCbits.RC3 = 1;
        while(Busy1USART());
        Write1USART('1');
        mcStartGSM =14;
        compteurTimer0 = 10;

    }
    else if(mcStartGSM ==14 && compteurTimer0 >= 12)
    {
        PORTCbits.RC3 = 0;
        while(Busy1USART());
        Write1USART('0');
        mcStartGSM =1;
        compteurTimer0 = 10;
    }
    else if(mcStartGSM ==1 && VstartReady && compteurTimer0 >= 12)
    {
        VstartReady = false;
        VOK = false;
        mcStartGSM =2;
        writeUsart2((char*)ATbd);
        commun_delaiMS((int)delayTest);
        send_cr();
        compteurTimer0 = 10;
    }
    else if(mcStartGSM ==2 && VOK && compteurTimer0 >= 11)
    {
        VOK = false;
        mcStartGSM =3;
        writeUsart2((char*)G1_APN);
        commun_delaiMS((int)delayTest);
//        writeUsart2((char*)V_APN);
//        commun_delaiMS((int)delayTest);
        send_cr();
        compteurTimer0 = 10;
    }
    else if(mcStartGSM ==3 && VOK && compteurTimer0 >= 11)
    {
        VOK = false;
        mcStartGSM =4;
        writeUsart2((char*)G2_USER);
        commun_delaiMS((int)delayTest);
//        writeUsart2((char*)V_USER);
//        commun_delaiMS((int)delayTest);
        send_cr();
        compteurTimer0 = 10;
    }
    else if(mcStartGSM ==4 && VOK && compteurTimer0 >= 11)
    {
        VOK = false;
        mcStartGSM =5;
        writeUsart2((char*)G3_Password);
        commun_delaiMS((int)delayTest);
//        writeUsart2((char*)V_PWD);
//        commun_delaiMS((int)delayTest);
        send_cr();
        compteurTimer0 = 10;
    }
    else if(mcStartGSM ==5 && VOK && compteurTimer0 >= 13)
    {
        VOK = false;
        mcStartGSM =6;
        writeUsart2((char*)G4_bearer1);
        commun_delaiMS((int)delayTest);
        send_cr();
        compteurTimer0 = 10;
    }
    else if(mcStartGSM ==6 && VOK && compteurTimer0 >= 11)
    {
        VOK = false;
        mcStartGSM =7;
        writeUsart2((char*)G5_HTTP);
        send_cr();
        compteurTimer0 = 10;
    }
    else if(mcStartGSM ==7 && VOK && compteurTimer0 >= 11)
    {
        VOK = false;
        mcStartGSM =8;
        writeUsart2((char*)G6_ParaHTTP);
        send_cr();
        compteurTimer0 = 10;
    }
    else if(mcStartGSM ==8 && VOK && compteurTimer0 >= 11)
    {
        VOK = false;
        mcStartGSM =9;
        writeUsart2((char*)G7_ParaHTTP);
        commun_delaiMS((int)delayTest);
//        writeUsart2((char*)G7_2ParaHTTP);
//        commun_delaiMS((int)delayTest);
        send_cr();
        compteurTimer0 = 10;
    }
    else if(mcStartGSM ==9 && VOK && compteurTimer0 >= 11)
    {
        VOK = false;
        Vy =false;
        mcStartGSM =0;
        writeUsart2((char*)G8_ParaHTTP);
        commun_delaiMS((int)delayTest);
//        writeUsart2((char*)G8_2ParaHTTP);
//        commun_delaiMS((int)delayTest);
//        writeUsart2((char*)G8_3ParaHTTP);
//        commun_delaiMS((int)delayTest);
        send_cr();
        compteurTimer0 = 0;
    }
    else if(mcStartGSM >0 && compteurTimer0 >= 25)
    {
        mcStartGSM =20;
        compteurTimer0 = 0;
    }

}

void GET()
{
    writeUsart2((char*)G9_GET);
    send_cr();
    while(VOK);
    VOK = true;
    send_cr();
    writeUsart2((char*)G10_GET);
    send_cr();
    while(VOK);
    VOK = true;
    send_cr();
}

void CloseGSM()
{
    writeUsart2((char*)G13_Close);
    send_cr();
    while(VOK);
    VOK = true;
    send_cr();
}