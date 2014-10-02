/* 
 * File:   usart.h
 * Author: nitro
 *
 * Created on 29 mai 2014, 09:52
 */

#ifndef USART_H
#define	USART_H


#define SOH 0x73
#define SOL 0x7F
#define PH 0x10
#define DO 0x11
#define EC 0x12
#define TDS 0x13
#define ResetTimer 0x20
#define CommandeManuel 0x21
#define PH_lenghINT 6
#define DO_lenghINT 6
#define EC_lenghINT 7
#define TDS_lenghINT 6
#define ResetTimer_lengh 3
#define CommandeManuel_lengh 3
#define emptyINT 0


#include "commun.h"

void send_cr();
void send_char1USART(char text1);
void send_char2USART(char text2);
void writeUsart2(char *datas);
void writeUsart1(char *datas1);
void writeUsart1Trame(char *datas2,unsigned int datatime,int id);

#endif	/* USART_H */

