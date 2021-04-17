




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
#define YES 89
#define yes 121

int level = 0;
int up = 0;
int score = 0;
int block_id;
int block_id_next;
int speed = 15;
int score_speed = 10;
int gameBoardInfo[GBOARD_HEIGHT + 2][GBOARD_WIDTH + 2];



int diagnosticTest()
{
  ShowCursorCustom();
  int diagnostic = getch();
  RemoveCursor();
  if (diagnostic == YES || diagnostic == yes)
    return 1;
  return 0;
}

int unity_print = 2;

char blockModel[][4][4];

/* Prototypes for all the test functions */
void test_GameBoard(void);
int GameBoard_tester();

void test_nextBlock(void);
int nextBlock_tester();

void test_HUD(void);
int HUD_tester();

void test_Add(void);
int Add_tester();

void test_BlockDown(void);
int BlockDown_tester();

void test_ShowBlock(void);
int ShowBlock_tester();

void test_DeleteBlock(void);
int DeleteBlock_tester();

//void test_subtract(void);
//void test_multiply(void);
//void test_divide(void);

/* Required by the unity test framework */
void setUp() {}
/* Required by the unity test framework */
void tearDown() {}
COORD now;
COORD start;
COORD curPos = {GBOARD_ORIGIN_X + GBOARD_WIDTH, GBOARD_ORIGIN_Y};
/* Start of the application test */
int main()
{
  /* Initiate the Unity Test Framework */
  system("cls");
  UNITY_BEGIN();
  start = GetCurrentCursorPos();
  int line_cnt = 0;
  RemoveCursor();
  now = GetCurrentCursorPos();
  RUN_TEST(test_GameBoard);
  //SetCurrentCursorPos(GBOARD_ORIGIN_X + GBOARD_WIDTH, 0);
  srand((unsigned int)time(NULL));
  block_id = (rand() % 7) * 4;
  block_id_next = (rand() % 7) * 4;

  //block_id = (rand() % 8) * 4;
  //block_id_next = (rand() % 8) * 4;
  RUN_TEST(test_HUD);
  RUN_TEST(test_nextBlock);
  RUN_TEST(test_Add);
  RUN_TEST(test_DeleteBlock);
  RUN_TEST(test_ShowBlock);
  RUN_TEST(test_BlockDown);

  SetCurrentCursorPos(0, now.Y + unity_print++);
  printf("redrawing blocks...\n");
  RedrawBlocks();

  /* Run Test functions */

  //RUN_TEST(test_subtract);
  //RUN_TEST(test_multiply);
  //RUN_TEST(test_divide);

  /* Close the Unity Test Framework */
  ShowCursorCustom();
  return UNITY_END();
}

void test_GameBoard(void)
{
  TEST_ASSERT_EQUAL(1, GameBoard_tester());
}

void test_nextBlock(void)
{
  TEST_ASSERT_EQUAL(1, nextBlock_tester());
}

void test_HUD(void)
{
  TEST_ASSERT_EQUAL(1, HUD_tester());
}

void test_Add(void)
{
  TEST_ASSERT_EQUAL(1, Add_tester());
}

void test_BlockDown(void)
{
  TEST_ASSERT_EQUAL(1, BlockDown_tester());
}

void test_DeleteBlock(void)
{
  TEST_ASSERT_EQUAL(1, DeleteBlock_tester());
}

void test_ShowBlock(void)
{
  TEST_ASSERT_EQUAL(1, ShowBlock_tester());
}

//COORD now;

int GameBoard_tester()
{
  DrawGameBoard();
  now = GetCurrentCursorPos();
  SetCurrentCursorPos(0, now.Y + unity_print++);
  printf("Did the GameBoard show up?(Y/N): ");
  return diagnosticTest();
}

int HUD_tester()
{
  ScoreBoard();
  SetCurrentCursorPos(0, now.Y + unity_print++);
  printf("Did the HUD show up?(Y/N): ");
  return diagnosticTest();
}

int nextBlock_tester()
{
  Show_next_block(block_id_next);
  SetCurrentCursorPos(0, now.Y + unity_print++);
  printf("Did the nextBlock show up?(Y/N): ");
  return diagnosticTest();
}

int Add_tester()
{
  AddBlockToBoard(block_id);
  RedrawBlocks();
  SetCurrentCursorPos(0, now.Y + unity_print++);
  printf("Did the block show up?(Y/N): ");
  return diagnosticTest();
}

int DeleteBlock_tester()
{
  curPos.X = GBOARD_ORIGIN_X + GBOARD_WIDTH;
  curPos.Y = GBOARD_ORIGIN_Y;
  SetCurrentCursorPos(curPos.X, curPos.Y);
  DeleteBlock(blockModel[block_id]);
  SetCurrentCursorPos(0, now.Y + unity_print++);
  printf("Did the block disappear?(Y/N): ");
  return diagnosticTest();
}

int ShowBlock_tester()
{
  curPos.X = GBOARD_ORIGIN_X + GBOARD_WIDTH;
  curPos.Y = GBOARD_ORIGIN_Y;
  SetCurrentCursorPos(curPos.X, curPos.Y);
  ShowBlock(blockModel[block_id]);
  SetCurrentCursorPos(0, now.Y + unity_print++);
  printf("Did the block re-appear?(Y/N): ");
  return diagnosticTest();
}


int BlockDown_tester()
{
  RedrawBlocks();
  curPos.X = GBOARD_ORIGIN_X + GBOARD_WIDTH;
  curPos.Y = GBOARD_ORIGIN_Y;
  //COORD curPos = {GBOARD_ORIGIN_X + GBOARD_WIDTH, GBOARD_ORIGIN_Y};

  SetCurrentCursorPos(curPos.X, curPos.Y);

  //int diagnosticy = getch();
  ShowCursorCustom();
  int diagnostic = getch();
  //printf("");
  //RedrawBlocks();

  while (1)
  {

    int i;
    for (i = 0; i < 25; i++)
    {
      /* 
      if (BlockDown() == 0)
      {
        //RedrawBlocks();
        SetCurrentCursorPos(0, now.Y + 8);
        printf("Did the block fall down?(Y/N): ");
        return diagnosticTest();

      }
      */
      //COORD curPosNow = GetCurrentCursorPos();
      //if (DetectCollision(curPos.X, curPos.Y + 1, blockModel[block_id]) == 0)
        //return 0;
      //int diagnostic1 = getch();
      //DeleteBlock(blockModel[block_id]);

      //curPos.Y++;
      //SetCurrentCursorPos(curPos.X, curPos.Y);

      //if (DetectCollision(curPos.X, curPos.Y + 1, blockModel[block_id]) == 0)
        //break;
      //ShowBlock(blockModel[block_id]);
      //DeleteBlock(blockModel[block_id]);
      //curPos.Y++;
      //SetCurrentCursorPos(curPos.X, curPos.Y);
      int p = BlockDown();

      int diagnositc4 = getch();

      //int p = BlockDown();
      //ShowBlock(blockModel[block_id]);
    }
    SetCurrentCursorPos(0, now.Y + unity_print++);
    printf("Did the block fall down?(Y/N): ");
    return diagnosticTest();
  }
  SetCurrentCursorPos(0, now.Y + unity_print++);
  printf("Did the block fall down?(Y/N): ");
  return diagnosticTest();
}

//AddBlockToBoard(block_id);
//RedrawBlocks();
/* Write all the test functions */

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