#include "Arm.h"


Arm::Arm() {}
Arm::~Arm() {}

void Arm::begin() {
    _frontArmServo.begin(FRONT_ARM_SERVO_PIN, _frontArmMinAngle, _frontArmMaxAngle);
    _backArmServo.begin(BACK_ARM_SERVO_PIN, _backArmMinAngle, _backArmMaxAngle);
    _myClaw.begin();
}

void Arm::_retract() {

    _myClaw.open();
    _frontArmServo.moveToPosition(_FrontArmPosition.RETRACTED_LOW);
    _backArmServo.moveToPosition(_BackArmPosition.RETRACTED_LOW);
    delay(500);
}

void Arm::_grab() {

    _frontArmServo.moveToPosition(_FrontArmPosition.GRAB_RETRACTED_LOW);
    _backArmServo.moveToPosition(_BackArmPosition.GRAB_RETRACTED_LOW);
    delay(500);
    _myClaw.close();
    delay(500);
    _frontArmServo.moveToPosition(_FrontArmPosition.GRAB_RETRACTED_HIGH);
    _backArmServo.moveToPosition(_BackArmPosition.GRAB_RETRACTED_HIGH);
    delay(500);
}

void Arm::_raise() {

    _frontArmServo.moveToPosition(_FrontArmPosition.RAISED);
    _backArmServo.moveToPosition(_BackArmPosition.RAISED);
    delay(500);
}

void Arm::_lower() {

    _frontArmServo.moveToPosition(_FrontArmPosition.GRAB_RETRACTED_HIGH);
    _backArmServo.moveToPosition(_BackArmPosition.GRAB_RETRACTED_HIGH);
    delay(500);
}

void Arm::_drop() {

    _frontArmServo.moveToPosition(_FrontArmPosition.GRAB_RETRACTED_LOW);
    _backArmServo.moveToPosition(_BackArmPosition.GRAB_RETRACTED_LOW);
    delay(500);
    _myClaw.open();
    delay(500);
    _frontArmServo.moveToPosition(_FrontArmPosition.RETRACTED_LOW);
    _backArmServo.moveToPosition(_BackArmPosition.RETRACTED_LOW);
    delay(500);
}
