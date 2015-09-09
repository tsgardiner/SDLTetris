#ifndef _ENGINE_
#define _ENGINE_


#include "GameBoard.h"
#include "Block.h"
#include "Shapes.h"
#include "Builder.h"
#include <time.h>

#define WAIT_TIME 600

class Engine
{
public:
	Engine(GameBoard *gameBoard, Shapes *shapes, Builder *builder, int screenHeight);
	
	int currentPositionX, currentPositionY, shapeType;
	void Run();
	int getCurrentShapeType();
	bool checkCollision(int pX, int pY, int shapeType);
	void makeNextShape();

private:
	int timer = SDL_GetTicks();
	int screenHeight;
	int random(int , int);
	GameBoard *gameBoard;
	Shapes *shapes;
	Builder *builder;
	SDL_Renderer* renderer;
	void DrawShape(int positionX, int positionY, int shapeType);
	void DrawBoard();
	void startEngine();
	
};
#endif // !_ENGINE_
