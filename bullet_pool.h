#ifndef __BULLET_POOL_H_INCLUDED__
#define __BULLET_POOL_H_INCLUDED__

#include "bullet.h"

class BulletPool
{
  public:
    static const int POOL_SIZE = 50;
    Bullet* bullets[POOL_SIZE];
    BulletPool();
    void create(int x, int y, float xVel, float yVel);
    void update();
};

#endif
