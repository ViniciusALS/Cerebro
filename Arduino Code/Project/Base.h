#ifndef BASE_H
#define BASE_H

#include "PINS.h"
#include "ServoMotor.h"


class Base {

    public:
        Base();
        ~Base();

        void init();

        void turnLeft();
        void turnRight();

    private:
        ServoMotor _baseServo;

        const int _baseMinAngle = 5;
        const int _baseMaxAngle = 180;

        const int _positionIncrement = 10;
        
        int _basePosition = 120;
};

#endif
