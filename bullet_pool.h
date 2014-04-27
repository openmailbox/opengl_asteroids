#ifndef __BULLET_POOL_H_INCLUDED__
#define __BULLET_POOL_H_INCLUDED__

#include "bullet.h"

class BulletPool
{
  public:
    BulletPool();
    void create(int x, int y, float xVel, float yVel);
    void update();
  private:
    static const int POOL_SIZE = 50;
    Bullet* bullets[POOL_SIZE];
};

#endif
