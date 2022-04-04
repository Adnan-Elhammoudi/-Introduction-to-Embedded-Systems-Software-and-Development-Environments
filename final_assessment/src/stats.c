/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.c
 * @brief  multi functions that  calculate the statistics for  array of data
 *
 * 
 *
 * @author Adnan El hammoudi
 * @date 16 Jan,2022
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

int states() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};
#ifdef VERBOSE
  //Print the Original array
  printf("The original array :\n");
  print_array(test,SIZE);
#endif

  //Functions implementation

  //Sort Process Descendingly
  sort_array(test, SIZE);
#ifdef VERBOSE
  printf("The array after sorting process descendingly is : \n");
  print_array(test, SIZE);
#endif

  // Printing Statistics  Functions
  print_statistics(test,SIZE);
  return 0;
 

}

/* Add other Implementation File Code Here */
void print_statistics(unsigned char* array, unsigned char length){

	printf("and it is statistics :\n");
	printf("the median: %d\n", find_median(array,length));
	printf("the mean: %d\n", find_mean(array,length));
	printf("the MAX: %d\n", find_maximum(array,length));
	printf("the MIN: %d\n", find_minimum(array,length));
}

#ifdef VERBOSE
void  print_array(unsigned char *ptr,unsigned char length){

for(int i = 0; i < length ; i++){printf("%d\t",ptr[i] );}
printf("\n");

}
 #endif


unsigned char find_mean(unsigned char *ptr, unsigned char length){

int sum=0;
for (int i=0;i<length;i++){sum += ptr[i];}

return sum/length;
}


unsigned char find_median(unsigned char *ptr, unsigned char length){
unsigned char L = length;
ptr =sort_array(ptr,length);

if(L % 2 ==0){return(ptr[L/2]+ptr[(L/2)-1])/2;}
else return ptr[L/2];

}

unsigned char find_maximum(unsigned char *ptr, unsigned char length){
unsigned char max = 0;
for (int i=0 ;i<length;i++){
if (ptr[i] >max){max=ptr[i];}

}
return max;
}

unsigned  char find_minimum(unsigned char *ptr, unsigned char length){
unsigned char min = ptr[0];
for (int i = 1;i<length;i++){if (ptr[i]<min){min=ptr[i];}

}
return min;
}

unsigned char* sort_array(unsigned char *ptr, unsigned char length){
for(int i=length-1; i>=0; i--){
	    for(int j=0; j<i; j++){
		          if(ptr[j]>ptr[j+1]){
				          unsigned char temp = ptr[j];
					          ptr[j] = ptr[j+1];
						          ptr[j+1] = temp;
							        }
			      }
	      }  
  return ptr;
}
