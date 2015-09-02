#include <SDL.h>

class Block
{
public:
	Block();
	~Block();


	Block(SDL_Renderer *renderBlock, SDL_Point *startPosition, int *size);

	void Draw();

	void DrawRect(SDL_Point firstPosition, SDL_Point secondPosition);

private:
	//SDL_Color REDBLOCK = { 128, 0, 0, 255 };
	SDL_Rect* block, blockOutline;
	int Block_Size, positionX, positionY, size;
	SDL_Point *startPosition;
	SDL_Renderer *renderBlock;
	
};

