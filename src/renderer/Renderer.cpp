#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <windows.h>
#include <GL/glut.h>
#endif

#include "renderer/Renderer.h"

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
	//DynamicCircle c(Point(10, 250), 8, Colour(1, 1, 0), Vector(5, 0));
	this->C->draw();
	this->C->update();
}

