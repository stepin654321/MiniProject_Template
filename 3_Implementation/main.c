#include <stdio.h>
#include <windows.h>
#include <time.h>
//#include "block.h"
#include "gameboard_operations.h"
#include "settings.h"


/*    
#define LEFT 75
#define RIGHT 77
#define UP 72
#define SPACE 32

//Size of gameboard
#define GBOARD_WIDTH 10
#define GBOARD_HEIGHT 20 

//Starting point of gameboard
#define GBOARD_ORIGIN_X 5
#define GBOARD_ORIGIN_Y 3
*/

int level = 0;
int up = 0;
int score = 0;
int block_id;
int block_id_next;
int speed = 15;
int score_speed = 10;
int gameBoardInfo[GBOARD_HEIGHT + 1][GBOARD_WIDTH + 2];

COORD curPos = {GBOARD_ORIGIN_X + GBOARD_WIDTH, GBOARD_ORIGIN_Y / 2};
COORD start;

extern char blockModel[][4][4];

int main()
{
	start = GetCurrentCursorPos();
	{
		int line_cnt = 0;
		RemoveCursor();
		DrawGameBoard();
		SetCurrentCursorPos(GBOARD_ORIGIN_X + GBOARD_WIDTH, 0);
		srand((unsigned int)time(NULL));
		block_id = (rand() % 7) * 4;
		block_id_next = (rand() % 7) * 4;

		//block_id = (rand() % 8) * 4;
		//block_id_next = (rand() % 8) * 4;

		Show_next_block(block_id_next);
	}

	while (1)
	{
		curPos.X = GBOARD_ORIGIN_X + GBOARD_WIDTH;
		curPos.Y = 0;
		ScoreBoard();
		if (IsGameOver()) break;
		while (1)
		{
			if (BlockDown() == 0)
			{
				if (block_id >= 28) RemoveLineBlock();
				else AddBlockToBoard(block_id);
				RedrawBlocks();
				if (up)
				{
					lineup();
					RedrawBlocks();
				}
			
				break;
			}
			Control_level(); 
			ProcessKeyInput();
		}
		RemoveFillUpLine(); 
		{
			block_id = block_id_next;
			Delete_next_block(blockModel[block_id]);
			block_id_next = (rand() % 7) * 4;
			//block_id_next = (rand() % 8) * 4;
			Show_next_block(block_id_next);
		}

	}
	{
		//SetCurrentCursorPos(start.X, start.Y);
		SetCurrentCursorPos(GBOARD_ORIGIN_X + GBOARD_WIDTH, 0);
		printf("Game Over!!");
	}

	return 0;
}