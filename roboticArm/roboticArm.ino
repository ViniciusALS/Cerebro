#include "Arm.h"

 
// Instanciate parts of robotic arm
Arm myArm;


void setup() {

    if (true) {
        Serial.begin(9600);
    }

    myArm.begin();
}

void loop() {

    bottomPot.read();
    bottomServo.moveToPosition(bottomPot.getValue());

    myArm.retract();
    delay(1000);
    myArm.grab();
    delay(1000);
    myArm.raise();
    delay(1000);
    myArm.lower();
    delay(1000);
    myArm.drop();





    if (Serial.available <= 0){
        myArm.wait();
    }

    delay(1000);
}
