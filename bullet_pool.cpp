#include "bullet_pool.h"

BulletPool::BulletPool()
{
  for (int i = 0; i < POOL_SIZE; i++) {
    bullets[i] = new Bullet();
  }
}

void BulletPool::create(int x, int y, float xVel, float yVel)
{
  for (int i = 0; i < POOL_SIZE; i++) {
    if (!bullets[i]->isInUse()) {
      bullets[i]->init(x, y, xVel, yVel);
      return;
    }
  }
}

void BulletPool::update()
{
  for (int i = 0; i < POOL_SIZE; i++) {
    bullets[i]->update();
  }
}
