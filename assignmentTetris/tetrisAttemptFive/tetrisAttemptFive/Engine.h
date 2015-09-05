#include "GameBoard.h"
#include "Block.h"
#include "Shapes.h"
#include "Builder.h"


class Engine
{
public:


	Engine(GameBoard *gameBoard, Shapes *shapes, Builder *builder, int screenHeight);
	~Engine();

	int currentPositionX, currentPositionY, shapeType;
	void startEngine();
	

private:

	int timer = SDL_GetTicks();
	int screenHeight;
	GameBoard *gameBoard;
	Shapes *shapes;
	Builder *builder;
	SDL_Renderer* renderer;
	//SDL_Renderer* renderer = builder->getRenderer();

	//Block testing stuff
	Block *block;
	

	
	void DrawShape(int positionX, int positionY, int shapeType);
	void DrawBoard();
	void Run();

};

