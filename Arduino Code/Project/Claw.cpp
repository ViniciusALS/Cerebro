#include "Claw.h"

Claw::Claw() {}
Claw::~Claw() {}

void Claw::begin() {
    _clawServo.begin(CLAW_SERVO_PIN, _clawMinAngle, _clawMaxAngle);
}

void Claw::open() {
    _clawServo.moveToPosition(255);
}

void Claw::close() {
    _clawServo.moveToPosition(0);
}
