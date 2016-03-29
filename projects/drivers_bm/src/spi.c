/*
 * uart.c
 *
 *  Created on: 31/01/2016
 *      Author: Matias Leandro Ferraro
 */
#include "spi.h"
//================================================[SPI Management]========================================================

void Board_SSP_Init(void)
{
	Chip_SCU_PinMuxSet(0xF, 4, (SCU_PINIO_FAST | SCU_MODE_FUNC0));  /* PF.4 => SCK1 */
	//Chip_GPIO_SetPinDIR(LPC_GPIO_PORT, 7, pin+14,FUNC0);
	Chip_SCU_PinMuxSet(0x1, 4, (SCU_MODE_INACT | SCU_MODE_INBUFF_EN | SCU_MODE_ZIF_DIS | SCU_MODE_FUNC5)); /* P1.4 => MOSI1 */
<<<<<<< HEAD
   // Chip_GPIO_SetPinDIR(LPC_GPIO_PORT, 0, 11, FUNC5);
=======
	//Chip_GPIO_SetPinDIR(LPC_GPIO_PORT, 0, 11, FUNC5);
>>>>>>> 274712184375b9f4cea9785f942a8561e451895b
	Chip_SCU_PinMuxSet(0x1, 3, (SCU_MODE_INACT | SCU_MODE_INBUFF_EN | SCU_MODE_ZIF_DIS | SCU_MODE_FUNC5)); /* P1.3 => MISO1 */
	//Chip_GPIO_SetPinDIR(LPC_GPIO_PORT, 0, 10, FUNC5);
}

void Board_SSP_config(uint8_t bits, uint8_t clockMode, uint32_t bitrate)
{
	uint32_t bitsConfig= SSP_BITS_8;
	switch(bits)
	{
		case 4: bitsConfig=SSP_BITS_4;break;
		case 8: bitsConfig=SSP_BITS_8;break;
		case 16: bitsConfig=SSP_BITS_16;break;
	}
<<<<<<< HEAD
	uint32_t clockModeConfig = SSP_CLOCK_CPHA1_CPOL1;
=======
	uint32_t clockModeConfig = SSP_CLOCK_CPHA0_CPOL0;
>>>>>>> 274712184375b9f4cea9785f942a8561e451895b
	switch(clockMode)
	{
		case 0: clockModeConfig = SSP_CLOCK_CPHA0_CPOL0;break;
		case 1: clockModeConfig = SSP_CLOCK_CPHA1_CPOL0;break;
		case 2: clockModeConfig = SSP_CLOCK_CPHA0_CPOL1;break;
		case 3: clockModeConfig = SSP_CLOCK_CPHA1_CPOL1;break;
	}
        Chip_SSP_Init(LPC_SSP1);
        Chip_SSP_SetFormat(LPC_SSP1, bitsConfig, SSP_FRAMEFORMAT_SPI, clockModeConfig);
        Chip_SSP_SetBitRate(LPC_SSP1, bitrate);
        Chip_SSP_Enable(LPC_SSP1);

}

uint32_t Board_SSP_writeBuffer(const uint8_t *buffer, uint32_t bufferLen)
{

	return Chip_SSP_WriteFrames_Blocking(LPC_SSP1, *buffer, bufferLen);
}
uint32_t Board_SSP_readBuffer(uint8_t *buffer, uint32_t bufferLen)
{
	return Chip_SSP_ReadFrames_Blocking(LPC_SSP1,*buffer, bufferLen);
}
uint32_t Board_SSP_transfer(uint8_t *bufferTx, uint8_t *bufferRx, uint32_t bufferLen)
{
	Chip_SSP_DATA_SETUP_T spiSetup;
	spiSetup.tx_data = bufferTx;
	spiSetup.rx_data = bufferRx;
	spiSetup.tx_cnt=0;
	spiSetup.rx_cnt=0;
	spiSetup.length=bufferLen;

	return Chip_SSP_RWFrames_Blocking(LPC_SSP1, &spiSetup);
}

//===========================================================================================================================




