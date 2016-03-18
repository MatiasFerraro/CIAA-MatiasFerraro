/*
 * puertos.h
 *
 *  Created on: 01/01/2016
 *  Author: Matias Leandro Ferraro
 */
#include "chip.h"

#define ENTRADA  0
#define SALIDA   1
#define init_in  0
#define init_out 1
#define high     2
#define low      3
#define state_in 4
#define disable  0

int port_pin(uint8_t puerto,uint8_t  pin,uint8_t  config ,uint8_t modo);//Inicializa un pin de un puerto.




