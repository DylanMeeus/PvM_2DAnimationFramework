/*
 * Boid.cpp
 *
 *  Created on: 6-jun.-2015
 *      Author: Dylan
 */

#include "Boid.h"
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <windows.h>
#include <GL/glut.h>
#endif

#include "util/Vector.h"
#include "util/Point.h"
#include <iostream>
#include <cmath>
#define PI 3.1415
void Boid::update(const Scene& scene)
{
	this->centre.x += this->velocity.x;
	this->centre.y += this->velocity.y;
//	this->velocity = this->velocity * 0.995;
//	this->velocity.y *= 1.01;

	Vector w = Vector(0, 0);
	if (this->centre.y >= 500 - 150)
	{
		w = Vector(0, -0.4);
	} else if (this->centre.x <= 150)
	{
		w = Vector(0.4, 0);
	} else if (this->centre.y <= 150)
	{
		w = Vector(0, 0.4);
	} else if (this->centre.x >= 850)
	{
		w = Vector(-0.4, 0);
	}
	this->velocity = this->velocity + w;
}

void Boid::draw() const
{
	/* Determine the angle between u(1,0) and v
	 * Specify P
	 * increase angle (theta=150)
	 * Specify Q
	 * Increase Angle (theta = 60)
	 * Point r
	 */

	/*
	 * The angle between two vectors = v.w / (|v||w|)
	 */

	Vector u = Vector(this->centre, Point((this->centre.x + 1), this->centre.y));
	Vector vNorm = this->velocity;
	double theta = (u.dot(this->velocity)) / (u.length() * vNorm.length());

	theta = acos(theta) * 180 / PI;

	glColor3f(this->colour.r, this->colour.g, this->colour.b);
	glBegin(GL_POLYGON);
	Point p = Point((this->velocity * this->size).x, (this->velocity * this->size).y);
	glVertex2f(this->centre.x + (this->size * cos(theta)), this->centre.y + (this->size * sin(theta)));
	theta += 150;
	glVertex2f(this->centre.x + (this->size * cos(theta)), this->centre.y + (this->size * sin(theta)));
	theta += 60;
	glVertex2f(this->centre.x + (this->size * cos(theta)), this->centre.y + (this->size * sin(theta)));
	glEnd();
}

void Boid::intersection(DynamicCircle * dynamicCircle)
{

}
