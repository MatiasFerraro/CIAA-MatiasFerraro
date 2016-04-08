/*
 * adc.c
 *
 *  Created on: 31/01/2016
 *      Author: Matias Leandro Ferraro
 */
#include "adc.h"


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
void delay_t(int time)
{
 int i,j;
  for(i=0;i<time;i++)
   for(j=0;j<2500;j++);
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
