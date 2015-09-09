#include "Shapes.h"


char shapes[2][4][4]
= 
{
		//First attempt
		{
			{ 0, 0, 0, 0 },
			{ 0, 0, 0, 0 },
			{ 0, 0, 0, 0 },
			{ 0, 0, 0, 0 }
		}, 
		{
			{ 0, 0, 0, 0 },
			{ 1, 1, 1, 1 },
			{ 0, 0, 0, 0 },
			{ 0, 0, 0, 0 }
		}
		
};


char startingPosition[2][2]
=
{ 	
	{ 4, -4 },
	{ 4, -4}
};


int Shapes::GetShape(int shapeType, int positionX, int positionY)
{
	return shapes [shapeType] [positionX] [positionY];
}

int Shapes::GetStartPositionX(int shapeType)
{
	return startingPosition [shapeType][0];
	

}

int Shapes::GetStartPositionY(int shapeType)
{
	return startingPosition[shapeType][1];
}


void Shapes::Move(int x, int y)
{
	
}

