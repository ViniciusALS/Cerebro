#include "PINS.h"
#include "ServoMotor.h"
#include "Potentiometer.h"
#include "Claw.h"

// Instanciate potentiometers
Potentiometer clawPot(CLAW_POT_PIN);
Potentiometer frontArmPot(FRONT_ARM_POT_PIN);
Potentiometer backArmPot(BACK_ARM_POT_PIN);
Potentiometer bottomPot(BOTTOM_POT_PIN);

// Instanciate parts of robotic arm
Claw myClaw;


void setup() {

    if (true){
        Serial.begin(9600);
    }

    myClaw.begin();
}

void loop() {

    // Testing claw
    clawPot.read();
    if (clawPot.getValue() > 125){ 
        myClaw.open();
    }
    else{
        myClaw.close();
    }
    
    Serial.println(clawPot.getValue());

    delay(1000);
}
