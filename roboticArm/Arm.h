#ifndef ARM_H
#define ARM_H

#include "PINS.h"
#include "ServoMotor.h"
#include "Claw.h"


class Arm {

    public:
        Arm();  
        ~Arm();

        void begin();
       

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


        void _retract();        
        void _grab();        
        void _raise();        
        void _lower();
        void _drop();
};

#endif
