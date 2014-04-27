#include "bullet.h"

const int Bullet::winWidth = 800;
const int Bullet::winHeight = 600;

Bullet::Bullet() : inUse(false), shape(glGenLists(1)), x(0), y(0), xVel(0), yVel(0)
{
  glNewList(shape, GL_COMPILE);
  glColor3f(1, 1, 1);
  glBegin(GL_LINES);
  glVertex2i(0, 0);
  glVertex2i(0, 3);
  glVertex2i(1, 0);
  glVertex2i(1, 3);
  glVertex2i(2, 0);
  glVertex2i(2, 3);
  glVertex2i(3, 0);
  glVertex2i(3, 3);
  glEnd();
  glEndList();
}

void Bullet::init(float newX, float newY, float newXVel, float newYVel)
{
  inUse = true;
  x = newX;
  y = newY;
  xVel = newXVel;
  yVel = newYVel;
}

bool Bullet::isInUse()
{
  return inUse;
}

void Bullet::update()
{
  if (inUse) {
    x += xVel;
    y += yVel;

    if ((x < 0 || x > winWidth) || (y < 0 || y > winHeight)) {
      inUse = false;
      return;
    }

    glPushMatrix();
    glTranslatef(x, y, 0);
    glCallList(shape);
    glPopMatrix();
  }
}

