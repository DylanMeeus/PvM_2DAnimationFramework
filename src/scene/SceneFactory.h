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
#include "WorldWindow.h"

class SceneFactory
{
public:
	SceneFactory(){}
	static Scene createScene(const std::string & filename, WorldWindow * worldWindow);

};

#endif /* SRC_SCENE_SCENEFACTORY_H_ */

