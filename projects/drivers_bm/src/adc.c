/*
 * adc.c
 *
 *  Created on: 31/01/2016
 *      Author: Matias Leandro Ferraro
 */
#include "adc.h"
#include "stdint.h"



void adc_init(uint8_t chanel, ADC_CLOCK_SETUP_T ADCSetup)
{
  switch(chanel){
	 case ADC_CH1:

		      Chip_ADC_Init(LPC_ADC0,&ADCSetup);
		      Chip_ADC_EnableChannel(LPC_ADC0,ADC_CH1,ENABLE);
		 	  Chip_ADC_SetSampleRate(LPC_ADC0, &ADCSetup,ADC_MAX_SAMPLE_RATE);

		 	 break;

	 case ADC_CH2:

		 	  Chip_ADC_Init(LPC_ADC0,&ADCSetup);
		 	  Chip_ADC_EnableChannel(LPC_ADC0,ADC_CH2,ENABLE);
		 	  Chip_ADC_SetSampleRate(LPC_ADC0, &ADCSetup,ADC_MAX_SAMPLE_RATE);

		 	 break;

	 case ADC_CH3:

		 	  Chip_ADC_Init(LPC_ADC0,&ADCSetup);
		      Chip_ADC_EnableChannel(LPC_ADC0,ADC_CH3,ENABLE);
		      Chip_ADC_SetSampleRate(LPC_ADC0, &ADCSetup,ADC_MAX_SAMPLE_RATE);

		     break;
	}

}

uint16_t adc_read(uint8_t chanel)
{
  uint16_t dataADC;
  /* Start A/D conversion */
  Chip_ADC_SetStartMode(LPC_ADC0, ADC_START_NOW, ADC_TRIGGERMODE_RISING);
  /* Waiting for A/D conversion complete */
  while (Chip_ADC_ReadStatus(LPC_ADC0,ADC_CH1,ADC_DR_DONE_STAT) != SET) {}
  switch(chanel){
	 case ADC_CH1:

		        /* Read ADC value */
		        Chip_ADC_ReadValue(LPC_ADC0,ADC_CH1, &dataADC);

		    break;

	 case ADC_CH2:

		        /* Read ADC value */
		        Chip_ADC_ReadValue(LPC_ADC0,ADC_CH2, &dataADC);

			break;

	 case ADC_CH3:

		        /* Read ADC value */
		        Chip_ADC_ReadValue(LPC_ADC0,ADC_CH3, &dataADC);

			break;
	}

	return dataADC;
}
