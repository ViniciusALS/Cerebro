#include "Potentiometer.h"

Potentiometer::Potentiometer(int pin){
    _pin = pin;
}

Potentiometer::~Potentiometer(){}

void Potentiometer::read(){
    _potentiometerValue = analogRead(_pin);
    _value = map(_potentiometerValue, 0, 1023, 0, 255);
}

byte Potentiometer::getValue() {

    if (_value)
        return _value;
    else
        return 0;
}
