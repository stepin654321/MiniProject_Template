#include "complex_calculator.h"
#include "unity.h"

static complex_t c1 = {0, 0};
static complex_t c2 = {0, 0};
static complex_t c3 = {0, 0};
static complex_t c4 = {0, 0};
static complex_t result = {0, 0};
/* Required by the unity test framework */
void setUp()
{
}
/* Required by the unity test framework */
void tearDown()
{
}

void c_add(void){
    c1.real = 0;
    c1.imaginary = 0;
    
    c2.real = 0;
    c2.imaginary = 0;
    TEST_ASSERT_EQUAL(SUCCESS, complex_sum(&c1, &c2, &result));
    TEST_ASSERT_EQUAL(0, result.real);
    TEST_ASSERT_EQUAL(0, result.imaginary);

    c1.real = 25;
    c1.imaginary = 15;
    
    c2.real = 75;
    c2.imaginary = 95;
    TEST_ASSERT_EQUAL(SUCCESS, complex_sum(&c1, &c2, &result));
    TEST_ASSERT_EQUAL(100, result.real);
    TEST_ASSERT_EQUAL(110, result.imaginary);

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

    c1.real = 2;
    c1.imaginary = 0;
    
    c2.real = -5;
    c2.imaginary = 0;
    TEST_ASSERT_EQUAL(SUCCESS, complex_sum(&c1, &c2, &result));
    TEST_ASSERT_EQUAL(-3, result.real);
    TEST_ASSERT_EQUAL(0, result.imaginary);

    c1.real = 0;
    c1.imaginary = 10;
    
    c2.real = 0;
    c2.imaginary = 5;
    TEST_ASSERT_EQUAL(SUCCESS, complex_sum(&c1, &c2, &result));
    TEST_ASSERT_EQUAL(0, result.real);
    TEST_ASSERT_EQUAL(15, result.imaginary);
}

void c_sub(void){
    c1.real = 0;
    c1.imaginary = 0;
    
    c2.real = 0;
    c2.imaginary = 0;
    TEST_ASSERT_EQUAL(SUCCESS, complex_diff(&c1, &c2, &result));
    TEST_ASSERT_EQUAL(0, result.real);
    TEST_ASSERT_EQUAL(0, result.imaginary);        

    c1.real = 25;
    c1.imaginary = 15;
    
    c2.real = 75;
    c2.imaginary = 95;
    TEST_ASSERT_EQUAL(SUCCESS, complex_diff(&c1, &c2, &result));
    TEST_ASSERT_EQUAL(-50, result.real);
    TEST_ASSERT_EQUAL(-80, result.imaginary);

    c1.real = -25;
    c1.imaginary = -15;
    
    c2.real = 75;
    c2.imaginary = 95;
    TEST_ASSERT_EQUAL(SUCCESS, complex_diff(&c1, &c2, &result));
    TEST_ASSERT_EQUAL(-100, result.real);
    TEST_ASSERT_EQUAL(-110, result.imaginary);

    c1.real = -25;
    c1.imaginary = -15;
    
    c2.real = -75;
    c2.imaginary = -95;
    TEST_ASSERT_EQUAL(SUCCESS, complex_diff(&c1, &c2, &result));
    TEST_ASSERT_EQUAL(50, result.real);
    TEST_ASSERT_EQUAL(80, result.imaginary);

    c1.real = 2;
    c1.imaginary = 0;
    
    c2.real = -5;
    c2.imaginary = 0;
    TEST_ASSERT_EQUAL(SUCCESS, complex_diff(&c1, &c2, &result));
    TEST_ASSERT_EQUAL(7, result.real);
    TEST_ASSERT_EQUAL(0, result.imaginary);

    c1.real = 0;
    c1.imaginary = 10;
    
    c2.real = 0;
    c2.imaginary = 5;
    TEST_ASSERT_EQUAL(SUCCESS, complex_diff(&c1, &c2, &result));
    TEST_ASSERT_EQUAL(0, result.real);
    TEST_ASSERT_EQUAL(5, result.imaginary);
}

void c_mul(void){
    c1.real = 0;
    c1.imaginary = 0;
    
    c2.real = 0;
    c2.imaginary = 0;
    TEST_ASSERT_EQUAL(SUCCESS, complex_mul(&c1, &c2, &result));
    TEST_ASSERT_EQUAL(0, result.real);
    TEST_ASSERT_EQUAL(0, result.imaginary);

    c1.real = 25;
    c1.imaginary = 15;
    
    c2.real = 75;
    c2.imaginary = 95;
    TEST_ASSERT_EQUAL(SUCCESS, complex_mul(&c1, &c2, &result));
    TEST_ASSERT_EQUAL(450, result.real);
    TEST_ASSERT_EQUAL(3500, result.imaginary);

    c1.real = -25;
    c1.imaginary = -15;
    
    c2.real = 75;
    c2.imaginary = 95;
    TEST_ASSERT_EQUAL(SUCCESS, complex_mul(&c1, &c2, &result));
    TEST_ASSERT_EQUAL(-450, result.real);
    TEST_ASSERT_EQUAL(-3500, result.imaginary);

    c1.real = -25;
    c1.imaginary = -15;
    
    c2.real = -75;
    c2.imaginary = -95;
    TEST_ASSERT_EQUAL(SUCCESS, complex_mul(&c1, &c2, &result));
    TEST_ASSERT_EQUAL(450, result.real);
    TEST_ASSERT_EQUAL(3500, result.imaginary);

    c1.real = 2;
    c1.imaginary = 0;
    
    c2.real = -5;
    c2.imaginary = 0;
    TEST_ASSERT_EQUAL(SUCCESS, complex_mul(&c1, &c2, &result));
    TEST_ASSERT_EQUAL(-10, result.real);
    TEST_ASSERT_EQUAL(0, result.imaginary);    

    c1.real = 0;
    c1.imaginary = 10;
    
    c2.real = 0;
    c2.imaginary = 5;
    TEST_ASSERT_EQUAL(SUCCESS, complex_mul(&c1, &c2, &result));
    TEST_ASSERT_EQUAL(-50, result.real);
    TEST_ASSERT_EQUAL(0, result.imaginary);  

}

void c_div(void){
    c3.real = 0;
    c3.imaginary = 0;
    
    c4.real = 0;
    c4.imaginary = 0;
    TEST_ASSERT_EQUAL(ERROR_DIV_BY_ZERO, complex_div(&c3, &c4, &result));
    TEST_ASSERT_EQUAL(0, result.real);
    TEST_ASSERT_EQUAL(0, result.imaginary);

    c3.real = 25;
    c3.imaginary = 15;
    
    c4.real = 75;
    c4.imaginary = 95;
    TEST_ASSERT_EQUAL(SUCCESS, complex_div(&c3, &c4, &result));
    TEST_ASSERT_EQUAL(0.6143, result.real);
    TEST_ASSERT_EQUAL(0.2218, result.imaginary);

    c3.real = -25;
    c3.imaginary = -15;
    
    c4.real = 75;
    c4.imaginary = 95;
    TEST_ASSERT_EQUAL(SUCCESS, complex_div(&c3, &c4, &result));
    TEST_ASSERT_EQUAL(-0.2252, result.real);
    TEST_ASSERT_EQUAL(0.0853, result.imaginary);

    c3.real = -25;
    c3.imaginary = -15;
    
    c4.real = -75;
    c4.imaginary = -95;
    TEST_ASSERT_EQUAL(SUCCESS, complex_div(&c3, &c4, &result));
    TEST_ASSERT_EQUAL(0.2252, result.real);
    TEST_ASSERT_EQUAL(-0.0853, result.imaginary);

    c3.real = 2;
    c3.imaginary = 0;
    
    c4.real = -5;
    c4.imaginary = 0;
    TEST_ASSERT_EQUAL(SUCCESS, complex_div(&c3, &c4, &result));
    TEST_ASSERT_EQUAL(-0.4, result.real);
    TEST_ASSERT_EQUAL(0, result.imaginary);

    c3.real = 0;
    c3.imaginary = 10;
    
    c4.real = 0;
    c4.imaginary = 2;
    TEST_ASSERT_EQUAL(SUCCESS, complex_div(&c3, &c4, &result));
    TEST_ASSERT_EQUAL(5, result.real);
    TEST_ASSERT_EQUAL(0, result.imaginary);
}

int main(void)
{
    /* Initiate the Unity Test Framework */
    UNITY_BEGIN();

    /* Run Test functions */
    RUN_TEST(c_add);
    RUN_TEST(c_sub);
    RUN_TEST(c_mul);
    RUN_TEST(c_div);

    /* Close the Unity Test Framework */
    return UNITY_END();
}
