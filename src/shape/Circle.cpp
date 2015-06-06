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
#include "util/Vector.h"

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
		glVertex2f(this->centre.x + (this->radius * cos(i)),
				this->centre.y + (this->radius * sin(i)));
	}
	glEnd();
}

void Circle::intersection(DynamicCircle * dynamicCircle)
{
	// smallest t-value of 'at²+bt+c=0'
	// a = v1.v1
	// b = 2(v1.u1)
	// c = u1.u1-(r1+r2)²
	// set centre to (c1+t.v1)x,(c1+t.v1)y

	// check if they collide first

	Vector centreLength = Vector(this->centre, dynamicCircle->centre);
	if (centreLength.length() < this->radius + dynamicCircle->radius)
	{
		std::cout << "collision" << std::endl;
		Vector v1 = dynamicCircle->getVelocity();
		Vector u1 = Vector(dynamicCircle->centre, this->centre);
		double a = v1.dot(v1);
		double b = 2 * (v1.dot(u1));
		double c = u1.dot(u1)
				- ((dynamicCircle->radius + this->radius)
						* (dynamicCircle->radius + this->radius));
		// solve the equation
		// b²-4(ac);
		double d = b * b - (4 * (a * c));
		std::cout << d << std::endl;
		// -b +- d / 2a
		double sol1 = (-b + sqrt(d)) / (2 * a);
		double sol2 = (-b - sqrt(d)) / (2 * a);
		std::cout << sol1 << " " << sol2 << std::endl;
		// now set the centre
		Vector solution1vector = dynamicCircle->getCentre() + (sol1 * v1);
		Vector solution2vector = dynamicCircle->getCentre() + (sol2 * v1);
		std::cout << solution1vector.x << " and y " << solution1vector.y << std::endl;
		dynamicCircle->setCentre(Point(solution2vector.x,solution1vector.y));



		// now change the velocity
		Vector u2 = Vector(this->getCentre(),dynamicCircle->getCentre());
		u2.normalize();
		Vector w1 = v1 - (2*(v1.dot(u2))*u2);
		dynamicCircle->setVelocity(w1);
	}
}
