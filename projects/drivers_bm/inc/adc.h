/*
 * adc.h
 *
 *  Created on: 31/01/2016
 *      Author: Matias Leandro Ferraro
 */
#include "stdint.h"
#include "ciaaPOSIX_stdbool.h"
#include "chip.h"

void adc_init(uint8_t chanel, ADC_CLOCK_SETUP_T ADCSetup);
uint16_t adc_read(uint8_t chanel);
