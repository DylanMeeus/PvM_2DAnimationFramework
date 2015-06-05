/*
 * DynamicCircle.cpp
 *
 *  Created on: 2-jun.-2015
 *      Author: Dylan
 */

#include "DynamicCircle.h"
#include <iostream>



void DynamicCircle::update(const Scene& scene)
{
	// get current position
	Point current = this->getCentre();
	current.x += this->velocity.x;
	current.y += this->velocity.y;

	Vector m = Vector();
	if (current.x >= 1000)
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
	else if(current.y >= 500)
	{
		m = Vector(current, Point(current.x, current.y-1));
	}
	Vector w = this->velocity - 2 * (this->velocity.dot(m) * m);
	this->velocity = w;
	this->setCentre(current);

}

void DynamicCircle::intersection(DynamicCircle * dynamicCircle)
{

}
