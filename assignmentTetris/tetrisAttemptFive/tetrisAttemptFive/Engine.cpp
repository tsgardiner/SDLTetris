#include "Engine.h"
#include <iostream>




Engine::Engine(GameBoard *gameBoard, Shapes *shapes, Builder *builder, int screenHeight)
{
	this->gameBoard = gameBoard;
	this->shapes = shapes;
	this->builder = builder;
	this->screenHeight = screenHeight;
	
	startEngine();
}


void Engine::Run()
{
	
	DrawBoard();
	DrawShape(currentPositionX, currentPositionY, shapeType);
	
}

void Engine::startEngine()
{
	//Make shape type random

	shapeType = 1; //Current only one shape to choose from at position 0 in the array.
	
	//Get starting position of shape
	currentPositionX = shapes->GetStartPositionX(shapeType); //X=3
	currentPositionY = shapes->GetStartPositionY(shapeType); //Y=3
	printf("X%d\n\n\n\nY%d\n\n\n", currentPositionX, currentPositionY);
}


void Engine::DrawBoard()
{
	//These basically do nothing whatever the number is.
	int boardSizeX1 =(BOARD_POSITION - (BLOCK_SIZE * (BOARD_WIDTH / 2)));
	//int boardSizeX2 = BOARD_POSITION + (BLOCK_SIZE * (BOARD_WIDTH / 2));
	int boardSizeY = (screenHeight - (BLOCK_SIZE * BOARD_HEIGHT));

	//boardSizeX1 += 1;
	for (int i = 0; i < BOARD_HEIGHT; i++)
	{
		for (int j = 0; j  < BOARD_WIDTH; j++)
		{
			// Not working correctly as of 10:50 - 06/09
			if (!gameBoard->checkCellFree(i, j))//Set to zero to test where board draws
			{
				SDL_Point drawPoint = { (j * BLOCK_SIZE), (i * BLOCK_SIZE) };
				//SDL_Point drawPoint{ 100, 100 };	
				builder->DrawRectBoard(&drawPoint);//Board draws green blocks
				
			}
		}
		
	}

}


void Engine::DrawShape(int positionX, int positionY, int shapeType)
{
	
	int shapePositionX = currentPositionX; //gameBoard->getPositionX(positionX);
	int shapePositionY = currentPositionY;//gameBoard->getPositionY(positionY);
	//printf("X%d\n\n\n\nY%d\n\n\n", shapePositionX, shapePositionY);
	for (int i = 0; i < SHAPE_DIMENTIONS ; i++)
	{
		for (int j = 0; j < SHAPE_DIMENTIONS ; j++)
		{
			if (shapes->GetShape (shapeType, j, i) != 0)
			{
				
				SDL_Point drawPoint = { ((shapePositionX + i) * BLOCK_SIZE), (shapePositionY + j) * BLOCK_SIZE };
				//SDL_Point drawPoint{ 20, 20 };
				builder->DrawRect(&drawPoint);//Shapes draw blue blocks
				
				
			}
		}
	}
}

/*
bool Engine::Collision()
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (currentPositionX + j >+ testSCREEN_WIDTH && shapes->GetShape(shapeType, i, j) > 0 )
			{
				return false;
			}
			else if (currentPositionX + j < 0 && shapes->GetShape(shapeType, i, j) > 0)
			{
				return false;
			}
			else if (currentPositionY + i >= testSCREEN_HEIGHT && shapes->GetShape(shapeType, i, j) > 0)
			{
				return false;
			}
			
			
		}
	}
	return true;
}*/


bool Engine::CollisionLeft()
{	
		if (currentPositionX < 1)
		{
			return false;				
		}	
	return true;
}

bool Engine::CollisionRight()
{
		if (currentPositionX + SHAPE_DIMENTIONS + 1 > BOARD_WIDTH) 
		{
			return false;
		}
	
	return true;
}

bool Engine::CollisionBottom()
{
	if (currentPositionY + SHAPE_DIMENTIONS > BOARD_HEIGHT +1) //Plus one because of current shape positoin in array
	{
		return false;
	}
	return true;
}

Engine::~Engine()
{
}




/* Copy of semi working code before I change it.
bool Engine::Collision()
{
for (int i1 = currentPositionX , i2 = 0; i1 < SHAPE_DIMENTIONS; i1++, i2++)
{
for (int j1 = currentPositionY, j2 = 0; j1 < currentPositionY + SHAPE_DIMENTIONS; j1++, j2++)
{
if ((i1 < 0) || (i1 > BOARD_WIDTH + SHAPE_DIMENTIONS ) || (j1 > BOARD_HEIGHT + 5))
{
if (shapes->GetShape (shapeType, j2, i2) !=0)
{
return 0;
}
if (j1 >= 0)
{
if ((shapes->GetShape(shapeType, j2, i2) != 0) && (!gameBoard->checkCellFree(i1, j1)))
{
return false;
}
}
}
}
}

return true;
}*/