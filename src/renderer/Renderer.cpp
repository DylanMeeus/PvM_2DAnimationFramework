#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <windows.h>
#include <GL/glut.h>
#endif

#include "renderer/Renderer.h"
#include <iostream>
#include <vector>

void Renderer::render()
{
	/*glColor3f(1, 0, 0);
	 glBegin(GL_POLYGON);
	 glVertex2f(50, 100);
	 glVertex2f(450, 100);
	 glVertex2f(250, 400);
	 glEnd();

	 glColor3f(0, 0, 1);
	 glBegin(GL_POLYGON);
	 glVertex2f(700, 50);
	 glVertex2f(900, 50);
	 glVertex2f(800, 450);
	 glEnd();
	 */
//	this->C->draw();
//	this->C->update();
	// Get them from the scene

	std::vector<IDrawable*> drawables = this->scene.getDrawables();
	for (std::vector<IDrawable>::size_type i = 0;i != drawables.size(); i++)
	{
		drawables[i]->draw();
	}

	std::vector<IAnimatable*> animatables = this->scene.getAnimatables();
	for (std::vector<IAnimatable>::size_type i = 0;
			i != animatables.size(); i++)
	{
		animatables[i]->update();
	}
}

