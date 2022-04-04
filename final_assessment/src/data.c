/**
 * @file data.c
 * @brief Performs simple data manipulation
 *
 * @author Adnan El hammoudi
 * @date 16 Jan, 2022
 */

#include"data.h"
#include "memory.h"


uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base){


	unsigned char digit = 0;
	char IS_NEG = 0;

	if(data == 0){
		*ptr = '0';
		digit++;
	}
	
	if(data < 0 && base == 10){
		data *= -1;
		IS_NEG = 1;
	}

	while(data != 0 && digit < 16){
		if(data%base > 9){
			*(ptr + digit) = 'A' + ((data%base)-10);
		}
		else{
			*(ptr + digit) = '0' + data%base;
		}
		
		digit++;
		data/=base;
	}

	if(IS_NEG){
		*(ptr + digit) = '-';
		digit++;
	}

	my_reverse(ptr, digit);
	
	*(ptr + digit)= '\0';
	digit++;

	return (digit - 1);



}


int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base)
{
	unsigned char data = 0;
	unsigned char IS_NEG = 0;
	int numb = 0;
	unsigned long my_base = 1;

	if(*(ptr) == '-' && 10 == base){
		IS_NEG = 1;
	}

	while(data < digits){
		if(*(ptr + digits - data - 1) >= '0' && *(ptr + digits - data - 1) <= '9' ){
			numb +=(*(ptr + digits - data - 1) - '0')*my_base;
		}
		else if((*(ptr + digits - data - 1) >= 'A' && *(ptr + digits - data - 1) <= 'Z') || (*(ptr + digits - data - 1) >= 'a' && *(ptr + digits - data - 1) <= 'z')){
			numb+=((*(ptr + digits - data - 1) - 'A') + 10)*my_base;
		}
		else
		{
			numb+=0;
		}

		data++;
		my_base *=base;
	}
	if(IS_NEG)
	{
		numb *=-1;
	}
	return numb;
}