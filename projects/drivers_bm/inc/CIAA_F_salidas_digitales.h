/*
 * CIAA_F_salidas_digitales.h
 *
 *  Created on: 07/03/16
 *      Author: Matias Leandro Ferraro
 */
#include "stdint.h"
#include "puertos.h"
#include "chip.h"


#define DOUT0   0
#define DOUT1   1
#define DOUT2   2
#define DOUT3   3
#define DOUT4   4
#define DOUT5   5
#define DOUT6   6
#define DOUT7   7

void rele_init(void);
void open_drain_init(void);
void rele_on(uint8_t rele_n);
void rele_off(uint8_t rele_n);
void open_drain_on(uint8_t drain_n);
void open_drain_off(uint8_t drain_n);
