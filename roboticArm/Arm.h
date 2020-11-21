#ifndef ARM_H
#define ARM_H

#include "PINS.h"
#include "ServoMotor.h"
#include "Claw.h"


class Arm {

    public:
        Arm() {}
        
        ~Arm() {}

        void begin() {
            _frontArmServo.begin(FRONT_ARM_SERVO_PIN, frontArmMinAngle, frontArmMaxAngle);
            _backArmServo.begin(BACK_ARM_SERVO_PIN, backArmMinAngle, backArmMaxAngle);
            _myClaw.begin();
        }

        void retract(){
            
            _myClaw.open();
            _frontArmServo.moveToPosition(_FrontArmPosition.RETRACTED_LOW);
            _backArmServo.moveToPosition(_BackArmPosition.RETRACTED_LOW);
            delay(500);
        }
        
        void grab(){

            _frontArmServo.moveToPosition(_FrontArmPosition.GRAB_RETRACTED_LOW);
            _backArmServo.moveToPosition(_BackArmPosition.GRAB_RETRACTED_LOW);
            delay(500);
            _myClaw.close();
            delay(500);
            _frontArmServo.moveToPosition(_FrontArmPosition.GRAB_RETRACTED_HIGH);
            _backArmServo.moveToPosition(_BackArmPosition.GRAB_RETRACTED_HIGH);
            delay(500);
        }
        
        void raise(){

            _frontArmServo.moveToPosition(_FrontArmPosition.RAISED);
            _backArmServo.moveToPosition(_BackArmPosition.RAISED);   
            delay(500);
        }
        
        void lower(){

            _frontArmServo.moveToPosition(_FrontArmPosition.GRAB_RETRACTED_HIGH);
            _backArmServo.moveToPosition(_BackArmPosition.GRAB_RETRACTED_HIGH);   
            delay(500);
        }
        
        void drop(){

            _frontArmServo.moveToPosition(_FrontArmPosition.GRAB_RETRACTED_LOW);
            _backArmServo.moveToPosition(_BackArmPosition.GRAB_RETRACTED_LOW);
            delay(500);
            _myClaw.open();
            delay(500);
            _frontArmServo.moveToPosition(_FrontArmPosition.RETRACTED_LOW);
            _backArmServo.moveToPosition(_BackArmPosition.RETRACTED_LOW);
            delay(500);
        }
        

    private:
        
        ServoMotor _frontArmServo;
        ServoMotor _backArmServo;

        Claw _myClaw;
        
        const int frontArmMinAngle = 0;
        const int frontArmMaxAngle = 150;

        const int backArmMinAngle = 0;
        const int backArmMaxAngle = 170;

        struct _FrontArmPosition { 
            const int RETRACTED_LOW = 35;
            const int GRAB_RETRACTED_LOW = 70;
            const int GRAB_RETRACTED_HIGH = 95;
            const int RAISED = 255;
        } _FrontArmPosition;
            
        struct _BackArmPosition { 
            const int RETRACTED_LOW = 212;
            const int GRAB_RETRACTED_LOW = 220;
            const int GRAB_RETRACTED_HIGH = 200;
            const int RAISED = 135;
        } _BackArmPosition;
};

#endif
