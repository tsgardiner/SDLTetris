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
	~Engine();
	int currentPositionX, currentPositionY, shapeType;
	void Run();
	int getCurrentShapeType();
	bool CollisionLeft();
	bool CollisionRight();
	bool CollisionBottom();
private:
	int timer = SDL_GetTicks();
	int screenHeight;
	GameBoard *gameBoard;
	Shapes *shapes;
	Builder *builder;
	SDL_Renderer* renderer;
	void DrawShape(int positionX, int positionY, int shapeType);
	void DrawBoard();
	void startEngine();
};

