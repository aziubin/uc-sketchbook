
/*
 Stepper Motor Control - one revolution

 This program drives a unipolar or bipolar stepper motor.
 The motor is attached to digital pins 8 - 11 of the Arduino.

 The motor should revolve one revolution in one direction, then
 one revolution in the other direction.


 Created 11 Mar. 2007
 Modified 30 Nov. 2009
 by Tom Igoe

 */
#include <Stepper.h>
const int stepsPerRevolution =520;  // change this to fit the number of steps per revolution
// for your motor

// initialize the stepper library on pins 8 through 11:
Stepper myStepper2(stepsPerRevolution, 2, 3, 4, 5);
Stepper myStepper1(stepsPerRevolution, 9, 10, 11, 12);

void setup() {
   // set the speed at 60 rpm:
   myStepper1.setSpeed(55);
   myStepper2.setSpeed(55);

   // initialize the serial port:
   //Serial.begin(112000);
}

void loop() {
//  int i;
//  for(i=0;i<=400;i++)
//  {
//   myStepper1.step(1);
//   myStepper2.step(-1);
//  }
 //   for(i=0;i<=400;i++)
 // {
 //  myStepper1.step(-1);
 //  myStepper2.step(-1);
 // }
int c = analogRead(A0);
    if(c<500) myStepper2.step(-1);
    else myStepper1.step(1);
    
  // step one revolution  in one direction:
//  Serial.println("clockwise");
//  myStepper1.step(stepsPerRevolution);
//  myStepper2.step(stepsPerRevolution);
//  delay(0);

  // step one revolution in the other direction:
//  Serial.println("counterclockwise");
//  myStepper1.step(-stepsPerRevolution);
//  myStepper2.step(-stepsPerRevolution);  
//  delay(0);
}
