/*
 * rtc.c
 *
 *  Created on: 15/01/16
 *      Author: Matias Leandro Ferraro
 */
#include "rtc.h"


void rtc_init(void)
{
    Chip_RTC_Init(LPC_RTC);
	Chip_RTC_Enable(LPC_RTC, ENABLE);
}
void rtc_set(int SECOND, int MINUTE, int HOUR, int DAYOFMONTH,
		            int DAYOFWEEK, int DAYOFYEAR, int MONTH, int YEAR)
{
	RTC_TIME_T FullTime;

	FullTime.time[RTC_TIMETYPE_SECOND]    = SECOND;
	FullTime.time[RTC_TIMETYPE_MINUTE]    = MINUTE;
	FullTime.time[RTC_TIMETYPE_HOUR]      = HOUR;
	FullTime.time[RTC_TIMETYPE_DAYOFMONTH]= DAYOFMONTH;
	FullTime.time[RTC_TIMETYPE_DAYOFWEEK] = DAYOFWEEK;
	FullTime.time[RTC_TIMETYPE_DAYOFYEAR] = DAYOFYEAR;
	FullTime.time[RTC_TIMETYPE_MONTH]     = MONTH;
	FullTime.time[RTC_TIMETYPE_YEAR]      = YEAR;
    Chip_RTC_SetFullTime(LPC_RTC, &FullTime);
}


int rtc_get_parametro(RTC_TIMEINDEX_T time)
{
	RTC_TIME_T FullTime_;
	Chip_RTC_GetFullTime(LPC_RTC, &FullTime_);
    return(FullTime_.time[time]);
}

void rtc_printf(int X ,int Y, RTC_TIMEINDEX_T time)
{
   RTC_TIME_T FullTime_;
   char aux[6];
   static int anterior[8];
   Chip_RTC_GetFullTime(LPC_RTC, &FullTime_);
   itoa (FullTime_.time[time],aux,10);
   if (FullTime_.time[time]!=anterior[time])
   {
     if (time==0)
     {
       lcd_gotoxy(X, Y);
       printf_lcd("  ");
     }
     if (FullTime_.time[time]<=9)
     {
    	lcd_gotoxy(X, Y);
    	printf_lcd("0");
     }else lcd_gotoxy(X, Y);
     printf_lcd(strcat(aux,"\0"));
     anterior[time]=FullTime_.time[time];
   }


}
