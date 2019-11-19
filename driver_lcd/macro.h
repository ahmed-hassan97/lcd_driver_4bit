/*
 * driver.c
 *
 * Created: 8/6/2019 5:40:02 PM
 *  Author: AHMED HASSAN
 */ 

#ifndef _macro_h
#define _macro_h
#include <util/delay.h>
#define F_CPU 8000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#define SET_BIT(REG,BIT) (REG |=(1<<BIT))
#define CLEAR_BIT(REG,BIT) (REG &=~(1<<BIT))
#define toogle_bit(reg,bit) (reg ^=(1<<bit))
#define CLEAR_ALL(REG) (REG &=~(255<<0))
#define SET_ALL(REG) (REG |=(255<<0))
#define READBIT(reg,bit) ((reg >>bit) &1)
#define DETERMINATE_CLEAR_ALOTOF_BIT(REG,BIT) (REG &=~(BIT<<0))
#define DETERMINATE_SET_ALOTOF_BIT(REG,BIT) (REG |=(BIT<<0))

#endif
