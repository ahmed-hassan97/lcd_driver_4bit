/*
 * LCD_DRIVER.c
 *
 * Created: 8/23/2019 10:16:46 AM
 *  Author: A
 */ 
#include "macro.h"
#include "LCD_DRIVER.h"

void lcd_init(){
init_port;
_delay_ms(5);
lcd_write_command(0x2);             //four bit mode
lcd_write_command(0x28);            //four bit mode
lcd_write_command(CLEAR);          //clear lcd
lcd_write_command(0xc);           //increment cursor
lcd_write_command(LINE_ONE);    //start first one
display_off_cursor;
_delay_ms(20);
 
	
}
void lcd_write_command(uint8_t cmd){
	
	RS(0);           //write command
	D7(READBIT(cmd,7));
	D6(READBIT(cmd,6));
	D5(READBIT(cmd,5));
	D4(READBIT(cmd,4));
	TRIGGER;
	D7(READBIT(cmd,3));
	D6(READBIT(cmd,2));
	D5(READBIT(cmd,1));
	D4(READBIT(cmd,0));
	TRIGGER;
	
	
	
	
}
void lcd_write_char(uint8_t data){
RS(1);           //write command
D7(READBIT(data,7));
D6(READBIT(data,6));
D5(READBIT(data,5));
D4(READBIT(data,4));
TRIGGER;
D7(READBIT(data,3));
D6(READBIT(data,2));
D5(READBIT(data,1));
D4(READBIT(data,0));
TRIGGER;
	
	
}
void lcd_write_string(uint8_t *str){
	while(*str!='\0'){
	lcd_write_char(*str);
	str++;	
		
	}
}
void lcd_write_num(uint32_t num){
	uint8_t y[10];
	int8_t i;
	
	for(i=0;num!=0;i++){
		
	y[i]=(num%10)+48;
	num=(num/10);
	}
	for(i--;i>=0;--i){
		lcd_write_char(y[i]);
	}
	
}
void lcd_set_cursor(uint8_t row,uint8_t column){
	row -=1;
	column-=1;
	
	lcd_write_command(0x80+(row*0x40)+column);
	_delay_ms(2);
	
}
