#include "Engine.h"




Engine::Engine(GameBoard *gameBoard, Shapes *shapes, Builder *builder, int screenHeight)
{
	this->gameBoard = gameBoard;
	this->shapes = shapes;
	this->builder = builder;
	this->screenHeight = screenHeight;
	
	Run();
}


void Engine::Run()
{
	DrawBoard();
	//DrawShape(currentPositionX, currentPositionY, shapeType);
}

void Engine::startEngine()
{
	currentPositionX =  shapes->GetStartPositionX(shapeType);
	currentPositionY = shapes->GetStartPositionY(shapeType);
}


void Engine::DrawBoard()
{
	int boardSizeX1 = BOARD_POSITION - (BLOCK_SIZE * (BOARD_WIDTH / 2)) - 1;
	//int boardSizeX2 = BOARD_POSITION + (BLOCK_SIZE * (BOARD_WIDTH / 2));
	int boardSizeY = screenHeight - (BLOCK_SIZE * BOARD_HEIGHT);

	//boardSizeX1 += 1;
	for (int i = 0; i < BOARD_WIDTH; i++)
	{
		for (int j = 0; j  < BOARD_HEIGHT; j ++)
		{
			if (!gameBoard->checkCellFree(i, j))
			{
				SDL_Point drawPoint = { (boardSizeX1 + i * BLOCK_SIZE, boardSizeY + j * BLOCK_SIZE) };
				//SDL_Point drawPoint{ 100, 100 };	
				builder->DrawRect(&drawPoint);
				
			}
		}
	}

}


void Engine::DrawShape(int positionX, int positionY, int shapeType)
{
	int boardPositionX = gameBoard->getPositionX(positionX);
	int boardPositionY = gameBoard->getPositionY(positionY);

	for (int i = 0; i < SHAPE_SIZE; i++)
	{
		for (int j = 0; j < SHAPE_SIZE; j++)
		{
			if (shapes->GetShape (shapeType, j, i) !=0)
			{
				
				SDL_Point drawPoint = { (boardPositionX + i * BLOCK_SIZE, boardPositionY + j * BLOCK_SIZE) };
				//SDL_Point drawPoint{ 20, 20 };
				builder->DrawRect(&drawPoint);
			}
		}
	}
}





Engine::~Engine()
{
}
