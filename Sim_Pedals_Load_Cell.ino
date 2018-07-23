
  
#include <HX711.h>
#include <Joystick.h>

  HX711 scale(0, 1);

  Joystick_ Joystick;

  
void setup() {

  pinMode(4, INPUT_PULLUP);      // Button Pins set to input with pull up risistors
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(16, INPUT_PULLUP);
  pinMode(14, INPUT_PULLUP);
  pinMode(15, INPUT_PULLUP);
  pinMode(18, INPUT_PULLUP);
  pinMode(19, INPUT_PULLUP);    
  
  pinMode(A2, INPUT);           // set potentiometer pins to input
  pinMode(A3, INPUT);            

  scale.set_scale(-10000);
  Joystick.begin(); 
}
 
  
void loop() {

Joystick.setButton(0, !digitalRead(4));       // turn on button if pin is connected to ground
Joystick.setButton(1, !digitalRead(5));
Joystick.setButton(2, !digitalRead(6));
Joystick.setButton(3, !digitalRead(7));
Joystick.setButton(4, !digitalRead(8));
Joystick.setButton(5, !digitalRead(9));
Joystick.setButton(6, !digitalRead(10));
Joystick.setButton(7, !digitalRead(16));
Joystick.setButton(8, !digitalRead(14));
Joystick.setButton(9, !digitalRead(15));
Joystick.setButton(10, !digitalRead(18));
Joystick.setButton(11, !digitalRead(19));

Joystick.setXAxis(analogRead(A2));              // analog read potentiometer 1 set x axis

Joystick.setYAxis(analogRead(A3));              // analog read potentiometer 1 set y axis

Joystick.setZAxis(abs(scale.get_units(1)));     // read load cell set z axis


}

