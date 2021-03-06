//
//  lrgmath.h
//  bitwise-math
//
//  A simple library for computing sums, subtractions, products, and divisions using only binary
//  numbers
//
//  Created by Sean Fischer on 5/18/19.
//  Copyright © 2019 Sean Fischer. All rights reserved.
//

#ifndef lrgmath
#define lrgmath

#include <stdio.h>

typedef unsigned short int bit;
typedef signed long int MAX_LEN; //max size is 2 GB for a number

typedef struct number{
    char *size;
    unsigned long int *bit_length;
    char *value;
}number;

void push_back(bit *n, size_t old_len, size_t new_len);

void equalize_bit_size(bit *a, bit *b, size_t a_len, size_t b_len);

bit *add(bit *buffer_a, bit *buffer_b, size_t a_len, size_t b_len);

bit *subtract(bit *buffer_a, bit *buffer_b, size_t a_len, size_t b_len);

void bit_shift_right(bit *a, MAX_LEN a_len, MAX_LEN dist);

void bit_shift_left(bit *a, MAX_LEN a_len, MAX_LEN dist);

#endif /* lrgmath */
