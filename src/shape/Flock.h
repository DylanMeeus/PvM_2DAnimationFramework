/*
 * Flock.h
 *
 *  Created on: 8-jun.-2015
 *      Author: Dylan
 */

#ifndef SRC_SHAPE_FLOCK_H_
#define SRC_SHAPE_FLOCK_H_

#include "Shape.h"
#include "Boid.h"
#include "DynamicCircle.h"
#include "IAnimatable.h"
#include "util/Colour.h"
#include <vector>
#include "scene/Scene.h"
class Flock: public Shape, public IAnimatable
{
private:
	std::vector<Boid*> boids = std::vector<Boid*>();
	double cohesion, separation, alignment, damping, maxSpeed;
public:
	Flock(Colour colour)
	{
		cohesion = 0.008;
		separation = 30;
		alignment = 0.025;
		damping = 0.15;
		maxSpeed = 8;
		Shape::setColour(colour);
	}
	void addBoid(Boid* boid);
	Vector rule1(unsigned index); // cohesion (index=the current boid)
	Vector rule2(unsigned index); // separation
	Vector rule3(unsigned index); // alignment

	virtual void draw() const;
	virtual void update(const Scene& scene);
	virtual void intersection(DynamicCircle* dynamicCircle);

};

#endif /* SRC_SHAPE_FLOCK_H_ */
