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
#define ILI9341_TFTWIDTH  240
#define ILI9341_TFTHEIGHT 320

#define ILI9341_NOP     0x00
#define ILI9341_SWRESET 0x01
#define ILI9341_RDDID   0x04
#define ILI9341_RDDST   0x09

#define ILI9341_SLPIN   0x10
#define ILI9341_SLPOUT  0x11
#define ILI9341_PTLON   0x12
#define ILI9341_NORON   0x13

#define ILI9341_RDMODE  0x0A
#define ILI9341_RDMADCTL  0x0B
#define ILI9341_RDPIXFMT  0x0C
#define ILI9341_RDIMGFMT  0x0A
#define ILI9341_RDSELFDIAG  0x0F

#define ILI9341_INVOFF  0x20
#define ILI9341_INVON   0x21
#define ILI9341_GAMMASET 0x26
#define ILI9341_DISPOFF 0x28
#define ILI9341_DISPON  0x29

#define ILI9341_CASET   0x2A
#define ILI9341_PASET   0x2B
#define ILI9341_RAMWR   0x2C
#define ILI9341_RAMRD   0x2E

#define ILI9341_PTLAR   0x30
#define ILI9341_MADCTL  0x36
#define ILI9341_PIXFMT  0x3A

#define ILI9341_FRMCTR1 0xB1
#define ILI9341_FRMCTR2 0xB2
#define ILI9341_FRMCTR3 0xB3
#define ILI9341_INVCTR  0xB4
#define ILI9341_DFUNCTR 0xB6

#define ILI9341_PWCTR1  0xC0
#define ILI9341_PWCTR2  0xC1
#define ILI9341_PWCTR3  0xC2
#define ILI9341_PWCTR4  0xC3
#define ILI9341_PWCTR5  0xC4
#define ILI9341_VMCTR1  0xC5
#define ILI9341_VMCTR2  0xC7

#define ILI9341_RDID1   0xDA
#define ILI9341_RDID2   0xDB
#define ILI9341_RDID3   0xDC
#define ILI9341_RDID4   0xDD

#define ILI9341_GMCTRP1 0xE0
#define ILI9341_GMCTRN1 0xE1
/*
#define ILI9341_PWCTR6  0xFC

*/

// Color definitions
#define ILI9341_BLACK       0x0000      /*   0,   0,   0 */
#define ILI9341_NAVY        0x000F      /*   0,   0, 128 */
#define ILI9341_DARKGREEN   0x03E0      /*   0, 128,   0 */
#define ILI9341_DARKCYAN    0x03EF      /*   0, 128, 128 */
#define ILI9341_MAROON      0x7800      /* 128,   0,   0 */
#define ILI9341_PURPLE      0x780F      /* 128,   0, 128 */
#define ILI9341_OLIVE       0x7BE0      /* 128, 128,   0 */
#define ILI9341_LIGHTGREY   0xC618      /* 192, 192, 192 */
#define ILI9341_DARKGREY    0x7BEF      /* 128, 128, 128 */
#define ILI9341_BLUE        0x001F      /*   0,   0, 255 */
#define ILI9341_GREEN       0x07E0      /*   0, 255,   0 */
#define ILI9341_CYAN        0x07FF      /*   0, 255, 255 */
#define ILI9341_RED         0xF800      /* 255,   0,   0 */
#define ILI9341_MAGENTA     0xF81F      /* 255,   0, 255 */
#define ILI9341_YELLOW      0xFFE0      /* 255, 255,   0 */
#define ILI9341_WHITE       0xFFFF      /* 255, 255, 255 */
#define ILI9341_ORANGE      0xFD20      /* 255, 165,   0 */
#define ILI9341_GREENYELLOW 0xAFE5      /* 173, 255,  47 */
#define ILI9341_PINK        0xF81F
#define INTERRUPT_MODE      0
#define LPC_SSP             LPC_SSP1
#define SSP_MODE_TEST       1/*1: Master, 0: Slave */
#define SSP_DATA_BITS       (SSP_BITS_8)
#define BUFFER_SIZE         8
typedef SPI_DATA[8];

typedef struct {
	SPI_DATA      *tx_data;	/*!< Pointer to transmit data */
	uint32_t  tx_cnt;	/*!< Transmit counter */
	SPI_DATA      *rx_data;	/*!< Pointer to transmit data */
	uint32_t  rx_cnt;	/*!< Receive counter */
	uint32_t  length;	/*!< Length of transfer data */
} Chip_SSP_DATA_SETUP_T_;

static SSP_ConfigFormat ssp_format;
static Chip_SSP_DATA_SETUP_T_ xf_setup;
/* Tx buffer */
 static uint8_t Tx_Buf[BUFFER_SIZE];

 /* Rx buffer */
static uint8_t Rx_Buf[BUFFER_SIZE];
void invierte (char *dest, const char *orig)
{
int i=0, j;
j = strlen(orig);
while (j--) dest[i++] = orig[j];
}


int aschex2int(char d){          // Convierte un caracter ascii hex a int

   int r=0;                       // Declaro e inicializo a cero el resultado
   if(isxdigit(d)){               // Si es un digito hexadecimal ...
      if(isdigit(d)){             // si es un digito decimal ...
         r=d-'0';                 // devuelvo su diferencia con el valor ascii del caracter "0"
      }
      if(isalpha(d)){             // si es alfanumerico ...
         d=toupper(d);            // lo paso a mayusculas y ...
         r=10+(d-'A');            // devuelvo 10 mas su diferencia con el valor ascii de la letra "A"
      }
   }
   return(r);
}
//SPI_DATA hex_bin(char hex)
//{
//	int byte;
//	SPI_DATA data;

	//byte= Hexadecimal_a_Decimal(hex);
	//data[0]=(!!(byte & 1));
	//data[1]=(!!(byte & 2));
	//data[2]=(!!(byte & 4));
	//data[3]=(!!(byte & 8));
	//data[4]=(!!(byte & 16));
	//data[5]=(!!(byte & 32));
	//data[6]=(!!(byte & 64));
	//data[7]=(!!(byte & 128));
 //return(data);
//}


void delay(uint time)
{
 uint i,j;
  for(i=0;i<time;i++)
   for(j=0;j<2500;j++);
}
void  write_data(uint8_t hexa)
{

	port_pin(4,9, disable, low);  //cs=0
	port_pin(4,10, disable, high);//dc=1
    xf_setup.length = sizeof(hexa);
    xf_setup.rx_data = Rx_Buf;
	xf_setup.rx_cnt = xf_setup.tx_cnt = 0;
	xf_setup.tx_data= hexa;
	Chip_SSP_Enable(LPC_SSP);
	Chip_SSP_RWFrames_Blocking(LPC_SSP, &xf_setup);
	port_pin(4,9, disable, high);//cs=1

}


void  write_command(uint8_t hexa)
{
	port_pin(4,9, disable, low);//cs=0
	port_pin(4,10, disable, low);//dc=0
    xf_setup.length = sizeof(hexa);
	xf_setup.rx_data = Rx_Buf;
    xf_setup.rx_cnt = xf_setup.tx_cnt = 0;
    xf_setup.tx_data= hexa;
    Chip_SSP_Enable(LPC_SSP);
    Chip_SSP_RWFrames_Blocking(LPC_SSP, &xf_setup);
    port_pin(4,9, disable, high);//cs=1

}
void wr_com16(uint8_t hexa1,uint8_t hexa2)
{

	port_pin(4,9, disable, low);//cs=0
	port_pin(4,10, disable, high);//dc=1
	xf_setup.length = sizeof(hexa1);
	xf_setup.rx_data = Rx_Buf;
	xf_setup.rx_cnt = xf_setup.tx_cnt = 0;
	xf_setup.tx_data = hexa1;
	Chip_SSP_RWFrames_Blocking(LPC_SSP, &xf_setup);

	port_pin(4,9, disable, high);//cs=0
    port_pin(4,9, disable, low);//cs=1
	port_pin(4,10, disable, high);//dc=1

	xf_setup.length = sizeof(hexa2);
    xf_setup.rx_data = Rx_Buf;
	xf_setup.rx_cnt = xf_setup.tx_cnt = 0;
	xf_setup.tx_data= hexa2;
	Chip_SSP_RWFrames_Blocking(LPC_SSP, &xf_setup);
    port_pin(4,9, disable, high);//cs=1
}
//////////////////////////////////////////////////////////////////////////////////////////////

void lcd_initial()
{

	 write_data(0x39);
	        write_data(0x2C);
	        write_data(0x00);
	        write_data(0x34);
	        write_data(0x02);

	        write_command(0xCF);
	        write_data(0x00);
	        write_data(0XC1);
	        write_data(0X30);

	        write_command(0xE8);
	        write_data(0x85);
	        write_data(0x00);
	        write_data(0x78);

	        write_command(0xEA);
	        write_data(0x00);
	        write_data(0x00);

	        write_command(0xED);
	        write_data(0x64);
	        write_data(0x03);
	        write_data(0X12);
	        write_data(0X81);

	        write_command(0xF7);
	        write_data(0x20);

	        write_command(0xC0);    //Power control
	        write_data(0x23);   //VRH[5:0]

	        write_command(0xC1);    //Power control
	        write_data(0x10);   //SAP[2:0];BT[3:0]

	        write_command(0xC5);    //VCM control
	        write_data(0x3e); //¶Ô±È¶Èµ÷½Ú
	        write_data(0x28);

	        write_command(0xC7);    //VCM control2
	        write_data(0x86);  //--

	        write_command(0x36);    // Memory Access Control
	        write_data(0x48); //C8	   //48 68ÊúÆÁ//28 E8 ºáÆÁ

	        write_command(0x3A);
	        write_data(0x55);

	        write_command(0xB1);
	        write_data(0x00);
	        write_data(0x18);

	        write_command(0xB6);    // Display Function Control
	        write_data(0x08);
	        write_data(0x82);
	        write_data(0x27);

	        write_command(0xF2);    // 3Gamma Function Disable
	        write_data(0x00);

	        write_command(0x26);    //Gamma curve selected
	        write_data(0x01);

	        write_command(0xE0);    //Set Gamma
	        write_data(0x0F);
	        write_data(0x31);
	        write_data(0x2B);
	        write_data(0x0C);
	        write_data(0x0E);
	        write_data(0x08);
	        write_data(0x4E);
	        write_data(0xF1);
	        write_data(0x37);
	        write_data(0x07);
	        write_data(0x10);
	        write_data(0x03);
	        write_data(0x0E);
	        write_data(0x09);
	        write_data(0x00);

	        write_command(0XE1);    //Set Gamma
	        write_data(0x00);
	        write_data(0x0E);
	        write_data(0x14);
	        write_data(0x03);
	        write_data(0x11);
	        write_data(0x07);
	        write_data(0x31);
	        write_data(0xC1);
	        write_data(0x48);
	        write_data(0x08);
	        write_data(0x0F);
	        write_data(0x0C);
	        write_data(0x31);
	        write_data(0x36);
	        write_data(0x0F);
	        write_command(0x11);    //Exit Sleep
	               delay(120);

	               write_command(0x29);    //Display on
	               write_command(0x2C);


      led_on(LED3);
}
void lcd_initial_adafruitIIL9341()
{

write_command(0xEF);
 write_data(0x03);
 write_data(0x80);
 write_data(0x02);

 write_command(0xCF);
 write_data(0x00);
 write_data(0XC1);
 write_data(0X30);

 write_command(0xED);
 write_data(0x64);
 write_data(0x03);
 write_data(0X12);
 write_data(0X81);

 write_command(0xE8);
 write_data(0x85);
 write_data(0x00);
 write_data(0x78);

 write_command(0xCB);
 write_data(0x39);
 write_data(0x2C);
 write_data(0x00);
 write_data(0x34);
 write_data(0x02);

 write_command(0xF7);
 write_data(0x20);

 write_command(0xEA);
 write_data(0x00);
 write_data(0x00);

 write_command(ILI9341_PWCTR1);    //Power control
 write_data(0x23);   //VRH[5:0]

 write_command(ILI9341_PWCTR2);    //Power control
 write_data(0x10);   //SAP[2:0];BT[3:0]

 write_command(ILI9341_VMCTR1);    //VCM control
 write_data(0x3E); //¶Ô±È¶Èµ÷½Ú
 write_data(0x28);

 write_command(ILI9341_VMCTR2);    //VCM control2
 write_data(0x86);  //--

 write_command(ILI9341_MADCTL);    // Memory Access Control
 write_data(0x48);

 write_command(ILI9341_PIXFMT);
 write_data(0x55);

 write_command(ILI9341_FRMCTR1);
 write_data(0x00);
 write_data(0x18);

 write_command(ILI9341_DFUNCTR);    // Display Function Control
 write_data(0x08);
 write_data(0x82);
 write_data(0x27);

 write_command(0xF2);    // 3Gamma Function Disable
 write_data(0x00);

 write_command(ILI9341_GAMMASET);    //Gamma curve selected
 write_data(0x01);

 write_command(ILI9341_GMCTRP1);    //Set Gamma
 write_data(0x0F);
 write_data(0x31);
 write_data(0x2B);
 write_data(0x0C);
 write_data(0x0E);
 write_data(0x08);
 write_data(0x4E);
 write_data(0xF1);
 write_data(0x37);
 write_data(0x07);
 write_data(0x10);
 write_data(0x03);
 write_data(0x0E);
 write_data(0x09);
 write_data(0x00);

 write_command(ILI9341_GMCTRN1);    //Set Gamma
 write_data(0x00);
 write_data(0x0E);
 write_data(0x14);
 write_data(0x03);
 write_data(0x11);
 write_data(0x07);
 write_data(0x31);
 write_data(0xC1);
 write_data(0x48);
 write_data(0x08);
 write_data(0x0F);
 write_data(0x0C);
 write_data(0x31);
 write_data(0x36);
 write_data(0x0F);

 write_command(ILI9341_SLPOUT);    //Exit Sleep

 delay(120);

 write_command(ILI9341_DISPON);    //Display on


}

void Initial_ILI9340C (void)
{
write_command (0xCB);
write_data (0x39);
write_data (0x2C);
write_data (0x00);
write_data (0x34);
write_data (0x02);

write_command(0xCF);
write_data (0x00);
write_data (0XC1);
write_data (0X30);

write_command (0xE8);
write_data (0x85);
write_data (0x00);
write_data (0x78);

write_command (0xEA);
write_data (0x00);
write_data (0x00);

write_command (0xED);
write_data (0x64);
write_data (0x03);
write_data (0X12);
write_data (0X81);

write_command (0xF7);
write_data (0x20);

write_command (0xC0); // Power control
write_data (0x23); // VRH [5:0]

write_command (0xC1); // Power control
write_data (0x10); // SAP [2:0]; BT [3:0]

write_command (0xC5); // VCM control
write_data (0x3e); // contrast adjustment
write_data (0x28);

write_command (0xC7); // VCM control2
write_data (0x86); // -

write_command (0x36); // Memory Access Control
write_data (0xC8);

write_command (0x3A);
write_data (0x55);

write_command (0xB1);
write_data (0x00);
write_data (0x18);

write_command (0xB6); // Display Function Control
write_data (0x08);
write_data (0x82);
write_data (0x27);

write_command (0xF2); // 3Gamma Function Disable
write_data (0x00);

write_command (0x26); // Gamma curve selected
write_data (0x01);

write_command (0xE0); // Set Gamma
write_data (0x0F);
write_data (0x31);
write_data (0x2B);
write_data (0x0C);
write_data (0x0E);
write_data (0x08);
write_data (0x4E);
write_data (0xF1);
write_data (0x37);
write_data (0x07);
write_data (0x10);
write_data (0x03);
write_data (0x0E);
write_data (0x09);
write_data (0x00);

write_command (0XE1); // Set Gamma
write_data (0x00);
write_data (0x0E);
write_data (0x14);
write_data (0x03);
write_data (0x11);
write_data (0x07);
write_data (0x31);
write_data (0xC1);
write_data (0x48);
write_data (0x08);
write_data (0x0F);
write_data (0x0C);
write_data (0x31);
write_data (0x36);
write_data (0x0F);

write_command (0x11); // Exit Sleep
Delay_ms (120);

write_command (0x29); // Display on
write_command (0x2c);

}

void addset(unsigned int x,unsigned int y)
{

	write_command(ILI9341_CASET); // Column addr set
	wr_com16(x>>8,x);
	write_command(ILI9341_PASET); // Row addr set
	wr_com16(y>>8,y);
	write_command(ILI9341_RAMWR); // write to RAM
}
 void Address_set (unsigned int x1, unsigned int x2, unsigned int y1, unsigned int y2)
 {
	     write_command (0x2a); // x -axis
	     write_data (x1);
	     write_data (x2);
         write_command(0x2b); // y -axis
         write_data (y1);
         write_data (y2);
         write_command(0x2c);
 }
 void LCD_TEST_SingleColor (uint8_t h,uint8_t l) {
 int i, j;
         Address_set (0,239,0,319);
         for (i=0;i<320; i++)
           for (j = 0;j<240;j++)
        	   wr_com16(h,l);


 }
 void dsp_single_colour(uint8_t DH,uint8_t DL)
{
 unsigned int i,j;
 addset(0,0);
 for (i=0;i<320;i++)
    for (j=0;j<240;j++)
        wr_com16(DH,DL);

}
 void LCD_Sleep_ILI9340C(void)
{
  write_command(0x28);//Display off
  delay(20);
  write_command(0x10);//Enter Sleep mode
}
void LCD_ExitSleep_ILI9340C(void)
{
  write_command(0x11);//Exit Sleep
  delay(120);
  write_command(0x29);//Display on
  write_command(0x2C);
}
/* Initialize buffer */
  void Buffer_Init(void)
   {
    uint16_t i;
    uint8_t ch = 0;

    for (i = 0; i < BUFFER_SIZE; i++) {
     Tx_Buf[i] = ch++;
     Rx_Buf[i] = 0xAA;
    }
   }

  void HD_reset () {
   // LCD Reset
	  port_pin(0,0, disable, high);// reset=1;
	  delay(10);
	  port_pin(0,0, disable, low);// reset=0;
	  delay(100);
	  port_pin(0,0, disable, high);// reset=1;
	  delay(120);
}
  void Delay_us (int value) //// delay function _us
  {
  while (value)
  value --;
  }
  void Delay_ms (int value) //// delay function _ms
  {
  while (value) {
  Delay_us (999);
  value--;
  }
  }

  main()
{
leds_init();

	// delay(500);

	 port_pin(4,10, SCU_MODE_INACT ,init_out);
    port_pin(4,9, SCU_MODE_INACT ,init_out);
    port_pin(0,0, SCU_MODE_INACT ,init_out);
//////////////////////////////////////////////////////////////////////////////////////////////////////
  //  Board_SSP_Init();

    //Chip_SSP_Init(LPC_SSP);

   // ssp_format.frameFormat = SSP_FRAMEFORMAT_SPI;
    //ssp_format.bits = SSP_DATA_BITS;
    //ssp_format.clockMode = SSP_CLOCK_CPHA0_CPOL0  ;
   // Chip_SSP_SetFormat(LPC_SSP,ssp_format.frameFormat, ssp_format.bits,  ssp_format.clockMode);
   // Chip_SSP_SetMaster(LPC_SSP, SSP_MODE_TEST);
   // Chip_SSP_Enable(LPC_SSP);
   // Buffer_Init();


//////////////////////////////////////////////////////////////////////////////////////////////////////


    Board_SSP_Init();


	Board_SSP_config(SSP_DATA_BITS,SSP_CLOCK_CPHA0_CPOL0 ,800000 );


    HD_reset ();
    Delay_ms (50) ;// delay 50ms
    lcd_initial_adafruitIIL9341();//lcd_initial();//////////Initial_ILI9340C();
    Delay_ms (300);
    // Test to enter / exit sleep



    //LCD_Sleep_ILI9340C ();
    //Delay_ms (300);
    //LCD_ExitSleep_ILI9340C ();
    //Display a black screen
    LCD_TEST_SingleColor (0xFF,0xE0);
    led_on(LED1);
    delay(50);

        dsp_single_colour(0xF8,0x1F);//rosa
        led_on(LED2);
        delay(50);

    while(1)
  {

   // Disp_gradscal(); //»Ò½×
    delay(5);
   LCD_Sleep_ILI9340C();
delay(500);
	LCD_ExitSleep_ILI9340C();
//# define Red 0xf800
		//LCD_TEST_SingleColor (Red);
		write_command(0x2C);



   dsp_single_colour(0x07,0xE0);//verde
   delay(50);


   dsp_single_colour(0xF8,0x00);//rojo
    delay(50);

    dsp_single_colour(0x07,0xE0);//verde


    dsp_single_colour(0x00,0x1F);//azul
   delay(50);


    }


  }


/** @} doxygen end group definition */
/** @} doxygen end group definition */
/** @} doxygen end group definition */
/*==================[end of file]============================================*/













