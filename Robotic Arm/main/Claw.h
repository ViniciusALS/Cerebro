#ifndef CLAW_H
#define CLAW_H

#include "PINS.h"
#include "ServoMotor.h"

//#include "Arduino.h"

class Claw {

    
    const int clawMinAngle = 70;
    const int clawMaxAngle = 180;

    private:
        bool _isOpen;
        ServoMotor _clawServo;
    
    public:
        Claw(){
            _clawServo.begin(CLAW_SERVO_PIN, clawMinAngle, clawMaxAngle);
        }
        ~Claw(){}

        void open(){
            _clawServo.moveToPosition(clawMaxAngle);
        }

        void close(){
            _clawServo.moveToPosition(clawMinAngle);
        }
};

#endif
