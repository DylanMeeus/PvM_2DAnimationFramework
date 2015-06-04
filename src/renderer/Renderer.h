#ifndef RENDERER_H_
#define RENDERER_H_

#include "shape/Circle.h"
#include "shape/DynamicCircle.h"
#include "util/Point.h"

class Renderer
{
private:
	DynamicCircle *C = new DynamicCircle(Point(10,150),8,Colour(1,1,0),Vector(5,1));

public:
	Renderer()
	{
	}
	void render();
};

#endif /* RENDERER_H_ */

