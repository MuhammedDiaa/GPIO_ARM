/*
 * RegMap.h
 *
 *  Created on: Feb 15, 2020
 *      Author: Diaa
 */

#ifndef REG_MAP_GPIO_H_
#define REG_MAP_GPIO_H_

                                       // GPIO PORTS BASE ADDRESSES //
#define PORTA_APB   0x40004000
#define PORTA_AHB   0x40058000
#define PORTB_APB   0x40005000
#define PORTB_AHB   0x40059000
#define PORTC_APB   0x40006000
#define PORTC_AHB   0x4005A000
#define PORTD_APB   0x40007000
#define PORTD_AHB   0x4005B000
#define PORTE_APB   0x40024000
#define PORTE_AHB   0x4005C000
#define PORTF_APB   0x40025000
#define PORTF_AHB   0x4005D000

                                   // GPIO REGISTERS OFFSET ADDRESSES //
#define GPIODATA    0x000
#define GPIODIR     0x400
#define GPIOAFSEL   0x420
#define GPIODR2R    0x500
#define GPIODR4R    0x504
#define GPIODR8R    0x508
#define GPIOSLR     0x518
#define GPIOODR     0x50C
#define GPIOPUR     0x510
#define GPIOPDR     0x514
#define GPIODEN     0x51C

                                   // GPIO REGISTERS IN SYSTEM CONTROL //

#define GPIOHBCTL (*((volatile uint32*)(0x400FE06C)))
#define RCGCGPIO  (*((volatile uint32*)(0x400FE608)))

#define Reg_addr(port_portmode,reg) ((port_portmode) + (reg))
typedef volatile unsigned long * Reg ;


#endif /* REG_MAP_GPIO_H_ */
