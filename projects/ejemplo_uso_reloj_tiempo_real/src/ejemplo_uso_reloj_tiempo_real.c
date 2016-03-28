#include "ejemplo_uso_reloj_tiempo_real.h"
#ifndef CPU
#error CPU shall be defined
#endif
#if (lpc4337 == CPU)
#include "chip.h"
#elif (mk60fx512vlq15 == CPU)
#else
#endif
#include "rtc.h"
#include "rtc_18xx_43xx.h"
#include "chip.h"
#include "stdint.h"

#include "lpc_types.h"
int sec_anterior=0;
int main(void)
{
   RTC_TIME_T FullTime;
   leds_init();
   lcd_init_port();
   lcd_init();

   rtc_set(0,1,14,16,6,16,1,2016);
   rtc_init();
   lcd_gotoxy(1, 1);
   printf_lcd("Hora:\0");
   lcd_gotoxy(9, 1);
   lcd_putc(':');
   lcd_gotoxy(12, 1);
   lcd_putc(':');
   lcd_gotoxy(1, 2);
   printf_lcd("Fecha:\0");
   lcd_gotoxy(9, 2);
   lcd_putc('/');
   lcd_gotoxy(12, 2);
   lcd_putc('/');
   while(1)
   {
	   rtc_printf(7,1, RTC_TIMETYPE_HOUR);
       rtc_printf(10,1, RTC_TIMETYPE_MINUTE);
       rtc_printf(13,1, RTC_TIMETYPE_SECOND);

       rtc_printf(7,2, RTC_TIMETYPE_DAYOFMONTH);
       rtc_printf(10,2, RTC_TIMETYPE_MONTH);
       rtc_printf(13,2, RTC_TIMETYPE_YEAR);

   }
}
