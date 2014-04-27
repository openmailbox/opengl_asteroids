#ifndef __SHIP_H_INCLUDED__
#define __SHIP_H_INCLUDED__

#include <GL/glut.h>

class Ship
{
  public:
    Ship(int originX, int originY);
    void rotate(int degreeOffset);
    int getRotation();
    void update();
  private:
    int rotationDegrees;
    const GLuint shape;
    int x;
    int y;
};

#endif
