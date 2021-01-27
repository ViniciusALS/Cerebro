#include "RoboticArm.h"

 
int choice;

RoboticArm myRoboticArm;

void setup() {
    Serial.begin(9600);
 
    // Sets components initial values
    myRoboticArm.init();
}

void loop() {

    if (Serial.available()) {
        // Receives either the integer 0, 1, 2, or 3 from serial connection
        // to signify "await", "turnLeft", "turnRight", or "toggle" respectively.
        choice = Serial.parseInt();

        myRoboticArm.movementChoice(choice);
    }
}
