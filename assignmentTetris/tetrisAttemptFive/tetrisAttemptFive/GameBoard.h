#include "Shapes.h"

#define BLOCK_SIZE 20
#define BOARD_HEIGHT 20
#define BOARD_WIDTH 10
#define SHAPE_SIZE 4
#define BOARD_POSITION 450



class GameBoard
{
public:
	GameBoard(Shapes *shapes, int screenHeight);
	~GameBoard();

	int getPositionX(int positionX);
	int getPositionY(int positionY);
	bool checkCellFree(int positionX, int positionY);

private:
	enum {positionFree = 1, positionFilled};
	int board[BOARD_WIDTH][BOARD_HEIGHT];
	int screenHeight;
	Shapes *shapes;

	void makeBoard();
	void deleteLine(int positionY);

	
};

