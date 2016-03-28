﻿/* Copyright 2016, Matias Leandro Ferraro
 * All rights reserved.
 *
 * This file is part of CIAA Firmware.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */

/** \brief Blinking Bare Metal example source file
 **
 ** This is a mini example of the CIAA Firmware.
 **
 **/

/** \addtogroup CIAA_Firmware CIAA Firmware
 ** @{ */

/** \addtogroup Examples CIAA Firmware Examples
 ** @{ */
/** \addtogroup Baremetal Bare Metal example source file
 ** @{ */

/*
 * Initials     Name
 * ---------------------------
 *
 */

/*
 * modification history (new versions first)
 * -----------------------------------------------------------
 * yyyymmdd v0.0.1 initials initial version
 */

/*==================[inclusions]=============================================*/
#include "ejemplo_uso_spi.h"       /* <= own header */
#include "puertos.h"
#include "spi.h"
#include "ciaaPOSIX_stdbool.h"
#ifndef CPU
#error CPU shall be defined
#endif
#if (lpc4337 == CPU)
#include "chip.h"
#elif (mk60fx512vlq15 == CPU)
#else
#endif

/*==================[macros and definitions]=================================*/

/*==================[internal data declaration]==============================*/

/*==================[internal functions declaration]=========================*/

/*==================[internal data definition]===============================*/

/*==================[external data definition]===============================*/

/*==================[internal functions definition]==========================*/

/*==================[external functions definition]==========================*/
/** \brief Main function
 *
 * This is the main entry point of the software.
 *
 * \returns 0
 *
 * \remarks This function never returns. Return value is only to avoid compiler
 *          warnings or errors.
 */

#define LPC_SSP             LPC_SSP1
#define SSP_MODE_TEST       1/*1: Master, 0: Slave */
#define SSP_DATA_BITS       SSP_BITS_16//(SSP_BITS_8)
#define BUFFER_SIZE         8
typedef SPI_DATA[8];
typedef struct {
	SPI_DATA  *tx_data;	/*!< Pointer to transmit data */
	uint32_t  tx_cnt;	/*!< Transmit counter */
	SPI_DATA  *rx_data;	/*!< Pointer to transmit data */
	uint32_t  rx_cnt;	/*!< Receive counter */
	uint32_t  length;	/*!< Length of transfer data */
} Chip_SSP_DATA_SETUP_T_;
static Chip_SSP_DATA_SETUP_T_ xf_setup;
/* Tx buffer */
 static uint8_t Tx_Buf[BUFFER_SIZE];
/* Rx buffer */
static uint8_t Rx_Buf[BUFFER_SIZE];


void  write_data(uint32_t hexa)
{

	port_pin(4,9, disable, low);  //cs=0
	port_pin(4,10, disable, high);//dc=1
    xf_setup.length = 1;
    xf_setup.rx_data = Rx_Buf;
	xf_setup.rx_cnt = xf_setup.tx_cnt = 0;
	xf_setup.tx_data= hexa;
	Chip_SSP_Enable(LPC_SSP);
	//Chip_SSP_RWFrames_Blocking(LPC_SSP, &xf_setup);
	Chip_SSP_WriteFrames_Blocking(LPC_SSP,&hexa, 1);
	port_pin(4,9, disable, high);//cs=1
}
int main(void)
{

	 port_pin(4,10, SCU_MODE_INACT,init_out);
	 port_pin(4,9, SCU_MODE_INACT ,init_out);
	 port_pin(0,0, SCU_MODE_INACT ,init_out);
	 leds_init();
	 Board_SSP_Init();
	 Board_SSP_config(8,SSP_CLOCK_CPHA0_CPOL0 ,5000);
	 write_data(0x12);
	 while(1){

	}

    return 0;
}



/** @} doxygen end group definition */
/** @} doxygen end group definition */
/** @} doxygen end group definition */
/*==================[end of file]============================================*/

