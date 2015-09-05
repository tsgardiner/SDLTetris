/*X9IXMUPUUC4C*/
#include <iostream>
#include "Engine.h"

using namespace std;

Builder builder;
int screenHeight = builder.getScreenHeight();
Shapes shapes;
GameBoard gameBoard (&shapes, screenHeight);
Engine engine(&gameBoard, &shapes, &builder, screenHeight);

int main(int argc, char* args[])
{
		bool quit = false;
		SDL_Event e;

			while (!quit)
			{
				while (SDL_PollEvent(&e) != 0)
				{
					if (e.type == SDL_QUIT)
					{
						quit = true;
					}
				}

				engine.startEngine();
				

				//engine.Run();
				//SDL_Point testPoint = { 10, 10 };
				//builder.DrawRect(testPoint);

			}
		

		//close();
		builder.closeAll();

	return 0;
}