#ifndef _Block_
#define _Block_

#include <SDL.h>

#define B_SIZE 20

class Block
{
public:
	Block();
	~Block();


	Block(SDL_Renderer *renderBlock, SDL_Point startPosition, int *size);

	void Draw();

	void DrawRect(SDL_Point renderPosition);

private:
	
	SDL_Rect blockTesting, blockOutline;
	int Block_Size, positionX, positionY, size;
	SDL_Point startPosition, TargerRenderPosition;
	SDL_Renderer* renderBlock;
	
};
#endif //_Block_
