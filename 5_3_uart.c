/* Copyright 2014, 2015 Mariano Cerdeiro
 * Copyright 2014, Pablo Ridolfi
 * Copyright 2014, Juan Cecconi
 * Copyright 2014, Gustavo Muro
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

/** \brief Bare Metal example source file
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
#include "5_3_uart.h"       /* <= own header */

#ifndef CPU
#error CPU shall be defined
#endif
#if (lpc4337 == CPU)
#include "chip.h"
#elif (mk60fx512vlq15 == CPU)
#else
#endif

#define LED1_PORT	0
#define LED_1	1<<14

#define LED2_PORT	1
#define LED_2	1<<11

#define LED3_PORT	1
#define LED_3 1<<12
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
int main(void)
{


	   /*Put initializations in a separate function hw_init(void) or something like that...*/

	   Chip_SCU_PinMux(1,0,MD_PUP|MD_EZI|MD_ZI,FUNC0); /* GPIO0[4], SW1 */
	   Chip_SCU_PinMux(1,1,MD_PUP|MD_EZI|MD_ZI,FUNC0); /* GPIO0[8], SW2 */
	   Chip_SCU_PinMux(1,2,MD_PUP|MD_EZI|MD_ZI,FUNC0); /* GPIO0[9], SW3 */
	   Chip_SCU_PinMux(1,6,MD_PUP|MD_EZI|MD_ZI,FUNC0); /* GPIO1[9], SW4 */

	   Chip_GPIO_SetDir(LPC_GPIO_PORT, 0,(1<<4)|(1<<8)|(1<<9),0);
	   Chip_GPIO_SetDir(LPC_GPIO_PORT, 1,(1<<9),0);

	   /* LEDs */
	   Chip_SCU_PinMux(2,0,MD_PUP,FUNC4);  /* GPIO5[0], LED0R */
	   Chip_SCU_PinMux(2,1,MD_PUP,FUNC4);  /* GPIO5[1], LED0G */
	   Chip_SCU_PinMux(2,2,MD_PUP,FUNC4);  /* GPIO5[2], LED0B */
	   Chip_SCU_PinMux(2,10,MD_PUP,FUNC0); /* GPIO0[14], LED1 */
	   Chip_SCU_PinMux(2,11,MD_PUP,FUNC0); /* GPIO1[11], LED2 */
	   Chip_SCU_PinMux(2,12,MD_PUP,FUNC0); /* GPIO1[12], LED3 */

	   Chip_GPIO_SetDir(LPC_GPIO_PORT, 5,(1<<0)|(1<<1)|(1<<2),1);
	   Chip_GPIO_SetDir(LPC_GPIO_PORT, 0,(1<<14),1);
	   Chip_GPIO_SetDir(LPC_GPIO_PORT, 1,(1<<11)|(1<<12),1);

	   Chip_GPIO_ClearValue(LPC_GPIO_PORT, 5,(1<<0)|(1<<1)|(1<<2));
	   Chip_GPIO_ClearValue(LPC_GPIO_PORT, 0,(1<<14));
	   Chip_GPIO_ClearValue(LPC_GPIO_PORT, 1,(1<<11)|(1<<12));

	/*Hardware GPIO initialization (leds, buttons ...)*/


	   /*UART initialization*/

	   /* UART0 (RS485/Profibus) */
	   Chip_UART_Init(LPC_USART0);
	   Chip_UART_SetBaud(LPC_USART0, 115200);

	   Chip_UART_SetupFIFOS(LPC_USART0, UART_FCR_FIFO_EN | UART_FCR_TRG_LEV0);

	   Chip_UART_TXEnable(LPC_USART0);

	   Chip_SCU_PinMux(9, 5, MD_PDN, FUNC7);              /* P9_5: UART0_TXD */
	   Chip_SCU_PinMux(9, 6, MD_PLN|MD_EZI|MD_ZI, FUNC7); /* P9_6: UART0_RXD */

	   Chip_UART_SetRS485Flags(LPC_USART0, UART_RS485CTRL_DCTRL_EN | UART_RS485CTRL_OINV_1);

	   Chip_SCU_PinMux(6, 2, MD_PDN, FUNC2);              /* P6_2: UART0_DIR */

	   /* UART2 (USB-UART) */
	   Chip_UART_Init(LPC_USART2);
	   Chip_UART_SetBaud(LPC_USART2, 115200);

	   Chip_UART_SetupFIFOS(LPC_USART2, UART_FCR_FIFO_EN | UART_FCR_TRG_LEV0);

	   Chip_UART_TXEnable(LPC_USART2);

	   Chip_SCU_PinMux(7, 1, MD_PDN, FUNC6);              /* P7_1: UART2_TXD */
	   Chip_SCU_PinMux(7, 2, MD_PLN|MD_EZI|MD_ZI, FUNC6); /* P7_2: UART2_RXD */

	   /* UART3 (RS232) */
	   Chip_UART_Init(LPC_USART3);
	   Chip_UART_SetBaud(LPC_USART3, 115200);

	   Chip_UART_SetupFIFOS(LPC_USART3, UART_FCR_FIFO_EN | UART_FCR_TRG_LEV0);

	   Chip_UART_TXEnable(LPC_USART3);

	   Chip_SCU_PinMux(2, 3, MD_PDN, FUNC2);              /* P2_3: UART3_TXD */
	   Chip_SCU_PinMux(2, 4, MD_PLN|MD_EZI|MD_ZI, FUNC2); /* P2_4: UART3_RXD */



       /*Chip_UART_IntDisable((LPC_USART_T *)LPC_USART2, UART_IER_THREINT);*/
       /* this one calls write */
       /*ciaaDriverUart_txConfirmation(device);*/
       /* enable THRE irq (TX) */
/*       Chip_UART_IntEnable((LPC_USART_T *)LPC_USART2, UART_IER_THREINT);*/

      uint64_t j;
	  uint8_t size = 28;
	  uint8_t i = 0;
	  uint8_t data = 0;

	  char message[] = "Follow the white rabbit...\n\r";

	  /*	  just send the F  ...! */
	 /*	   Chip_UART_Send((LPC_USART_T *) LPC_USART2, message, index); */

	  /*looking for a 'a' character*/
   /* perform the needed initialization here */
   while(1) {
      /* do nothing */
		  data = i = 0;

		  /*wait for keyboard character*/

		  while (data == 0)
		  {
			  data = Chip_UART_ReadByte((LPC_USART_T *)LPC_USART2);

			switch (data){
			case 'r':
				  /*Toggle Red Led*/
			 	  Chip_GPIO_SetPortToggle(LPC_GPIO_PORT,LED2_PORT,LED_2);
				break;
			case 'v':
				  /*Toggle Green Led*/
			 	  Chip_GPIO_SetPortToggle(LPC_GPIO_PORT,LED3_PORT,LED_3);
				break;
			case 'a':
				  /*Toggle Yellow Led*/
			 	  Chip_GPIO_SetPortToggle(LPC_GPIO_PORT,LED1_PORT,LED_1);
				break;
			default:
				data = 0;
			}
		  }

 	     /*Send string*/
		 while(((Chip_UART_ReadLineStatus((LPC_USART_T *)LPC_USART2) & UART_LSR_THRE) != 0) && (i < size))
	      {
	         /* send first byte */
	         Chip_UART_SendByte((LPC_USART_T *)LPC_USART2, message[i]);
	         /* bytes written */

	         /*delay*/
	         for (j=0;j<50000;j++){
	           asm  ("nop");
	           }
	         i++;
	      }
   }
   return 0;
}

/** @} doxygen end group definition */
/** @} doxygen end group definition */
/** @} doxygen end group definition */
/*==================[end of file]============================================*/

=======
/* Copyright 2014, 2015 Mariano Cerdeiro
 * Copyright 2014, Pablo Ridolfi
 * Copyright 2014, Juan Cecconi
 * Copyright 2014, Gustavo Muro
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

/** \brief Bare Metal example source file
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
#include "5_3_uart.h"       /* <= own header */

#ifndef CPU
#error CPU shall be defined
#endif
#if (lpc4337 == CPU)
#include "chip.h"
#elif (mk60fx512vlq15 == CPU)
#else
#endif

#define LED1_PORT	0
#define LED_1	1<<14

#define LED2_PORT	1
#define LED_2	1<<11

#define LED3_PORT	1
#define LED_3 1<<12
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
int main(void)
{


	   /*Put initializations in a separate function hw_init(void) or something like that...*/

	   Chip_SCU_PinMux(1,0,MD_PUP|MD_EZI|MD_ZI,FUNC0); /* GPIO0[4], SW1 */
	   Chip_SCU_PinMux(1,1,MD_PUP|MD_EZI|MD_ZI,FUNC0); /* GPIO0[8], SW2 */
	   Chip_SCU_PinMux(1,2,MD_PUP|MD_EZI|MD_ZI,FUNC0); /* GPIO0[9], SW3 */
	   Chip_SCU_PinMux(1,6,MD_PUP|MD_EZI|MD_ZI,FUNC0); /* GPIO1[9], SW4 */

	   Chip_GPIO_SetDir(LPC_GPIO_PORT, 0,(1<<4)|(1<<8)|(1<<9),0);
	   Chip_GPIO_SetDir(LPC_GPIO_PORT, 1,(1<<9),0);

	   /* LEDs */
	   Chip_SCU_PinMux(2,0,MD_PUP,FUNC4);  /* GPIO5[0], LED0R */
	   Chip_SCU_PinMux(2,1,MD_PUP,FUNC4);  /* GPIO5[1], LED0G */
	   Chip_SCU_PinMux(2,2,MD_PUP,FUNC4);  /* GPIO5[2], LED0B */
	   Chip_SCU_PinMux(2,10,MD_PUP,FUNC0); /* GPIO0[14], LED1 */
	   Chip_SCU_PinMux(2,11,MD_PUP,FUNC0); /* GPIO1[11], LED2 */
	   Chip_SCU_PinMux(2,12,MD_PUP,FUNC0); /* GPIO1[12], LED3 */

	   Chip_GPIO_SetDir(LPC_GPIO_PORT, 5,(1<<0)|(1<<1)|(1<<2),1);
	   Chip_GPIO_SetDir(LPC_GPIO_PORT, 0,(1<<14),1);
	   Chip_GPIO_SetDir(LPC_GPIO_PORT, 1,(1<<11)|(1<<12),1);

	   Chip_GPIO_ClearValue(LPC_GPIO_PORT, 5,(1<<0)|(1<<1)|(1<<2));
	   Chip_GPIO_ClearValue(LPC_GPIO_PORT, 0,(1<<14));
	   Chip_GPIO_ClearValue(LPC_GPIO_PORT, 1,(1<<11)|(1<<12));

	/*Hardware GPIO initialization (leds, buttons ...)*/


	   /*UART initialization*/

	   /* UART0 (RS485/Profibus) */
	   Chip_UART_Init(LPC_USART0);
	   Chip_UART_SetBaud(LPC_USART0, 115200);

	   Chip_UART_SetupFIFOS(LPC_USART0, UART_FCR_FIFO_EN | UART_FCR_TRG_LEV0);

	   Chip_UART_TXEnable(LPC_USART0);

	   Chip_SCU_PinMux(9, 5, MD_PDN, FUNC7);              /* P9_5: UART0_TXD */
	   Chip_SCU_PinMux(9, 6, MD_PLN|MD_EZI|MD_ZI, FUNC7); /* P9_6: UART0_RXD */

	   Chip_UART_SetRS485Flags(LPC_USART0, UART_RS485CTRL_DCTRL_EN | UART_RS485CTRL_OINV_1);

	   Chip_SCU_PinMux(6, 2, MD_PDN, FUNC2);              /* P6_2: UART0_DIR */

	   /* UART2 (USB-UART) */
	   Chip_UART_Init(LPC_USART2);
	   Chip_UART_SetBaud(LPC_USART2, 115200);

	   Chip_UART_SetupFIFOS(LPC_USART2, UART_FCR_FIFO_EN | UART_FCR_TRG_LEV0);

	   Chip_UART_TXEnable(LPC_USART2);

	   Chip_SCU_PinMux(7, 1, MD_PDN, FUNC6);              /* P7_1: UART2_TXD */
	   Chip_SCU_PinMux(7, 2, MD_PLN|MD_EZI|MD_ZI, FUNC6); /* P7_2: UART2_RXD */

	   /* UART3 (RS232) */
	   Chip_UART_Init(LPC_USART3);
	   Chip_UART_SetBaud(LPC_USART3, 115200);

	   Chip_UART_SetupFIFOS(LPC_USART3, UART_FCR_FIFO_EN | UART_FCR_TRG_LEV0);

	   Chip_UART_TXEnable(LPC_USART3);

	   Chip_SCU_PinMux(2, 3, MD_PDN, FUNC2);              /* P2_3: UART3_TXD */
	   Chip_SCU_PinMux(2, 4, MD_PLN|MD_EZI|MD_ZI, FUNC2); /* P2_4: UART3_RXD */



       /*Chip_UART_IntDisable((LPC_USART_T *)LPC_USART2, UART_IER_THREINT);*/
       /* this one calls write */
       /*ciaaDriverUart_txConfirmation(device);*/
       /* enable THRE irq (TX) */
/*       Chip_UART_IntEnable((LPC_USART_T *)LPC_USART2, UART_IER_THREINT);*/

      uint64_t j;
	  uint8_t size = 28;
	  uint8_t i = 0;
	  uint8_t data = 0;

	  char message[] = "Follow the white rabbit...\n\r";

	  /*	  just send the F  ...! */
	 /*	   Chip_UART_Send((LPC_USART_T *) LPC_USART2, message, index); */

	  /*looking for a 'a' character*/
   /* perform the needed initialization here */
   while(1) {
      /* do nothing */
		  data = i = 0;

		  /*wait for keyboard character*/

		  while (data == 0)
		  {
			  data = Chip_UART_ReadByte((LPC_USART_T *)LPC_USART2);

			switch (data){
			case 'r':
				  /*Toggle Red Led*/
			 	  Chip_GPIO_SetPortToggle(LPC_GPIO_PORT,LED2_PORT,LED_2);
				break;
			case 'v':
				  /*Toggle Green Led*/
			 	  Chip_GPIO_SetPortToggle(LPC_GPIO_PORT,LED3_PORT,LED_3);
				break;
			case 'a':
				  /*Toggle Yellow Led*/
			 	  Chip_GPIO_SetPortToggle(LPC_GPIO_PORT,LED1_PORT,LED_1);
				break;
			default:
				data = 0;
			}
		  }

 	     /*Send string*/
		 while(((Chip_UART_ReadLineStatus((LPC_USART_T *)LPC_USART2) & UART_LSR_THRE) != 0) && (i < size))
	      {
	         /* send first byte */
	         Chip_UART_SendByte((LPC_USART_T *)LPC_USART2, message[i]);
	         /* bytes written */

	         /*delay*/
	         for (j=0;j<50000;j++){
	           asm  ("nop");
	           }
	         i++;
	      }
   }
   return 0;
}

/** @} doxygen end group definition */
/** @} doxygen end group definition */
/** @} doxygen end group definition */
/*==================[end of file]============================================*/

