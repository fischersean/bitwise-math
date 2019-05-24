//
//  lrgmath.c
//  bitwise-math
//
//  A simple library for computing sums, subtractions, products, and divisions using only binary
//  numbers
//
//  Created by Sean Fischer on 5/18/19.
//  Copyright © 2019 Sean Fischer. All rights reserved.
//

//#include "lrgmath2.h"
#include <stdlib.h>
#include <stdio.h>
#include "lrgmath.h"
#include <string.h>

/*
char *product(char *a, char *b, size_t length){
    //Takes two integers, represented by char arrays of their digits and returns a char array of their product
    
    //Karatsuba multiplication
    
    int base = 10;
    int product;
    int carry;
    
    int n;
    int m;
    
    char *result = malloc(length*sizeof(char));
    
    for(MAX_LEN i = length - 1; i >= 0; i++){
        n = a[i] - '0';
        m = b[i] - '0';
        
        product = n * m;
        if(product >= base){
            carry = product - base;
        }else{
            carry = 0;
        }
        
    }
    
    return result;
    
}*/
/*
char *bit_to_int(bit *n, size_t bit_length){
    //Given bit array *n, convert to char* where each element is a digit in the base-10 number
    char *result = malloc(bit_length*sizeof(char));
    
    int product;
    int carry;
    
    for(MAX_LEN i = bit_length - 1; i >= 0; i++){
        
    }
    
    return result;
}*/

void push_back(bit *n, size_t old_len, size_t new_len){
    //Takes an array, originally of length old_len before realloc to new_len and pushes values to end
    if(old_len > new_len){
        printf("%zu < %zu\n", old_len, new_len);
        printf("New length must be > old length\n");
        return;
    }
    MAX_LEN pos = new_len - 1;
    
    for(MAX_LEN i = old_len-1; i >= 0; i--){
        //printf("Index %lu moved to index %lu\n", i, pos);
        //printf("New value at %lu = %hu\n", pos, n[i]);
        n[pos] = n[i];
        //n[i] = 0 + '0';
        pos--;
    }
    
    for(MAX_LEN i = 0; i < new_len - old_len; i++){
        n[i] = 0;
        //printf("New value at %lu = %hu\n", i, n[i]);
    }
}

void equalize_bit_size(bit *a, bit *b, size_t a_len, size_t b_len){
    
    //Given two bit*, make them the same size and push them back to the right
    
    if(a_len < b_len){
        a = realloc(a, b_len);
        push_back(a, a_len, b_len);
    }else if (b_len < a_len){
        b = realloc(b, a_len);
        push_back(b, b_len, a_len);
    }
    
}

bit *add(bit *buffer_a, bit *buffer_b, size_t a_len, size_t b_len){
    //Take two bit arrays, of any length (max is size_t) and adds them together. Does not free buffer a or buffer b
    
    //https://www.electronics-tutorials.ws/combination/comb_7.html
    
    //Need to eventually move this out of this function to a seperate one
    size_t new_len;
    
    if(a_len > b_len){
        new_len = a_len;
    }else{
        new_len = b_len;
    }
    
    //since the worst case scenario of addition is 2x we need 1 more bit than the input bits to guarantee we have enough memory
    new_len++;
    
    bit *result = malloc((new_len)*sizeof(bit));
    
    //fix format and add leading 0's
    push_back(buffer_a, a_len, new_len);
    push_back(buffer_b, b_len, new_len);
    
    bit a;
    bit b;
    bit sum_bit;
    bit carry_bit = 0;
    
    for(MAX_LEN i = new_len - 1; i >= 0; i--){
        a = buffer_a[i];
        b = buffer_b[i];
        sum_bit = (a ^ b) ^ carry_bit;
        carry_bit = (a & b) | (carry_bit & (a ^ b));
        result[i] = sum_bit;
    }
    
    return result;
    
}

bit *subtract(bit *buffer_a, bit *buffer_b, size_t a_len, size_t b_len){
    
    //Take two bit arrays, of any length (max is size_t) and subtracts them. Does not free buffer a or buffer b
    
    //Only valid if buffer_a > buffer_b
    
    //https://www.electronics-tutorials.ws/combination/binary-subtractor.html
    
    //Need to eventually move this out of this function to a seperate one
    size_t new_len;
    
    if(a_len > b_len){
        new_len = a_len;
    }else{
        new_len = b_len;
    }
    
    bit *result = malloc((new_len)*sizeof(bit));
    
    //fix format and add leading 0's
    equalize_bit_size(buffer_a, buffer_b, a_len, b_len);
    
    bit a;
    bit b;
    bit difference;
    bit carry_bit = 0;
    
    for(MAX_LEN i = new_len - 1; i >= 0; i--){
        a = buffer_a[i];
        b = buffer_b[i];
        difference = (a ^ b) ^ carry_bit;
        carry_bit = (~a & b) | (~(a ^ b) & carry_bit);
        result[i] = difference;
    }
    
    return result;
}

bit *mulitply(bit *buffer_a, bit *buffer_b, size_t a_len, size_t b_len){
    
    //https://en.wikipedia.org/w/index.php?title=Binary_multiplier&section=4#Unsigned_numbers
    //Worst case scenario is x^2, therefore we need 2x the number of bits to guarantee we have enough to store the answer
    size_t new_len;
    
    if(a_len > b_len){
        new_len = a_len;
    }else{
        new_len = b_len;
    }

    bit *n = malloc((1+a_len) * sizeof(bit));

    new_len = new_len * 2;
    
    bit *result = malloc((new_len)*sizeof(bit));

    //fix format and add leading 0's
    equalize_bit_size(buffer_a, buffer_b, a_len, b_len);
    
    for (MAX_LEN i = new_len; i >= 0; i--){
        
    }


    return result;
}


bit *divide(bit *buffer_a, bit *buffer_b, size_t a_len, size_t b_len){
    
    return 0;
}


