#include "Block.h"

static SDL_Surface *mScreen;

Block::Block()
{

}

Block::Block(SDL_Renderer *renderBlock, SDL_Point *startPosition, int *size)
{
	this->renderBlock = renderBlock;
	this->startPosition = startPosition;
	this->size = *size;
	
}

void Block::Draw()
 {
	 SDL_SetRenderDrawColor(renderBlock, 0, 0, 0, 255);
	 //SDL_RenderClear(renderBlock); //Flashing on and off
	 SDL_Rect blockOutline = { startPosition->x, startPosition->y, size, size };
	 //SDL_SetRenderDrawColor(renderBlock, 255, 255, 0, 255);
	 SDL_SetRenderDrawColor(renderBlock, 128, 0, 0, 255);
	 SDL_RenderFillRect(renderBlock, &blockOutline);
	 SDL_RenderPresent(renderBlock);
 }


void Block::DrawRect(SDL_Point firstPosition, SDL_Point secondPosition)
{
	
	//{ mScreen, firstPosition.x, firstPosition.y, secondPosition.x, secondPosition.y, REDBLOCK);
}

/* Method from main
void block()
{

	SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 255);
	//SDL_RenderClear(gRenderer); //Flashing on and off

	SDL_Rect block = { startPosition.x, startPosition.y, BLOCK_SIZE, BLOCK_SIZE };
	//SDL_Rect block = { 150, 50, 20, 20 };
	SDL_SetRenderDrawColor(gRenderer, 128, 0, 0, 255);
	SDL_RenderFillRect(gRenderer, &block);

	SDL_RenderPresent(gRenderer);
	SDL_RenderCopy(gRenderer, testingTexture, NULL, &block);
}*/




Block::~Block()
{
}
