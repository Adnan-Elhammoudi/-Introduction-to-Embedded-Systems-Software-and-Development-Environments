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
 * @file stats.h .
 * @brief calculating statistics of given array and printing it on the screen.
 *
 * @author Adnan Elhammoudi.
 * @date 2020-6-24.
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

 void print_statistics( unsigned char mean ,unsigned char  median ,unsigned char  min, unsigned char  max);

/*
 * @brief shows  statistics of the array on the screen.
 *
 * A function that prints the statistics of an array including minimum, maximum, mean, and median.
 *
 * @param mean mean of the array .
 * @param median median of the array .
 * @param min minimum value of the array.
 * @param max maximum value of the array.
 * @return void.
 *
 */

void print_array(unsigned char *ptr,unsigned int length);
/* @brif prints the array on the screen.
 *
 * Given an array of data and a length, prints the array to the screen.
 *
 * @param *ptr array of data.
 * @param length length of the array.
 *
 * @return void.
 *
 */

unsigned char find_median(unsigned char *ptr, unsigned int length);
/* @brief median of given array.
 
 * Given an array of data and a length, returns the median value.
 *
 * @param *ptr  array of data.
 * @param length length of the array.
 *
 * @return median value of the given array.
 *
 */
     	     
unsigned  char find_mean (unsigned char *ptr, unsigned int length);
/* @brief mean of the  given array.
 *
 * Given an array of data and a length, returns the mean of the array.
 *
 * @param *ptr array of data.
 * @param length  length of the array.
 *
 * @return mean value of the given array.
 *
 */

unsigned char find_maximum(unsigned char *ptr, unsigned int length);
/* @brief maximum value of given array.
 *
 * Given an array of data and a length, returns the maximum value  of thie array.
 *
 * @param *ptr array of data.
 * @param length length of the array.
 * 
 * @return maximum value of the given array.
 *
 */

unsigned char find_minimum(unsigned char *ptr, unsigned int length);
/* @brief minimum value of given array.
 *
 * Given an array of data and a length, returns the minimum .
 *
 * @param *ptr  array of data.
 * @param length length of the array.
 *
 * @return minimim value of the  given array.
 *
 */
unsigned char* sort_array(unsigned char *ptr, unsigned int length);
/*@brief sorting the arraye from largest to smallest.
 *
 * Given an array of data and a length,sorts the array from largest to smallest. (The zeroth Element should be the largest value, and the last element (n-1) should be the smallest value.
 *
 * @param *ptr array of data.
 * @param length length of the array.
 *
 * @return array after sorting .
 *
 */

#endif /* __STATS_H__ */
