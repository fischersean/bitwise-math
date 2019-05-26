#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../src/lrgmath.h"
#include "../unity/src/unity.h"

void test_bit_shift_right(void)
{

    bit *a = malloc(10 * sizeof(bit));

    bit n[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    bit m[10] = {0, 0, 1, 1, 1, 1, 1, 1, 1, 1};
    bit l[10] = {0, 0, 0, 1, 1, 1, 1, 1, 1, 1};

    for (int i = 0; i < 10; i++)
    {
        a[i] = n[i];
    }

    for (int i = 0; i < 10; i++)
    {
        TEST_ASSERT_EQUAL_UINT(n[i], a[i]);
    }

    //TEST_ASSERT_EQUAL_UINT_ARRAY(n, a, 10);

    bit_shift_right(a, 10, 2);

    for (int i = 0; i < 10; i++)
    {
        TEST_ASSERT_EQUAL_UINT(m[i], a[i]);
    }

    bit_shift_right(a, 10, 1);

    for (int i = 0; i < 10; i++)
    {
        TEST_ASSERT_EQUAL_UINT(l[i], a[i]);
    }

    free(a);
}

void test_bit_shift_left(void)
{

    bit *a = malloc(10 * sizeof(bit));

    bit n[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    bit m[10] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 0};
    bit l[10] = {3, 4, 5, 0, 7, 8, 9, 10, 0, 0};

    for (int i = 0; i < 10; i++)
    {
        a[i] = n[i];
    }

    for (int i = 0; i < 10; i++)
    {
        TEST_ASSERT_EQUAL_UINT(n[i], a[i]);
    }

    //TEST_ASSERT_EQUAL_UINT_ARRAY(n, a, 10);

    bit_shift_left(a, 10, 1);

    for (int i = 0; i < 10; i++)
    {
        TEST_ASSERT_EQUAL_UINT(m[i], a[i]);
    }

    bit_shift_left(a, 10, 1);

    for (int i = 0; i < 10; i++)
    {
        TEST_ASSERT_EQUAL_UINT(l[i], a[i]);
    }

    free(a);
}

void test_bit_add(void){
    bit *bit_arr = malloc(10 * sizeof(bit));
    bit a[17] = {1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0};
    bit b[18] = {1, 0, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0};
    bit result[18] = {1, 1, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0};

    for (int i = 0; i < 18; i++)
    {
        //TEST_ASSERT_EQUAL_UINT();
    }



}

void test_bit_subtract(void){

}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_bit_shift_right);
    RUN_TEST(test_bit_shift_left);
    RUN_TEST(test_bit_add);
    RUN_TEST(test_bit_subtract);
    
    UNITY_END();
}