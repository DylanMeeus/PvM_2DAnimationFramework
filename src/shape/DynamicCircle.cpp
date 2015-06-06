/*
 * DynamicCircle.cpp
 *
 *  Created on: 2-jun.-2015
 *      Author: Dylan
 */

#include "DynamicCircle.h"
#include <iostream>
#include <vector>
#include "scene/Scene.h"

void DynamicCircle::update(const Scene& scene)
{
	std::vector<IDrawable*> drawables = scene.getDrawables();
	for (std::vector<IDrawable>::size_type i = 0; i != drawables.size(); i++)
	{
		drawables[i]->intersection(this);
	}
}

void DynamicCircle::intersection(DynamicCircle * dynamicCircle)
{

}
