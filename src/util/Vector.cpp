/*
 * Vector.cpp
 *
 *  Created on: 1-jun.-2015
 *      Author: Dylan
 */

#include "Vector.h"
#include <cmath>


Vector::Vector(Point from, Point to)
{
	this->x = to.x-from.x;
	this->y = to.y-from.y;
}

void Vector::normalize()
{
	this->x = this->x/length();
	this->y = this->y/length();
}

double Vector::length()
{
	return sqrt(this->x*this->x+this->y*this->y);
}

double Vector::dot(const Vector &w)
{
	return (this->x*w.x + this->y*w.y);
}

Vector operator+(const Vector &v, const Point &p)
{
	return Vector(v.x + p.x, v.y + p.y);
}

Vector operator*(const Vector &v, const double scalar)
{
	return Vector(v.x * scalar, v.y * scalar);
}

Vector operator*(const double scalar, const Vector &v)
{
	return Vector(v.x * scalar, v.y * scalar);
}

Vector operator+(const Vector &v, const Vector &w)
{
	return Vector(v.x+w.x,v.y+w.y);
}

Vector operator-(const Vector &v, const Vector &w)
{
	return Vector(v.x-w.x, v.y-w.y);
}



