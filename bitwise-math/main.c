//
//  main.c
//  bitwise-math
//
//  Created by Sean Fischer on 5/18/19.
//  Copyright © 2019 Sean Fischer. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lrgmath.h"

typedef unsigned short int bit;

int main(int argc, const char * argv[]) {
    // insert code here...
    /*size_t old_len = 10;
    bit *test_arr = malloc(old_len * sizeof(bit));
    
    for(int i = 0; i < 10; i++){
        test_arr[i] = i; //int -> char conversion
    }
    
    //size_t new = 1000;
    size_t new_len = 100;
    test_arr = realloc(test_arr, new_len*sizeof(bit));
    
    push_back(test_arr, old_len, new_len);
    
    for(unsigned long int i=0; i < new_len; i++){
        printf("%u", test_arr[i]);
    }*/
    
    bit *a = malloc(4 * sizeof(bit));// [0,0,0,0,0,1];
    bit *b = malloc(4 * sizeof(bit));//[0,0,0,0,0,1];
    
    a[3] = 1;
    a[2] = 1;
    a[1] = 1;
    a[0] = 0;
    b[3] = 0;
    b[2] = 1;
    b[1] = 1;
    b[0] = 0;
    
    bit *result = subtract(a, b, 4, 4);
    
    for(int i = 0; i < 4; i++){
        printf("%d", a[i]);
    }
    
    printf("\n");
    
    for(int i = 0; i < 4; i++){
        printf("%d", b[i]);
    }
    printf("-\n");
    
    for(int i = 0; i < 4; i++){
        printf("-");
    }
    printf("\n");
    
    for(int i = 0; i < 4; i++){
        printf("%d", result[i]);
    }
    
    free(result);
    free(a);
    free(b);
    
    printf("\n\n");
    return 0;
}
