/*
	Tetris Assignment 
	Tim Gardiner
	10/09/2015

	For this assignment I got most of my ideas from the LazyFoo SDL tutorials
	these where backed up from the working example of C++/SDL tetris found online.
	I tried to put comments on the methods I stole directly from this example,
	but may have missed some. Choose not to add hardcoded roations of shapes into
	the shape array as I wanted to try figure out the sorting rotation, ended up 
	having to have no rotation.

	I put some bookmarks on key methods to make navigation a bit easier.

	Current bugs:
	The Delete lines method doesn't work correctly. All the numbers seem to be right
	it just doesn't actually delete the line.

	When the board builds up to about halfway if the down key is held the draw rate,
	and refresh rate get out of sync and it cuts some shapes in half. It does look cool though.

	Some inline comments where for testing purposes. I have left most of them in.

	Forgot about adding a game over function at all.

	//My commits to github
	https://github.com/tsgardiner/SDLTetris 
*/


#include <iostream>
#include "Engine.h"

using namespace std;

Builder builder;
int screenHeight = builder.getScreenHeight();
Shapes shapes;
GameBoard gameBoard (&shapes, screenHeight);
Engine engine(&gameBoard, &shapes, &builder, screenHeight);

unsigned long mTime1 = SDL_GetTicks();

int main(int argc, char* args[])
{
		
	//Key input code stolen straight from example.
	//Needs tweaking to make shape move but key selection works.
	while (!builder.IsKeyDown(SDLK_ESCAPE))
	{
				
				engine.Run();
				int mKey = builder.Pollkey();

				switch (mKey)
				{
				case (SDLK_RIGHT) :
				{
					if (engine.checkCollision(engine.currentPositionX +1, engine.currentPositionY, engine.shapeType))
					{
						engine.currentPositionX++;
						builder.clearScreen();
						//printf("Right Key\n\n");
						//printf("\n%d\n\n\n", engine.currentPositionX);
					}
					break;
				}

				case (SDLK_LEFT) :
				{
					if (engine.checkCollision(engine.currentPositionX -1, engine.currentPositionY, engine.shapeType))
					{
						engine.currentPositionX--;
						builder.clearScreen();
						//printf("Left Key\n");
						//printf("\n%d\n\n\n", engine.currentPositionX);
					}					
					break;
				}
				
				//Cool bug if down key is held.
				case (SDLK_DOWN) :
				{
					if (engine.checkCollision(engine.currentPositionX, engine.currentPositionY +1, engine.shapeType))
					{
						engine.currentPositionY++;
						builder.clearScreen();
						
					}
					break;
				}
				}

				// ----- Vertical movement -----

				unsigned long mTime2 = SDL_GetTicks();

				if ((mTime2 - mTime1) > WAIT_TIME)
				{
					//printf("Current Positoin of Y:\n%d\n\n\n", engine.currentPositionY);
					if (engine.checkCollision(engine.currentPositionX , engine.currentPositionY +1, engine.shapeType))
					{
						engine.currentPositionY++;
						builder.clearScreen();
					}
					else
					{
						gameBoard.storeShape(engine.currentPositionX, engine.currentPositionY, engine.shapeType);

						gameBoard.deleteLines();

						engine.makeNextShape();
					}
					
					mTime1 = SDL_GetTicks();
				}
			}
		builder.CloseAll();

	return 0;
}