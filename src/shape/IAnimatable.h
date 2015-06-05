/*
 * IAnimatable.h
 *
 *  Created on: 2-jun.-2015
 *      Author: Dylan
 */

#ifndef SRC_SHAPE_IANIMATABLE_H_
#define SRC_SHAPE_IANIMATABLE_H_

class Scene;

class IAnimatable
{
public:
	virtual void update(const Scene& scene)
	{
	}
};

#endif /* SRC_SHAPE_IANIMATABLE_H_ */
