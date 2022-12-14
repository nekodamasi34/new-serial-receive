#include "mbed.h"
#include <SerialBridge.hpp>
#include <MbedHardwareSerial.hpp>
#include <Controller.hpp>
#include <fstream>


SerialDev *dev = new MbedHardwareSerial(new BufferedSerial(PC_10, PC_11, 115200));
SerialBridge serial(dev);

Controller msc;

PwmOut pwm1(D14);
PwmOut pwm2(D15);
DigitalOut jo1(D12);
DigitalOut jo2(D13);

float m1;
float m2;
float x;
float y;



int main()
{
    serial.add_frame(0, &msc);
    pwm1.period(0.00005);
    pwm2.period(0.00005);

    while (1) {

        serial.update();
        if(msc.was_updated())
        {
            printf("x = %f y = %f\n\r",msc.data.x,msc.data.y);

            x = msc.data.x;
            y = msc.data.y;

            m1 = ( 0.7 * y ) + ( 0.5 * x );
            m2 = ( 0.7 * y ) - ( 0.5 * x );
            

            if(m1 < 0){
                jo1 = 0;
                m1 *= -1;
            }else if(m1 > 0){
                jo1 = 1;
            }

            if(m2 < 0){
                jo2 = 1;
                m2 *= -1;
            }else if(m2 > 0){
                jo2 = 0;
            }

            pwm1 = m1;
            pwm2 = m2;
        }
    }
}

