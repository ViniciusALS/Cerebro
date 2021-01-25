#include "Base.h"

Base::Base() {}
Base::~Base() {}

void Base::begin() {
    _baseServo.begin(BASE_SERVO_PIN, _baseMinAngle, _baseMaxAngle); 
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
