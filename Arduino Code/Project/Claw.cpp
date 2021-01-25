#include "Claw.h"

Claw::Claw() {}
Claw::~Claw() {}

void Claw::begin() {
    // Sets component initial value
    _clawServo.begin(CLAW_SERVO_PIN, _clawMinAngle, _clawMaxAngle);
}

void Claw::open() {
    _clawServo.moveToPosition(255);
}

void Claw::close() {
    _clawServo.moveToPosition(0);
}
