/*
 Run jumpers from GSM shield pin 2 to Mega 19, and shield 3 to Mega 18
 Ensure that there is NOT a connection from shield pins RX and TX to anywhere. 
 Ensure that the VCC pin of each cicruit is connected to the Arduino's 5V.
 Ensure that the GND pin of each circuit is connected to the Arduino's GND.
 PH: TX pin is connected to pin 10 of the arduino, RX pin is connected to pin 11 of the arduino.
 Conductivity: TX pin is connected to pin 15 of the arduino, RX pin is connected to pin 14 of the arduino.
 D.O.: TX pin is connected to pin 17 of the arduino, RX pin is connected to pin 16 of the arduino.
 Temperature sensor DS1822, require the data cable to be connected to pin 4 of the arduino and with a 4.7k resistor to the 5V.
 Don't forget to connect the GND cable to the GND of the Arduino and the VCC to the 5V of the Arduino.
 */

#include <OneWire.h>                                     //Library for temperature probe
#include <DallasTemperature.h>                           //Library for temperature probe
#include <SoftwareSerial.h>                              //Library to add a virtual serial port
#include <EEPROM.h>                                      //Library for the EEPROM memory
#define ONE_WIRE_BUS 4                                   //Define the pin for temperature data
#define rxpin 10                                         //Define the RX pin, for the virtual serial port
#define txpin 11                                         //Define the TX pin, for the virtual serial port
SoftwareSerial myserial(rxpin, txpin);                   //Creating a virtual port named myserial

String sonde1 = "";                                      //(Conductivity) String where the data is saved    
String sonde2 = "";                                      //(D.O.) String where the data is saved    
String sonde3 = "";                                      //(pH) String where the data is saved
float sonde4;                                            //(Temp) Float where the data is saved
const String comp  =  "--";                              //String where we verify conductivity error
const String name = "Sherbrooke";                        //String where the name of the sensor is saved
const String latitude = "45.410412";                     //String where the latitude coordinate is saved
const String longitude = "-71.885973";                   //String where the longitude coordinate is saved
const int adresse = 200;                                 //Define which byte to use for EEPROM (0 1 2 3 bytes are used)
unsigned long serie = 0;                                 //Unsigned long where the data is saved for the number of SMS
const char mobilenumber[] = "21212";                     //Replace xxxxxxxx with the recipient's mobile number.


boolean sondeComplete1 = false;                          //Declaring 3 Boolean, which will be use as condition to avoid multiple request to each probe
boolean sondeComplete2 = false;  
boolean sondeComplete3 = false;  

OneWire oneWire(ONE_WIRE_BUS);                           //Setup a oneWire instance to communicate with any OneWire devices, on pin 4, defined earlier.  
DallasTemperature sensors(&oneWire);                     //Pass our oneWire reference to Dallas Temperature. 


void setup() 
{
  Serial1.begin(9600);                                   //Starting communication with gsm
  Serial3.begin(38400);                                  //Starting communication with the conductivity probe
  Serial2.begin(38400);                                  //Starting communication with the D.O. probe 
  myserial.begin(38400);                                 //Starting communication with the PH probe
  delay(35000);                                          //Delay required for gsm module to connect to the network  
  sensors.begin();                                       //Starting the temperature probe
  sonde1.reserve(30);                                    //Reserving bytes for data from conductivity probe
  sonde2.reserve(30);                                    //Reserving bytes for data from D.O. probe
  sonde3.reserve(30);                                    //Reserving bytes for data from PH probe
  Serial1.println("AT+CMGF=1");
  serie = EEPROM_readlong(adresse);

}

void loop()
{
  while (myserial.available())                           //Storing the data received from the PH in string sonde3 
  {   
    char inchar = (char)myserial.read();
    sonde3 += inchar;
    if (inchar == '\r')
    {
      sondeComplete3 = true;
    }        
  } 
  while (Serial3.available())                             //Storing the data received from the Conductivity in string sonde1
  {
    char inChar = (char)Serial3.read();
    sonde1 += inChar;
    if (inChar == '\r')
    {
      sondeComplete1 = true;
    }
  }
  while (Serial2.available())                             //Storing the data received from the D.O. in string sonde3  
  {
    char inChar = (char)Serial2.read();
    sonde2 += inChar;
    if (inChar == '\r')
    {
      sondeComplete2 = true;
    }
  }
  sensors.requestTemperatures();                         //Requesting the temperature from the sensor  
  delay(500); 
  sonde4 = sensors.getTempCByIndex(0);
  if (sondeComplete1)                                    //Verifying if the data from Conductivity is stored.  
  {
    if (sondeComplete2)                                  //Verifying if the data from D.O. is stored.
    {
      if (sondeComplete3)                                //Verifying if the data from PH is stored.
      { 
        serie++;                                         //Adding 1 to the number of SMS
        EEPROM_writelong(adresse, serie);                //Writing the new value in the EEPROM
        delay(300);
        Serial1.print("AT+CMGS=");                       //Command to set the phone number
        Serial1.write((byte)34);                         //ASCII equivalent of "
        Serial1.print(mobilenumber);
        Serial1.write((byte)34);                         //ASCII equivalent of "
        Serial1.println("");
        delay(300);                                      //give the module some thinking time
        Serial1.print("Id:");                            //Command to write data in the SMS
        Serial1.println(serie);                          
        Serial1.print("Name:");
        Serial1.println(name);
        Serial1.print("Lat:");
        Serial1.println(latitude);
        Serial1.print("Long:");
        Serial1.println(longitude);        
        Serial1.print("TempC:");
        Serial1.println(sonde4);     
        sonde1.trim(); 
        if (sonde1.substring(0,2) == "--"||(sonde1.indexOf(",")==sonde1.lastIndexOf(","))||sonde1.indexOf(",")==-1)               //Verification of the conductivity data
        { 
          Serial1.println("ConduS:check probe");  
          Serial1.println("PPM:check probe");
          Serial1.println("Salinity:check probe");          
        }
        else 
        {                  
          int virgule1=sonde1.indexOf(",",1);                                      //Separing the conductivity data in 3 part
          int virgule2=sonde1.indexOf(",",virgule1+1);
          Serial1.print("ConduS:");
          Serial1.println(sonde1.substring(0,virgule1)); 
          Serial1.print("PPM:");
          Serial1.println(sonde1.substring(virgule1+1,virgule2));
          Serial1.print("Salinity:");
          Serial1.println(sonde1.substring(virgule2+1,sonde1.length()));                 
        }        
        delay(300);
        sonde1 = "";
        sondeComplete1 = false;
        sonde2.trim();
        Serial1.print("D.O.mgL:");
        Serial1.println(sonde2);                           //Command to insert the D.O. data in the SMS
        delay(300);
        sonde2 = "";
        sondeComplete2 = false; 
        sonde3.trim(); 
        Serial1.print("PH:");
        Serial1.println(sonde3);                           //Command to insert the PH data in the SMS
        delay(300);
        sonde3 = "";  
        sondeComplete3 = false; 
        Serial1.write((byte)26);                         //ASCII equivalent of Ctrl-Z
        delay(15000);                                    //The SMS module needs time to return to OK status
      }
      else
      {
        myserial.print(sonde4);      //Sending the temperature to the PH sensor
        myserial.print("\r");
        delay(1500);                                     //Give the sensor some thinking time
      }
    }
    else 
    {
      Serial2.print(sonde4);         //Sending the temperature to the D.O. sensor
      Serial2.print("\r");
      delay(1500);                                       //Give the sensor some thinking time
    } 
  }
  else  
  {
    Serial3.print(sonde4);           //Sending the temperature to the PH sensor
    Serial3.print("\r");
    delay(1500);                                         //Give the sensor some thinking time
  }
}        


