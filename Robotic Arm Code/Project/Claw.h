#ifndef CLAW_H
#define CLAW_H

#include "PINS.h"
#include "ServoMotor.h"


class Claw {

    public:
        Claw();
        ~Claw();

        void init();

        void open();
        void close();

    private:
        ServoMotor _clawServo;

        const int _clawMinAngle = 70;
        const int _clawMaxAngle = 180;
};

#endif
