/*
 * Boid.h
 *
 *  Created on: 6-jun.-2015
 *      Author: Dylan
 */

#ifndef SRC_SHAPE_BOID_H_
#define SRC_SHAPE_BOID_H_

#include "Shape.h"
#include "IAnimatable.h"
#include "util/Point.h"
#include "util/Vector.h"
#include "DynamicCircle.h"

class Boid: public Shape, public IAnimatable{

private:
	Point centre;
	double size;
	Vector velocity;

public:

	Boid(Point c, double s, Vector v, Colour colour) : centre(c), size(s), velocity(v){
		Shape::setColour(colour);
	}

	Point getCentre(){return centre;}
	double getSize(){return size;}
	Vector getVelocity(){return velocity;}

	void setCentre(Point c){centre=c;}
	void setSize(double s){size=s;}
	void setVelocity(Vector v){velocity=v;}
	virtual void draw() const;
	virtual void update(const Scene& scene);
	virtual void intersection(DynamicCircle * dynamicCircle);

};


#endif /* SRC_SHAPE_BOID_H_ */
