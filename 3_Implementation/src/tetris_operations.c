

#include <stdio.h>
#include <windows.h>
#include <time.h>
#include "block.h"
#include "gameboard_operations.h"
#include "settings.h"
#include <conio.h>

extern int level;
extern int up;
extern int score;
extern int block_id;
extern int block_id_next;
extern int speed;
extern int score_speed;
extern int gameBoardInfo[GBOARD_HEIGHT + 1][GBOARD_WIDTH + 2];
//extern char blockModel[][4][4];

extern COORD curPos;

void SetCurrentCursorPos(int x, int y)
{
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
//Ŀ�� �ش� ��ġ�� �ֱ�

COORD GetCurrentCursorPos(void)
{
    COORD curPoint;
    CONSOLE_SCREEN_BUFFER_INFO curInfo;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
    curPoint.X = curInfo.dwCursorPosition.X;
    curPoint.Y = curInfo.dwCursorPosition.Y;
    return curPoint;
}
//Ŀ�� ���

void RemoveCursor(void)
{
    CONSOLE_CURSOR_INFO curInfo;
    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
    curInfo.bVisible = 0;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}
//Ŀ�� �����

void ShowBlock(char blockInfo[4][4])
{
    int x, y;
    COORD curPos = GetCurrentCursorPos();
    for (y = 0; y < 4; y++)
    {
        for (x = 0; x < 4; x++)
        {
            SetCurrentCursorPos(curPos.X + (x * 2), curPos.Y + y);
            if (blockInfo[y][x] == 1)
                printf("#");
        }
    }
    SetCurrentCursorPos(curPos.X, curPos.Y);
}
//���� ���

void DeleteBlock(char blockInfo[4][4])
{
    int x, y;
    COORD curPos = GetCurrentCursorPos();
    for (y = 0; y < 4; y++)
    {
        for (x = 0; x < 4; x++)
        {
            SetCurrentCursorPos(curPos.X + (x * 2), curPos.Y + y);
            if (blockInfo[y][x] == 1)
                printf(" ");
        }
    }
    SetCurrentCursorPos(curPos.X, curPos.Y);
}
//���� ����

int DetectCollision(int posX, int posY, char blockModelNow[4][4])
{
    int x, y;
    int arrX = (posX - GBOARD_ORIGIN_X) / 2;
    int arrY = posY - GBOARD_ORIGIN_Y;

    for (y = 0; y < 4; y++)
        for (x = 0; x < 4; x++)
            if (blockModelNow[y][x] == 1 && gameBoardInfo[arrY + y][arrX + x] == 1)
                return 0;
    return 1;
}
//���ϰ� �� �浹üũ

int ShiftRight()
{
    if (!DetectCollision(curPos.X + 2, curPos.Y, blockModel[block_id]))
        return 0;
    DeleteBlock(blockModel[block_id]);
    curPos.X += 2;
    SetCurrentCursorPos(curPos.X, curPos.Y);
    ShowBlock(blockModel[block_id]);
}
//������ ���������� �����̰Բ�

int ShiftLeft()
{
    if (!DetectCollision(curPos.X - 2, curPos.Y, blockModel[block_id]))
        return 0;
    DeleteBlock(blockModel[block_id]);
    curPos.X -= 2;
    SetCurrentCursorPos(curPos.X, curPos.Y);
    ShowBlock(blockModel[block_id]);
}
//������ �������� �����̰Բ�

void ShiftUp()
{
    DeleteBlock(blockModel[block_id]);
    curPos.Y -= 2;
    SetCurrentCursorPos(curPos.X, curPos.Y);
    ShowBlock(blockModel[block_id]);
}
//������ ���� ���� ���Բ�

int BlockDown()
{
    if (DetectCollision(curPos.X, curPos.Y + 1, blockModel[block_id]) == 0)
        return 0;
    DeleteBlock(blockModel[block_id]);
    curPos.Y++;
    SetCurrentCursorPos(curPos.X, curPos.Y);
    ShowBlock(blockModel[block_id]);
    return 1;
}
//������ �Ʒ��� �����̰Բ�

void SpaceDown()
{
    while (BlockDown());
}
//�����̽��ٸ� ����� �ѹ��� ������ ��

void RotateBlock()
{
    int block_base = block_id - block_id % 4;
    int block_rotated = block_base + (block_id + 1) % 4;
    if (!DetectCollision(curPos.X, curPos.Y, blockModel[block_rotated]))
        return;
    DeleteBlock(blockModel[block_id]);
    block_id = block_rotated;
    ShowBlock(blockModel[block_id]);
}
//������ ��׸�����

void ProcessKeyInput()
{
    int i, key, y;
    for (i = 0; i < 20; i++) 
    {                        
        if (kbhit() != 0)   
        {
            key = getch();
            switch (key)
            {
            case LEFT:
                ShiftLeft();
                break;
            case RIGHT:
                ShiftRight();
                break;
            case UP:
                RotateBlock();
                break;
            case SPACE:
                SpaceDown();
                break;
            case ESC:
                exit(0);
                break;
            }
        }
        Sleep(speed);
    }
}
//Ű���� ����Ű ���� ������

void DrawGameBoard()
{
    int x, y;
    for (y = 0; y <= GBOARD_HEIGHT; y++)
    {
        SetCurrentCursorPos(GBOARD_ORIGIN_X, GBOARD_ORIGIN_Y + y);
        if (y == GBOARD_HEIGHT)
            printf("-");
        else
            printf("|");
    }
    for (y = 0; y <= GBOARD_HEIGHT; y++)
    {
        SetCurrentCursorPos(GBOARD_ORIGIN_X + (GBOARD_WIDTH + 1) * 2, GBOARD_ORIGIN_Y + y);
        if (y == GBOARD_HEIGHT)
            printf("-");
        else
            printf("|");
    }
    for (x = 0; x < GBOARD_WIDTH; x++)
    {
        SetCurrentCursorPos(GBOARD_ORIGIN_X + x * 2 + 2, GBOARD_ORIGIN_Y + GBOARD_HEIGHT);
        printf("-");
    }

    //Collision Check
    for (y = 0; y < GBOARD_HEIGHT; y++)
    {
        gameBoardInfo[y][0] = 1;
        gameBoardInfo[y][GBOARD_WIDTH + 1] = 1;
    }
    for (x = -1; x < GBOARD_WIDTH; x++)
        gameBoardInfo[GBOARD_HEIGHT][x + 1] = 1;
}
//������ Ʋ(������ ��� ����)

void AddBlockToBoard(int shape)
{
    int x, y, arrCurX, arrCurY;
    for (y = 0; y < 4; y++)
    {
        for (x = 0; x < 4; x++)
        {
            /*	if (shape >= 28 && !DetectCollision(curPos.X + 2, curPos.Y, blockModel[shape]))
			{
				arrCurX = (curPos.X + 1 - GBOARD_ORIGIN_X) / 2;
				arrCurY = curPos.Y - GBOARD_ORIGIN_Y;
				gameBoardInfo[arrCurY + y][arrCurX + x] = 0;
			}
			if (shape >= 28 && !DetectCollision(curPos.X - 2, curPos.Y, blockModel[shape]))
			{
				arrCurX = (curPos.X - 1 - GBOARD_ORIGIN_X) / 2;
				arrCurY = curPos.Y - GBOARD_ORIGIN_Y;
				gameBoardInfo[arrCurY + y][arrCurX + x] = 0;
			}
			if (shape >= 28 && !DetectCollision(curPos.X, curPos.Y - 1, blockModel[shape]))
			{
				arrCurX = (curPos.X - GBOARD_ORIGIN_X) / 2;
				arrCurY = curPos.Y - GBOARD_ORIGIN_Y - 1;
				gameBoardInfo[arrCurY + y][arrCurX + x] = 0;
			}
			if (shape >= 28 && !DetectCollision(curPos.X, curPos.Y + 1, blockModel[shape]))
			{
				arrCurX = (curPos.X - GBOARD_ORIGIN_X) / 2;
				arrCurY = curPos.Y - GBOARD_ORIGIN_Y + 1;
				gameBoardInfo[arrCurY + y][arrCurX + x] = 0;
			}*/
            //Convert X,Y cordinate to array index
            arrCurX = (curPos.X - GBOARD_ORIGIN_X) / 2;
            arrCurY = curPos.Y - GBOARD_ORIGIN_Y;

            if (blockModel[block_id][y][x] == 1)
                gameBoardInfo[arrCurY + y][arrCurX + x] = 1;
        }
    }
}
//���� ���̸� ��Ŀ� �߰�

void RedrawBlocks()
{
    int x, y;
    int cursX, cursY;
    for (y = 0; y < GBOARD_HEIGHT; y++)
    {
        for (x = 1; x < GBOARD_WIDTH + 1; x++)
        {
            cursX = x * 2 + GBOARD_ORIGIN_X;
            cursY = y + GBOARD_ORIGIN_Y;
            SetCurrentCursorPos(cursX, cursY);
            if (gameBoardInfo[y][x] == 1)
                printf("#");
            else
                printf(" ");
        }
    }
}
//������ ��������

void RemoveFillUpLine()
{
    int line, x, y;
    for (y = GBOARD_HEIGHT - 1; y > 0; y--)
    {
        for (x = 1; x < GBOARD_WIDTH + 1; x++)
        {
            if (gameBoardInfo[y][x] != 1)
                break;
        }
        if (x == (GBOARD_WIDTH + 1))
        {
            for (line = 0; y - line > 0; line++)
            {
                memcpy(&gameBoardInfo[y - line][1],
                       &gameBoardInfo[(y - line) - 1][1], GBOARD_WIDTH * sizeof(int));
            }
            y++;
            score += 10;
        }
    }
    RedrawBlocks();
    SetCurrentCursorPos(GBOARD_ORIGIN_X + (GBOARD_WIDTH + 1) * 2, GBOARD_ORIGIN_Y + GBOARD_HEIGHT);
    printf("J");
}
//�� �� ä������ �����

void RemoveLineBlock()
{
    int line, x, y;
    for (y = GBOARD_HEIGHT - 1; y > 0; y--)
    {
        for (line = 0; y - line > 0; line++)
        {
            memcpy(&gameBoardInfo[y - line][1],
                   &gameBoardInfo[(y - line) - 1][1], GBOARD_WIDTH * sizeof(int));
        }
        y++;
    }
    score += 10;
    RedrawBlocks();
    SetCurrentCursorPos(GBOARD_ORIGIN_X + (GBOARD_WIDTH + 1) * 2, GBOARD_ORIGIN_Y + GBOARD_HEIGHT);
    printf("J");
}
//block���� �� �����(�� �� ���� ��ä������ ����)

void ScoreBoard()
{
    level = score / 20 + 1;
    SetCurrentCursorPos(GBOARD_ORIGIN_X + 25, GBOARD_ORIGIN_Y + 12);
    printf("Level : ");
    printf("%d", level);
    SetCurrentCursorPos(GBOARD_ORIGIN_X + 25, GBOARD_ORIGIN_Y + 13);
    printf("Score : ");
    printf("%d", score);
    SetCurrentCursorPos(GBOARD_ORIGIN_X + 25, GBOARD_ORIGIN_Y + 14);
    printf("Speed :");
    printf("%d", score_speed);
}
//������ Ʋ(����, ����, ���ǵ� ���)

void lineup()
{
    srand((unsigned int)time(NULL));
    int tt = 0;
    int vacant = 0;
    for (int c = 0; c < GBOARD_HEIGHT; c++)
    {
        memcpy(&gameBoardInfo[c - 1][1], &gameBoardInfo[c][1], GBOARD_WIDTH * sizeof(int));
        RedrawBlocks();
    }
    for (int x = 1; x < GBOARD_WIDTH; x++)
    {
        tt = rand() % 100;
        if (tt == 0)
        {
            gameBoardInfo[GBOARD_HEIGHT - 1][x] = 0;
            RedrawBlocks();
        }
        else
        {
            gameBoardInfo[GBOARD_HEIGHT - 1][x] = 1;
            RedrawBlocks();
        }
    }
    vacant = rand() % GBOARD_WIDTH;
    vacant += 1;
    gameBoardInfo[GBOARD_HEIGHT - 1][vacant] = 0;
    RedrawBlocks();
}
//�ؿ��� �� ����

void Control_level()
{
    switch (level)
    {
    case 2:
    {
        score_speed = 20;
        speed = 10;
        up = 1;
        break;
    }
    case 3:
    {
        score_speed = 30;
        speed = 8;
        break;
    }
    case 4:
    {
        score_speed = 40;
        speed = 5;
        break;
    }
    case 5:
    {
        score_speed = 50;
        speed = 3;
        break;
    }
    }
}
//����, ���ǵ� ����

int IsGameOver()
{
    if (!DetectCollision(curPos.X, curPos.Y, blockModel[block_id]))
        return 1;
    return 0;
}
//���ӿ��� ��

void Show_next_block(int shape)
{
    SetCurrentCursorPos(GBOARD_ORIGIN_X + 25, GBOARD_ORIGIN_Y + 4);
    ShowBlock(blockModel[shape]);
}
//���� ���� �����ֱ�

void Delete_next_block(char blockInfo[4][4])
{
    int x, y;
    SetCurrentCursorPos(GBOARD_ORIGIN_X + 25, GBOARD_ORIGIN_Y + 4);
    for (y = 0; y < 4; y++)
    {
        for (x = 0; x < 4; x++)
        {
            SetCurrentCursorPos(GBOARD_ORIGIN_X + 25 + (x * 2), GBOARD_ORIGIN_Y + 4 + y);
            if (blockInfo[y][x] == 1)
                printf(" ");
        }
    }
}
