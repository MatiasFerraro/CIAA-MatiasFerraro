/*
 * leds.c
 *
 *  Created on: 15/01/16
 *      Author: Matias Leandro Ferraro
 */


#include "leds.h"




void leds_init(void){

	/*inicializo leds*/
	port_pin(2,0, MD_PUP,init_out);
	port_pin(2,1, MD_PUP,init_out);
	port_pin(2,2, MD_PUP,init_out);
	port_pin(2,10,MD_PUP,init_out);
	port_pin(2,11,MD_PUP,init_out);
	port_pin(2,12,MD_PUP,init_out);
	/*los apago*/
	port_pin(2,0, disable, low);
	port_pin(2,1, disable, low);
	port_pin(2,2, disable, low);
	port_pin(2,10,disable, low);
	port_pin(2,11,disable, low);
	port_pin(2,12,disable, low);
}


void led_on(uint8_t led_n)
{
  switch(led_n)
  {

    case LED1      : port_pin(2,10, disable, high);
                     break;
    case LED2      : port_pin(2,11, disable, high);
                     break;
    case LED3      : port_pin(2,12, disable, high);
                     break;
    case LED_RGB_R : port_pin(2,0, disable, high);
                     break;
    case LED_RGB_G : port_pin(2,1, disable, high);
                     break;
    case LED_RGB_B : port_pin(2,2, disable, high);
                     break;
  }
}
void led_off(uint8_t led_n)
{
  switch(led_n)
  {

    case LED1      : port_pin(2,10, disable, low);
                     break;
    case LED2      : port_pin(2,11, disable, low);
                     break;
    case LED3      : port_pin(2,12, disable, low);
                     break;
    case LED_RGB_R : port_pin(2,0, disable, low);
                     break;
    case LED_RGB_G : port_pin(2,1, disable, low);
                     break;
    case LED_RGB_B : port_pin(2,2, disable, low);
                     break;
  }
}


