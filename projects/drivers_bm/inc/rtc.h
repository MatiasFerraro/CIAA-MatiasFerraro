/*
 * rtc.h
 *
 *  Created on: 15/01/16
 *      Author: Matias Leandro Ferraro
 */



#include "chip.h"
#include "stdint.h"
#include "lcd.h"
#include "rtc_18xx_43xx.h"

void rtc_init(void);
void rtc_set(int SECOND, int MINUTE, int HOUR, int DAYOFMONTH, int DAYOFWEEK, int DAYOFYEAR, int MONTH, int YEAR);
int  rtc_get_parametro(RTC_TIMEINDEX_T time);
void rtc_printf(int X ,int Y, RTC_TIMEINDEX_T time);

