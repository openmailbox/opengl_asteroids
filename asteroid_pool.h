#ifndef __ASTEROID_POOL_H_INCLUDED__
#define __ASTEROID_POOL_H_INCLUDED__

#include "asteroid.h"

class AsteroidPool
{
  public:
    static const int POOL_SIZE = 50;
    Asteroid* asteroids[POOL_SIZE];
    AsteroidPool();
    void create();
    void update();
  private:
    static const int winWidth;
    static const int winHeight;
};

#endif
