#include <iostream>
#include <math.h>
#include <GL/glut.h>
#include <GL/freeglut.h>

#include "asteroid.h"
#include "asteroid_pool.h"
#include "bullet.h"
#include "bullet_pool.h"
#include "ship.h"

GLsizei winWidth = 800, winHeight = 600;   
int asteroidCreated = 0;

Ship* ship;
BulletPool* bulletPool;
AsteroidPool* asteroidPool;

// Initialize method
void init()
{
  // Get and display your OpenGL version
  std::cout << "Your OpenGL version is " << glGetString(GL_VERSION) << std::endl;

  ship = new Ship(winWidth / 2, winHeight / 2);
  bulletPool = new BulletPool();
  asteroidPool = new AsteroidPool();

  // Black background
  glClearColor(0.0, 0.0, 0.0, 0.0);

}

void checkCollisions()
{
  for (int i = 0; i < BulletPool::POOL_SIZE; i++) {
    Bullet* b = bulletPool->bullets[i];
    if (!b->isInUse()) {
      continue;
    } else {
      for (int i = 0; i < AsteroidPool::POOL_SIZE; i++) {
        Asteroid* a = asteroidPool->asteroids[i];
        if (!a->isInUse()) {
          continue;
        } else {
          float x1 = b->x, x2 = a->x, y1 = b->y, y2 = a->y;
          float distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
          if (distance <= a->radius) {
            a->destroy();
            b->destroy();
          }
        }
      }
    }
  }
}

// Draw method
void displayFcn()
{
  // Clear display window.
  glClear(GL_COLOR_BUFFER_BIT);  

  glColor3f(1, 1, 1);
  glRasterPos2i(0, 10);
  glutBitmapString(
      GLUT_BITMAP_TIMES_ROMAN_24, 
      (const unsigned char*)"Use arrow keys to rotate.  Use spacebar to fire."
      );
  
  checkCollisions();
  ship->update();
  bulletPool->update();
  asteroidPool->update();

  glutSwapBuffers();

  glFlush( );
}

// Window redraw method
void winReshapeFcn(GLint newWidth, GLint newHeight)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity( );
    gluOrtho2D(0.0,(GLdouble) newWidth, 0.0,(GLdouble) newHeight);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT);  
}

void animate(void)
{
  asteroidCreated += 1;
  if (asteroidCreated > 100) {
    if (1 + (rand() % 100) > 65) {
      asteroidPool->create();
      asteroidCreated = 0;
    }
  }
  glutPostRedisplay();
}

void keyboardArrows(int key, int x, int y)
{
  switch (key) {
    case GLUT_KEY_LEFT:
      ship->rotate(-10);
    break;
    case GLUT_KEY_RIGHT:
      ship->rotate(10);
    break;
  }
}

void keyboard(unsigned char key, int x, int y)
{
  switch (key) {
    case (char)32:
      float radians = ((ship->getRotation() + 90) * 3.14159) / 180;
      bulletPool->create(winWidth / 2, winHeight / 2, cos(radians) * 3, sin(radians) * 3);
      break;
  }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    glutInitWindowPosition(100, 100);
    glutInitWindowSize(winWidth, winHeight);

    glutCreateWindow("Asteroids");
    init();
    glutDisplayFunc(displayFcn);

    glutReshapeFunc(winReshapeFcn);
    glutSpecialFunc(keyboardArrows);
    glutKeyboardFunc(keyboard);
    glutIdleFunc(animate);
    glutMainLoop();

    return 0;
}
