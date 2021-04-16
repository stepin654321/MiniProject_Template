#include "unity.h"
#include <stdio.h>
#include <windows.h>
#include <time.h>
//#include "block.h"
#include "gameboard_operations.h"
#include "test_settings.h"
#include <conio.h>

/* Modify these two lines according to the project */
//#include <_operations.h>
#define PROJECT_NAME "Tetris"


int level = 0;
int up = 0;
int score = 0;
int block_id;
int block_id_next;
int speed = 15;
int score_speed = 10;
int gameBoardInfo[GBOARD_HEIGHT + 1][GBOARD_WIDTH + 2];

COORD curPos = {GBOARD_ORIGIN_X + GBOARD_WIDTH, GBOARD_ORIGIN_Y / 2};

//char blockModel[][4][4];

/* Prototypes for all the test functions */
void test_HUD(void);
int HUD_tester();
//void test_subtract(void);
//void test_multiply(void);
//void test_divide(void);

/* Required by the unity test framework */
void setUp() {}
/* Required by the unity test framework */
void tearDown() {}
COORD start;
/* Start of the application test */
int main()
{
  /* Initiate the Unity Test Framework */
  UNITY_BEGIN();
  start = GetCurrentCursorPos();
  int line_cnt = 0;
  RemoveCursor();
  DrawGameBoard();
  SetCurrentCursorPos(GBOARD_ORIGIN_X + GBOARD_WIDTH, 0);
  srand((unsigned int)time(NULL));
  block_id = (rand() % 7) * 4;
  block_id_next = (rand() % 7) * 4;

  //block_id = (rand() % 8) * 4;
  //block_id_next = (rand() % 8) * 4;

  

  /* Run Test functions */
  RUN_TEST(test_HUD);
  //RUN_TEST(test_subtract);
  //RUN_TEST(test_multiply);
  //RUN_TEST(test_divide);

  /* Close the Unity Test Framework */
  
  return UNITY_END();
}

int HUD_tester() 
{
  Show_next_block(block_id_next);
  ScoreBoard();

  //

  SetCurrentCursorPos(0, start.Y + 25);
  printf("Did the HUD show up?(Y/N): ");
  ShowCursorCustom();
  char diagnostic;
  scanf("%c", &diagnostic);
  RemoveCursor();
  if (diagnostic == 'Y' || diagnostic == 'y')
    return 1;
  return 0;

}

/* Write all the test functions */
void test_HUD(void)
{

  TEST_ASSERT_EQUAL(1, HUD_tester());

  /* Dummy fail*/
  //TEST_ASSERT_EQUAL(15000, add(7500, 7500));
}
/*
void test_subtract(void)
{
  TEST_ASSERT_EQUAL(-3, subtract(0, 3));

  TEST_ASSERT_EQUAL(100, subtract(1000, 900));
}

void test_multiply(void)
{
  TEST_ASSERT_EQUAL(0, multiply(1, 0));


  TEST_ASSERT_EQUAL(10, multiply(2, 5));
}

void test_divide(void)
{
  TEST_ASSERT_EQUAL(0, divide(1, 0));


  TEST_ASSERT_EQUAL(1, divide(2, 2));
}  

*/