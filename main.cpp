#include "mbed.h"
#include <SerialBridge.hpp>
#include <MbedHardwareSerial.hpp>
#include <Controller.hpp>
#include <fstream>
#include <md.hpp>


SerialDev *dev = new MbedHardwareSerial(new BufferedSerial(PC_10, PC_11, 115200));
SerialBridge serial(dev);

Controller msc;


MD md1(D14,D12);
MD md2(D15,D13);



float m1;
float m2;
float x;
float y;



int main()
{
    serial.add_frame(0, &msc);

    while (1) {

        serial.update();
        if(msc.was_updated())
        {
            printf("x = %f y = %f\n\r",msc.data.x,msc.data.y);

            x = msc.data.x;
            y = msc.data.y;

            m1 = ( 0.7 * y ) + ( 0.5 * x );
            m2 = ( 0.7 * y ) - ( 0.5 * x );

            md1.drive(m1);
            md2.drive(m2);
            
        
        }
    }
}

