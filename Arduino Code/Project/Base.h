#ifndef BASE_H
#define BASE_H

#include "PINS.h"
#include "ServoMotor.h"


class Base {

    public:
        Base();
        ~Base();

        void begin();

        void turnLeft(int increment = 10);
        void turnRight(int increment = 10);

    private:
        ServoMotor _baseServo;

        const int _baseMinAngle = 5;
        const int _baseMaxAngle = 180;

        int _basePosition = 120;
};

#endif
