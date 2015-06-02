/*
 * Circle.h
 *
 *  Created on: 2-jun.-2015
 *      Author: Dylan
 */

#ifndef SRC_SHAPE_CIRCLE_H_
#define SRC_SHAPE_CIRCLE_H_

#include "util/Point.h"
#include "Shape.h"
#include "util/Colour.h"

class Circle : public Shape{
private:
	double radius;
	Point centre;

public:

	Circle(Point centre, double radius, Colour colour): centre(centre), radius(radius){
		Shape::setColour(colour);
	};
	double getRadius(){return radius;}
	Point getCentre(){return centre;}
	Colour getColour(){return this->colour;}
	void setRadius(double r){radius=r;}
	void setCentre(Point c){centre=c;}
	void setColour(Colour c){this->colour=c;}
	virtual void draw();
};



#endif /* SRC_SHAPE_CIRCLE_H_ */
