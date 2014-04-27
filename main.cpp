#include <iostream>
#include <math.h>
#include <GL/glut.h>

#include "asteroid.h"
#include "bullet.h"
#include "bullet_pool.h"
#include "ship.h"

GLsizei winWidth = 800, winHeight = 600;   

Ship* ship;
BulletPool* bulletPool;

// Initialize method
void init()
{
  // Get and display your OpenGL version
  std::cout << "Your OpenGL version is " << glGetString(GL_VERSION) << std::endl;

  ship = new Ship(winWidth / 2, winHeight / 2);
  bulletPool = new BulletPool();

  // Black background
  glClearColor(0.0, 0.0, 0.0, 0.0);
}

// Draw method
void displayFcn()
{
  // Clear display window.
  glClear(GL_COLOR_BUFFER_BIT);  
  
  ship->update();
  bulletPool->update();

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
