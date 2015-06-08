/*
 * Flock.cpp
 *
 *  Created on: 8-jun.-2015
 *      Author: Dylan
 */

#include "Flock.h"
#include <iostream>
void Flock::draw() const
{
	std::cout << this->boids.size() << std::endl;
	for (std::vector<Boid*>::size_type i = 0; i != this->boids.size(); i++)
	{
		this->boids[i]->draw();
	}

}

void Flock::addBoid(Boid* boid)
{
	this->boids.push_back(boid);
}

void Flock::update(const Scene& scene)
{
	for(std::vector<Boid*>::size_type i = 0; i != this->boids.size(); i++)
	{
		this->boids[i]->update(scene);
	}
}

void Flock::intersection(DynamicCircle* dynamicCircle)
{

}
