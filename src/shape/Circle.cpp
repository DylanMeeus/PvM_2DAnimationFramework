/*
 * Circle.cpp
 *
 *  Created on: 2-jun.-2015
 *      Author: Dylan
 */

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <windows.h>
#include <GL/glut.h>
#endif

#include <iostream>
#include <cmath>
#include "renderer/Renderer.h"
#include "Circle.h"

void Circle::draw() const
{
	// (a+ r.cos(theta), b + r.sin(theta))
	// a == x; b == y
	// i == theta?
	// More vertices == smoother circle. (Max 360)

//	std::cout << "drawing: " << this->centre.x << " " << this->centre.y << " " << this->radius << " " << this->colour.r << std::endl;
	glColor3f(this->colour.r, this->colour.g, this->colour.b);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 50; i++)
	{
		glVertex2f(this->centre.x + (this->radius * cos(i)),this->centre.y + (this->radius * sin(i)));
	}
	glEnd();
}

void Circle::intersection(DynamicCircle * dynamicCircle)
{

}
