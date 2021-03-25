#include "complex_calculator.h"
#include "unity.h"

static complex_t c1 = {0, 0};
static complex_t c2 = {0, 0};
static complex_t result = {0, 0};
/* Required by the unity test framework */
void setUp()
{
}
/* Required by the unity test framework */
void tearDown()
{
}

void test_zero(void)
{
    // Can ommi the below intialization as it is done at the declaration time
    c1.real = 0;
    c1.imaginary = 0;
    
    c2.real = 0;
    c2.imaginary = 0;
    
    TEST_ASSERT_EQUAL(SUCCESS, complex_sum(&c1, &c2, &result));
    TEST_ASSERT_EQUAL(0, result.real);
    TEST_ASSERT_EQUAL(0, result.imaginary);
}
void test_positive(void)
{
    c1.real = 25;
    c1.imaginary = 15;
    
    c2.real = 75;
    c2.imaginary = 95;
    
    TEST_ASSERT_EQUAL(SUCCESS, complex_sum(&c1, &c2, &result));
    TEST_ASSERT_EQUAL(100, result.real);
    TEST_ASSERT_EQUAL(110, result.imaginary);
}

void test_negative(void)
{
    c1.real = -25;
    c1.imaginary = -15;
    
    c2.real = 75;
    c2.imaginary = 95;
    
    TEST_ASSERT_EQUAL(SUCCESS, complex_sum(&c1, &c2, &result));
    TEST_ASSERT_EQUAL(50, result.real);
    TEST_ASSERT_EQUAL(80, result.imaginary);

    c1.real = -25;
    c1.imaginary = -15;
    
    c2.real = -75;
    c2.imaginary = -95;
    
    TEST_ASSERT_EQUAL(SUCCESS, complex_sum(&c1, &c2, &result));
    TEST_ASSERT_EQUAL(-100, result.real);
    TEST_ASSERT_EQUAL(-110, result.imaginary);

}
void test_sub(void){
    // test zero
    c1.real = 0;
    c1.imaginary = 0;
    
    c2.real = 0;
    c2.imaginary = 0;
    TEST_ASSERT_EQUAL(SUCCESS, complexSub(&c1, &c2, &result));
    TEST_ASSERT_EQUAL(0, result.real);
    TEST_ASSERT_EQUAL(0, result.imaginary);

    // test positive
    c1.real = 25;
    c1.imaginary = 15;
    
    c2.real = 75;
    c2.imaginary = 95;

    TEST_ASSERT_EQUAL(SUCCESS, complexSub(&c1, &c2, &result));
    TEST_ASSERT_EQUAL(-50, result.real);
    TEST_ASSERT_EQUAL(-80, result.imaginary);

    // test negative

    c1.real = -25;
    c1.imaginary = -15;
    
    c2.real = -75;
    c2.imaginary = -95;

    TEST_ASSERT_EQUAL(SUCCESS, complexSub(&c1, &c2, &result));
    TEST_ASSERT_EQUAL(50, result.real);
    TEST_ASSERT_EQUAL(80, result.imaginary);


}
void test_mul(void){
    // test zero
    c1.real = 0;
    c1.imaginary = 0;
    
    c2.real = 0;
    c2.imaginary = 0;
    TEST_ASSERT_EQUAL(SUCCESS, complexMul(&c1, &c2, &result));
    TEST_ASSERT_EQUAL(0, result.real);
    TEST_ASSERT_EQUAL(0, result.imaginary);

    // test positive
    c1.real = 25;
    c1.imaginary = 15;
    
    c2.real = 75;
    c2.imaginary = 95;
    TEST_ASSERT_EQUAL(SUCCESS, complexMul(&c1, &c2, &result));
    TEST_ASSERT_EQUAL(450, result.real);
    TEST_ASSERT_EQUAL(3500, result.imaginary);

    // test negative
    c1.real = -25;
    c1.imaginary = -15;
    
    c2.real = -75;
    c2.imaginary = -95;
    TEST_ASSERT_EQUAL(SUCCESS, complexMul(&c1, &c2, &result));
    TEST_ASSERT_EQUAL(450, result.real);
    TEST_ASSERT_EQUAL(3500, result.imaginary);
}

void test_div(void){
    // test zero
    c1.real = 0;
    c1.imaginary = 0;
    
    c2.real = 0;
    c2.imaginary = 0;
    
    TEST_ASSERT_EQUAL(ERROR_DIV_BY_ZERO, complexDiv(&c1, &c2, &result));
    // test positive
    c1.real = 1;
    c1.imaginary = -3;
    c2.real = 1;
    c2.imaginary = 2;
    TEST_ASSERT_EQUAL(SUCCESS, complexDiv(&c1, &c2, &result));
    TEST_ASSERT_EQUAL(-1, result.real);
    TEST_ASSERT_EQUAL(-1, result.imaginary);
    // test negative
    c1.real = -5;
    c1.imaginary = -5;
    c2.real = -5;
    c2.imaginary = 5;
    TEST_ASSERT_EQUAL(SUCCESS, complexDiv(&c1, &c2, &result));
    TEST_ASSERT_EQUAL(0, result.real);
    TEST_ASSERT_EQUAL(1, result.imaginary);
}

int main(void)
{
    /* Initiate the Unity Test Framework */
    UNITY_BEGIN();

    /* Run Test functions */
    RUN_TEST(test_zero);
    RUN_TEST(test_positive);
    RUN_TEST(test_negative);
    RUN_TEST(test_sub);
    RUN_TEST(test_mul);
    RUN_TEST(test_div);

    /* Close the Unity Test Framework */
    return UNITY_END();
}

