#ifndef SERVOMOTOR_H
#define SERVOMOTOR_H

#include <Arduino.h>
#include <Servo.h>

class ServoMotor {

    public:
        ServoMotor();
        ~ServoMotor();
        
        void begin(int pin, int minAngle, int maxAngle);
        void moveToPosition(byte value);

    private:
        Servo _myServo;
        int _angle;
        int _minAngle, _maxAngle;
};

#endif
