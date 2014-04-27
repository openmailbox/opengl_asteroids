#ifndef __ASTEROID_H_INCLUDED__
#define __ASTEROID_H_INCLUDED__

#include <math.h>
#include <GL/glut.h>

class Asteroid
{
  public:
    float x;
    float y;
    float radius;
    Asteroid();
    void destroy();
    void init(float newX, float newY, float newXVel, float newYVel);
    bool isInUse();
    void update();
  private:
    static const int winWidth;
    static const int winHeight;
    bool inUse;
    const GLuint shape;
    float xVel;
    float yVel;
};

#endif
