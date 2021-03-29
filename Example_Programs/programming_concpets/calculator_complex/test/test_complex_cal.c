#include "complex_cal.h"
#include "unity.h"

static complex_t c1 = {0, 0};
static complex_t c2 = {0, 0};
static complex_t x = {1, 1};
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

    TEST_ASSERT_EQUAL(SUCCESS, complex_diff(&c1, &c2, &result));
    TEST_ASSERT_EQUAL(0, result.real);
    TEST_ASSERT_EQUAL(0, result.imaginary);

    TEST_ASSERT_EQUAL(SUCCESS, complex_mul(&c1, &c2, &result));
    TEST_ASSERT_EQUAL(0, result.real);
    TEST_ASSERT_EQUAL(0, result.imaginary);

    TEST_ASSERT_EQUAL(ERR_DIV_BY_ZERO, complex_div(&c1, &c2, &result));
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

    TEST_ASSERT_EQUAL(SUCCESS, complex_diff(&c1, &c2, &result));
    TEST_ASSERT_EQUAL(-50, result.real);
    TEST_ASSERT_EQUAL(-80, result.imaginary);

    TEST_ASSERT_EQUAL(SUCCESS, complex_mul(&c1, &c2, &result));
    TEST_ASSERT_EQUAL(450, result.real);
    TEST_ASSERT_EQUAL(3500, result.imaginary);

    TEST_ASSERT_EQUAL(SUCCESS, complex_div(&c1, &c2, &result));
    TEST_ASSERT_EQUAL(0.225256, result.real);
    TEST_ASSERT_EQUAL(-0.0853242, result.imaginary);
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

    TEST_ASSERT_EQUAL(SUCCESS, complex_diff(&c1, &c2, &result));
    TEST_ASSERT_EQUAL(-100, result.real);
    TEST_ASSERT_EQUAL(-110, result.imaginary);

    TEST_ASSERT_EQUAL(SUCCESS, complex_mul(&c1, &c2, &result));
    TEST_ASSERT_EQUAL(-450, result.real);
    TEST_ASSERT_EQUAL(-3500, result.imaginary);

    TEST_ASSERT_EQUAL(SUCCESS, complex_div(&c1, &c2, &result));
    TEST_ASSERT_EQUAL(-0.225256, result.real);
    TEST_ASSERT_EQUAL(0.0853242, result.imaginary);

    c1.real = -25;
    c1.imaginary = -15;

    c2.real = -75;
    c2.imaginary = -95;

    TEST_ASSERT_EQUAL(SUCCESS, complex_sum(&c1, &c2, &result));
    TEST_ASSERT_EQUAL(-100, result.real);
    TEST_ASSERT_EQUAL(-110, result.imaginary);

    TEST_ASSERT_EQUAL(SUCCESS, complex_diff(&c1, &c2, &result));
    TEST_ASSERT_EQUAL(50, result.real);
    TEST_ASSERT_EQUAL(80, result.imaginary);

    TEST_ASSERT_EQUAL(SUCCESS, complex_mul(&c1, &c2, &result));
    TEST_ASSERT_EQUAL(450, result.real);
    TEST_ASSERT_EQUAL(3500, result.imaginary);

    TEST_ASSERT_EQUAL(SUCCESS, complex_div(&c1, &c2, &result));
    TEST_ASSERT_EQUAL(0.225256, result.real);
    TEST_ASSERT_EQUAL(-0.0853242, result.imaginary);
}

void test_null(void)
{

    TEST_ASSERT_EQUAL(ERR_NULL_PTR, complex_sum(NULL, NULL, &result));
    TEST_ASSERT_EQUAL(ERR_NULL_PTR, complex_sum(&x, NULL, &result));
    TEST_ASSERT_EQUAL(ERR_NULL_PTR, complex_sum(NULL, &x, &result));

    TEST_ASSERT_EQUAL(ERR_NULL_PTR, complex_diff(NULL, NULL, &result));
    TEST_ASSERT_EQUAL(ERR_NULL_PTR, complex_diff(NULL, &x, &result));
    TEST_ASSERT_EQUAL(ERR_NULL_PTR, complex_diff(&x, NULL, &result));

    TEST_ASSERT_EQUAL(ERR_NULL_PTR, complex_mul(NULL, NULL, &result));
    TEST_ASSERT_EQUAL(ERR_NULL_PTR, complex_mul(NULL, &x, &result));
    TEST_ASSERT_EQUAL(ERR_NULL_PTR, complex_mul(&x, NULL, &result));

    TEST_ASSERT_EQUAL(ERR_NULL_PTR, complex_div(NULL, NULL, &result));
    TEST_ASSERT_EQUAL(ERR_NULL_PTR, complex_div(&x, NULL, &result));
    TEST_ASSERT_EQUAL(ERR_NULL_PTR, complex_div(NULL, &x, &result));
}
int main(void)
{
    /* Initiate the Unity Test Framework */
    UNITY_BEGIN();

    /* Run Test functions */
    RUN_TEST(test_zero);
    RUN_TEST(test_positive);
    RUN_TEST(test_negative);
    RUN_TEST(test_null);

    /* Close the Unity Test Framework */
    return UNITY_END();
}
/*UNIT TEST OUTPUT
test/test_complex_calculator.c:139:test_zero:PASS
test/test_complex_calculator.c:140:test_positive:PASS
test/test_complex_calculator.c:141:test_negative:PASS
test/test_complex_calculator.c:142:test_null:PASS

-----------------------
4 Tests 0 Failures 0 Ignored 
OK
*/
