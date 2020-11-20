#include "PINS.h"
#include "ServoMotor.h"
#include "Potentiometer.h"
#include "Claw.h"

// Instanciate servo motors
//ServoMotor clawServo;
ServoMotor frontArmServo;
ServoMotor backArmServo;
ServoMotor bottomServo;

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
    
    // Attach servo motors to Arduino pins and set min and max angle for motor
//    clawServo.begin(CLAW_SERVO_PIN, 70, 180);
    frontArmServo.begin(FRONT_ARM_SERVO_PIN, 0, 150);
    backArmServo.begin(BACK_ARM_SERVO_PIN, 0, 180);
    bottomServo.begin(BOTTOM_SERVO_PIN, 0, 180);
}

void loop() {

//    clawPot.read();
//    clawServo.moveToPosition(clawPot.getValue());

    myClaw.open();

    frontArmPot.read();
    frontArmServo.moveToPosition(frontArmPot.getValue());

    backArmPot.read();
    backArmServo.moveToPosition(backArmPot.getValue());

    bottomPot.read();
    bottomServo.moveToPosition(bottomPot.getValue());
    
    Serial.println();

    delay(500);
//    myClaw.close();
    delay(500);
}
