

#include <SDL.h>
#include <iostream>


using namespace std;

class Builder
{
public:
	Builder();
	~Builder();

	void DrawRect(SDL_Point *renderPosition);
	const int getScreenHeight();
	const int getSreenWidth();
	
	void closeAll();
	void blockTesting();
	void flipScreen();
	//SDL_Renderer *getRenderer();

private:
	const int SCREEN_WIDTH = 900;
	const int SCREEN_HEIGHT = 900;
	const int blockSize = 20;

	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Surface* screen;
	

	bool init();

};

