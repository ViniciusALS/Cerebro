#include "Arduino.h"
#include "Arm.h"
#include "Base.h"

 
String choice;

// Instanciates robotic arm
//Arm myArm;

Base myBase;

void setup() {
    Serial.begin(9600);

    // Initialize values for robotic arm components
    //myArm.begin();

    myBase.begin();
}

void loop() {

//    while (Serial.available()) {
//        choice = Serial.readString();
//
//        myArm.movementChoice(choice);
//
//        Serial.print("You entered: ");
//        Serial.println(choice);
//    }

//    if (Serial.available() <= 0){
//        myArm.movementChoice("await");
//    }

    delay(1000);
}
