#include "Shapes.h"

//Total of seven shapes in a 4x4 matrix.
char shapes[7][4][4]
= 
{
		//Shapes
		{
			{ 0, 0, 1, 0 },
			{ 0, 0, 1, 0 },
			{ 0, 0, 1, 0 },
			{ 0, 0, 1, 0 }
		}, 
		{
			{ 0, 1, 0, 0 },
			{ 0, 1, 1, 0 },
			{ 0, 0, 1, 0 },
			{ 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 1, 0 },
			{ 0, 1, 1, 1 },
			{ 0, 0, 0, 0 },
			{ 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0 },
			{ 0, 0, 1, 0 },
			{ 0, 0, 1, 1 },
			{ 0, 0, 1, 0 }
		},
		{
			{ 0, 0, 0, 0 },
			{ 0, 1, 1, 0 },
			{ 0, 0, 1, 0 },
			{ 0, 0, 1, 0 }
		},
		{//Crazy shape test left in.
			{ 0, 1, 0, 0 },
			{ 0, 1, 1, 1 },
			{ 1, 1, 1, 0 },
			{ 0, 0, 1, 0 }
		},
		{
			{ 0, 0, 0, 0 },
			{ 0, 1, 1, 0 },
			{ 0, 1, 1, 0 },
			{ 0, 0, 0, 0 }
		}
};

//Starting Position of all shapes.
char startingPosition[1][2]
=
{ 	
	{ 4, -4 }//Set to minus 4 so whole shape is drawn off screen to start.
};


int Shapes::GetShape(int shapeType, int positionX, int positionY)
{
	return shapes [shapeType] [positionX] [positionY];
}

int Shapes::GetStartPositionX(int shapeType)
{
	return startingPosition [0][0];
	

}

int Shapes::GetStartPositionY(int shapeType)
{
	return startingPosition[0][1];
}
