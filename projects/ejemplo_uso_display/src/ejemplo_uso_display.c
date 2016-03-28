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
#include "ejemplo_uso_display.h"       /* <= own header */

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

    int i=1,j=1,k=1,m=1;
    char string_1[12]="Boton->UNO\0";
    char string_2[12]="Boton->DOS\0";
    char string_3[12]="Boton->TRES\0";
    char string_4[16]="Boton->CUATRO\0";
    char string_5[16]="Boton->ninguno\0";

int main(void)
{
	    leds_init();
		lcd_init_port();
		lcd_init();
		pulsadores_init();

        lcd_gotoxy(1, 1);
		lcd_putc('P');
		lcd_putc('U');
		lcd_putc('L');
		lcd_putc('S');
		lcd_putc('A');
		lcd_putc('D');
		lcd_putc('O');
		lcd_putc('R');
		lcd_putc(' ');
		lcd_putc('P');
		lcd_putc('R');
		lcd_putc('E');
		lcd_putc('S');
		lcd_putc('S');
		lcd_putc(':');

		while(1)
	{
    if (estado_pulsador(TEC4))
	{
		led_on(LED3);
		lcd_gotoxy(1, 2);
		printf_lcd("                ");
		lcd_gotoxy(1, 2);
		printf_lcd(string_4);
	}else
		{
			led_off(LED3);
		}
    if (estado_pulsador(TEC3))
    {
    	led_on(LED2);
    	lcd_gotoxy(1, 2);
    	printf_lcd("                ");
    	lcd_gotoxy(1, 2);
    	printf_lcd(string_3);
    }else
    	{
    		led_off(LED2);
        }
	if (estado_pulsador(TEC2))
    {
    	led_on(LED1);
		lcd_gotoxy(1, 2);
		printf_lcd("                ");
		lcd_gotoxy(1, 2);
		printf_lcd(string_2);
	}else
    	{
		led_off(LED1);
		}
	if (estado_pulsador(TEC1))
	{
    	led_on(LED_RGB_B);
		lcd_gotoxy(1, 2);
		printf_lcd("                ");
		lcd_gotoxy(1, 2);
		printf_lcd(string_1);
	}else
	{
		led_off(LED_RGB_B);
    }
  }

  return 0;
}

/** @} doxygen end group definition */
/** @} doxygen end group definition */
/** @} doxygen end group definition */
/*==================[end of file]============================================*/

