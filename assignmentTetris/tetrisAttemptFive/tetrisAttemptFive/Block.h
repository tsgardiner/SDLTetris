#include <SDL.h>


class Block
{
public:
	Block();
	~Block();


	Block(SDL_Renderer *renderBlock, SDL_Point *startPosition, int *size);

	void Draw();

private:
	SDL_Rect* block, blockOutline;
	int Block_Size, positionX, positionY, size;
	SDL_Point *startPosition;
	SDL_Renderer *renderBlock;
	
};

