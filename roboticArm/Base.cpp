#include "Base.h"

Base::Base() {}
Base::~Base() {}

void Base::begin() {
    _baseServo.begin(BASE_SERVO_PIN, 0, 180);
    
//    _BaseServo.moveToPosition(this->_baseStartPosition);
}

void Base::turnLeft() {
    _baseServo.moveToPosition(255);
}

void Base::turnRight() {
    _baseServo.moveToPosition(0);
}
