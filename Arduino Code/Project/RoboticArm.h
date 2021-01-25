#ifndef ROBOTIC_ARM_H
#define ROBOTIC_ARM_H

#include "Arm.h"
#include "Base.h"


class RoboticArm {

    public:
        RoboticArm();  
        ~RoboticArm();

        void begin();
        void movementChoice(int choice);
       

    private:
        
        Arm _myArm;
        Base _myBase;
};

#endif
