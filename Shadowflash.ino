// - - - - -
// DmxSerial - A hardware supported interface to DMX.
// DmxSerialSend.ino: Sample DMX application for sending 3 DMX values:
// address 1 (red) -> also available on PWM Port 9
// address 2 (green) -> also available on PWM Port 6
// address 3 (blue) -> also available on PWM Port 5
// 
// Copyright (c) 2011 by Matthias Hertel, http://www.mathertel.de
// This work is licensed under a BSD style license. See http://www.mathertel.de/License.aspx
// 
// Documentation and samples are available at http://www.mathertel.de/Arduino
// 25.07.2011 creation of the DmxSerial library.
// 10.09.2011 fully control the serial hardware register
//            without using the Arduino Serial (HardwareSerial) class to avoid ISR implementation conflicts.
// 01.12.2011 include file and extension changed to work with the Arduino 1.0 environment
// - - - - -

#include <DMXSerial.h>
#include <Button.h>

//create a Button object at pin 12
/*
|| Wiring:
|| GND -----/ ------ pin 9
*/

Button button = Button(9,PULLUP);

int var = 0;
int i = 1;

void setup() {
  
  DMXSerial.init(DMXController);
  pinMode(3,OUTPUT); //debug to led 13
  
} // setup

// fade LED continuously  
void loop() {
  
    
    
    if(var >= 255){
      i = -3;
    } 
    
    if(var <= 0){
      i = 3;
    }
    
    var = var + i;
 
delay(30);
 
 // SHADOWFLASH 
 
 if(button.isPressed()){
	var = 0;
        DMXSerial.write(1, 255);
        digitalWrite(13,HIGH);
  }else{
	//
        DMXSerial.write(1, 0);
        digitalWrite(13,LOW);
  } 
   
  analogWrite(3, var);  
  
} // loop
