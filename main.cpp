#include <iostream>
#include <math.h>
#include <GL/glut.h>

GLsizei winWidth = 1280, winHeight = 1024;   
GLint xpos = 0, ypos = 0;

class Ship
{
  public:
    Ship(int originX, int originY) : rotationDegrees(0), shape(glGenLists(1)), x(originX), y(originY)
    {
      glNewList(shape, GL_COMPILE);
      glColor3f(1, 1, 1);
      glBegin(GL_LINES);
      glVertex2i(x - 15, y - 10);
      glVertex2i(x, y + 25);
      glVertex2i(x, y + 25);
      glVertex2i(x + 15, y - 10);
      glVertex2i(x + 15, y);
      glVertex2i(x - 15, y);
      glEnd();
      glEndList();
    }
    void rotate(int degreeOffset)
    {
      rotationDegrees += degreeOffset;
    }
    int getRotation()
    {
      return rotationDegrees;
    }
    void update()
    {
      glPushMatrix();
      glTranslated(x, y, 0);
      glRotated(rotationDegrees, 0, 0, 1);
      glTranslated(-1 * x, -1 * y, 0);
      glCallList(shape);
      glPopMatrix();
    }
  private:
    int rotationDegrees;
    const GLuint shape;
    int x;
    int y;
};

class Bullet
{
  public:
    float x;
    float y;
    float vectorX;
    float vectorY;
    Bullet(float vectorX, float vectorY): x(winWidth / 2), y(winHeight / 2), vectorX(vectorX), vectorY(vectorY), shape(glGenLists(1))
    {
      glNewList(shape, GL_COMPILE);
      glColor3f(1, 1, 1);
      glBegin(GL_POINTS);
      glVertex2i(0, 0);
      glVertex2i(0, 1);
      glVertex2i(0, 2);
      glVertex2i(0, 3);
      glVertex2i(1, 0);
      glVertex2i(1, 1);
      glVertex2i(1, 2);
      glVertex2i(1, 3);
      glVertex2i(2, 0);
      glVertex2i(2, 1);
      glVertex2i(2, 2);
      glVertex2i(2, 3);
      glVertex2i(3, 0);
      glVertex2i(3, 1);
      glVertex2i(3, 2);
      glVertex2i(3, 3);
      glEnd();
      glEndList();
    }
    void update()
    {
      x += vectorX;
      y += vectorY;
      glPushMatrix();
      glTranslatef(x, y, 0);
      glCallList(shape);
      glPopMatrix();
    }
  private:
    const GLuint shape;
};

Bullet* bullet;
Ship* ship;

// Initialize method
void init()
{
  // Get and display your OpenGL version
  std::cout << "Your OpenGL version is " << glGetString(GL_VERSION) << std::endl;

  ship = new Ship(winWidth / 2, winHeight / 2);
  bullet = new Bullet(1, 0);

  // Black background
  glClearColor(0.0, 0.0, 0.0, 0.0);
}

// Draw method
void displayFcn()
{
  // Clear display window.
  glClear(GL_COLOR_BUFFER_BIT);  
  
  ship->update();

  bullet->update();

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
      bullet->x = winWidth / 2;
      bullet->y = winHeight / 2;
      float radians = ((ship->getRotation() + 90) * 3.14159) / 180;
      bullet->vectorX = cos(radians);
      bullet->vectorY = sin(radians);
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
