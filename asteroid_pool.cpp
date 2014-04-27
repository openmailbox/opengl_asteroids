#include "asteroid_pool.h"

const int AsteroidPool::winWidth = 800;
const int AsteroidPool::winHeight = 600;

AsteroidPool::AsteroidPool()
{
  for (int i = 0; i < POOL_SIZE; i++) {
    asteroids[i] = new Asteroid();
  }
}

void AsteroidPool::create()
{
  float x, y, xVel, yVel;

  if (1 + (rand() % 100) > 50) {
    if (1 + (rand() % 100) > 50) {
      x = 0;
      xVel = 1;
    } else {
      x = winWidth;
      xVel = -1;
    }
    
    y = 1 + (rand() % winHeight);
    yVel = 0;
  } else {
    if (1 + (rand() % 100) > 50) {
      y = 0;
      yVel = 1;
    } else {
      y = winHeight;
      yVel = -1;
    }

    x = 1 + (rand() % winHeight);
    xVel = 0;
  }
  
  for (int i = 0; i < POOL_SIZE; i++) {
    if (!asteroids[i]->isInUse()) {
      asteroids[i]->init(x, y, xVel, yVel);
      return;
    }
  }
}

void AsteroidPool::update()
{
  for (int i = 0; i < POOL_SIZE; i++) {
    asteroids[i]->update();
  }
}
