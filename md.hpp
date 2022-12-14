#ifndef _MD_HPP_
#define _MD_HPP_

#include "mbed.h"
#include "math.h"

class MD
{
    public:
    MD(PinName pwm_pin, PinName dir_pin)
    : pwm(pwm_pin), dir(dir_pin)
    {
        pwm.period(0.00005);
    };

    void drive(float power)
    {   
        if(power < 0){
            dir = 0;
        }else{
            dir = 1;
        }
        pwm = abs(power);
    }

    private:
        PwmOut pwm;
        DigitalOut dir;
};



#endif