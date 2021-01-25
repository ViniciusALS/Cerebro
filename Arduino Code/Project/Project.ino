#include "Arduino.h"
#include "RoboticArm.h"

 
int choice;

// Instantiates robotic arm
RoboticArm myRoboticArm;

void setup() {
    Serial.begin(9600);

    // Initialize values for robotic arm components
    myRoboticArm.begin();
}

void loop() {

    while (Serial.available()) {
        // Receives either the integer 0, 1, 2, or 3 from serial connection to signify "await", "turnLeft", "turnRight", or "toggle" respectively.
        choice = Serial.parseInt();

        myRoboticArm.movementChoice(choice);

        Serial.print("You entered: ");
        Serial.println(choice);
    }
}
