#ifndef POTENTIOMETER_H
#define POTENTIOMETER_H

#include <Arduino.h>

class Potentiometer {

    public:
        Potentiometer(int pin);
        ~Potentiometer();

        void read();
        byte getValue();

    private:
        int _pin;
        int _potentiometerValue;
        byte _value;
};

#endif
