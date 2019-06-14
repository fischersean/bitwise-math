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

void push_back(bit *n, size_t old_len, size_t new_len)
{
    //Takes an array, originally of length old_len before realloc to new_len and pushes values to end
    if (old_len > new_len)
    {
        printf("%zu < %zu\n", old_len, new_len);
        printf("New length must be > old length\n");
        return;
    }
    MAX_LEN pos = new_len - 1;

    for (MAX_LEN i = old_len - 1; i >= 0; i--)
    {
        //printf("Index %lu moved to index %lu\n", i, pos);
        //printf("New value at %lu = %hu\n", pos, n[i]);
        n[pos] = n[i];
        //n[i] = 0 + '0';
        pos--;
    }

    for (MAX_LEN i = 0; i < new_len - old_len; i++)
    {
        n[i] = 0;
        //printf("New value at %lu = %hu\n", i, n[i]);
    }
}

void equalize_bit_size(bit *a, bit *b, size_t a_len, size_t b_len)
{

    //Given two bit*, make them the same size and push them back to the right

    if (a_len < b_len)
    {
        a = realloc(a, b_len);
        push_back(a, a_len, b_len);
    }
    else if (b_len < a_len)
    {
        b = realloc(b, a_len);
        push_back(b, b_len, a_len);
    }
}

void bit_shift_left(bit *a, MAX_LEN a_len, MAX_LEN dist)
{
    // Shift all bits of a dist places left

    for (MAX_LEN j = 0; j < dist; j++)
    {
        for (MAX_LEN i = 0; i < a_len; i++)
        {
            a[i] = a[i + 1];
        }
        a[a_len - j - 1] = 0;
    }
}

void bit_shift_right(bit *a, MAX_LEN a_len, MAX_LEN dist)
{
    // Shift all bits of a dist places right

    for (MAX_LEN j = 0; j < dist; j++)
    {
        for (MAX_LEN i = a_len - 1; i > 0; i--)
        {
            a[i] = a[i - 1];
        }
        a[j] = 0;
    }
}

bit *add(bit *buffer_a, bit *buffer_b, size_t a_len, size_t b_len)
{
    //Take two bit arrays, of any length (max is size_t) and adds them together. Does not free buffer a or buffer b

    //https://www.electronics-tutorials.ws/combination/comb_7.html

    //Need to eventually move this out of this function to a seperate one
    size_t new_len;

    if (a_len > b_len)
    {
        new_len = a_len;
    }
    else
    {
        new_len = b_len;
    }

    //since the worst case scenario of addition is 2x we need 1 more bit than the input bits to guarantee we have enough memory
    new_len++;

    bit *result = malloc((new_len) * sizeof(bit));

    //fix format and add leading 0's
    //equalize_bit_size(buffer_a, buffer_b, a_len, b_len);
    push_back(buffer_a, a_len, new_len);
    push_back(buffer_b, b_len, new_len);

    bit a;
    bit b;
    bit sum_bit;
    bit carry_bit = 0;

    for (MAX_LEN i = new_len - 1; i >= 0; i--)
    {
        a = buffer_a[i];
        b = buffer_b[i];
        sum_bit = (a ^ b) ^ carry_bit;
        carry_bit = (a & b) | (carry_bit & (a ^ b));
        result[i] = sum_bit;
    }

    return result;
}

bit *subtract(bit *buffer_a, bit *buffer_b, size_t a_len, size_t b_len)
{

    //Take two bit arrays, of any length (max is size_t) and subtracts them. Does not free buffer a or buffer b

    //Only valid if buffer_a > buffer_b

    //https://www.electronics-tutorials.ws/combination/binary-subtractor.html

    //Need to eventually move this out of this function to a seperate one

    // D = (X xor Y) xor Bin
    // Bout = ((not X) and Y) + (not (X xor Y)) and Bin
    size_t new_len;

    if (a_len > b_len)
    {
        new_len = a_len;
    }
    else
    {
        new_len = b_len;
    }

    bit *result = malloc((new_len) * sizeof(bit));

    //fix format and add leading 0's
    push_back(buffer_a, a_len, new_len);
    push_back(buffer_b, b_len, new_len);
    //equalize_bit_size(buffer_a, buffer_b, a_len, b_len);

    bit a;
    bit b;
    bit difference;
    bit carry_bit = 0;

    for (MAX_LEN i = new_len - 1; i >= 0; i--)
    {
        a = buffer_a[i];
        b = buffer_b[i];
        difference = (a ^ b) ^ carry_bit;
        carry_bit = (~a & b) | (~(a ^ b) & carry_bit);
        result[i] = difference;
    }
    // If first bit is 0, bit shift left to cut off leading 0
    bit_shift_left(result,new_len, 1);
    return result;
}
