#define F_CPU 8000000UL

#include <stdint.h>
#include <avr/io.h>
#include <util/delay.h>
#include <string.h>
#include <stdlib.h>
#include <avr/interrupt.h>

//Including the library to work with the 7-segments display/
#include "tm1637.h"
#include "tm1637_2.h"

void set_value(uint16_t );
void set_value_2(uint16_t );
uint16_t up=0;
uint16_t down = 1000;


int main(void)
{	TM1637_init(1/*enable*/, 7/*brightness*/);
	TM1637_2_init(1/*enable*/, 7/*brightness*/);
    /* Replace with your application code */
    while (1) 
    {
		set_value(up);
		set_value_2(down);
		
		up+=10;
		down-=10;
		
		if(up>1000){
			up = 0;
		}
		if (down<1){
			down = 1000;
		}
		_delay_ms(300);
    }
}


void set_value(uint16_t val){
	TM1637_display_colon(0);
	for (int i = 0;i <4 ; i++){
		TM1637_display_digit(3-i,val%10);
		val = val/10;
	}
}

void set_value_2(uint16_t val){
	TM1637_2_display_colon(0);
	
	for (int i = 0;i <4 ; i++){
		TM1637_2_display_digit(3-i,val%10);
		val = val/10;
	}
	
}