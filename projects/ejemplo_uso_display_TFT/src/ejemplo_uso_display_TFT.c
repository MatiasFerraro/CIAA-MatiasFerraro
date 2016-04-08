/* Copyright 2016, Matias Leandro Ferraro
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
#include "ejemplo_uso_display_TFT.h"       /* <= own header */
#include "stdio.h"
#include "string.h"
#include "tft.h"
#include "lpc_types.h"

static SSP_ConfigFormat ssp_format;


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


//
/***************************************************/

 main()
{
    leds_init();
    port_pin(4,10, SCU_MODE_INACT,init_out);
	port_pin(4,9, SCU_MODE_INACT ,init_out);
    port_pin(0,0, SCU_MODE_INACT ,init_out);
	Board_SSP_Init();
	Board_SSP_config(8,SSP_CLOCK_CPHA0_CPOL0 ,101000000);
	tft_hardware_reset ();
    tft_init_c();
    led_on(LED1);
    while(1)
    {

     //tft_single_colour(ILI9341_BLACK);
     //tft_single_colour(ILI9341_NAVY);
     //tft_single_colour(ILI9341_DARKGREEN);
     //tft_single_colour(ILI9341_DARKCYAN);
     //tft_single_colour(ILI9341_MAROON);
     //tft_single_colour(ILI9341_PURPLE);
     //tft_single_colour(ILI9341_OLIVE);
     //tft_single_colour(ILI9341_LIGHTGREY);
     //tft_single_colour(ILI9341_DARKGREY);
     //tft_single_colour(ILI9341_BLUE);
     //tft_single_colour(ILI9341_GREEN);
     //tft_single_colour(ILI9341_CYAN);
     //tft_single_colour(ILI9341_RED);
     //tft_single_colour(ILI9341_MAGENTA);
     //tft_single_colour(ILI9341_YELLOW);
     //tft_single_colour(ILI9341_WHITE);
     //tft_single_colour(ILI9341_ORANGE);
     //tft_single_colour(ILI9341_GREENYELLOW);
     //tft_single_colour(ILI9341_PINK);
     //tft_sleep();
     //tft_delay(5000);
     //tft_exit_sleep();
    	printf_tft(70, 70,'M', ILI9341_BLACK,ILI9341_YELLOW);

    }
 }
/** @} doxygen end group definition */
/** @} doxygen end group definition */
/** @} doxygen end group definition */
/*==================[end of file]============================================*/













