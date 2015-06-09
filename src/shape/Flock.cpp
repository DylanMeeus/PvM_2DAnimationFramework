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
//	std::cout << this->boids.size() << std::endl;
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
	for (std::vector<Boid*>::size_type i = 0; i != this->boids.size(); i++)
	{
		//this->boids[i]->update(scene);
		Vector u = rule1(i) + rule2(i) + rule3(i);
		u = u * this->damping;
		u = u + this->boids[i]->getVelocity();
		if (u.length() > this->maxSpeed)
		{
			u = u * (maxSpeed / u.length());

			Vector w = Vector(0, 0);
			if (this->boids[i]->getCentre().y >= 500 - 200)
			{
				w = Vector(0, -0.4);
			} else if (this->boids[i]->getCentre().x <= 0)
			{
			//	w = Vector(0.12, 0);
				this->boids[i]->setColour(Colour(0,1,0));
				this->boids[i]->setCentre(Point(1000,this->boids[i]->getCentre().y));
			} else if (this->boids[i]->getCentre().y <= 200)
			{
				w = Vector(0, 0.4);
			} else if (this->boids[i]->getCentre().x >= 1000)
			{
		//		w = Vector(-0.12, 0);
				this->boids[i]->setColour(Colour(1,0,1));
				this->boids[i]->setCentre(Point(0,this->boids[i]->getCentre().y));
			}
			u = u + w;
		}
		this->boids[i]->setVelocity(u);
		this->boids[i]->setCentre(
				Point(this->boids[i]->getCentre().x + this->boids[i]->getVelocity().x, this->boids[i]->getCentre().y + this->boids[i]->getVelocity().y));


		// now the wind


	}
}

void Flock::intersection(DynamicCircle* dynamicCircle)
{

}

Vector Flock::rule1(unsigned index) // cohesion
{
	Point flockCentre;
	for (std::vector<Boid*>::size_type i = 0; i < this->boids.size(); i++)
	{
		if (i != index)
		{
			flockCentre = flockCentre + this->boids[i]->getCentre();
		}
	}
	flockCentre /= this->boids.size();
	Vector toCentre = Vector(this->boids[index]->getCentre(), flockCentre);
	toCentre = toCentre * this->cohesion;
	return toCentre;
}

Vector Flock::rule2(unsigned index) // separation
{
	Vector res;
	for (std::vector<Boid*>::size_type i = 1; i != this->boids.size(); i++)
	{
		if (i != index)
		{
			// distance between two boids == distance from centre to centre?
			Vector distance = Vector(this->boids[i]->getCentre(), this->boids[index]->getCentre());
			if (distance.length() < this->separation)
			{
				Vector u = Vector(this->boids[i]->getCentre(), this->boids[index]->getCentre());
				double factor = this->separation / (u.length() * u.length());
				if (factor > 100)
				{
					factor = 100;
				}
				res = res + u;
			}
		}
	}
	return res;
}

Vector Flock::rule3(unsigned index) // alignment
{
	Vector avVelocity;
	for (std::vector<Boid*>::size_type i = 1; i != this->boids.size(); i++)
	{
		if (i != index)
		{
			avVelocity = avVelocity + this->boids[i]->getVelocity();
		}
	}
	avVelocity = avVelocity / this->boids.size();
	Vector neededVel = this->boids[index]->getVelocity() - avVelocity;
	neededVel = neededVel * this->alignment;
	return neededVel;
}
