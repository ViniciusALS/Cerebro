#ifndef ARM_H
#define ARM_H

#include "PINS.h"
#include "ServoMotor.h"
#include "Claw.h"


class Arm {

    public:
        Arm();  
        ~Arm();

        void init();
        void toggle();
       
    private:
        
        ServoMotor _frontArmServo;
        ServoMotor _backArmServo;
        Claw _myClaw;

        bool isGrabbing;

        
        const int _frontArmMinAngle = 0;
        const int _frontArmMaxAngle = 150;

        const int _backArmMinAngle = 0;
        const int _backArmMaxAngle = 170;

        struct _FrontArmPosition { 
            const int RETRACTED = 35;
            const int REACHING = 70;
            const int RAISED = 255;
        } _FrontArmPosition;
            
        struct _BackArmPosition { 
            const int RETRACTED = 212;
            const int REACHING = 220;
            const int RAISED = 135;
        } _BackArmPosition;
};

#endif
