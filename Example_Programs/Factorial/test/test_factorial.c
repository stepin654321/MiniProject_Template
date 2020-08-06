#include "unity.h"
#include "factorial.h"
/* Required by the unity test framework */
void setUp(){}
/* Required by the unity test framework */
void tearDown(){}

void test_Factorial(void)
{
  TEST_ASSERT_EQUAL(120, factorial(5));
  TEST_ASSERT_EQUAL(720, factorial(6));
}
void test_Zero_One(void)
{
  TEST_ASSERT_EQUAL(1, factorial(0));
  TEST_ASSERT_EQUAL(1, factorial(1));
}
void test_Negative(void)
{
  TEST_ASSERT_EQUAL(-1, factorial(-5));
  TEST_ASSERT_EQUAL(-1, factorial(-10));
}

int test_main(void)
{
/* Initiate the Unity Test Framework */
  UNITY_BEGIN();

  RUN_TEST(test_Factorial);
  RUN_TEST(test_Zero_One);
  RUN_TEST(test_Negative);

  /* Close the Unity Test Framework */
  return UNITY_END();
}
