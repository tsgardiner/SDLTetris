#include "Block.h"

Block::Block()
{

}



Block::Block(SDL_Renderer *renderBlock, SDL_Point *startPosition, int *size)
{
	this->renderBlock = renderBlock;
	this->startPosition = startPosition;
	this->size = *size;
	
}

/*
Doesn't seem to like the SDL_Point changing to positio.x /.y
 void Draw(SDL_Renderer *renderBlock, SDL_Point startPosition, int size)
{
	
	SDL_Rect blockOutline = { startPosition.x, startPosition.y, size, size};
	SDL_SetRenderDrawColor(renderBlock, 255, 255, 0, 255);
	SDL_RenderDrawRect(renderBlock, &blockOutline);
	SDL_RenderPresent(renderBlock);
}*/

void Block::Draw()
 {
	 SDL_Rect blockOutline = { startPosition->x, startPosition->y, size, size };
	 SDL_SetRenderDrawColor(renderBlock, 255, 255, 0, 255);
	 SDL_RenderDrawRect(renderBlock, &blockOutline);
	 SDL_RenderPresent(renderBlock);
 }

Block::~Block()
{
}
