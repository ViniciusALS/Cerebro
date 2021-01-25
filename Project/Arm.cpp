#include "Arm.h"


Arm::Arm() {}
Arm::~Arm() {}

void Arm::begin() {
    _frontArmServo.begin(FRONT_ARM_SERVO_PIN, _frontArmMinAngle, _frontArmMaxAngle);
    _backArmServo.begin(BACK_ARM_SERVO_PIN, _backArmMinAngle, _backArmMaxAngle);
    _myClaw.begin();

    _myClaw.open();
    _frontArmServo.moveToPosition(_FrontArmPosition.RETRACTED);
    _backArmServo.moveToPosition(_BackArmPosition.RETRACTED);
    isGrabbing = false;
}

void Arm::toggle() {

    Serial.println("toggling...");
    if (isGrabbing){
        _frontArmServo.moveToPosition(_FrontArmPosition.REACHING);
        _backArmServo.moveToPosition(_BackArmPosition.REACHING);
        delay(500);

        _myClaw.open();
        delay(500);

        _frontArmServo.moveToPosition(_FrontArmPosition.RETRACTED);
        _backArmServo.moveToPosition(_BackArmPosition.RETRACTED);
        
        isGrabbing = false;            
    }
    else {        
        _frontArmServo.moveToPosition(_FrontArmPosition.REACHING);
        _backArmServo.moveToPosition(_BackArmPosition.REACHING);
        delay(500);
        
        _myClaw.close();     
        delay(500);
        
        _frontArmServo.moveToPosition(_FrontArmPosition.RAISED);
        _backArmServo.moveToPosition(_BackArmPosition.RAISED);

        isGrabbing = true;
    }
}
