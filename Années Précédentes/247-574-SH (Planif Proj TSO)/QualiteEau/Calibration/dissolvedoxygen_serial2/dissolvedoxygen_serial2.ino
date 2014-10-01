
/*
Calibration Programme (Dissolved Oxygen serial 2)
Open TOOLS > serial monitor, set the serial monitor to the correct serial port and set the baud rate to 38400.
Remember, select carriage return from the drop down menu next to the baud rate selection; not "both NL & CR".

Calibration should be done the first time the stamp is used. Dip your probe in water, just to get it wet.
Let it sit in the air for 5 minutes. Do not leave it in water, it must calibrate to the oxygen level in the
surrounding atmosphere. After 5 minutes, transmit the “x” command to calibrate.

After transmitting the 'X' command both LEDs will slowly blink twice.
Take your D.O. probe and wave it in the air. The D.O. Circuit will need
to read the atmospheric oxygen partial pressure.

After 1 to 2 seconds the D.O. Circuit will then transmit: “calibration set: nn”
Where nn is the atmospheric oxygen partial pressure. D.O. Circuit will
then return to standby mode. The calibration data will be stored in eeprom
and will be used as the bases for all future readings. 
This data will not be lost due to power failure.
*/



String inputstring = "";                                                       //a string to hold incoming data from the PC
String sensorstring = "";                                                      //a string to hold the data from the Atlas Scientific product
boolean input_stringcomplete = false;                                          //have we received all the data from the PC
boolean sensor_stringcomplete = false;                                         //have we received all the data from the Atlas Scientific product


  void setup(){                                                                //set up the hardware
     Serial.begin(38400);                                                      //set baud rate for the hardware serial port_0 to 38400
     Serial2.begin(38400);                                                     //set baud rate for software serial port_3 to 38400
     inputstring.reserve(5);                                                   //set aside some bytes for receiving data from the PC
     sensorstring.reserve(30);                                                 //set aside some bytes for receiving data from Atlas Scientific product
     }
 
 
 
   void serialEvent() {                                                         //if the hardware serial port_0 receives a char              
               char inchar = (char)Serial.read();                               //get the char we just received
               inputstring += inchar;                                           //add it to the inputString
               if(inchar == '\r') {input_stringcomplete = true;}                //if the incoming character is a <CR>, set the flag
              }  


  void serialEvent2(){                                                         //if the hardware serial port_3 receives a char 
              char inchar = (char)Serial2.read();                              //get the char we just received
              sensorstring += inchar;                                          //add it to the inputString
              if(inchar == '\r') {sensor_stringcomplete = true;}               //if the incoming character is a <CR>, set the flag 
             }



 void loop(){                                                                   //here we go....
     
  if (input_stringcomplete){                                                   //if a string from the PC has been recived in its entierty 
      Serial2.print(inputstring);                                              //send that string to the Atlas Scientific product
      inputstring = "";                                                        //clear the string:
      input_stringcomplete = false;                                            //reset the flage used to tell if we have recived a completed string from the PC
      }

 if (sensor_stringcomplete){                                                   //if a string from the Atlas Scientific product has been recived in its entierty 
      Serial.println(sensorstring);                                            //send that string to to the PC's serial monitor
      sensorstring = "";                                                       //clear the string:
      sensor_stringcomplete = false;                                           //reset the flage used to tell if we have recived a completed string from the Atlas Scientific product
      }
 }


