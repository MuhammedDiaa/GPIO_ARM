/*
 * app.c
 *
 *  Created on: Feb 18, 2020
 *      Author: SHIKO
 */
#include "GPIO.h"


void main(){

    GPIOBusSet(PORTF,AHB);
    GPIOClockSet(PORTF);
    GPIODirModeSet(PORTF , 0b00001000 ,MODE_OUT);
    GPIODirModeSet(PORTF , 0b00100000 ,MODE_OUT);
    GPIOWrite( PORTF,0b00100000, 0b00100000);
    while(1)
    {
        if(GPIORead(PORTF, 0b00100000) == 0b00100000){
            GPIOWrite( PORTF,0b00001000 , 0b00001000);
        }
    }
}


