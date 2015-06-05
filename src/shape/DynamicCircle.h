/*
 * DynamicCircle.h
 *
 *  Created on: 2-jun.-2015
 *      Author: Dylan
 */

#ifndef SRC_SHAPE_DYNAMICCIRCLE_H_
#define SRC_SHAPE_DYNAMICCIRCLE_H_

#include "IAnimatable.h"
#include "Circle.h"
#include "util/Vector.h"

class DynamicCircle: public Circle, public IAnimatable
{
private:
	Vector velocity;

public:
	DynamicCircle(){}
	DynamicCircle(Point centre, double radius, Colour colour, Vector velocity) :
			velocity(velocity)
	{
		Circle::setCentre(centre);
		Circle::setRadius(radius);
		Circle::setColour(colour);
	}

	Vector getVelocity() const {return velocity;}
	void setVelocity(Vector vel){velocity=vel;}
	virtual void update(const Scene& scene);
	virtual void intersection(DynamicCircle * dynamicCircle);
};

#endif /* SRC_SHAPE_DYNAMICCIRCLE_H_ */
