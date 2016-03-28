/*
 * uart.c
 *
 *  Created on: 31/01/2016
 *      Author: Matias Leandro Ferraro
 */

#include "uart.h"

void uart_init(uint8_t usart, uint32_t baud)
{
  switch(usart){
	 case USART0:
	    /* UART0 (RS485/Profibus) */
		  Chip_UART_Init(LPC_USART0);
		  Chip_UART_SetBaud(LPC_USART0, baud);
		  Chip_UART_SetupFIFOS(LPC_USART0, UART_FCR_FIFO_EN | UART_FCR_TX_RS | UART_FCR_RX_RS | UART_FCR_TRG_LEV0);
		  Chip_UART_ConfigData(LPC_USART0,UART_LCR_WLEN8 | UART_LCR_PARITY_ODD );
		  Chip_UART_IntEnable(LPC_USART0, UART_IER_RBRINT);
		  Chip_SCU_PinMux(9, 5, MD_PDN, FUNC7);              /* P9_5: UART0_TXD */
  	      Chip_SCU_PinMux(9, 6, MD_PLN|MD_EZI|MD_ZI, FUNC7); /* P9_6: UART0_RXD */
          Chip_UART_SetRS485Flags(LPC_USART0, UART_RS485CTRL_DCTRL_EN | UART_RS485CTRL_OINV_1);
          Chip_SCU_PinMux(6, 2, MD_PDN, FUNC2);              /* P6_2: UART0_DIR */

        break;
	 case USART2:
	      /* UART2 (USB-UART) */
		  Chip_UART_Init(LPC_USART2);
		  Chip_UART_SetBaud(LPC_USART2, baud);
		  Chip_UART_SetupFIFOS(LPC_USART2, UART_FCR_FIFO_EN | UART_FCR_TX_RS | UART_FCR_RX_RS | UART_FCR_TRG_LEV0);
		  Chip_UART_ConfigData(LPC_USART2,UART_LCR_WLEN8 | UART_LCR_PARITY_ODD );
		  Chip_UART_IntEnable(LPC_USART2, UART_IER_RBRINT);
		  Chip_GPIO_SetPinDIR(LPC_GPIO_PORT, 3, 9, 1);
          Chip_GPIO_SetPinDIR(LPC_GPIO_PORT, 3, 10, 0);
          Chip_UART_TXEnable(LPC_USART2);
          Chip_SCU_PinMux(7, 1, MD_PDN, FUNC6);              /* P7_1: UART2_TXD */
	      Chip_SCU_PinMux(7, 2, MD_PLN|MD_EZI|MD_ZI, FUNC6); /* P7_2: UART2_RXD */

	      break;
	 case USART3:
	   /* UART3 (RS232) */
		 Chip_UART_Init(LPC_USART3);
		 Chip_UART_SetBaud(LPC_USART3, baud);
		 Chip_UART_SetupFIFOS(LPC_USART3, UART_FCR_FIFO_EN | UART_FCR_TX_RS | UART_FCR_RX_RS | UART_FCR_TRG_LEV0);
		 Chip_UART_ConfigData(LPC_USART3,UART_LCR_WLEN8 | UART_LCR_PARITY_ODD );
		 Chip_UART_IntEnable(LPC_USART3, UART_IER_RBRINT);
		 Chip_SCU_PinMux(2, 3, MD_PDN, FUNC2);              /* P2_3: UART3_TXD */
	     Chip_SCU_PinMux(2, 4, MD_PLN|MD_EZI|MD_ZI, FUNC2); /* P2_4: UART3_RXD */
	     break;
}
}

void printf_uart(LPC_USART_T *pUART, char buffer_tx[])
{
   uint8_t i = 0;
   uint64_t j;
   while (buffer_tx[i]!='\0')
   {

	 while(((Chip_UART_ReadLineStatus((LPC_USART_T *)pUART) & UART_LSR_THRE) == 0)){}

     /* send first byte */
	Chip_UART_SendByte((LPC_USART_T *)pUART, buffer_tx[i]);
	/* bytes written */

	/*delay*/
	for (j=0;j<50000;j++) asm  ("nop");

	i++;
   }
}

uint32_t uart_getChar(LPC_USART_T *pUART)
{
	if (Chip_UART_ReadLineStatus((LPC_USART_T *)pUART) & UART_LSR_RDR)
      		            return (uint32_t)Chip_UART_ReadByte((LPC_USART_T *)pUART);
}

void uart_readstring(LPC_USART_T *pUART, char buffer_rx[], uint8_t num_char)
{
	uint8_t i = 0;
	char char_actual='0', char_anterior;
	while (i<=(num_char-1))
	{
	 char_anterior=char_actual;
	 buffer_rx[i]=uart_getChar((LPC_USART_T *)pUART);
	 //if (Chip_UART_ReadLineStatus((LPC_USART_T *)pUART) & UART_LSR_RDR) i++;
	 char_actual=buffer_rx[i];
	 if (char_actual!=char_anterior) i++;
	}
    if (i==num_char) buffer_rx[i]='\0';
}
/* Initialize Interrupt for UART */









	/* Clearn interrupt */
	     //Chip_RIT_ClearInt(LPC_USART2);
	  // Chip_UART_Interrupt_Handler(LPC_USART2);
    //  led_on(LED3);
//     }


