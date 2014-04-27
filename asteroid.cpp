#include "asteroid.h"

const int Asteroid::winWidth = 800;
const int Asteroid::winHeight = 600;

Asteroid::Asteroid() : x(0), y(0), inUse(false), shape(glGenLists(1)), xVel(0), yVel(0)
{
  radius = 10.0 + (rand() % 40);
  GLfloat twicePI = 2.0f * 3.14159;
  glColor3f(1, 1, 1);

  glNewList(shape, GL_COMPILE);
  glBegin(GL_LINE_LOOP);
  for (int i = 0; i < 360; i += 5) {
    glVertex2f(
        x + (radius * cos(i * twicePI / 360)),
        y + (radius * sin(i * twicePI / 360))
        );
  }
  glEnd();
  glEndList();
}

void Asteroid::destroy()
{
  inUse = false;
}

void Asteroid::init(float newX, float newY, float newXVel, float newYVel)
{
  inUse = true;
  x = newX;
  y = newY;
  xVel = newXVel;
  yVel = newYVel;
}

bool Asteroid::isInUse()
{
  return inUse;
}

void Asteroid::update()
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

