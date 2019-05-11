#include <Stepper.h>

const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution
// for your motor

// initialize the stepper library on pins 8 through 11:
Stepper myStepperRight(stepsPerRevolution, 8, 9, 10, 11);
Stepper myStepperLeft(stepsPerRevolution, 2, 3, 4, 5);
void setup() {
  // set the speed at 60 rpm:
  myStepperRight.setSpeed(140);
  myStepperLeft.setSpeed(140);
  // initialize the serial port:
  Serial.begin(9600);
}

void loop() {
  // step one revolution  in one direction:
  if(analogRead(A0)<100)
      myStepperRight.step (1);
  else if(analogRead(A0)>923)
      myStepperLeft.step (-1);
  else {
      myStepperRight.step (1);
      myStepperRight.step (-1);
      };
 }
