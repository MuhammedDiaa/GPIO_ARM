/*
 * GPIO.h
 *
 *  Created on: Feb 16, 2020
 *      Author: DIAA
 */

#ifndef GPIO_H_
#define GPIO_H_

#include "std_types.h"
#include "common_macros.h"
#include "Reg_Map_GPIO.h"

typedef enum {MODE_IN = 0x00, MODE_OUT = 0xff, MODE_AF = 0x3} gpio_mode_t;
typedef enum {PORTA, PORTB, PORTC,PORTD,PORTE,PORTF} gpio_port_t;
typedef enum {APB,AHB} gpio_bus_t;
typedef enum {Drive_2mA = GPIODR2R , Drive_4mA = GPIODR4R, Drive_8mA = GPIODR8R, Drive_8mA_Selw = GPIOSLR} gpio_drive_t;
typedef enum {Pad_PU = GPIOPUR,Pad_PD = GPIOPDR,PAD_OD = GPIOODR, PAD_NPU_NPD} gpio_pad_t;


                                            //Functions prototype//

void GPIOBusSet(uint8 port,gpio_bus_t bus);
gpio_bus_t GPIOBusGet(uint8 port);

void GPIOClockSet(uint8 port);
void GPIOClockRst(uint8 port);
char GPIOClockGet(uint8 port);

void GPIODirModeSet(uint8 port, uint8 pins, gpio_mode_t Mode);
unsigned char GPIODirGet(uint8 port, uint8 pins);
unsigned char GPIOModeGet(uint8 port, uint8 pins);

void GPIOPadSet(uint8 port, uint8 pins, gpio_drive_t str, gpio_pad_t pad);
unsigned char GPIOPadDriveStrGet(uint32 port, uint8 pins);
unsigned char GPIOPadOpenDrainGet(uint32 port, uint8 pins);
unsigned char GPIOPadPullUpGet(uint32 port, uint8 pins);
unsigned char GPIOPadPullDownGet(uint32 port, uint8 pins);

unsigned char GPIORead(uint8 port, uint8 pins);
void GPIOWrite(uint8 port, uint8 pins, uint8 data);



#endif /* GPIO_H_ */
