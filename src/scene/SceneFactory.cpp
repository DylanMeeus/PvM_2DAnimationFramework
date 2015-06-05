/*
 * SceneFactory.cpp
 *
 *  Created on: 4-jun.-2015
 *      Author: Dylan
 */

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "SceneFactory.h"
#include "util/Colour.h"
#include "shape/Circle.h"
#include "shape/DynamicCircle.h"

Scene SceneFactory::createScene(const std::string & filename,
		WorldWindow * worldWindow)
{
	std::ifstream sdlfile(filename.c_str());
	Scene scene = Scene(worldWindow);

	//	scene.addDrawable(worldWindow);
	Colour colour;
	if (!sdlfile)
	{
		std::cout << "file could not be opened!\n" << std::endl;
	} else
	{
		while (sdlfile)
		{
			std::string key;
			sdlfile >> key;
			if (key.empty())
			{
				continue;
			}
			if (key.compare("colour") == 0)
			{
				double r, g, b;
				sdlfile >> r >> g >> b;
				colour = Colour(r, g, b);
			}
			if (key.compare("circle") == 0)
			{
				std::cout << "circle" << std::endl;
				Circle *circle = new Circle();
				// read the data. First two data = Point(centre), next = radius
				double x, y, r;
				sdlfile >> x >> y >> r;
				circle->setCentre(Point(x, y));
				circle->setRadius(r);
				circle->setColour(colour);
				std::cout << "adding to the scene" << std::endl;
				//		std::cout << circle.getCentre().x << " " << circle.getCentre().y << " " << circle.getRadius() << std::endl;
				scene.addDrawable(circle);
			}
			if (key.compare("dynamicCircle") == 0)
			{
				std::cout << "Dynamic Circle" << std::endl;
				double x, y, r, vx, vy;
				sdlfile >> x >> y >> r >> vx >> vy;
				DynamicCircle *dyncircle = new DynamicCircle();
				dyncircle->setCentre(Point(x, y));
				dyncircle->setRadius(r);
				dyncircle->setVelocity(Vector(vx, vy));
				dyncircle->setColour(colour);
				scene.addDrawable(dyncircle);
				scene.addAnimatable(dyncircle);
			}
		}
	}

	return scene;
}
