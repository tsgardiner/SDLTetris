

#define B_SIZE 16
#define BOARD_HEIGHT 10
#define BOARD_WIDTH 10

class GameBoard
{
public:
	GameBoard();
	~GameBoard();

	void InitBoard();

private:
	enum 
	{
		positionFree, positionFilled
	};
	int board[BOARD_WIDTH][BOARD_HEIGHT];

	

	
};

