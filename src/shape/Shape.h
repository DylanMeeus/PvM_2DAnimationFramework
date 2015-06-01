/*
 * Shape.h
 *
 *  Created on: 2-jun.-2015
 *      Author: Dylan
 */

#ifndef SRC_SHAPE_SHAPE_H_
#define SRC_SHAPE_SHAPE_H_

#include "IDrawable.h"
#include "Colour.h"

class Shape : public IDrawable{

protected:
	Colour colour;

};


#endif /* SRC_SHAPE_SHAPE_H_ */
