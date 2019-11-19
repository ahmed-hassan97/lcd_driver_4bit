/*
 * driver_lcd.c
 *
 * Created: 8/23/2019 10:14:46 AM
 *  Author: A
 */ 


#include "macro.h"
#include "LCD_DRIVER.h"

int main(void)
{
	lcd_init();
    lcd_write_string("ahmed hassan");
	lcd_set_cursor(2,1);
	lcd_write_num(10000);
    while(1)
    {
	
	
    }
}
