#include "GameBoard.h"


GameBoard::GameBoard()
{
}


void GameBoard::InitBoard()
{
	for (int i = 0; i < BOARD_WIDTH; i++)
	{
		for (int j = 0; j < BOARD_HEIGHT; j++)
		{
			board[i][j] = positionFree;
		}
	}
}

GameBoard::~GameBoard()
{
}
