#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../src/lrgmath.h"
#include "./unity/src/unity.h"

/*
n_buff_a
n_buff_b *optional for bit shift routines
buff_a
buff_b *optional for bit shift routines
buff_result
*/
/*
int rand_in_range(int min, int max)
{

    return (rand() % (max - min + 1)) + min;
}*/

struct TestCase
{

    bit *bit_a;
    bit *bit_b;
    bit *result;

    int len_a;
    int len_b;
    int len_result;
};

struct TestSuite
{

    int n_cases;
    struct TestCase *test_cases;
};

void read_test_case(struct TestCase *test_case, FILE **f)
{

    //Read len of buff a
    fscanf(*f, "%d", &test_case->len_a);
    //Read len of buff b
    fscanf(*f, "%d", &test_case->len_b);
    //Read len of buff result
    fscanf(*f, "%d", &test_case->len_result);

    //Malloc space for each bit stream
    test_case->bit_a = malloc((test_case->len_a) * sizeof(int));
    test_case->bit_b = malloc((test_case->len_b) * sizeof(int));
    test_case->result = malloc((test_case->len_result) * sizeof(int));

    //Read in bit stream for each of the three required bit streams
    for (int j = 0; j < test_case->len_a; j++)
    {
        fscanf(*f, "%hd", &test_case->bit_a[j]);
    }

    for (int j = 0; j < test_case->len_b; j++)
    {
        fscanf(*f, "%hd", &test_case->bit_b[j]);
    }

    for (int j = 0; j < test_case->len_result; j++)
    {
        fscanf(*f, "%hd", &test_case->result[j]);
    }
}

void read_test_suite(struct TestSuite *test_suite, FILE **f)
{

    int max_len = 255;
    char *_char_n_cases = malloc(max_len * sizeof(char));

    //Ignore comment lines (#)
    do
    {
        fgets(_char_n_cases, max_len, *f);
    } while (_char_n_cases[0] == '#');

    test_suite->n_cases = *_char_n_cases - '0';
    free(_char_n_cases);

    //Allocate space for the test case struct array
    test_suite->test_cases = malloc(test_suite->n_cases * sizeof(struct TestCase));

    //For each test case, read from file object and store in suite
    for (int i = 0; i < test_suite->n_cases; i++)
    {
        read_test_case(&test_suite->test_cases[i], f);
    }

    return;
}

void free_test_suite(struct TestSuite *test_suit)
{
    //TODO
    return;
}

void test_bit_shift_right(void)
{
    //Since we are only shifting the bits on one bit stream, we will ignore the bit b numbers.
    // bit b values are stored as all 0's in the test data file

    FILE *test_file = fopen("bitshiftright_test.txt", "r");
    struct TestSuite *test_suite = malloc(sizeof(struct TestSuite));
    read_test_suite(test_suite, &test_file);

    bit *test_a;
    //bit *test_b;
    //bit *test_result;

    int len_a;
    //int len_b;
    //int len_result;
    int len_shift;

    for (int i = 0; i < test_suite->n_cases; i++)
    {

        len_a = test_suite->test_cases[i].len_a;
        //len_b = test_suite->test_cases[i].len_b;
        //len_result = test_suite->test_cases[i].len_result;
        len_shift = test_suite->test_cases[i].len_b;

        test_a = malloc(len_a * sizeof(bit));
        //test_b = realloc(test_b, len_b*sizeof(bit));
        //test_result = realloc(test_result, len_result*sizeof(bit));

        memcpy(test_a, test_suite->test_cases[i].bit_a, len_a * sizeof(bit));
        //memcpy(test_b, test_suite->test_cases[i].bit_b, len_b*sizeof(bit));
        //memcpy(test_result, test_suite->test_cases[i].result, len_result*sizeof(bit));
        //printf("%d\n", len_a);
        bit_shift_right(test_a, len_a, len_shift);

        for (int j = 0; j < len_a; j++)
        {
            TEST_ASSERT_EQUAL_UINT(test_suite->test_cases[i].result[j], test_a[j]);
        }
    }

    free_test_suite(test_suite);
    fclose(test_file);
}

void test_bit_shift_left(void)
{

    //Since we are only shifting the bits on one bit stream, we will ignore the bit b numbers.
    // bit b values are stored as all 0's in the test data file

    FILE *test_file = fopen("bitshiftleft_test.txt", "r");
    struct TestSuite *test_suite = malloc(sizeof(struct TestSuite));
    read_test_suite(test_suite, &test_file);

    bit *test_a;
    //bit *test_b;
    //bit *test_result;

    int len_a;
    //int len_b;
    //int len_result;
    int len_shift;

    for (int i = 0; i < test_suite->n_cases; i++)
    {

        len_a = test_suite->test_cases[i].len_a;
        //len_b = test_suite->test_cases[i].len_b;
        //len_result = test_suite->test_cases[i].len_result;
        len_shift = test_suite->test_cases[i].len_b;

        test_a = malloc(len_a * sizeof(bit));
        //test_b = realloc(test_b, len_b*sizeof(bit));
        //test_result = realloc(test_result, len_result*sizeof(bit));

        memcpy(test_a, test_suite->test_cases[i].bit_a, len_a * sizeof(bit));
        //memcpy(test_b, test_suite->test_cases[i].bit_b, len_b*sizeof(bit));
        //memcpy(test_result, test_suite->test_cases[i].result, len_result*sizeof(bit));
        //printf("%d\n", len_a);
        bit_shift_left(test_a, len_a, len_shift);

        for (int j = 0; j < len_a; j++)
        {
            TEST_ASSERT_EQUAL_UINT(test_suite->test_cases[i].result[j], test_a[j]);
        }
    }

    free_test_suite(test_suite);
    fclose(test_file);
}

void test_bit_add(void)
{
    FILE *test_file = fopen("bitadd_test.txt", "r");
    struct TestSuite *test_suite = malloc(sizeof(struct TestSuite));
    read_test_suite(test_suite, &test_file);

    bit *test_a;
    bit *test_b;
    bit *test_result;

    int len_a;
    int len_b;
    int len_result;
    int len_shift;

    for (int i = 0; i < test_suite->n_cases; i++)
    {

        len_a = test_suite->test_cases[i].len_a;
        len_b = test_suite->test_cases[i].len_b;
        len_result = test_suite->test_cases[i].len_result;
        len_shift = test_suite->test_cases[i].len_b;

        test_a = malloc(len_a * sizeof(bit));
        test_b = malloc(len_b*sizeof(bit));
        //test_result = realloc(test_result, len_result*sizeof(bit));

        memcpy(test_a, test_suite->test_cases[i].bit_a, len_a*sizeof(bit));
        memcpy(test_b, test_suite->test_cases[i].bit_b, len_b*sizeof(bit));
        //memcpy(test_result, test_suite->test_cases[i].result, len_result*sizeof(bit));

        test_result = add(test_a, test_b, len_a, len_b);

        for (int j = 0; j < len_result; j++)
        {
            TEST_ASSERT_EQUAL_UINT(test_suite->test_cases[i].result[j], test_result[j]);
        }
    }

    free_test_suite(test_suite);
    fclose(test_file);
}

void test_bit_subtract(void)
{
    char message_str[128];

    FILE *test_file = fopen("bitsubtract_test.txt", "r");
    struct TestSuite *test_suite = malloc(sizeof(struct TestSuite));
    read_test_suite(test_suite, &test_file);

    bit *test_a;
    bit *test_b;
    bit *test_result;

    int len_a;
    int len_b;
    int len_result;
    int len_shift;
    
    for (int i = 0; i < test_suite->n_cases; i++)
    {

        len_a = test_suite->test_cases[i].len_a;
        len_b = test_suite->test_cases[i].len_b;
        len_result = test_suite->test_cases[i].len_result;
        len_shift = test_suite->test_cases[i].len_b;

        test_a = malloc(len_a * sizeof(bit));
        test_b = malloc(len_b*sizeof(bit));
        //test_result = realloc(test_result, len_result*sizeof(bit));

        memcpy(test_a, test_suite->test_cases[i].bit_a, len_a*sizeof(bit));
        memcpy(test_b, test_suite->test_cases[i].bit_b, len_b*sizeof(bit));
        //memcpy(test_result, test_suite->test_cases[i].result, len_result*sizeof(bit));

        test_result = subtract(test_a, test_b, len_a, len_b);
        for(int j = 0; j < len_result; j++){
            printf("%d", test_result[j]);
        }
        printf("\n");
        for (int j = 0; j < len_result; j++)
        {
            sprintf(message_str, "%d, %d", i, j);
            TEST_ASSERT_EQUAL_UINT_MESSAGE(test_suite->test_cases[i].result[j], test_result[j], message_str);
        }
    }

    free_test_suite(test_suite);
    fclose(test_file);
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