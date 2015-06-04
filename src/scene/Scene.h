/*
 * Scene.h
 *
 *  Created on: 4-jun.-2015
 *      Author: Dylan
 */

#ifndef SRC_SCENE_SCENE_H_
#define SRC_SCENE_SCENE_H_


#include <vector>
#include "shape/IDrawable.h"
#include "shape/IAnimatable.h"

class Scene
{
private:
	// Add to both vectors if it needs be drawn and animated
	std::vector<IDrawable*> drawables;
	std::vector<IAnimatable*> animatables;

public:
	Scene(){}
	std::vector<IDrawable*> getDrawables() const {return drawables;}
	std::vector<IAnimatable*> getAnimatables() const {return animatables;}
	void addDrawable(IDrawable* drawable){drawables.push_back(drawable);}
	void addAnimatable(IAnimatable* animatable){animatables.push_back(animatable);}

};

#endif /* SRC_SCENE_SCENE_H_ */
