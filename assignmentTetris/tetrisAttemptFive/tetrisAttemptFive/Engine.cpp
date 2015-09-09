#include "Engine.h"
#include <iostream>

//This is the game engine it sets up the game board and the shapse, and  also checks collisions.

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

int Engine::random(int min, int max)
{
	return rand() % (max - min + 1) + min;
}

void Engine::startEngine()
{
	srand((unsigned int)time(NULL));

	shapeType = random(0, 6); 
	//printf("First random: %d\n\n\n", shapeType);
	
	//Get starting position of shape
	currentPositionX = shapes->GetStartPositionX(shapeType); //X=3
	currentPositionY = shapes->GetStartPositionY(shapeType); //Y=3
	//printf("\nX: %d\n\nY: %d\n\n", currentPositionX, currentPositionY);
}

void Engine::makeNextShape()
{
	//printf("First random: %d\n\n\n", shapeType);
	shapeType = random(0, 6);
	currentPositionX = shapes->GetStartPositionX(shapeType); //X=3
	currentPositionY = shapes->GetStartPositionY(shapeType); //Y=3
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
				SDL_Point drawPoint = { (j * BLOCK_SIZE), (i * BLOCK_SIZE) };//Too many brackets = bad.
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


//Stolen from SDL example. Took a while to convert to mine as they implimented this in gameboard.
bool Engine::checkCollision(int positionX, int positionY, int shapeType)
{
	for (int i1 = positionX, i2 = 0; i1 < positionX + SHAPE_DIMENTIONS; i1++, i2++)
	{
		for (int j1 = positionY, j2 = 0; j1 < positionY + SHAPE_DIMENTIONS; j1++, j2++)
		{
			if ((i1 < 0) || (i1  > BOARD_WIDTH - 1) || (j1 > BOARD_HEIGHT - 1))
			{
				if (shapes->GetShape(shapeType, j2, i2) != 0)
				{
					return false;
				}
			}
			else if (j1 >= 0)
			{
				//printf("Get shape is:\n%d\n\n\n", shapes->GetShape(shapeType, j2, i2)); 
				//printf("Check cell is:\n%d\n\n\n", gameBoard->checkCellFree(i1, j1)); //This was original layout.
				//Needed to swap i1 and j1 in checkCell method to make it work with my board.
				if ((shapes->GetShape(shapeType, j2, i2) != 0) &&  (!gameBoard->checkCellFree(j1, i1)))
				{
					return false;
				}
			}
		
	}
}

return true;
}