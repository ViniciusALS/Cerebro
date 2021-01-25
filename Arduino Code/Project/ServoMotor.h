#ifndef SERVOMOTOR_H
#define SERVOMOTOR_H

#include <Arduino.h>
#include <Servo.h>

class ServoMotor {

    public:
        ServoMotor();
        ~ServoMotor();
        
        void init(int pin, int minAngle, int maxAngle);
        void moveToPosition(byte value);

    private:
        Servo _myServo;
        const int _servoDelaySpeed = 10;
        int _previousAngle;
        int _angle;
        int _minAngle, _maxAngle;
};

#endif
