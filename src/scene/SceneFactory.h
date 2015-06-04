/*
 * SceneFactory.h
 *
 *  Created on: 4-jun.-2015
 *      Author: Dylan
 */

#ifndef SRC_SCENE_SCENEFACTORY_H_
#define SRC_SCENE_SCENEFACTORY_H_

#import "Scene.h"

class SceneFactory
{
public:
	Scene createScene(std::string filename);

};

#endif /* SRC_SCENE_SCENEFACTORY_H_ */

