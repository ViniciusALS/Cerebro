#include "Claw.h"

Claw::Claw() {}
Claw::~Claw() {}

void Claw::init() {
    // Sets component initial value
    _clawServo.init(CLAW_SERVO_PIN, _clawMinAngle, _clawMaxAngle);
}

void Claw::open() {
    _clawServo.moveToPosition(255);
}

void Claw::close() {
    _clawServo.moveToPosition(0);
}
