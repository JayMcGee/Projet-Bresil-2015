/* 
 * File:   bufferint.h
 * Author: nitro
 *
 * Created on 29 mai 2014, 09:43
 */

#ifndef BUFFERINT_H
#define	BUFFERINT_H


#include "commun.h"

bool VSOH = false;
bool VSOok= false;
bool VtrameReceived = false;

bool VO = false;
bool VOK = true;
bool VKA = false;

bool VERROR_E = false;
bool VERROR_R= false;
bool VERROR_O = false;

bool Vstarte = false;
bool Vstarta = false;
bool Vstartd = false;
bool VstartReady = false;

int nbOfChar = 0;
int idReceived = 0;
int checksumtoChesck = 0 ;
int dataLenghtoReceived = 0;
int ChecksumReceived = 0;

int buffer1Read = 0 ;
int buffer1Write = 0;
int buffer2Read = 0 ;
int buffer2Write = 0;
unsigned char bufferint1[128];
unsigned char bufferint2[128];

unsigned char trameToParse[30];





void readbuffer();
void executeBuffer();

#endif	/* BUFFERINT_H */

