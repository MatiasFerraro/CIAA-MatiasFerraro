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
#include "ejemplo_uso_timer.h"       /* <= own header */

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

   uint32_t retardo,_retardo;
   uint32_t conteo=0;
   char cadena[6];
   uint32_t RITIMER_IRQ=11;
   void RIT_IRQHandler(void)
   {
    /* Clearn interrupt */
   Chip_RIT_ClearInt(LPC_RITIMER);
   _retardo--;
   led_off(LED1);
   led_off(LED2);
   led_off(LED3);
   led_off(LED_RGB_B);
<<<<<<< HEAD
   port_pin(6,10, disable, low);
=======
>>>>>>> 274712184375b9f4cea9785f942a8561e451895b
   if (!_retardo){
	   lcd_gotoxy(10,1);
	   conteo=conteo+1;
	   sprintf(cadena,"%d",conteo);
	   printf_lcd(cadena);
	   _retardo=retardo;
	   led_on(LED1);
	   led_on(LED2);
	   led_on(LED3);
	   led_on(LED_RGB_B);
<<<<<<< HEAD
       port_pin(6,10, disable, high);
=======
>>>>>>> 274712184375b9f4cea9785f942a8561e451895b
   }

    }

int main(void)
{
  	/* Inserte su código desde aquí */
	//Matriz de teclado
	   char keypad[3][4] =   { {'1','2','3'},
	                           {'4','5','6'},
	                           {'7','8','9'},
	                           {'*','0','#'} };
	   leds_init();
	   lcd_init_port();
	   lcd_init();
	   pulsadores_init();
<<<<<<< HEAD
	   port_pin(6,10,MD_PUP,init_out);
       RITIMER_IRQ=11;
=======
	   RITIMER_IRQ=11;
>>>>>>> 274712184375b9f4cea9785f942a8561e451895b
	   retardo=5;
	   _retardo=retardo;
	   Chip_RIT_Init(LPC_RITIMER);
	   Chip_RIT_SetTimerInterval(LPC_RITIMER,50);
	   NVIC_EnableIRQ(RITIMER_IRQ);
	   lcd_gotoxy(1, 1);
	   printf_lcd("Contador:\0");

	   while(1){

	           }
 return 0;
}

/** @} doxygen end group definition */
/** @} doxygen end group definition */
/** @} doxygen end group definition */
/*==================[end of file]============================================*/

