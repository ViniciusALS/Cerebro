#include "Arm.h"

 
String choice;

// Instanciate parts of robotic arm
Arm myArm;


void setup() {
    Serial.begin(9600);

    myArm.begin();
}

void loop() {

    while (Serial.available() > 0) {
        choice = Serial.readString();

        myArm.move(choice);

        Serial.print("You entered: ");
        Serial.println(choice);
    }

    if (Serial.available <= 0){
        myArm.wait();
    }

    delay(1000);
}
