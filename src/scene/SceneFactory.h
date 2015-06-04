/*
 * SceneFactory.h
 *
 *  Created on: 4-jun.-2015
 *      Author: Dylan
 */

#ifndef SRC_SCENE_SCENEFACTORY_H_
#define SRC_SCENE_SCENEFACTORY_H_

#include "Scene.h"
#include <iostream>

class SceneFactory
{
public:
	SceneFactory(){}
	static Scene createScene(const std::string & filename);

};

#endif /* SRC_SCENE_SCENEFACTORY_H_ */

