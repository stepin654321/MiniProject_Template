/** 
* @file calculator_operations.h
* Calculator application with 4 mathematical operations
*
*/
#ifndef __GAMEBOARD_OPERATIONS_H__
#define __GAMEBOARD_OPERATIONS_H__


//courser

/**
 * sets the position of courser at latest shape
 * @param[in] x
 * @param[in] y
*/
void SetCurrentCursorPos(int x, int y);


COORD GetCurrentCursorPos(void);
void RemoveCursor(void);
void ShowCursorCustom(void);

//gameboard block
void ShowBlock(char blockInfo[4][4]);
void DeleteBlock(char blockInfo[4][4]);

//block
int DetectCollision(int posX, int posY, char blockModel[4][4]);
int ShiftRight();
int ShiftLeft();
void ShiftUp();
int BlockDown();
void SpaceDown();
void RotateBlock();
void ProcessKeyInput();

//gameboard 
void DrawGameBoard();
void AddBlockToBoard(int shape);
void RedrawBlocks();
void RemoveFillUpLine();
void RemoveLineBlock();

//hud and settings
void ScoreBoard();
void lineup();
void Control_level();
int IsGameOver();
void Show_next_block(int shape);
void Delete_next_block(char blockInfo[4][4]);



#endif  /* #define __CALCULATOR_OPERATIONS_H__ */