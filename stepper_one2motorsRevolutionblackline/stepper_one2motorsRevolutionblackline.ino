
#include <Stepper.h>
const int stepsPerRevolution =520;
Stepper myStepper2(stepsPerRevolution, 2, 3, 4, 5);
Stepper myStepper1(stepsPerRevolution, 9, 10, 11, 12);
void setup() {
   myStepper1.setSpeed(55);
   myStepper2.setSpeed(55);
}
void loop() {
    if(analogRead(A0)<500) myStepper2.step(-1);
    else myStepper1.step(1);
}
