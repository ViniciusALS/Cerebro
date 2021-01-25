#include "Arm.h"


Arm::Arm() {}
Arm::~Arm() {}

void Arm::init() {
    // Sets components initial values
    _frontArmServo.begin(FRONT_ARM_SERVO_PIN, _frontArmMinAngle, _frontArmMaxAngle);
    _backArmServo.begin(BACK_ARM_SERVO_PIN, _backArmMinAngle, _backArmMaxAngle);
    _myClaw.init();

    // Sets arm initial position
    _myClaw.open();
    _frontArmServo.moveToPosition(_FrontArmPosition.RETRACTED);
    _backArmServo.moveToPosition(_BackArmPosition.RETRACTED);

    // Sets arm initial state
    isGrabbing = false;
}

void Arm::toggle() {

    if (isGrabbing){
        // Move arm to release position
        
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
        // Move arm to grabbing position  
        
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
