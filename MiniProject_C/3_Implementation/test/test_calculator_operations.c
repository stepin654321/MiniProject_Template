#include "unity.h"
#include "../calculator_operations.h"

/* Modify these two lines according to the project */
#define PROJECT_NAME    "Calculator"

/* Prototypes for all the test functions */
void test_add(void);
void test_subtract(void);
void test_multiply(void);
void test_divide(void);

/* Required by the unity test framework */
void setUp(){}
/* Required by the unity test framework */
void tearDown(){}

/* Start of the application test */
int main()
{
/* Initiate the Unity Test Framework */
  UNITY_BEGIN();

/* Run Test functions */
  RUN_TEST(test_add);
  RUN_TEST(test_subtract);
  RUN_TEST(test_multiply);
  RUN_TEST(test_divide);

  /* Close the Unity Test Framework */
  return UNITY_END();
}

/* Write all the test functions */ 
void test_add(void) {
  struct complex_t a,b;
  a.real = 5; a.imaginary = 6;
  b.real = 10; b.imaginary = 5;
  TEST_ASSERT_EQUAL("15.000000 11.000000", add(a, b));
  
  /* Dummy fail*/
  TEST_ASSERT_EQUAL("15.000000 10.000000", add(a,b));
}

void test_subtract(void) {
  struct complex_t a,b, ans;
  a.real = 5; a.imaginary = 6;
  b.real = 10; b.imaginary = 5;
  ans.real = -5; ans.imaginary = 1;
  TEST_ASSERT(ans == subtract(a, b));
  
  /* Dummy fail*/
  TEST_ASSERT_EQUAL("-5.000000 14.000000", subtract(a, b));
}

void test_multiply(void) {
  struct complex_t a,b,ans;
  a.real = 5; a.imaginary = 6;
  b.real = 10; b.imaginary = 5;
  ans.real = 20; ans.imaginary = 85;
  TEST_ASSERT(ans == multiply(a, b));
  
  /* Dummy fail*/
  TEST_ASSERT_EQUAL("20.000000 8.000000", multiply(a, b));
}

void test_divide(void) {
  struct complex_t a,b, ans;
  a.real = 5; a.imaginary = 6;
  b.real = 10; b.imaginary = 5;
  ans.real = 0.64; ans.imaginary = 0.28;
  TEST_ASSERT_EQUAL(ans, divide(a, b));
  
  /* Dummy fail*/
  TEST_ASSERT_EQUAL("0.640000 0.280000", divide(a, b));
}
