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
		printf ("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf ("Warning: Linear texture filtering not enabled!");
		}
		//Create window
		window = SDL_CreateWindow("SDL Tetris Attempt", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			printf ("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Create renderer for window
			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
			if (renderer == NULL)
			{
				printf ("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				
				//Initialize renderer color
				SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0xFF);
			}
		}
	}

	return success;
}

void Builder::ClearScreen()
{
	SDL_Rect gridPointRender = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderFillRect(renderer, &gridPointRender);
	SDL_RenderPresent(renderer);
}


void Builder::DrawRect(SDL_Point *renderPosition)
{
	shapePosition = { (renderPosition->x), (renderPosition->y) };
	SDL_Rect gridPointRender = { renderPosition->x, renderPosition->y, blockSize, blockSize };
	SDL_SetRenderDrawColor(renderer, 0, 0, 204, 255);
	SDL_RenderFillRect(renderer, &gridPointRender);
	SDL_RenderPresent(renderer);
}

void Builder::DrawRectBoard(SDL_Point *renderPosition)
{

	SDL_Rect gridPointRender = { renderPosition->x, renderPosition->y, blockSize, blockSize };
	SDL_SetRenderDrawColor(renderer, 0, 102, 0, 255);
	SDL_RenderFillRect(renderer, &gridPointRender);
	SDL_RenderPresent(renderer);

}


/*
======================================
Keyboard Input //Stolen from Tetris example
======================================
*/
int Builder::Pollkey()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type) {
		case SDL_KEYDOWN:
			return event.key.keysym.sym;
		case SDL_QUIT:
			exit(3);
		}
	}
	return -1;
}
/*
======================================
Keyboard Input //Stolen from Tetris example
======================================
*/
int Builder::Getkey()
{
	SDL_Event event;
	while (true)
	{
		SDL_WaitEvent(&event);
		if (event.type == SDL_KEYDOWN)
			break;
		if (event.type == SDL_QUIT)
			exit(3);
	};
	return event.key.keysym.sym;
}

/*
======================================
Keyboard Input //Stolen from Tetris example
======================================
*/
int Builder::IsKeyDown(int pKey)
{
	const Uint8* mKeytable;
	int mNumkeys;
	SDL_PumpEvents();
	mKeytable = SDL_GetKeyboardState(&mNumkeys);
	return mKeytable[pKey];
}

const int Builder::getScreenHeight()
{
	return SCREEN_HEIGHT;
}

const int Builder::getSreenWidth()
{
	return SCREEN_WIDTH;
}


void Builder::CloseAll()
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
