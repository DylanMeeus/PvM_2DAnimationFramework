/*
 * WorldWindow.cpp
 *
 *  Created on: 5-jun.-2015
 *      Author: Dylan
 */


#include "WorldWindow.h"
#include <iostream>

void WorldWindow::intersection(DynamicCircle * dynamicCircle)
{

	Point current = dynamicCircle->getCentre();
	current.x += dynamicCircle->getVelocity().x;
	current.y += dynamicCircle->getVelocity().y;

	Vector m = Vector();
	if (current.x >= this->right)
	{
		m = Vector(current, Point(current.x - 1, current.y));
	} else if (current.x <= 0)
	{
		m = Vector(current, Point(current.x +1, current.y));
	}
	if(current.y <= 0)
	{
		m = Vector(current, Point(current.x, current.y+1));
	}
	else if(current.y >= this->top)
	{
		m = Vector(current, Point(current.x, current.y-1));
	}
	Vector w = dynamicCircle->getVelocity() - 2 * (dynamicCircle->getVelocity().dot(m) * m);
	dynamicCircle->setVelocity(w);
	dynamicCircle->setCentre(current);

}
