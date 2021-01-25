#include "Base.h"

Base::Base() {}
Base::~Base() {}

void Base::init() {
    // Sets components initial values
    _baseServo.init(BASE_SERVO_PIN, _baseMinAngle, _baseMaxAngle); 

    // Set base initial position 
    _baseServo.moveToPosition(_basePosition);
}

void Base::turnLeft() {
    _basePosition -= _positionIncrement;
    _baseServo.moveToPosition(_basePosition);
}

void Base::turnRight() {
    _basePosition += _positionIncrement;
    _baseServo.moveToPosition(_basePosition);
}
