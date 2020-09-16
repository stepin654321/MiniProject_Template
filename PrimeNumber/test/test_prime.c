#include <stdbool.h>
#include "unity.h"
#include "Prime.h"

void setUp(){}
/* Required by the unity test framework */

void tearDown(){}

void test_prime_number(void)
{
    TEST_ASSERT_EQUAL(true,prime(5));
    TEST_ASSERT_EQUAL(true,prime(7));
    TEST_ASSERT_EQUAL(false,prime(9));
}

void test_zero_one(void)
{
    TEST_ASSERT_EQUAL(false,prime(0));
    TEST_ASSERT_EQUAL(false,prime(-1));
}
void test_negative(void)
{
    TEST_ASSERT_EQUAL(false,prime(-12));
    TEST_ASSERT_EQUAL(false,prime(-10));
}

int test_main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_prime_number);
    RUN_TEST(test_zero_one);
    RUN_TEST(test_negative);
    return UNITY_END();
}

