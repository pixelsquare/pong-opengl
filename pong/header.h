// HEADER -------//
 
#define _USE_MATH_DEFINES
#ifndef __HEADER_H__
#define __HEADER_H__
 
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <vector>
#include <math.h>
#include <glut.h>
#include <time.h>
 
/* OpenGL Library */
#include "glut.h"
 
// Window Dimension
const int width = 900;
const int height = 700;
 
//For Keyboard Keys
float AngleY = 0.0;
float AngleX = 0.0;
 
//For Camera
float LookX = 0.0f;
float LookY = 0.0f;
float LookZ = 20.0f;
 
float MoveX = 0.0f;
float MoveY = 0.0f;
 
// For Spheres
int stacks = 10;
int slices = 10;
 
// Ball Rotation
float angle = 0.0f;
 
// Static Object Position (Center)
float x = 0.0f;
float y = 0.0f;
float z = 0.0f;
 
// Color
float R = 1.0f;
float G = 1.0f;
float B = 1.0f;
 
// Paddle Dimensions
#define pheight 0.3
#define pwidth 0.3

// Ball Size
double bsize = 0.2;

// Ball Movement
float ball_x = 0.0f;
float ball_y = 0.0f;

// Ball Collision
float bulx = -0.1f;
float blrx = 0.1f;
float buly = 0.1f;
float blry = -0.1f;

// Test Ball Collision
bool Tx = true;
bool Ty = true;

// Paddle1 Collision
float p1lrx = 3.8, p1ulx = 3.8;
float p1lry = -1.2, p1uly = 1.2;

// Paddle2 Collision
float p2lrx = -3.8, p2ulx = -3.8;
float p2lry = -1.2, p2uly = 1.2;

// Paddle Control
float p1 = 0.0f;
float p2 = 0.0f;

// Box Collision
float boxT = 5.2f;
float boxB = -5.2f;
float boxL = -4.0f;
float boxR = 4.0f;

// Test Paddle AI
bool Tai = true;

// Other Test Functions
bool Tai1 = false;
bool Tai2 = false;
bool Tp1 = false;
bool start = false;

// Global Random
float Srate = 0.01;

void Lighting()
{      
        //Add ambient light
        GLfloat ambientColor[] = {0.4f, 0.4f, 0.4f, 1.0f}; //Color (0.2, 0.2, 0.2)
        glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);
       
        //Add positioned light
        GLfloat lightColor0[] = {0.2f, 0.2f, 0.2f, 1.0f}; //Color (0.5, 0.5, 0.5)
        GLfloat lightPos0[] = {4.0f, 0.0f, 8.0f, 1.0f}; //Positioned at (4, 0, 8)
        glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0);
        glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);
       
        //Add directed light
        GLfloat lightColor1[] = {1.0f, 1.0f, 1.0f, 1.0f}; //Color (0.5, 0.2, 0.2)
        //Coming from the direction (-1, 0.5, 0.5)
        GLfloat lightPos1[] = {-1.0f, 0.5f, 0.5f, 0.0f};
        glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor1);
        glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);
 
}
 
// RENDERING OBJECTS
void Scene();
void grid();
void bg();
void box();
void ball();
void paddle1();
void paddle2();
 
/* Initiates 3D Rendering (LIGHTING) */
 
void initRendering() {
        glEnable(GL_DEPTH_TEST);
        glEnable(GL_COLOR_MATERIAL);
        glEnable(GL_LIGHTING); //Enable lighting
        glEnable(GL_LIGHT0); //Enable light #0
        glEnable(GL_LIGHT1); //Enable light #1
        glEnable(GL_NORMALIZE); //Automatically normalize normals
        //glShadeModel(GL_SMOOTH); //Enable smooth shading
}
 
/* Controls framerate */
void Timer(int extra)
{
  glutPostRedisplay();
  glutTimerFunc(10, Timer, extra);
}
 
/* Controls the camera */
void ResizeWindow(int w, int h)
{
  float ratio = 1.0 * w / h;
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
 
  glViewport(0, 0, w, h);
 
  gluPerspective(45.0, ratio, 1, 1000);
 
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
 
  //gluLookAt(0.0, 0.0, 10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}
 
void Keys(unsigned char key, int x, int y)
{
  switch(key)
  {
/* CAMERA MOVE FUNCTION */
  /*case 'w':
          MoveY -= 1.0;
          break;
 
  case 's':
          MoveY += 1.0;
          break;
 
  case 'd':
          MoveX -= 1.0;
          break;
 
  case 'a':
          MoveX += 1.0;
          break;*/
  case 'p':
	  Tai1 = !Tai1;
	  break;
  case 'q':
	  Tai2 = !Tai2;
	  break;

  case 'w':
	 if(p2uly < 5.2)
	 {
	  p2 += 0.9;
	  p2uly += 0.9;
	  p2lry += 0.9;
	 }
	  break;

  case 's':
	 if(p2lry > -5.2)
	 {
	  p2 -= 0.9;
	  p2uly -= 0.9;
	  p2lry -= 0.9;
	 }
	  break;

  case 'o':
	 if(p1uly < 5.2)
	 {
	  p1 += 0.9;
	  p1uly += 0.9;
	  p1lry += 0.9;
	 }
	  break;

  case 'l':
	 if(p1lry > -5.2)
	 {
	  p1 -= 0.9;
	  p1uly -= 0.9;
	  p1lry -= 0.9;
	 }
	  break;
 
/* ZOOM FUNCTION */
        case 'z':
                LookZ += 1.0;
                break;
 
        case 'x':
                LookZ -= 1.0;
                break;
 
// Normal Camera Position
        case 'c':
                LookX = 0.0f;
                LookY = 0.0f;
                LookZ = 10.0f;
                break;
 
    case 27:
      exit(0);
  }
}
 
 
void SpecialKeys(int key, int x, int y)
{
  switch(key)
  {
    case GLUT_KEY_UP:
      AngleX -= 1.0;
      break;
 
    case GLUT_KEY_DOWN:
      AngleX += 1.0;
      break;
 
    case GLUT_KEY_LEFT:
      AngleY -= 1.0;
      break;
 
    case GLUT_KEY_RIGHT:
      AngleY += 1.0;
      break;
  }
}
 
/* Main program */
void GLUTmain(int argc, char **argv)
{
 srand(time(NULL));
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
 
glutInitWindowPosition(0, 0);
glutInitWindowSize(width, height);
glutCreateWindow("3D Pong");
initRendering();
 
//glutFullScreen();
 
glutReshapeFunc(ResizeWindow);
 
glEnable(GL_DEPTH_TEST);
 
glutTimerFunc(0, Timer, 0);
 
glutKeyboardFunc(Keys);
 
glutDisplayFunc(Scene);
//glutIdleFunc(Scene);
 
glutSpecialFunc(SpecialKeys);
 
glutMainLoop();
return;
}
#endif
 