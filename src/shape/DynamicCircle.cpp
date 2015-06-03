/*
 * DynamicCircle.cpp
 *
 *  Created on: 2-jun.-2015
 *      Author: Dylan
 */


#include "DynamicCircle.h"
#include <iostream>

void DynamicCircle::update(){
	// get current position
	Point current = this->getCentre();
	current.x += this->velocity.x;
	current.y += this->velocity.y;
	this->setCentre(current);
}
