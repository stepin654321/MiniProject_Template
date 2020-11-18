#include "unity.h"
#include "phone_book.h"

/* Required by the unity test framework */
void setUp(){}
/* Required by the unity test framework */
void tearDown(){}

void test_add_contact(void) {
  contact_t new_contact = {"Add_user", "12345", "user1@email.com"};
  TEST_ASSERT_EQUAL(0, add_contact(&new_contact));
}

void test_delete_contact(void) {
  contact_t new_contact = {"Delete_user", "12345", "user1@email.com"};
  TEST_ASSERT_EQUAL(0, add_contact(&new_contact));
  TEST_ASSERT_EQUAL(0, delete_contact(new_contact.name));
}

void test_modify_contact(void) {
  contact_t new_contact = {"Modify_User", "12345", "user1@email.com"};
  contact_t new_contact1 = {"Modified_User", "345", "new@email.com"};
  TEST_ASSERT_EQUAL(0, add_contact(&new_contact));
  TEST_ASSERT_EQUAL(0, modify_contact(new_contact.name, &new_contact1));
  TEST_ASSERT_EQUAL(0, delete_contact(new_contact1.name));
}
void test_search_contact(void) {
  contact_t new_contact = {"Search_User", "345", "new@email.com"};
  TEST_ASSERT_EQUAL(0, add_contact(&new_contact));
  TEST_ASSERT_EQUAL(0 , search_contact(new_contact.name));
  TEST_ASSERT_EQUAL(0 , delete_contact(new_contact.name));
}
void test_display_contact(void) 
{ 
  TEST_ASSERT_EQUAL(1, display_contact()>0);
}

int main(void)
{
/* Initiate the Unity Test Framework */
  UNITY_BEGIN();

/* Run Test functions */
  RUN_TEST(test_add_contact);
  RUN_TEST(test_delete_contact);
  RUN_TEST(test_modify_contact);
  RUN_TEST(test_search_contact);
  RUN_TEST(test_display_contact);

  /* Close the Unity Test Framework */
  return UNITY_END();
}
