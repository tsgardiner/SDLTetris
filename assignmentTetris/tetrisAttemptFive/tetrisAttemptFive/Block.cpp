#include "Block.h"

static SDL_Surface *mScreen;

Block::Block()
{

}

Block::Block(SDL_Renderer *renderBlock, SDL_Point startPosition, int *size)
{
	this->renderBlock = renderBlock;
	this->startPosition = startPosition;
	this->size = *size;
	
}

void Block::Draw()
 {
	 SDL_SetRenderDrawColor(renderBlock, 0, 0, 0, 255);
	 SDL_RenderClear(renderBlock); //Flashing on and off
	 blockOutline = {startPosition.x, startPosition.y, size, size };
	 //SDL_SetRenderDrawColor(renderBlock, 255, 255, 0, 255);
	 SDL_SetRenderDrawColor(renderBlock, 128, 0, 0, 255);
	 SDL_RenderFillRect(renderBlock, &blockOutline);
	 SDL_RenderPresent(renderBlock);
 }


void Block::DrawRect(SDL_Point renderPosition)
{
	blockTesting = { renderPosition.x, renderPosition.y, B_SIZE, B_SIZE };
	SDL_SetRenderDrawColor(renderBlock, 0, 0, 204, 255);
	SDL_RenderFillRect(renderBlock, &blockTesting);
	SDL_RenderPresent(renderBlock);
	//block = { renderPosition.x, renderPosition.y, size, size };
	//{ mScreen, firstPosition.x, firstPosition.y, secondPosition.x, secondPosition.y, REDBLOCK);
}


Block::~Block()
{
}
