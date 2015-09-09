#include "Shapes.h"
#include "Builder.h"

#define BLOCK_SIZE 23
#define BOARD_HEIGHT 26
#define BOARD_WIDTH 13
#define SHAPE_DIMENTIONS 4
#define BOARD_POSITION 142 //For some reason this is roughly the center of the board for drawing a shape.


class GameBoard
{
public:
	GameBoard(Shapes *shapes, int screenHeight);
	~GameBoard();

	int getPositionX(int positionX);
	int getPositionY(int positionY);
	bool checkCellFree(int positionX, int positionY);

	bool checkMovment(int positionX, int positionY);
	bool movementPossible(int pX, int pY, int shapeType);

	void deleteLines();
	bool gameOver();
	
	void storeShape(int positionX, int positionY, int shapeType);

private:
	enum {positionFree, positionFilled}; 
	int board[BOARD_HEIGHT][BOARD_WIDTH];
	int screenHeight;
	Shapes *shapes;
	Builder *builder;
	void makeBoard();


	void deleteLine(int positionY);
	
	
};

