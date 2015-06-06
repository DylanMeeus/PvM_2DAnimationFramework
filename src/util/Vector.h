/*
 * Vector.h
 *
 *  Created on: 1-jun.-2015
 *      Author: Dylan
 */

#ifndef SRC_UTIL_VECTOR_H_
#define SRC_UTIL_VECTOR_H_
#include "Point.h"

class Vector{


public:
	double x,y;
	Vector(double x=0, double y=0): x(x), y(y) { }
	Vector(Point a, Point b);
	friend Vector operator+(const Vector &v, const Vector &w);
	friend Vector operator+(const Vector &v, const Point &p);
	friend Vector operator+(const Point &p,const Vector &v);
	friend Vector operator-(const Vector &v, const Vector &w);
	friend Vector operator*(const Vector &v, const Vector &w);
	friend Vector operator*(const Vector &v, double scalar);
	friend Vector operator*(double scalar,const Vector &v);
	double dot(const Vector &w);
	double length();
	void normalize();
};


#endif /* SRC_UTIL_VECTOR_H_ */
