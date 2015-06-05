/*
 * IDrawable.h
 *
 *  Created on: 2-jun.-2015
 *      Author: Dylan
 */

#ifndef SRC_SHAPE_IDRAWABLE_H_
#define SRC_SHAPE_IDRAWABLE_H_


class DynamicCircle;

class IDrawable {
public:
	virtual void draw() const{}
	virtual void intersection(DynamicCircle * dynamicCircle){}
};

#endif /* SRC_SHAPE_IDRAWABLE_H_ */
