#ifndef RENDERER_H_
#define RENDERER_H_

#include "shape/Circle.h"
#include "shape/DynamicCircle.h"
#include "util/Point.h"
#include "scene/Scene.h"
#include "scene/SceneFactory.h"

class Renderer
{
private:
	DynamicCircle *C = new DynamicCircle(Point(10,150),8,Colour(1,1,0),Vector(5,1));
	Scene scene;
public:
	Renderer(Scene s)
	{
		scene = s;
	}
	void render();
};

#endif /* RENDERER_H_ */

