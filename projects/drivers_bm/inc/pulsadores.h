/*
 * pulsadores.h
 *
 *  Created on: 15/01/16
 *      Author: Matias Leandro Ferraro
 */
#define TEC1  1
#define TEC2  2
#define TEC3  3
#define TEC4  4

#include "stdint.h"
#include "chip.h"

void pulsadores_init(void);
int estado_pulsador(uint8_t pulsador);



