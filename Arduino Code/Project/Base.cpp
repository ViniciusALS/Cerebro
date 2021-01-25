#include "Base.h"

Base::Base() {}
Base::~Base() {}

void Base::init() {
    // Sets components initial values
    _baseServo.init(BASE_SERVO_PIN, _baseMinAngle, _baseMaxAngle); 

    // Set base initial position 
    _baseServo.moveToPosition(_basePosition);
}

void Base::turnLeft(int increment = 10) {
    _basePosition -= increment;
    _baseServo.moveToPosition(_basePosition);
}

void Base::turnRight(int increment = 10) {
    _basePosition += increment;
    _baseServo.moveToPosition(_basePosition);
}
