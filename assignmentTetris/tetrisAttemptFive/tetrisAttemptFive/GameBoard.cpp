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


int GameBoard::getPositionX(int positonX)
{
	return (BOARD_POSITION - (BLOCK_SIZE * (BOARD_WIDTH / 2))) + (positonX * BLOCK_SIZE) -5;
}

int GameBoard::getPositionY(int positonY)
{
	return (screenHeight - (BLOCK_SIZE * BOARD_HEIGHT)) + (positonY * BLOCK_SIZE);
}

//Checks the state of positions on the game board.
bool GameBoard::checkCellFree(int positionX, int positionY)
{
	if (board[positionX][positionY] == positionFree)
	{
		return true;
	}
	return false;	
}


//Seems to function, but doesn't actually delete the lines.
void GameBoard::deleteLine(int positionY)
{
	//printf(" Position Y : %d\n\n", positionY);
	for (int i = positionY; i > 0; i--)
	{
		//printf(" Position i : \n%d\n\n", i);
		for (int j = 0; j < BOARD_WIDTH; j++) 
		{
			//printf("Made it finally  j:\n%d\n\n",j);
			//printf("Made it here too i:%d\n\n\n", i);
			board[j][i] = board[j][i - 1]; //Causes game crash!! i = 801???
		}
	}
}

//Public method for deleting lines.
//Works out which lines are full and tells the delete line method.
void GameBoard::deleteLines()
{
	for (int i = 0; i < BOARD_HEIGHT; i++)
	{
		int j = 0;
		//printf("Current value of j:\n%d\n\n\n", j);
		while (j < BOARD_WIDTH)
		{
			if (board[i][j] != positionFilled) break;	
			//printf("Got to here.\n\n\n");
				j++;
		}
			if (j == BOARD_WIDTH)
			{
				deleteLine(j);
			}
		
	}
}

//Stores into the game board that hit the bottom or other stored shapes.
void GameBoard::storeShape(int positionX, int positionY, int shapeType)
{
	for (int i1 = positionX, i2 =0; i1 < positionX + SHAPE_DIMENTIONS; i1++, i2++)
	{
		for (int j1 = positionY, j2 = 0; j1 < positionY + SHAPE_DIMENTIONS; j1++, j2++)
		{
			if (shapes->GetShape(shapeType, j2, i2) !=0)
			{
				board[j1][i1] = positionFilled;
			}
		}
	}
}


