//
//  lrgmath.h
//  bitwise-math
//
//  Created by Sean Fischer on 5/18/19.
//  Copyright © 2019 Sean Fischer. All rights reserved.
//

#ifndef lrgmath2_h
#define lrgmath2_h

#include <stdio.h>

typedef unsigned short int bit;

typedef struct number{
    char *size;
    unsigned long int *bit_length;
    char *value;
}number;

void push_back(bit *n, size_t old_len, size_t new_len);

bit *add(bit *buffer_a, bit *buffer_b, size_t a_len, size_t b_len);

#endif /* lrgmath2_h */
