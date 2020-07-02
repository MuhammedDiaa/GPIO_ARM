#include "GPIO.h"


 uint32 port_arr[12] = {
  PORTA_APB,
  PORTA_AHB,
  PORTB_APB,
  PORTB_AHB,
  PORTC_APB,
  PORTC_AHB,
  PORTD_APB,
  PORTD_AHB,
  PORTE_APB,
  PORTE_AHB,
  PORTF_APB,
  PORTF_AHB
};

uint32 port_arr_used[6] ={0};
// this array to store the addresses of ports that user decide to access the array is initialized by zero.
//everytime the user calls the function GPIOBusSet, array elements will change according to bus choice


void GPIOBusSet(gpio_port_t port, gpio_bus_t bus) {

  if (bus == APB){
    GPIOHBCTL &= ~(1 << port) ; //register9 in system control chapter
    port_arr_used[port] = port_arr[2 * port];
  }else if (bus == AHB){
    GPIOHBCTL |= (1 << port);
    port_arr_used[port] = port_arr[2 * port + 1];
  }
}


void GPIODirModeSet(gpio_port_t port, uint8 pins, gpio_mode_t mode) {

  volatile unsigned long * reg = (unsigned long *)(port_arr_used[port] + GPIOAFSEL);

  if (mode == MODE_AF)
  {
    *reg = pins ;
  }else if(mode == MODE_IN)
  {
    *reg = *reg & (~pins);
    reg = (uint32 *)(port_arr_used[port] + GPIODIR); //to set the direction
    *reg = *reg & (~pins) ;
    reg = (uint32 *)(port_arr_used[port] + GPIODEN);
    *reg = *reg & (~pins) | pins ;
   }else if(mode == MODE_OUT){
    *reg = *reg & (~pins);
     reg = (uint32 *)(port_arr_used[port] + GPIODIR); //to set the direction
     *reg = *reg | pins ;
     reg = (uint32 *)(port_arr_used[port] + GPIODEN);
     *reg = *reg & (~pins) | pins ;
    }
}


void GPIOClockSet(uint8 port)
{
  RCGCGPIO |= (1 << port);
  //SCGCGPIO and DCGCGPIO !!
}

void GPIOWrite(uint8 port, uint8 pins, uint8 data)
{
    volatile uint32 * reg = (volatile uint32*)(port_arr_used[port]);
    uint32 reg_addr = (uint32)reg ;
    uint32 pins_edited = (uint32)(pins<<2) ;
    reg_addr |= pins_edited ;
    reg = reg_addr ;
    *reg= *reg | data ;
}

unsigned char GPIORead(uint8 port, uint8 pins)
{
    volatile uint32 * reg = (volatile uint32*)(port_arr_used[port]);
    uint32 reg_addr =(uint32) reg ;
    uint32 pins_edited = (uint32)(pins<<2) ;
    reg_addr |= pins_edited ;
    reg = reg_addr ;
    return *reg ;
}


/*
void GPIOPadSet(uint8 port, uint8 pins, gpio_drive_t str, gpio_pad_t pad)
{
    volatile uint32 * reg = (uint32 *) (port_arr_used[port] + str) ; //for drive selection
    //str represents the offset address of the corresponding register to drive the desired current through the pin
    uint32 data = * reg ;
    data &= 0xFF00 ;
    data |= pins ;
    *reg = data ;
    if(pad != PAD_NPU_NPD)
    {
    reg = (uint32*) (port_arr_used[port] + pad) ; //for pad selection
    //pad represents the offset address of the corresponding register that responsible for PU or PD or OD control
    data = *reg ;
    data &= 0xff00 ;
    data |= pins ;
    *reg = data ;
    }
}

*/
