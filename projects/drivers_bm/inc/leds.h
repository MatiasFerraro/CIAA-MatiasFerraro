/*
 * leds.h
 *
 *  Created on: 15/01/16
 *      Author: Matias Leandro Ferraro
 */
#include "stdint.h"
#include "puertos.h"
#include "chip.h"


#define LED_RGB_R   0
#define LED_RGB_G   1
#define LED_RGB_B   2
#define LED1        3
#define LED2        4
#define LED3        5


void led_init(void);
void led_on(uint8_t led_n);
void led_off(uint8_t led_n);

