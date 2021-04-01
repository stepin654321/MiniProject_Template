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

void cadd(void)
{
    c1.real = 0;
    c1.imaginary = 0;

    c2.real = 0;
    c2.imaginary = 0;

    TEST_ASSERT_EQUAL(SUCCESS, complex_sum(&c1, &c2, &result));
    TEST_ASSERT_EQUAL(0, result.real);
    TEST_ASSERT_EQUAL(0, result.imaginary);

    c1.real = 30;
    c1.imaginary = 40;

    c2.real = 20;
    c2.imaginary = 80;

    TEST_ASSERT_EQUAL(SUCCESS, complex_sum(&c1, &c2, &result));
    TEST_ASSERT_EQUAL(50, result.real);
    TEST_ASSERT_EQUAL(120, result.imaginary);

    c1.real = -50;
    c1.imaginary = -25;

    c2.real = 80;
    c2.imaginary = 85;

    TEST_ASSERT_EQUAL(SUCCESS, complex_sum(&c1, &c2, &result));
    TEST_ASSERT_EQUAL(30, result.real);
    TEST_ASSERT_EQUAL(60, result.imaginary);

    c1.real = -25;
    c1.imaginary = -15;

    c2.real = -75;
    c2.imaginary = -95;

    TEST_ASSERT_EQUAL(SUCCESS, complex_sum(&c1, &c2, &result));
    TEST_ASSERT_EQUAL(-100, result.real);
    TEST_ASSERT_EQUAL(-110, result.imaginary);
}

void cdiff(void)
{
    c1.real = 0;
    c1.imaginary = 0;

    c2.real = 0;
    c2.imaginary = 0;

    TEST_ASSERT_EQUAL(SUCCESS, complex_sub(&c1, &c2, &result));
    TEST_ASSERT_EQUAL(0, result.real);
    TEST_ASSERT_EQUAL(0, result.imaginary);

    c1.real = 30;
    c1.imaginary = 40;

    c2.real = 20;
    c2.imaginary = 80;

    TEST_ASSERT_EQUAL(SUCCESS, complex_sub(&c1, &c2, &result));
    TEST_ASSERT_EQUAL(10, result.real);
    TEST_ASSERT_EQUAL(-40, result.imaginary);

    c1.real = -50;
    c1.imaginary = -25;

    c2.real = 80;
    c2.imaginary = 85;

    TEST_ASSERT_EQUAL(SUCCESS, complex_sub(&c1, &c2, &result));
    TEST_ASSERT_EQUAL(-130, result.real);
    TEST_ASSERT_EQUAL(-110, result.imaginary);

    c1.real = -25;
    c1.imaginary = -15;

    c2.real = -75;
    c2.imaginary = -95;

    TEST_ASSERT_EQUAL(SUCCESS, complex_sub(&c1, &c2, &result));
    TEST_ASSERT_EQUAL(50, result.real);
    TEST_ASSERT_EQUAL(80, result.imaginary);
}

void cmul(void)
{
    c1.real = 0;
    c1.imaginary = 0;

    c2.real = 0;
    c2.imaginary = 0;

    TEST_ASSERT_EQUAL(SUCCESS, complex_mul(&c1, &c2, &result));
    TEST_ASSERT_EQUAL(0, result.real);
    TEST_ASSERT_EQUAL(0, result.imaginary);

    c1.real = 30;
    c1.imaginary = 40;

    c2.real = 20;
    c2.imaginary = 80;

    TEST_ASSERT_EQUAL(SUCCESS, complex_mul(&c1, &c2, &result));
    TEST_ASSERT_EQUAL(-2600, result.real);
    TEST_ASSERT_EQUAL(3200, result.imaginary);

    c1.real = -50;
    c1.imaginary = -25;

    c2.real = 80;
    c2.imaginary = 85;

    TEST_ASSERT_EQUAL(SUCCESS, complex_mul(&c1, &c2, &result));
    TEST_ASSERT_EQUAL(-1875, result.real);
    TEST_ASSERT_EQUAL(-6250, result.imaginary);

    c1.real = -25;
    c1.imaginary = -15;

    c2.real = -75;
    c2.imaginary = -95;

    TEST_ASSERT_EQUAL(SUCCESS, complex_mul(&c1, &c2, &result));
    TEST_ASSERT_EQUAL(450, result.real);
    TEST_ASSERT_EQUAL(3500, result.imaginary);

    c1.real = 0;
    c1.imaginary = -15;

    c2.real = -75;
    c2.imaginary = 0;

    TEST_ASSERT_EQUAL(SUCCESS, complex_mul(&c1, &c2, &result));
    TEST_ASSERT_EQUAL(0, result.real);
    TEST_ASSERT_EQUAL(1125, result.imaginary);
}

void cdiv(void)
{
    c1.real = 0;
    c1.imaginary = 0;

    c2.real = 0;
    c2.imaginary = 0;

    TEST_ASSERT_EQUAL(ERROR_DIV_BY_ZERO, complex_div(&c1, &c2, &result));

    c1.real = 30;
    c1.imaginary = 40;

    c2.real = 20;
    c2.imaginary = 80;

    TEST_ASSERT_EQUAL(SUCCESS, complex_div(&c1, &c2, &result));
    TEST_ASSERT_EQUAL(0, result.real);
    TEST_ASSERT_EQUAL(0, result.imaginary);

    c1.real = 55;
    c1.imaginary = -3;

    c2.real = 10;
    c2.imaginary = 10;

    TEST_ASSERT_EQUAL(SUCCESS, complex_div(&c1, &c2, &result));
    TEST_ASSERT_EQUAL(2, result.real);
    TEST_ASSERT_EQUAL(-2, result.imaginary);

    c1.real = -50;
    c1.imaginary = -25;

    c2.real = 80;
    c2.imaginary = 85;

    TEST_ASSERT_EQUAL(SUCCESS, complex_div(&c1, &c2, &result));
    TEST_ASSERT_EQUAL(0, result.real);
    TEST_ASSERT_EQUAL(0, result.imaginary);

    c1.real = -25;
    c1.imaginary = -15;

    c2.real = -75;
    c2.imaginary = -95;

    TEST_ASSERT_EQUAL(SUCCESS, complex_div(&c1, &c2, &result));
    TEST_ASSERT_EQUAL(0, result.real);
    TEST_ASSERT_EQUAL(0, result.imaginary);

    c1.real = 0;
    c1.imaginary = -15;

    c2.real = -75;
    c2.imaginary = 0;

    TEST_ASSERT_EQUAL(SUCCESS, complex_div(&c1, &c2, &result));
    TEST_ASSERT_EQUAL(0, result.real);
    TEST_ASSERT_EQUAL(0, result.imaginary);
}

int test_main(void)

{
    /* Initiate the Unity Test Framework */
    UNITY_BEGIN();

    /* Run Test functions */
    RUN_TEST(test_zero);
    RUN_TEST(test_positive);
    RUN_TEST(test_negative);
    RUN_TEST(cadd);
    RUN_TEST(cdiff);
    RUN_TEST(cmul);
    RUN_TEST(cdiv);

    /* Close the Unity Test Framework */
    return UNITY_END();
}

// int main(void)
//{
    /* Initiate the Unity Test Framework */
  //  UNITY_BEGIN();

    /* Run Test functions */


    /* Close the Unity Test Framework */
   // return UNITY_END();
 
//} 