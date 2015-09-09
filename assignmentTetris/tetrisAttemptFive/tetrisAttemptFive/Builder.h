#ifndef _BUILDER_
#define _BUILDER_

#include <SDL.h>
#include <iostream>
#include <stdio.h>

using namespace std;

#define testSCREEN_WIDTH 300
#define testSCREEN_HEIGHT 600

class Builder
{
public:
	Builder();
	~Builder();

	void DrawRect(SDL_Point *renderPosition);
	void DrawRectBoard(SDL_Point *renderPosition);
	void ClearRect(SDL_Point *clearPosition);
	const int getScreenHeight();
	const int getSreenWidth();
	
	void CloseAll();	
	void ClearScreen(); 

	int Pollkey();
	int Getkey();
	int IsKeyDown(int pKey);

private:
	const int SCREEN_WIDTH = 300;
	const int SCREEN_HEIGHT = 600;
	const int blockSize = 20;

	SDL_Window* window;
	SDL_Renderer* renderer;
	
	
	SDL_Point shapePosition;

	bool init();

};
#endif
