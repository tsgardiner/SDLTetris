#include "GameBoard.h"


GameBoard::GameBoard(Shapes *shapes, int screenHeight)
{

	this->shapes = shapes;
	this->screenHeight = screenHeight;


}


void GameBoard::makeBoard()
{
	for (int i = 0; i < BOARD_WIDTH; i++)
	{
		for (int j = 0; j < BOARD_HEIGHT; j++)
		{
			board[i][j] = positionFree;
		}
	}
}


int GameBoard::getPositionX(int positonX)
{
	return	((BOARD_POSITION - (BLOCK_SIZE * (BOARD_WIDTH / 2))) + (positonX * BLOCK_SIZE));
}

int GameBoard::getPositionY(int positonY)
{
	return ((screenHeight - (BLOCK_SIZE * BOARD_HEIGHT)) + (positonY * BLOCK_SIZE));
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





GameBoard::~GameBoard()
{
}
