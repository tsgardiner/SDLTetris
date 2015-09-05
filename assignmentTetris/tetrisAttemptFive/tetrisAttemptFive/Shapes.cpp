#include "Shapes.h"


char shapes[1][4][4]
= 
{
		//First attempt
		{
			{ 1, 1, 1, 1 },
			{ 1, 1, 1, 1 },
			{ 1, 1, 1, 1 },
			{ 1, 1, 1, 1 }
		}
		
};


char startingPosition[1][2]
=
{ 	
	{ 50, 50}
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


