

#ifndef _SHAPES_
#define _SHAPES_
class Shapes
{
public:

	int GetShape(int shapeType, int positionX, int positionY);

	int GetStartPositionX(int shapeType);

	int GetStartPositionY(int shapeType);



	void Move(int x, int y);
};
#endif //_SHAPES_
