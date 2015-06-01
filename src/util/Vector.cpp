/*
 * Vector.cpp
 *
 *  Created on: 1-jun.-2015
 *      Author: Dylan
 */

#include "Vector.h"
#include <cmath>

Vector operator+(const Vector &v, const Point &p){
	return Vector (v.x + p.x, v.y + p.y);
}


