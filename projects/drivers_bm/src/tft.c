/*
 * tft.c
 *
 *  Created on: 02/04/16
 *      Author: Matias Leandro Ferraro
 */
#include "puertos.h"
#include "spi.h"
#include "tft.h"
#include "font8x16.h"
void  write_data(uint8_t hexa)
{
    port_pin(4,9, disable, low);  //cs=0
	port_pin(4,10, disable, high);//rs=1
    write_spi_XXh(LPC_SSP,hexa);
	port_pin(4,9, disable, high); //cs=1
}
void  write_command(uint8_t hexa)
{
    port_pin(4,9, disable, low);  //cs=0
	port_pin(4,10, disable, low); //rs=0
	write_spi_XXh(LPC_SSP,hexa);
	port_pin(4,9, disable, high); //cs=1
}
void write_com16(uint16_t double_hexa)
{
    write_data(double_hexa>>8);
	port_pin(4,9, disable, low);   //cs=0
    port_pin(4,10, disable, high); //rs=1
    write_data(double_hexa);
}

void write_dat16(uint16_t double_hexa)
{
   write_data(double_hexa>>8);
   write_data(double_hexa);
}
void tft_single_colour(uint16_t double_hexa)
{
 unsigned int i,j;
 tft_addres_set(0,0);
 for (i=0;i<320;i++)
    for (j=0;j<240;j++)
    	write_com16(double_hexa);

}
void tft_sleep(void)
{
  write_command(0x28);//Display off
  tft_delay(20);
  write_command(0x10);//Enter Sleep mode
}
void tft_exit_sleep(void)
{
  write_command(0x11);//Exit Sleep
  tft_delay(120);
  write_command(0x29);//Display on
  write_command(0x2C);
}
void tft_addres_set(unsigned int x,unsigned int y)
{

	write_command(ILI9341_CASET); // Column addr set
	write_com16(x);
	write_command(ILI9341_PASET); // Row addr set
	write_com16(y);
	write_command(ILI9341_RAMWR); // write to RAM
}
static void tft_set_pos(unsigned int x0,unsigned int x1,unsigned int y0,unsigned int y1)
{
   write_command(0x2A);
   write_data(x0>>8);
   write_data(x0);
   write_data(x1>>8);
   write_data(x1);

   write_command(0x2B);
   write_data(y0>>8);
   write_data(y0);
   write_data(y1>>8);
   write_data(y1);
   write_command(0x2c);
}
void tft_delay(int time)
{
 int i,j;
  for(i=0;i<time;i++)
   for(j=0;j<2500;j++);
}
void tft_hardware_reset ()
{
  // LCD Reset
	  port_pin(0,0, disable, high);// reset=1;
	  tft_delay(100);
	  port_pin(0,0, disable, low);// reset=0;
	  tft_delay(100);
	  port_pin(0,0, disable, high);// reset=1;
	  tft_delay(120);
}
void tft_putc(uint32_t x, uint32_t y, char *c, uint16_t fColor,uint16_t bColor)
{
 LCD_PutChar8x16( x, y, c, fColor, bColor );
}
void LCD_PutString(uint32_t x,uint32_t y,char *s,uint32_t fColor, uint32_t bColor) {
	uint32_t l=0;
	while(*s) {
		if( *s < 0x80)
		    {
			tft_putc(x+l*8,y,*s,fColor,bColor);
			s++;l++;
			}
		else
		    {
			LCD_PutChar8x16(x+l*8,y,*s,fColor,bColor);
			s+=2;l+=2;
			}
		}
	}

void printf_tft(uint32_t x, uint32_t y, char *string, uint16_t fColor, uint16_t bColor)
{
	int c=0,l=0;
    while (string[c]!='\0')
	{
	   LCD_PutChar8x16(x+l*8,y,string[c],fColor,bColor);
	   c++;
	   l++;
	}
}

void LCD_PutChar8x16(uint32_t x, uint32_t y, char *c, uint16_t fColor, uint16_t bColor)
{
 unsigned int i,j;
 tft_set_pos(x,x+8-1,y,y+16-1);
 for(i=0; i<16;i++) {
		 char m=Font8x16[*c*16+i];
		for(j=0;j<8;j++) {
			if((m&0x80)==0x80) {
				write_dat16(fColor);
				}
			else {
				write_dat16(bColor);
				}
			m<<=1;
			}
		}
}
void tft_init_a()
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
	write_data(0x23);       //VRH[5:0]

	write_command(0xC1);    //Power control
	write_data(0x10);       //SAP[2:0];BT[3:0]

	write_command(0xC5);    //VCM control
	write_data(0x3e);
	write_data(0x28);

	write_command(0xC7);    //VCM control2
	write_data(0x86);       //--

    write_command(0x36);    //Memory Access Control
	write_data(0x48); //C8	//48 68竖屏//28 E8 横屏

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
	tft_delay(120);
    write_command(0x29);    //Display on
	write_command(0x2C);
}
void tft_init_b()
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
    write_data(0x23);                 //VRH[5:0]

    write_command(ILI9341_PWCTR2);    //Power control
    write_data(0x10);                 //SAP[2:0];BT[3:0]

    write_command(ILI9341_VMCTR1);    //VCM control
    write_data(0x3E); //对比度调节
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

    write_command(ILI9341_DFUNCTR);   // Display Function Control
    write_data(0x08);
    write_data(0x82);
    write_data(0x27);

    write_command(0xF2);              // 3Gamma Function Disable
    write_data(0x00);

    write_command(ILI9341_GAMMASET);   //Gamma curve selected
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
    tft_delay(120);
    write_command(ILI9341_DISPON);    //Display on
}

void tft_init_c()
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
   tft_delay(120);

   write_command (0x29); // Display on
   write_command (0x2c);
 }



