#include "Builder.h"



Builder::Builder()
{
	init();
}



bool Builder::init()
{
	bool success = true;

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) < 0)
	{
		cout << ("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			cout << ("Warning: Linear texture filtering not enabled!");
		}
		//Create window
		window = SDL_CreateWindow("SDL Tetris Attempt", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			cout << ("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Create renderer for window
			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (renderer == NULL)
			{
				cout << ("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{

				screen = SDL_GetWindowSurface(window);
				//Initialize renderer color
				SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
			}
		}
	}

	return success;
}


void Builder::DrawRect(SDL_Point *renderPosition)
{
	SDL_Rect gridPointRender = { renderPosition->x, renderPosition->y, blockSize, blockSize };
	SDL_SetRenderDrawColor(renderer, 0, 0, 204, 255);
	SDL_RenderFillRect(renderer, &gridPointRender);
	SDL_RenderPresent(renderer);

}

void Builder::blockTesting()
{
	/*Block testing stuff

	SDL_Point newPoint = { 150, 150 };
	int size1 = 50;
	Block *newBlock = new Block(renderer, newPoint, &size1);

	SDL_Point newPoint254 = { 280, 580 };
	int size123 = 20;
	Block *newBlock1 = new Block(renderer, newPoint254, &size123);

	SDL_Point newPoint2 = { 150, 580 };
	int size12 = 20;
	Block *newBlock2 = new Block(renderer, newPoint2, &size12);

	newBlock1->Draw();
	newBlock2->Draw();
	newBlock->Draw();
	*/
}

/*
SDL_Renderer *Builder::getRenderer()
{
	return renderer;
}*/

const int Builder::getScreenHeight()
{
	return SCREEN_HEIGHT;
}

const int Builder::getSreenWidth()
{
	return SCREEN_WIDTH;
}

void Builder::flipScreen()
{
	SDL_RendererFlip(screen);
}

void Builder::closeAll()
{
	//Destroy window	
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	window = NULL;
	renderer = NULL;

	SDL_Quit();
}

Builder::~Builder()
{
}
