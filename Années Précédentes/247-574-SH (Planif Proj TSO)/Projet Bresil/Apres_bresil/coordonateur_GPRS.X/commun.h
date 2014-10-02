#ifndef COMMUN_H
#define COMMUN_H

#include <xc.h>
#include <stdbool.h>       /* For true/false definition */
#include <plib/usart.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <plib/adc.h>
#include "configuration_bits.c"
#include <plib/rtcc.h>
#include <plib/dpslp.h>

#include "bufferint.h"
#include "GSM.h"
#include "usart.h"

#define _XTAL_FREQ 4000000
#define USE_AND_MASKS
#define nbchar  10
#define cr      0x0D

#define sContinuousR 0x63
#define sStopR 0x65
#define staID "bra002"
#define senC_ID_PH "su0002"
#define senC_ID_DO "su0003"
#define senC_ID_EC_TDS "su0004"
#define IDPH "su0002_01"
#define IDDO "su0003-01"
#define IDEC "su0004_01"
#define IDTDS "su0004_02"
#define min2 240
#define min3 360
#define min15 1800
#define heure2 14400
#define regularReading "regularreading"

#define valuetype "asis"
#define timeOfTransfert "20000"
#define delayTest 500
/*It is for set the main object *///121caractere
//#define  START    "POST /? 1234567890"
//#define  CLOSE_MESSAGE     "HTTP/1.1\r Host: cloudiaproject.org\r Connection: close\r "
#define  headerS1 "data={\"stationmessage\":{"//19
#define  headerS2 "\"datetime\":\""  //31  //hh:mm:ss:DD:MM:YYYY
#define  headerS4 "\",\"stationid\":\""//15 //station123
#define  headerS4_1 "\",\"eventtype\":\""//15
#define  headerS5 "\",\"event\":["//12
/*It is for set the object to the Time Value Identification (TVI)*/
#define  headerV6 "{\"sensorunit\":\""
#define  headerV6_1 "\",\"data\":["//accel_123
/*It is the Array for the Time Value Identification (TVI)*///50caractere
#define  headerV7 "{\"id\":\""
#define  headerV8 "\",\"datetime\":\""  //hh:mm:ss:DD:MM:YYYY
#define  headerV9 "\",\"valuetype\":\""// maxvaleur
#define  headerV10 "\",\"value\":\"" //accel_123-2
#define  headerV11 "\"},"
/*It is for close the object to the Time Value Identification (TVI)*/
#define  headerVF "]}}                  "
#define  dep "depart \r"


/*Set the GSM*/
#define ATbd          "AT+IPR=9600"
#define G1_APN      "AT+SAPBR=3,1,\"APN\",\"tim.br\""
//#define V_APN       "\"APN\",\"tim.br\""
#define G2_USER     "AT+SAPBR=3,1,\"USER\",\"tim\""
//#define V_USER      "\"USER\",\"tim\""
#define G3_Password "AT+SAPBR=3,1,\"PWD\",\"tim\""
//#define V_PWD       "\"PWD\",\"tim\""
#define G4_bearer1  "AT+SAPBR=1,1"
#define G5_HTTP     "AT+HTTPINIT"
#define G6_ParaHTTP "AT+HTTPPARA=\"CID\",1"
#define G7_ParaHTTP "AT+HTTPPARA=\"URL\",\"cloudiaproject.org/data/\""
#define G7_2ParaHTTP "\"cloudiaproject.org/data/\""
#define G8_ParaHTTP "AT+HTTPPARA=\"CONTENT\",\"application/x-www-form-urlencoded\""
#define G8_2ParaHTTP "\"application/"
#define G8_3ParaHTTP "x-www-form-urlencoded\""
/*GET*/
#define G9_GET      "AT+HTTPACTION=0"
#define G10_GET     "AT+HTTPREAD"
/*Post*/
#define G11_POST    "AT+HTTPDATA="//x,y x=strlen and y=time of transmition
#define G12_POST    "AT+HTTPACTION=1"
/*Close GSM*/
#define G13_Close   "AT+HTTPTERM"
/**
 *
 * @brief Fonction contenant les configurations de depart des differents registres
 *
 */
void commun_initialisationRegistres(void);
/**
 * @brief Fonction utilitaire pour permettre d'avoir des delais > 500 msec
 * @param ms valeur en ms du delai voulu (precision au 10 msec)
 */
void commun_delaiMS(unsigned int ms);

void initialisation_ActiverTimer0(void);

int readingTime = 0;

bool VPH = false;
bool VFC = false;
bool Vq = false;
bool Vy = false;
bool Vg = false;
bool Vu = false;
bool Vo = false;

bool VPOST = false;
bool VpowerSensor = true;
bool howtimeIsIt = false;
bool takeTime = false;
bool timeRE = true;
//bool VTest2 = true;

int valuTestCheckSum = 0;
int mcStartGSM = 0;
int mcPostGSM = 0;


int nbFramePH = 0;
int nbFrameDO = 0;
int nbFrameEC = 0 ;
int nbFrameTDS = 0 ;
int compteurTimer0 = 0;
int Ctime = 0;
int virguleRecu=0;
unsigned char CtoS[2];
unsigned char dataToSend[1500];
unsigned char timeReceived[30];
unsigned char timetoPost[27];
unsigned char timetoPost2[10];

struct FrameReceived
{
    unsigned char receivedFramePH[5];
    int receivedDataTimePH;

    unsigned char receivedFrameDO[5];
    int receivedDataTimeDO;

    unsigned char receivedFrameEC[5];
    int receivedDataTimeEC;

    unsigned char receivedFrameTDS[5];
    int receivedDataTimeTDS;
}my_FrameReceived[50];



 
#endif