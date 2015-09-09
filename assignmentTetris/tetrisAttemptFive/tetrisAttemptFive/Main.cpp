/*X9IXMUPUUC4C*/
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
		/*bool quit = false;
		SDL_Event e;

			while (!quit)
			{
				while (SDL_PollEvent(&e) != 0)
				{
					if (e.type == SDL_QUIT)
					{
						quit = true;
					}
				}*/
		
	//Key input code straight from example.
	//Needs tweaking to make shape move but key selection works.
	while (!builder.IsKeyDown(SDLK_ESCAPE))
	{
				
				engine.Run();
				int mKey = builder.Pollkey();

				switch (mKey)
				{
				case (SDLK_RIGHT) :
				{
					if (engine.CollisionRight())
					{
						engine.currentPositionX++;
						builder.ClearScreen();
						printf("Right Key\n\n");
						printf("\n%d\n\n\n", engine.currentPositionX);
					}
					break;
				}

				case (SDLK_LEFT) :
				{
					if (engine.CollisionLeft())
					{
						engine.currentPositionX--;
						builder.ClearScreen();
						printf("Left Key\n");
						printf("\n%d\n\n\n", engine.currentPositionX);
					}					
					break;
				}

				case (SDLK_DOWN) :
				{
					if (engine.CollisionBottom())
					{
						engine.currentPositionY++;
						builder.ClearScreen();

						
					}
					break;
				}

			/*	case (SDLK_x) :
				{
					// Check collision from up to down
					while (mBoard.IsPossibleMovement(mGame.mPosX, mGame.mPosY, mGame.mPiece, mGame.mRotation)) { mGame.mPosY++; }

					mBoard.StorePiece(mGame.mPosX, mGame.mPosY - 1, mGame.mPiece, mGame.mRotation);

					mBoard.DeletePossibleLines();

					if (mBoard.IsGameOver())
					{
						mIO.Getkey();
						exit(0);
					}

					mGame.CreateNewPiece();

					break;
				}

				case (SDLK_z) :
				{
					if (mBoard.IsPossibleMovement(mGame.mPosX, mGame.mPosY, mGame.mPiece, (mGame.mRotation + 1) % 4))
						mGame.mRotation = (mGame.mRotation + 1) % 4;

					break;
				}*/
				}

				// ----- Vertical movement -----

				unsigned long mTime2 = SDL_GetTicks();

				if ((mTime2 - mTime1) > WAIT_TIME)
				{
					printf("Current Positoin of Y:\n%d\n\n\n", engine.currentPositionY);

					if (engine.CollisionBottom())
					{
						engine.currentPositionY++;
						builder.ClearScreen();
					}
					else
					{
						gameBoard.
					}
					
					/*
					if (mBoard.IsPossibleMovement(mGame.mPosX, mGame.mPosY + 1, mGame.mPiece, mGame.mRotation))
					{
						mGame.mPosY++;
					}
					else
					{
						mBoard.StorePiece(mGame.mPosX, mGame.mPosY, mGame.mPiece, mGame.mRotation);

						mBoard.DeletePossibleLines();

						if (mBoard.IsGameOver())
						{
							builder.Getkey();
							exit(0);
						}

						mGame.CreateNewPiece();
					}*/

					mTime1 = SDL_GetTicks();
				}
			}

			
		

		//close();
		builder.CloseAll();

	return 0;
}