#include "RoboticArm.h"

RoboticArm::RoboticArm() {}
RoboticArm::~RoboticArm() {}

void RoboticArm::begin() {
    // Sets components initial values
    _myArm.begin();
    _myBase.begin();
}

void RoboticArm::movementChoice(int choice){

    // Awaits for another command
    if (choice == 0){
        return;
    }

    if (choice == 1){
        _myBase.turnLeft();
    }

    if (choice == 2){
        _myBase.turnRight();
    }

    if (choice == 3){
        _myArm.toggle();
    }       
}
