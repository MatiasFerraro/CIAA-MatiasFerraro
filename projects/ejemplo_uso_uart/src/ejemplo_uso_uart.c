/* Copyright 2015, Matias Leandro Ferraro
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
#include "ejemplo_uso_uart.h"       /* <= own header */



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
uint32_t buffer_rx[max_long_buff_rx];
uint8_t dato_completo;
int UART2_IRQ=26;
uint8_t i_rx;
void UART2_IRQHandler()
{

	buffer_rx[i_rx]=uart_getChar(LPC_USART2);

	 if (buffer_rx[i_rx]=='0')
	 {
	  dato_completo=1;
	  //buffer_rx[i_rx+1]='\0';
	  //i_rx=0;

	 }
	 else
	   {
	    dato_completo=0;
	    i_rx++;
	   }
	 NVIC_ClearPendingIRQ(UART2_IRQ);

}
int main(void)

{
  	/* Inserte su código desde aquí */

	char buffer_tx[] = "Hola mundo...\n\r\0";
#include "leds.h"



    leds_init();
	lcd_init_port();
	lcd_init();
	uart_init(USART2, 115200);
    lcd_gotoxy(1, 1);
    printf_lcd("Valor UART:\0");
    printf_uart(LPC_USART2,buffer_tx);
    int UART2_IRQ=26;
    NVIC_EnableIRQ(UART2_IRQ);

    while(1){
    	lcd_gotoxy(12,1);
    	//leer un caracter solo//
    	//buffer_rx[0]=uart_getChar(LPC_USART2);
    	//buffer_rx[1]='\0';

    	//leer un string//

    	//uart_readstring(LPC_USART2, buffer_rx,3);
    	//led_on(LED2);
    	if (dato_completo==1) printf_lcd(buffer_rx);
    	//led_on(LED3);
   	}
    return 0;
}






/** @} doxygen end group definition */
/** @} doxygen end group definition */
/** @} doxygen end group definition */
/*==================[end of file]============================================*/

