#include<iostream>
#include<GL/glu.h>
#include<GL/freeglut.h>
#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#include "grid.h"

using namespace std;

double rotate_y=0; 
double rotate_x=0;

void display();
void specialKeys();

grid ARENA;
int hori=17,verti=11;



void face(float cx,float cy, float cz ,float lx,float ly,float lz){

  //Yellow size-FRONT
  glBegin(GL_POLYGON);
  glColor3f(   1,  (236.0/255.0), (139.0/255.0) );
  glVertex3f(  cx+lx, cy-ly, cz-lz );
  glVertex3f(  cx+lx,  cy+ly, cz-lz );
  glVertex3f( cx-lx,  cy+ly, cz-lz );
  glVertex3f( cx-lx, cy-ly, cz-lz );
  glEnd();

 
  // White side - BACK
  glBegin(GL_POLYGON);
  glColor3f(   1,  (236.0/255.0), (139.0/255.0) );
  glVertex3f(  cx+lx, cy-ly, cz+lz );
  glVertex3f(  cx+lx,  cy+ly, cz+lz );
  glVertex3f( cx-lx,  cy+ly, cz+lz );
  glVertex3f( cx-lx, cy-ly, cz+lz );
  glEnd();
 
 
  // Purple side - RIGHT
  glBegin(GL_POLYGON);
  glColor3f(  (238.0/255.0),  (220.0/255.0),  (130.0/255.0) );
  glVertex3f( cx+lx, cy-ly, cz-lz );
  glVertex3f( cx+lx,  cy+ly, cz-lz );
  glVertex3f( cx+lx,  cy+ly,  cz+lz );
  glVertex3f( cx+lx, cy-ly,  cz+lz );
  glEnd();
 
 
  // Green side - LEFT
  glBegin(GL_POLYGON);
  glColor3f(   (238.0/255.0),  (220.0/255.0),  (130.0/255.0) );
  glVertex3f( cx-lx, cy-ly,  cz+lz );
  glVertex3f( cx-lx,  cy+ly,  cz+lz );
  glVertex3f( cx-lx,  cy+ly, cz-lz );
  glVertex3f( cx-lx, cy-ly, cz-lz );
  glEnd();
 
  // Blue side - TOP
  glBegin(GL_POLYGON);
  glColor3f(   (65.0/255.0),  (105.0/255.0),  (225./255.0) );
  glVertex3f(  cx+lx,  cy+ly,  cz+lz );
  glVertex3f(  cx+lx,  cy+ly, cz-lz );
  glVertex3f( cx-lx,  cy+ly, cz-lz );
  glVertex3f( cx-lx,  cy+ly,  cz+lz );
  glEnd();
 
  // Red side - BOTTOM
  glBegin(GL_POLYGON);
  glColor3f(   (205.0/255.0),  (190.0/255.0),  (112.0/255.0) );
  glVertex3f(  cx+lx, cy-ly, cz-lz );
  glVertex3f(  cx+lx, cy-ly,  cz+lz );
  glVertex3f( cx-lx, cy-ly,  cz+lz );
  glVertex3f( cx-lx, cy-ly, cz-lz );
  glEnd();

}

void hair(float cx,float cy, float cz ,float lx,float ly,float lz){

  //Yellow size-FRONT
  glBegin(GL_POLYGON);
  glColor3f(   (210.0/255.0),  (105.0/255.0), (30.0/255.0) );
  glVertex3f(  cx+lx, cy-ly, cz-lz );
  glVertex3f(  cx+lx,  cy+ly, cz-lz );
  glVertex3f( cx-lx,  cy+ly, cz-lz );
  glVertex3f( cx-lx, cy-ly, cz-lz );
  glEnd();

 
  // White side - BACK
  glBegin(GL_POLYGON);
  glColor3f(   (210.0/255.0),  (105.0/255.0), (30.0/255.0) );
  glVertex3f(  cx+lx, cy-ly, cz+lz );
  glVertex3f(  cx+lx,  cy+ly, cz+lz );
  glVertex3f( cx-lx,  cy+ly, cz+lz );
  glVertex3f( cx-lx, cy-ly, cz+lz );
  glEnd();
 
 
  // Purple side - RIGHT
  glBegin(GL_POLYGON);
  glColor3f(  (238.0/255.0),  (118.0/255.0),  (33.0/255.0) );
  glVertex3f( cx+lx, cy-ly, cz-lz );
  glVertex3f( cx+lx,  cy+ly, cz-lz );
  glVertex3f( cx+lx,  cy+ly,  cz+lz );
  glVertex3f( cx+lx, cy-ly,  cz+lz );
  glEnd();
 
 
  // Green side - LEFT
  glBegin(GL_POLYGON);
  glColor3f(   (238.0/255.0),  (118.0/255.0),  (33.0/255.0) );
  glVertex3f( cx-lx, cy-ly,  cz+lz );
  glVertex3f( cx-lx,  cy+ly,  cz+lz );
  glVertex3f( cx-lx,  cy+ly, cz-lz );
  glVertex3f( cx-lx, cy-ly, cz-lz );
  glEnd();
 
  // Blue side - TOP
  glBegin(GL_POLYGON);
  glColor3f(   (199.0/255.0),  (97.0/255.0),  (20.0/255.0) );
  glVertex3f(  cx+lx,  cy+ly,  cz+lz );
  glVertex3f(  cx+lx,  cy+ly, cz-lz );
  glVertex3f( cx-lx,  cy+ly, cz-lz );
  glVertex3f( cx-lx,  cy+ly,  cz+lz );
  glEnd();
 
  // Red side - BOTTOM
  glBegin(GL_POLYGON);
  glColor3f(   (199.0/255.0),  (97.0/255.0),  (20.0/255.0) );
  glVertex3f(  cx+lx, cy-ly, cz-lz );
  glVertex3f(  cx+lx, cy-ly,  cz+lz );
  glVertex3f( cx-lx, cy-ly,  cz+lz );
  glVertex3f( cx-lx, cy-ly, cz-lz );
  glEnd();

}

void eye(float cx,float cy, float cz ,float lx,float ly,float lz){

  //Yellow size-FRONT
  glBegin(GL_POLYGON);
  glColor3f(   (51.0/255.0),  (161.0/255.0), (201.0/255.0) );
  glVertex3f(  cx+lx, cy-ly, cz-lz );
  glVertex3f(  cx+lx,  cy+ly, cz-lz );
  glVertex3f( cx-lx,  cy+ly, cz-lz );
  glVertex3f( cx-lx, cy-ly, cz-lz );
  glEnd();

 
  // White side - BACK
  glBegin(GL_POLYGON);
  glColor3f(   (210.0/255.0),  (105.0/255.0), (30.0/255.0) );
  glVertex3f(  cx+lx, cy-ly, cz+lz );
  glVertex3f(  cx+lx,  cy+ly, cz+lz );
  glVertex3f( cx-lx,  cy+ly, cz+lz );
  glVertex3f( cx-lx, cy-ly, cz+lz );
  glEnd();
 
 
  // Purple side - RIGHT
  glBegin(GL_POLYGON);
  glColor3f(  0,  (178.0/255.0),  (238.0/255.0) );
  glVertex3f( cx+lx, cy-ly, cz-lz );
  glVertex3f( cx+lx,  cy+ly, cz-lz );
  glVertex3f( cx+lx,  cy+ly,  cz+lz );
  glVertex3f( cx+lx, cy-ly,  cz+lz );
  glEnd();
 
 
  // Green side - LEFT
  glBegin(GL_POLYGON);
  glColor3f(   0,  (178.0/255.0),  (238.0/255.0) );
  glVertex3f( cx-lx, cy-ly,  cz+lz );
  glVertex3f( cx-lx,  cy+ly,  cz+lz );
  glVertex3f( cx-lx,  cy+ly, cz-lz );
  glVertex3f( cx-lx, cy-ly, cz-lz );
  glEnd();
 
  // Blue side - TOP
  glBegin(GL_POLYGON);
  glColor3f(   0,  (154.0/255.0),  (205.0/255.0) );
  glVertex3f(  cx+lx,  cy+ly,  cz+lz );
  glVertex3f(  cx+lx,  cy+ly, cz-lz );
  glVertex3f( cx-lx,  cy+ly, cz-lz );
  glVertex3f( cx-lx,  cy+ly,  cz+lz );
  glEnd();
 
  // Red side - BOTTOM
  glBegin(GL_POLYGON);
  glColor3f(   0,  (154.0/255.0),  (205.0/255.0) );
  glVertex3f(  cx+lx, cy-ly, cz-lz );
  glVertex3f(  cx+lx, cy-ly,  cz+lz );
  glVertex3f( cx-lx, cy-ly,  cz+lz );
  glVertex3f( cx-lx, cy-ly, cz-lz );
  glEnd();

}


void displayhero(){
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
  	glLoadIdentity();
	glRotatef( rotate_x, 1.0, 0.0, 0.0 );
	glRotatef( rotate_y, 0.0, 1.0, 0.0 );
	glScalef(1,1,1);
	face(0,0,0,0.35,0.25,0.3);
	hair(0,0.3,0,0.4,0.15,0.4);
	eye(-0.2,0.1,-0.325,0.05,0.03,0.0125);	
	eye(0.2,0.1,-0.325,0.05,0.03,0.0125);	
	/*for(int i=1;i<=hori;i++){
		for(int j=1;j<verti;j++){
			if(ARENA.block(i,j).empty){
			}
			else{
				if(ARENA.block(i,j).destructible){
					destructibles(i-9,6-j,0,0.45,0.45,0.45);
				}
				else
					undestructibles(i-9,6-j,0);
			}
		}
	}
	base(0,0,0.7,8.5,5.5,0.2);
	borders(0,5.6,0.5,8.5,0.1,0.2);
	borders(0,-5.6,0.5,8.5,0.1,0.2);
	borders(8.6,0,0.5,0.1,5.5,0.2);
	borders(-8.6,0,0.5,0.1,5.5,0.2);*/

	glFlush();
	glutSwapBuffers(); 
}


void specialKeys( int key, int x, int y ) {
 
  //  Right arrow - increase rotation by 5 degree
  if (key == GLUT_KEY_RIGHT)
    rotate_y += 5;
 
  //  Left arrow - decrease rotation by 5 degree
  else if (key == GLUT_KEY_LEFT)
    rotate_y -= 5;
 
  else if (key == GLUT_KEY_UP)
    rotate_x += 5;
 
  else if (key == GLUT_KEY_DOWN)
    rotate_x -= 5;
 
  //  Request display update
  glutPostRedisplay();
 
}

int main(int argc, char* argv[]){
 
  //  Initialize GLUT and process user parameters
  glutInit(&argc,argv);
 
  //  Request double buffered true color window with Z-buffer
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
   // Create window
  glutInitWindowSize(700,700);
  glutInitWindowPosition(100,100);
  glutCreateWindow("cube");
 
  //  Enable Z-buffer depth test
  glEnable(GL_DEPTH_TEST);
 
  // Callback functions
  glutDisplayFunc(displayhero);
  glutSpecialFunc(specialKeys);
 
  //  Pass control to GLUT for events
  glutMainLoop();
 
  //  Return to OS
  return 0;
 
}
