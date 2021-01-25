#include "ServoMotor.h"

ServoMotor::ServoMotor(){}
ServoMotor::~ServoMotor(){}
        
void ServoMotor::init(int pin, int minAngle, int maxAngle) {
    _myServo.attach(pin); 
    
    if (minAngle < 0)
        _minAngle = 0;
    else
        _minAngle = minAngle;

    if (maxAngle > 180)
        _maxAngle = 180;
    else
        _maxAngle = maxAngle;
}

void ServoMotor::moveToPosition(byte value){
    _angle = map(value, 0, 255, _minAngle, _maxAngle);

    if (_angle >= _previousAngle){
        for (int i = _previousAngle+1; i <= _angle; i++){
            _myServo.write(i);
            delay(_servoDelaySpeed);
        }
    }
    else {
        for (int i = _previousAngle-1; i >= _angle; i--){
            _myServo.write(i);
            delay(_servoDelaySpeed);
        }
    }
    
    _previousAngle = _angle;
}
