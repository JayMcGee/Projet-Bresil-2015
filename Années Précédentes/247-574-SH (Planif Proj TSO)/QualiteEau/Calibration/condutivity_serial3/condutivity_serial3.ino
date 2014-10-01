
/*
Calibration Programme (Conductivity serial 3)
Open TOOLS > serial monitor, set the serial monitor to the correct serial port and set the baud rate to 38400.
Remember, select carriage return from the drop down menu next to the baud rate selection; not "both NL & CR".

Step 1: Set probe type
Connect the E.C. probe to your E.C. Circuit through the BNC connector. The E.C.
Circuit needs to know what type of probe it is connected to; there are 3 possible
probe types to choose from.
K0.1
K1.0
K10.0
The E.C. Circuit will permanently change its configuration settings to the probe
type that has been specified. Anytime a new probe type is connected to the
stamp it must be configured to read from that probe.
The command to set the probe type is:
“P,1” for a K0.1 E.C probe
“P,2” for a K1.0 E.C probe
“P,3” for a K10.0 E.C probe
P,[1] [2] [3]
Informs the E.C. Circuit what type of probe it is connected to.
The E.C. Circuit is defaulted to probe type#2
K 0.1 = 11μs to 3,000μs

Step2: Dry Calibration
Do not put the probe in any liquid. You are going to calibrate your
E.C. Circuit for a dry condition. This is much like setting the TARE on a scale.

Z0 informs the E.C. Circuit to calibrate for dry probe.
The E.C. Circuit will respond: Dry Cal<CR>

Step 3: Calibrate the E.C. stamp for high side μs readings

Each E.C. probe type is calibrated against 2 different E.C. solutions. One E.C.
calibration solution is on the low side of the probes E.C. range and the other
calibration solution is on the high side

k0.1 = 220μs for low side, 3000μs for high side

Place the E.C. probe in the high side calibration solution.
Put your E.C. Circuit in continues mode by transmitting the “C” command.
Let the E.C. Circuit run in continues mode for 3-5 minutes. 
The readings will start to stabilize after 3-5 minutes.
Transmit high side calibration command (K0.1 3000μs) Command: Z30<CR>
The E.C. Circuit will respond: 3000 μs cal

Step 4: Calibrate the E.C. stamp for low side μs readings
K0.1 = 220μs
Place the E.C. probe in the low side calibration solution.(220)
Put your E.C. Circuit in continues mode by transmitting the “C” command.
Let the E.C. Circuit run in continues mode for 3-5 minutes. 
The readings will start to stabilize after 3-5 minutes.
Transmit high side calibration command (K0.1 220μs) Command: Z2<CR>
The E.C. Circuit will respond: 220 μs cal
*/



String inputstring = "";                                                       //a string to hold incoming data from the PC
String sensorstring = "";                                                      //a string to hold the data from the Atlas Scientific product
boolean input_stringcomplete = false;                                          //have we received all the data from the PC
boolean sensor_stringcomplete = false;                                         //have we received all the data from the Atlas Scientific product


  void setup(){                                                                //set up the hardware
     Serial.begin(38400);                                                      //set baud rate for the hardware serial port_0 to 38400
     Serial3.begin(38400);                                                     //set baud rate for software serial port_3 to 38400
     inputstring.reserve(5);                                                   //set aside some bytes for receiving data from the PC
     sensorstring.reserve(30);                                                 //set aside some bytes for receiving data from Atlas Scientific product
     }
 
 
 
   void serialEvent() {                                                         //if the hardware serial port_0 receives a char              
               char inchar = (char)Serial.read();                               //get the char we just received
               inputstring += inchar;                                           //add it to the inputString
               if(inchar == '\r') {input_stringcomplete = true;}                //if the incoming character is a <CR>, set the flag
              }  


  void serialEvent3(){                                                         //if the hardware serial port_3 receives a char 
              char inchar = (char)Serial3.read();                              //get the char we just received
              sensorstring += inchar;                                          //add it to the inputString
              if(inchar == '\r') {sensor_stringcomplete = true;}               //if the incoming character is a <CR>, set the flag 
             }



 void loop(){                                                                   //here we go....
     
  if (input_stringcomplete){                                                   //if a string from the PC has been recived in its entierty 
      Serial3.print(inputstring);                                              //send that string to the Atlas Scientific product
      inputstring = "";                                                        //clear the string:
      input_stringcomplete = false;                                            //reset the flage used to tell if we have recived a completed string from the PC
      }

 if (sensor_stringcomplete){                                                   //if a string from the Atlas Scientific product has been recived in its entierty 
      Serial.println(sensorstring);                                            //send that string to to the PC's serial monitor
      sensorstring = "";                                                       //clear the string:
      sensor_stringcomplete = false;                                           //reset the flage used to tell if we have recived a completed string from the Atlas Scientific product
      }
 }


