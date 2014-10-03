/*
Calibration Programme (PH SENSORS PIN 10-11)
Open TOOLS > serial monitor, set the serial monitor to the correct serial port and set the baud rate to 38400.
Remember, select carriage return from the drop down menu next to the baud rate selection; not "both NL & CR".
1. First place you pH probe in the yellow pH 7 calibration solution.
2. Instruct the stamp to go into continues mode.
3. Wait 1 to 2 minutes.
4. TX the S command. 
Your pH Circuit is now calibrated for pH7.
5. Rinse off pH probe, dry with paper towel.
6. Place pH probe in the red pH 4 calibration solution.
7. Wait 1 to 2 minutes (Circuit should still be in continues mode).
8. TX the F command.
Your pH stamp is now calibrated for pH4.
9. Rinse off pH probe, dry with paper towel.
10. Place pH probe in the blue pH 10 calibration solution.
11. Wait 1 to 2 minutes (Circuit should still be in continues mode).
12. TX the T command.
Your pH Circuit is now calibrated for pH10.
13. Transmit the E command.
14. The pH Circuit is now calibrated. The calibration data is stored in the EEPROM
and will be retained even if the stamp is powered off.

*/




#include <SoftwareSerial.h>                                                    //add the soft serial libray
#define rxpin 10                                                                //set the RX pin to pin 2
#define txpin 11                                                                //set the TX pin to pin 3


SoftwareSerial myserial(rxpin, txpin);                                         //enable the soft serial port


String inputstring = "";                                                       //a string to hold incoming data from the PC
String sensorstring = "";                                                      //a string to hold the data from the Atlas Scientific product
boolean input_stringcomplete = false;                                          //have we received all the data from the PC
boolean sensor_stringcomplete = false;                                         //have we received all the data from the Atlas Scientific product


  void setup(){                                                                //set up the hardware
     Serial.begin(38400);                                                      //set baud rate for the hardware serial port to 38400
     myserial.begin(38400);                                                    //set baud rate for software serial port to 38400
     inputstring.reserve(5);                                                   //set aside some bytes for receiving data from the PC
     sensorstring.reserve(30);                                                 //set aside some bytes for receiving data from Atlas Scientific product
     }
 
 
 
   void serialEvent() {                                                         //if the hardware serial port receives a char
               char inchar = (char)Serial.read();                               //get the char we just received
               inputstring += inchar;                                           //add it to the inputString
               if(inchar == '\r') {input_stringcomplete = true;}                //if the incoming character is a <CR>, set the flag
              }  
 
 
 
 void loop(){                                                                   //here we go....
     
  if (input_stringcomplete){                                                   //if a string from the PC has been recived in its entierty 
      myserial.print(inputstring);                                             //send that string to the Atlas Scientific product
      inputstring = "";                                                        //clear the string:
      input_stringcomplete = false;                                            //reset the flage used to tell if we have recived a completed string from the PC
      }
 

  while (myserial.available()) {                                               //while a char is holding in the serial buffer
         char inchar = (char)myserial.read();                                  //get the new char
         sensorstring += inchar;                                               //add it to the sensorString
         if (inchar == '\r') {sensor_stringcomplete = true;}                   //if the incoming character is a <CR>, set the flag
         }


   if (sensor_stringcomplete){                                                 //if a string from the Atlas Scientific product has been received in its entirety
       Serial.print(sensorstring);                                             //use the hardware serial port to send that data to the PC
       sensorstring = "";                                                      //clear the string:
       sensor_stringcomplete = false;                                          //reset the flag used to tell if we have received a completed string from the Atlas Scientific product
      }
}



