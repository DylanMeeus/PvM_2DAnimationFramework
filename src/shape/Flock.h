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

public:
	Flock(Colour colour){
		Shape::setColour(colour);
	}
	void addBoid(Boid* boid);
	virtual void draw() const;
	virtual void update(const Scene& scene);
	virtual void intersection(DynamicCircle* dynamicCircle);
};

#endif /* SRC_SHAPE_FLOCK_H_ */
