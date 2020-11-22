#include "PINS.h"
#include "ServoMotor.h"
#include "Potentiometer.h"
#include "Claw.h"
#include "Arm.h"

// Instanciate potentiometers
Potentiometer clawPot(CLAW_POT_PIN);
Potentiometer frontArmPot(FRONT_ARM_POT_PIN);
Potentiometer backArmPot(BACK_ARM_POT_PIN);
Potentiometer bottomPot(BOTTOM_POT_PIN);

// Instanciate parts of robotic arm
//Claw myClaw;
Arm myArm;

// Instanciate servos
ServoMotor bottomServo;


void setup() {

    if (true) {
        Serial.begin(9600);
    }

    myArm.begin();
//    bottomServo.begin(BOTTOM_SERVO_PIN, 0, 180);
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





//    Serial.println(clawPot.getValue());
//    Serial.println(frontArmPot.getValue());
//    Serial.println(backArmPot.getValue());
//    Serial.println(bottomPot.getValue());
    Serial.println();

    delay(1000);
}
