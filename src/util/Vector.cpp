/*
 * Vector.cpp
 *
 *  Created on: 1-jun.-2015
 *      Author: Dylan
 */

#include "Vector.h"
#include <cmath>

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
