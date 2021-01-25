#ifndef BASE_H
#define BASE_H

#include "PINS.h"
#include "ServoMotor.h"


class Base {

    public:
        Base();
        ~Base();

        void begin();

        void turnLeft();
        void turnRight();

    private:
        ServoMotor _baseServo;

        const int positionIncrement = 10;

        int _baseStartPosition = 90;
//        const int clawMinAngle = 70;
//        const int clawMaxAngle = 180;
};

#endif
