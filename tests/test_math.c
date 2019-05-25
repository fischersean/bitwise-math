#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../src/lrgmath.h"
#include "../unity/src/unity.h"

// 
void test_bit_shift_right(void){

    bit *a = malloc(10*sizeof(bit));

    bit n[10] = {1,1,1,1,1,1,1,1,1,1};
    bit m[10] = {0,0,1,1,1,1,1,1,1,1};

    for(int i = 0; i < 10; i++){
        a[i] = n[i];
    }

    TEST_ASSERT_EQUAL_UINT_ARRAY(a, n, 10);

    bit_shift_right(a, 10, 2);

    TEST_ASSERT_EQUAL_UINT_ARRAY(a, m, 10);

    free(a);
    
}

int main(void){
    UNITY_BEGIN();
    RUN_TEST(test_bit_shift_right);
    UNITY_END();
}