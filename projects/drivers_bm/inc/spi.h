/*
 * uart.h
 *
 *  Created on: 31/01/2016
 *      Author: Matias Leandro Ferraro
 */
#include "stdint.h"
#include "ciaaPOSIX_stdbool.h"
#include "chip.h"
#include "scu_18xx_43xx.h"



//uint8_t *bufferTx[BUFFER_SIZE];
//uint8_t *bufferRx[BUFFER_SIZE];
void Board_SSP_Init(void);
//void Board_SSP_config(uint8_t bits, uint8_t clockMode, uint32_t bitrate);
uint32_t Board_SSP_writeBuffer(const uint8_t *buffer, uint32_t bufferLen);
uint32_t Board_SSP_readBuffer(uint8_t *buffer, uint32_t bufferLen);
uint32_t Board_SSP_transfer(uint8_t *bufferTx, uint8_t *bufferRx, uint32_t bufferLen);
//void Buffer_Init(void);
