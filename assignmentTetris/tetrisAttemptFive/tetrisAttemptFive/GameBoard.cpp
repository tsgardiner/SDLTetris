#include "GameBoard.h"


GameBoard::GameBoard(Shapes *shapes, int screenHeight)
{

	this->shapes = shapes;
	this->screenHeight = screenHeight;

	makeBoard();
}

//Seems to work..finally.
void GameBoard::makeBoard()
{
	for (int i = 0; i < BOARD_HEIGHT; i++)
	{
		for (int j = 0; j < BOARD_WIDTH; j++)
		{
			board[i][j] = positionFree;
		}
	}
}

//The below issue was fixed, it was a draw point issue.
//They work if I hard code them so have done so when shape is drawn.
int GameBoard::getPositionX(int positonX)
{
	//return 0;
	return (BOARD_POSITION - (BLOCK_SIZE * (BOARD_WIDTH / 2))) + (positonX * BLOCK_SIZE) -5;
}

int GameBoard::getPositionY(int positonY)
{
	//return 0;
	return (screenHeight - (BLOCK_SIZE * BOARD_HEIGHT)) + (positonY * BLOCK_SIZE);
}

bool GameBoard::checkCellFree(int positionX, int positionY)
{
	if (board[positionX][positionY] == positionFree)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void GameBoard::deleteLine(int positionY)
{
	for (int i = positionY; i > 0; i--)
	{
		for (int j = 0; j < BOARD_WIDTH; i++)
		{
			board[j][i] = board[j][i - 1];
		}
	}
}

void GameBoard::storeShape(int positionX, int positionY, int shapeType)
{
	for (int i1 = positionX, i2 =0; i1 < positionX + SHAPE_DIMENTIONS; i1++, i2++)
	{
		for (int j1 = positionY, j2 = 0; j1 < positionY + SHAPE_DIMENTIONS; j1++, j2++)
		{
			if (shapes->GetShape(shapeType, j2, i2) !=0)
			{
				board[i1][j1] = positionFilled;
			}
		}
	}
}

GameBoard::~GameBoard()
{
}
