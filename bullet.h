#ifndef __BULLET_H_INCLUDED__
#define __BULLET_H_INCLUDED__

#include <GL/glut.h>

class Bullet
{
  public:
    float x;
    float y;
    Bullet();
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
