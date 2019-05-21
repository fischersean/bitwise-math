//
//  lrgmath.c
//  bitwise-math
//
//  Created by Sean Fischer on 5/18/19.
//  Copyright © 2019 Sean Fischer. All rights reserved.
//

//#include "lrgmath2.h"
#include <stdlib.h>
#include <stdio.h>
#include "lrgmath.h"

char* bit_to_int(bit *n){
    
}

void push_back(bit *n, size_t old_len, size_t new_len){
    //Takes an array, originally of length old_len before realloc to new_len and pushes values to end
    if(old_len > new_len){
        printf("%zu < %zu\n", old_len, new_len);
        printf("New length must be > old length\n");
        return;
    }
    unsigned long int pos = new_len - 1;
    
    for(signed long int i = old_len-1; i >= 0; i--){
        //printf("Index %lu moved to index %lu\n", i, pos);
        //printf("New value at %lu = %hu\n", pos, n[i]);
        n[pos] = n[i];
        //n[i] = 0 + '0';
        pos--;
    }
    
    for(unsigned long int i = 0; i < new_len - old_len; i++){
        n[i] = 0;
        //printf("New value at %lu = %hu\n", i, n[i]);
    }
}

bit *add(bit *buffer_a, bit *buffer_b, size_t a_len, size_t b_len){
    //Take two bit arrays, of arbitray length (max is size_t) and adds them together. Does not free buffer a or buffer b
    
    //https://www.electronics-tutorials.ws/combination/comb_7.html
    
    size_t new_len;
    
    if(a_len < b_len){
        buffer_a = realloc(buffer_a, b_len);
        push_back(buffer_a, a_len, b_len);
        new_len = b_len;
    }else if (b_len < a_len){
        buffer_b = realloc(buffer_b, a_len);
        push_back(buffer_b, b_len, a_len);
        new_len = a_len;
    }else{
        new_len = a_len;
    }
    
    bit *result = malloc((1+new_len)*sizeof(bit)); //since the worst case scenario of addition is 2x we need 1 more bit than the input bits to guarantee we have enough memory
    
    bit a;
    bit b;
    bit sum_bit;
    bit carry_bit = 0;
    
    for(signed long int i = new_len - 1; i >= 0; i--){
        a = buffer_a[i];
        b = buffer_b[i];
        sum_bit = (a ^ b) ^ carry_bit;
        carry_bit = (a & b) | (carry_bit & (a ^ b));
        result[i] = sum_bit;
    }
    
    return result;
    
}

