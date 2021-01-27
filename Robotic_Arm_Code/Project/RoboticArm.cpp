#include "RoboticArm.h"

RoboticArm::RoboticArm() {}
RoboticArm::~RoboticArm() {}

void RoboticArm::init() {
    // Sets components initial values
    _myArm.init();
    _myBase.init();
}

void RoboticArm::movementChoice(int choice){

	switch(choice){
		case 1:
			_myBase.turnLeft();
			break;

		case 2:
			_myBase.turnRight();
			break;

		case 3:
			_myArm.toggle();
			break;

		default:		// Awaits for another command
			return;
	}    
}
