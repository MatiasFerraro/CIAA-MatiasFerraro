/*
 * uart.h
 *
 *  Created on: 31/01/2016
 *      Author: Matias Leandro Ferraro
 */
#include "stdint.h"
#include "ciaaPOSIX_stdbool.h"
#include "chip.h"
#include "lpc_types.h"
#define USART0 0
#define USART2 2
#define USART3 3
#define max_long_buff_rx 15
void uart_init(uint8_t usart, uint32_t baud);
void printf_uart(LPC_USART_T *pUART, char buffer_tx[]);
uint32_t uart_getChar(LPC_USART_T *pUART);
void uart_readstring(LPC_USART_T *pUART, char buffer_rx[], uint8_t num_char);
void UART2_IRQHandler();
