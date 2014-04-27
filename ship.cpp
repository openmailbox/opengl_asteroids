#include "ship.h"

Ship::Ship(int originX, int originY) : rotationDegrees(0), shape(glGenLists(1)), x(originX), y(originY)
{
  glNewList(shape, GL_COMPILE);
  glColor3f(1, 1, 1);
  glBegin(GL_LINES);
  glVertex2i(x - 15, y - 10);
  glVertex2i(x, y + 25);
  glVertex2i(x, y + 25);
  glVertex2i(x + 15, y - 10);
  glVertex2i(x + 15, y);
  glVertex2i(x - 15, y);
  glEnd();
  glEndList();
}

void Ship::rotate(int degreeOffset)
{
  rotationDegrees += degreeOffset;
}

int Ship::getRotation()
{
  return rotationDegrees;
}

void Ship::update()
{
  glPushMatrix();
  glTranslated(x, y, 0);
  glRotated(rotationDegrees, 0, 0, 1);
  glTranslated(-1 * x, -1 * y, 0);
  glCallList(shape);
  glPopMatrix();
}
