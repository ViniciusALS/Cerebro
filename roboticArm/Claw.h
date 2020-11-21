#ifndef CLAW_H
#define CLAW_H

#include "PINS.h"
#include "ServoMotor.h"


class Claw {

    public:
        Claw();
        ~Claw();

        void begin();

        void open();
        void close();

    private:
        ServoMotor _clawServo;

        const int clawMinAngle = 70;
        const int clawMaxAngle = 180;
};

#endif
