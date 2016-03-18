/*
 * lcd.c
 *
 *  Created on: 15/01/16
 *  Author: Matias Leandro Ferraro
 */

#include "lcd.h"
#include "puertos.h"
LCD_DATA_Type data;
void lcd_init_port(void)
{
     port_pin(LCD_PORT,LCD_RS,MD_PLN,init_out);
     port_pin(LCD_PORT,LCD_EN,MD_PLN,init_out);
     port_pin(LCD_PORT,LCD4,MD_PLN,init_out);
     port_pin(LCD_PORT,LCD3,MD_PLN,init_out);
     port_pin(LCD_PORT,LCD2,MD_PLN,init_out);
     port_pin(LCD_PORT,LCD1,MD_PLN,init_out);

}
void lcd_init(void)
{

//---------------------------------------------------
//INICIALIZACION
//---------------------------------------------------
//1)-----------D7,D6,D5,D4=0011------------------
    delay();
    data.D1=1;
    data.D2=1;
    data.D3=0;
    data.D4=0;
    data.RS=0;
    enviar_lcd(data);
    delay();
//2)-----------D7,D6,D5,D4=0011------------------
    delay();
    data.D1=1;
    data.D2=1;
    data.D3=0;
    data.D4=0;
    data.RS=0;
    enviar_lcd(data);
    delay();
//3)-----------D7,D6,D5,D4=0011------------------
    delay();
    data.D1=1;
    data.D2=1;
    data.D3=0;
    data.D4=0;
    data.RS=0;
    enviar_lcd(data);
    delay();
//4)-----------D7,D6,D5,D4=0010------------------
    delay();
    data.D1=0;
    data.D2=1;
    data.D3=0;
    data.D4=0;
    data.RS=0;
    enviar_lcd(data);
    delay();
//5)---PRIMERO--------D7,D6,D5,D4=0010------------------
///----DESPUES--------D7,D6,D5,D4=1111------------------
//D7=1 UNA LINEA, D7=0 DOS LINEAS
//D6=1 5x7 PUNTOS, D6=1 5x10 PUNTOS
//D5=X
//D4=X
    delay();
    data.D1=0;
    data.D2=1;
    data.D3=0;
    data.D4=0;
    data.RS=0;
    enviar_lcd(data);
    delay();
    data.D1=1;
    data.D2=1;
    data.D3=1;
    data.D4=1;
    data.RS=0;
    enviar_lcd(data);
//6)---PRIMERO--------D7,D6,D5,D4=0000------------------
///----DESPUES--------D7,D6,D5,D4=1000------------------
    delay();
    data.D1=0;
    data.D2=0;
    data.D3=0;
    data.D3=0;
    data.RS=0;
    enviar_lcd(data);
    delay();
    data.D1=0;
    data.D2=0;
    data.D3=0;
    data.D4=1;
    data.RS=0;
    enviar_lcd(data);
    delay();
//7)---PRIMERO--------D7,D6,D5,D4=0000------------------
///----DESPUES--------D7,D6,D5,D4=0001------------------
    delay();
    data.D1=0;
    data.D2=0;
    data.D3=0;
    data.D4=0;
    data.RS=0;
    enviar_lcd(data);
    delay();
    data.D1=1;
    data.D2=0;
    data.D3=0;
    data.D4=0;
    data.RS=0;
    enviar_lcd(data);
    delay();
//8)---PRIMERO--------D7,D6,D5,D4=0000------------------
///----DESPUES--------D7,D6,D5,D4=0110------------------
//D7=0
//D6=1
//D5=1 I/D--> D5=1 EL CURSOR Y LA FUNCION DE PARPADEO SE MUEVEN
//SOBRE EL DISPLAY UNA POSICION A LA DERECHA D5=0 A LA IZQUIERDA
//D4=0   S--> D4=1 EL DISPLAY ENTERO SE DESPLAZA UNA POSICION A
//LA IZQUIERDA, D4=0 NO SE DESPLAZA

    delay();
    data.D1=0;
    data.D2=0;
    data.D3=0;
    data.D4=0;
    data.RS=0;
    enviar_lcd(data);
    delay();
    data.D1=0;
    data.D2=1;
    data.D3=1;
    data.D4=0;
    data.RS=0;
    enviar_lcd(data);
    delay();

//-----------------------------------------------
// FIN INICIALIZACION
//----------------------------------------------
//DISPLAY ON/OFF
///---PRIMERO--------D7,D6,D5,D4=0000------------------
///----DESPUES-------D7,D6,D5,D4=1100------------------
//D7=1
//D6=1 D--> D6=1 EL DISPLAY SE HABILITA, D=0 EL DISPLAY SE APAGA
//D5=0  C--> D5=1 EL CURSOR SE MUESTRA EN LA POSICION DEFINIDA POR AC D5=0
//NO SE MUESTRA EN PANTALLA
//D4=0 B--> D4=1 EL CARACTER  QUE SE MUESTRA EN LA POSICION DEL CURSOR PARPADEA,
//D4=0 LA FUNCION PARPADEO QUEDA DESHABILITADA
//LA IZQUIERDA, D4=0 NO SE DESPLAZA

    delay();
    data.D1=0;
    data.D2=0;
    data.D3=0;
    data.D4=0;
    data.RS=0;
    enviar_lcd(data);
    delay();
    data.D1=0;
    data.D2=0;
    data.D3=1;
    data.D4=1;
    data.RS=0;
    enviar_lcd(data);
    delay();
}

void lcd_gotoxy(int x, int y)
{
//numeracion de los caracteres dentro del display
//    1    2    3    4    5    6    7     8   9    10   11   12   13   14   15   16 (columnas)
//	<---><---><---><---><---><---><---><---><---><---><---><---><---><---><---><--->
//  < 0..........................................................................79> linea 1
//  <64.........................................................................101> linea 2
//  <---><---><---><---><---><---><---><---><---><---><---><---><---><---><---><--->
   int address;
   LCD_DATA_Type data;
   int nibble;
   switch(y)
   {
     case 1: address = 0;
     break;
     case 2: address = 64;
     break;
   }
//primero envio tres bits de direccion y d7=1, luego cuatro bits mas de direccion
   address =(address+(x-1));
   delay();
   data.D1=(!!(address & 16));
   data.D2=(!!(address & 32));
   data.D3=(!!(address & 64));
   data.D4=1;
   data.RS=0;
   enviar_lcd(data);
   delay();
   data.D1=(!!(address & 1));
   data.D2=(!!(address & 2));
   data.D3=(!!(address & 4));
   data.D4=(!!(address & 8));
   data.RS=0;
   enviar_lcd(data);
}

void lcd_putc(char C)
{
   LCD_DATA_Type data;
   int nibble;
   switch(C)
      {
       case '\f':
       break;
       case '\n':
       break;
       case '\b'://borra pantalla
                delay();
    	        data.D1=0;
    	        data.D2=0;
    	        data.D3=0;
    	        data.D4=0;
    	        data.RS=0;
    	        enviar_lcd(data);
    	        delay();
    	        data.D1=1;
    	        data.D2=0;
    	        data.D3=0;
    	        data.D4=0;
    	        data.RS=0;
    	        enviar_lcd(data);
    	        delay();
       break;
       default:
                nibble= (int) C;
                data.D1=(!!(nibble & 16));
                data.D2=(!!(nibble & 32));
                data.D3=(!!(nibble & 64));
                data.D4=(!!(nibble & 128));
                data.RS=1;
                enviar_lcd(data);
                delay();
                data.D1=(!!(nibble & 1));
                data.D2=(!!(nibble & 2));
                data.D3=(!!(nibble & 4));
                data.D4=(!!(nibble & 8));
                data.RS=1;
                enviar_lcd(data);
                delay();
       break;
       }
}
void enviar_lcd (LCD_DATA_Type data)
{
   if (data.D1==1)	port_pin(LCD_PORT,LCD1, disable, high);
	else		port_pin(LCD_PORT,LCD1, disable, low);
   if (data.D2==1)	port_pin(LCD_PORT,LCD2, disable, high);
    else		port_pin(LCD_PORT,LCD2, disable, low);
   if (data.D3==1)	port_pin(LCD_PORT,LCD3, disable, high);
	else		port_pin(LCD_PORT,LCD3, disable, low);
   if (data.D4==1)	port_pin(LCD_PORT,LCD4, disable, high);
	else		port_pin(LCD_PORT,LCD4, disable, low);
   if (data.RS==1)	port_pin(LCD_PORT,LCD_RS, disable, high);
	else		port_pin(LCD_PORT,LCD_RS, disable, low);
   delay();
   port_pin(LCD_PORT,LCD_EN, disable, high);
   delay();
   port_pin(LCD_PORT,LCD_EN, disable, low);
   delay();
}
void printf_lcd(char * string)
{
   int c=0;
   while (string[c]!='\0')
   {
      lcd_putc(string[c]);
      c++;
   }
}
void delay(void)
{
   long int i=0,x=0;
   for(i=0; i<9999; i++){x++;}//
}

