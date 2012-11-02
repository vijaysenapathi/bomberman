#include<iostream>
#include<GL/glu.h>
#include<GL/freeglut.h>
#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#include "grid.h"
#include "hero.h"

using namespace std;

double rotate_z=0; 
double rotate_x=0;
double heroXpos=-8; 
double heroYpos=5;
int heroDirection=0;

void display();
void specialKeys();

grid ARENA;
int hori=17,verti=11;

void undestructibles(float cx,float cy, float cz ){

  /*glBegin(GL_POLYGON);
 
  glColor3f( 1.0, 0.0, 0.0 );     glVertex3f(  cx+0.5, cy-0.5, cz-0.5 );      // P1 is red
  glColor3f( 0.0, 1.0, 0.0 );     glVertex3f(  cx+0.5, cy+ 0.5, cz-0.5 );      // P2 is green
  glColor3f( 0.0, 0.0, 1.0 );     glVertex3f( cx-0.5,  cy+0.5, cz-0.5 );      // P3 is blue
  glColor3f( 1.0, 0.0, 1.0 );     glVertex3f( cx-0.5, cy-0.5, cz-0.5 );      // P4 is purple
 
  glEnd();*/

  //Yellow size-FRONT
  glBegin(GL_POLYGON);
  glColor3f(   0,  (100.0/255.0), 0 );
  glVertex3f(  cx+0.5, cy-0.5, cz-0.5 );
  glVertex3f(  cx+0.5,  cy+0.5, cz-0.5 );
  glVertex3f( cx-0.5,  cy+0.5, cz-0.5 );
  glVertex3f( cx-0.5, cy-0.5, cz-0.5 );
  glEnd();

 
  // White side - BACK
  glBegin(GL_POLYGON);
  glColor3f(   1.0,  1.0, 1.0 );
  glVertex3f(  cx+0.5, cy-0.5, cz+0.5 );
  glVertex3f(  cx+0.5,  cy+0.5, cz+0.5 );
  glVertex3f( cx-0.5,  cy+0.5, cz+0.5 );
  glVertex3f( cx-0.5, cy-0.5, cz+0.5 );
  glEnd();
 
 
  // Purple side - RIGHT
  glBegin(GL_POLYGON);
  glColor3f(  0.0,  1.0,  0.0 );
  glVertex3f( cx+0.5, cy-0.5, cz-0.5 );
  glVertex3f( cx+0.5,  cy+0.5, cz-0.5 );
  glVertex3f( cx+0.5,  cy+0.5,  cz+0.5 );
  glVertex3f( cx+0.5, cy-0.5,  cz+0.5 );
  glEnd();
 
 
  // Green side - LEFT
  glBegin(GL_POLYGON);
  glColor3f(   0.0,  1.0,  0.0 );
  glVertex3f( cx-0.5, cy-0.5,  cz+0.5 );
  glVertex3f( cx-0.5,  cy+0.5,  cz+0.5 );
  glVertex3f( cx-0.5,  cy+0.5, cz-0.5 );
  glVertex3f( cx-0.5, cy-0.5, cz-0.5 );
  glEnd();
 
  // Blue side - TOP
  glBegin(GL_POLYGON);
  glColor3f(   0.0,  (205.0/255.0),  0 );
  glVertex3f(  cx+0.5,  cy+0.5,  cz+0.5 );
  glVertex3f(  cx+0.5,  cy+0.5, cz-0.5 );
  glVertex3f( cx-0.5,  cy+0.5, cz-0.5 );
  glVertex3f( cx-0.5,  cy+0.5,  cz+0.5 );
  glEnd();
 
  // Red side - BOTTOM
  glBegin(GL_POLYGON);
  glColor3f(   0.0,  (205.0/255.0),  0.0 );
  glVertex3f(  cx+0.5, cy-0.5, cz-0.5 );
  glVertex3f(  cx+0.5, cy-0.5,  cz+0.5 );
  glVertex3f( cx-0.5, cy-0.5,  cz+0.5 );
  glVertex3f( cx-0.5, cy-0.5, cz-0.5 );
  glEnd();

}

void base(float cx,float cy, float cz ,float lx,float ly,float lz){

  //Yellow size-FRONT
  glBegin(GL_POLYGON);
  glColor3f(   1.0,  1.0, 0 );
  glVertex3f(  cx+lx, cy-ly, cz-lz );
  glVertex3f(  cx+lx,  cy+ly, cz-lz );
  glVertex3f( cx-lx,  cy+ly, cz-lz );
  glVertex3f( cx-lx, cy-ly, cz-lz );
  glEnd();

 
  // White side - BACK
  glBegin(GL_POLYGON);
  glColor3f(   1.0,  1.0, 0 );
  glVertex3f(  cx+lx, cy-ly, cz+lz );
  glVertex3f(  cx+lx,  cy+ly, cz+lz );
  glVertex3f( cx-lx,  cy+ly, cz+lz );
  glVertex3f( cx-lx, cy-ly, cz+lz );
  glEnd();
 
 
  // Purple side - RIGHT
  glBegin(GL_POLYGON);
  glColor3f(  1.0,  0.0,  0.0 );
  glVertex3f( cx+lx, cy-ly, cz-lz );
  glVertex3f( cx+lx,  cy+ly, cz-lz );
  glVertex3f( cx+lx,  cy+ly,  cz+lz );
  glVertex3f( cx+lx, cy-ly,  cz+lz );
  glEnd();
 
 
  // Green side - LEFT
  glBegin(GL_POLYGON);
  glColor3f(   1.0,  0.0,  0.0 );
  glVertex3f( cx-lx, cy-ly,  cz+lz );
  glVertex3f( cx-lx,  cy+ly,  cz+lz );
  glVertex3f( cx-lx,  cy+ly, cz-lz );
  glVertex3f( cx-lx, cy-ly, cz-lz );
  glEnd();
 
  // Blue side - TOP
  glBegin(GL_POLYGON);
  glColor3f(   (205.0/255.0),  0.0,  0.0 );
  glVertex3f(  cx+lx,  cy+ly,  cz+lz );
  glVertex3f(  cx+lx,  cy+ly, cz-lz );
  glVertex3f( cx-lx,  cy+ly, cz-lz );
  glVertex3f( cx-lx,  cy+ly,  cz+lz );
  glEnd();
 
  // Red side - BOTTOM
  glBegin(GL_POLYGON);
  glColor3f(   (205.0/255.0),  0.0,  0.0 );
  glVertex3f(  cx+lx, cy-ly, cz-lz );
  glVertex3f(  cx+lx, cy-ly,  cz+lz );
  glVertex3f( cx-lx, cy-ly,  cz+lz );
  glVertex3f( cx-lx, cy-ly, cz-lz );
  glEnd();

}

void borders(float cx,float cy, float cz ,float lx,float ly,float lz){

  //Yellow size-FRONT
  glBegin(GL_POLYGON);
  glColor4f(   0.0,  0.0, 1.0 ,0.1);
  glVertex3f(  cx+lx, cy-ly, cz-lz );
  glVertex3f(  cx+lx,  cy+ly, cz-lz );
  glVertex3f( cx-lx,  cy+ly, cz-lz );
  glVertex3f( cx-lx, cy-ly, cz-lz );
  glEnd();

 
  // White side - BACK
  glBegin(GL_POLYGON);
  glColor4f(   0,  0, 1.0,0.1 );
  glVertex3f(  cx+lx, cy-ly, cz+lz );
  glVertex3f(  cx+lx,  cy+ly, cz+lz );
  glVertex3f( cx-lx,  cy+ly, cz+lz );
  glVertex3f( cx-lx, cy-ly, cz+lz );
  glEnd();
 
 
  // Purple side - RIGHT
  glBegin(GL_POLYGON);
  glColor4f(  (65.0/255.0),  (105.0/255.0),  (225.0/255.0),0.1 );
  glVertex3f( cx+lx, cy-ly, cz-lz );
  glVertex3f( cx+lx,  cy+ly, cz-lz );
  glVertex3f( cx+lx,  cy+ly,  cz+lz );
  glVertex3f( cx+lx, cy-ly,  cz+lz );
  glEnd();
 
 
  // Green side - LEFT
  glBegin(GL_POLYGON);
  glColor4f(   (65.0/255.0),  (105.0/255.0),  (225.0/255.0) ,0.1);
  glVertex3f( cx-lx, cy-ly,  cz+lz );
  glVertex3f( cx-lx,  cy+ly,  cz+lz );
  glVertex3f( cx-lx,  cy+ly, cz-lz );
  glVertex3f( cx-lx, cy-ly, cz-lz );
  glEnd();
 
  // Blue side - TOP
  glBegin(GL_POLYGON);
  glColor4f(   (65.0/255.0),  (105.0/255.0),  (225./255.0) ,0.1);
  glVertex3f(  cx+lx,  cy+ly,  cz+lz );
  glVertex3f(  cx+lx,  cy+ly, cz-lz );
  glVertex3f( cx-lx,  cy+ly, cz-lz );
  glVertex3f( cx-lx,  cy+ly,  cz+lz );
  glEnd();
 
  // Red side - BOTTOM
  glBegin(GL_POLYGON);
  glColor4f(   (65.0/255.0),  (105.0/255.0),  (225.0/255.0),0.1 );
  glVertex3f(  cx+lx, cy-ly, cz-lz );
  glVertex3f(  cx+lx, cy-ly,  cz+lz );
  glVertex3f( cx-lx, cy-ly,  cz+lz );
  glVertex3f( cx-lx, cy-ly, cz-lz );
  glEnd();

}
void destructibles(float cx,float cy, float cz ,float lx,float ly,float lz){

  //Yellow size-FRONT
  glBegin(GL_POLYGON);
  glColor3f(   1.0,  (165.0/255.0), 0 );
  glVertex3f(  cx+lx, cy-ly, cz-lz );
  glVertex3f(  cx+lx,  cy+ly, cz-lz );
  glVertex3f( cx-lx,  cy+ly, cz-lz );
  glVertex3f( cx-lx, cy-ly, cz-lz );
  glEnd();

 
  // White side - BACK
  glBegin(GL_POLYGON);
  glColor3f(   1.0,  1.0, 0 );
  glVertex3f(  cx+lx, cy-ly, cz+lz );
  glVertex3f(  cx+lx,  cy+ly, cz+lz );
  glVertex3f( cx-lx,  cy+ly, cz+lz );
  glVertex3f( cx-lx, cy-ly, cz+lz );
  glEnd();
 
 
  // Purple side - RIGHT
  glBegin(GL_POLYGON);
  glColor3f(  (205.0/255.0),  (133.0/255.0),  0.0 );
  glVertex3f( cx+lx, cy-ly, cz-lz );
  glVertex3f( cx+lx,  cy+ly, cz-lz );
  glVertex3f( cx+lx,  cy+ly,  cz+lz );
  glVertex3f( cx+lx, cy-ly,  cz+lz );
  glEnd();
 
 
  // Green side - LEFT
  glBegin(GL_POLYGON);
  glColor3f(   (205.0/255.0),  (133.0/255.0),  0.0 );
  glVertex3f( cx-lx, cy-ly,  cz+lz );
  glVertex3f( cx-lx,  cy+ly,  cz+lz );
  glVertex3f( cx-lx,  cy+ly, cz-lz );
  glVertex3f( cx-lx, cy-ly, cz-lz );
  glEnd();
 
  // Blue side - TOP
  glBegin(GL_POLYGON);
  glColor3f(   (238.0/255.0),  (154.0/255.0),  0.0 );
  glVertex3f(  cx+lx,  cy+ly,  cz+lz );
  glVertex3f(  cx+lx,  cy+ly, cz-lz );
  glVertex3f( cx-lx,  cy+ly, cz-lz );
  glVertex3f( cx-lx,  cy+ly,  cz+lz );
  glEnd();
 
  // Red side - BOTTOM
  glBegin(GL_POLYGON);
  glColor3f(   (238.0/255.0),  (154.0/255.0),  0.0 );
  glVertex3f(  cx+lx, cy-ly, cz-lz );
  glVertex3f(  cx+lx, cy-ly,  cz+lz );
  glVertex3f( cx-lx, cy-ly,  cz+lz );
  glVertex3f( cx-lx, cy-ly, cz-lz );
  glEnd();

}
 
void display(){
	glEnable(GL_POINT_SMOOTH | GL_LINE_SMOOTH | GL_POLYGON_SMOOTH);
	glClearColor((176.0/255.0),(226.0/255.0),1,1);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
  	glLoadIdentity();
	gluLookAt(0,0,0,0,0,-5,0,1,0); 
	glFrustum(-10,10,6,-6,-5,10);
	glRotatef( rotate_x, 1.0, 0.0, 0.0 );
	glRotatef( rotate_z, 0.0, 0.0, 1.0 );
	glScalef(0.1,0.1,0.1);
	for(int i=1;i<=hori;i++){
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
	borders(-8.6,0,0.5,0.1,5.5,0.2);
	//glLoadIdentity();
	glTranslatef(heroXpos,heroYpos,-1.34);
	glRotatef(90*heroDirection,0,0,1);
	hero();
	glFlush();
	glutSwapBuffers(); 
}


void specialKeys( int key, int x, int y ) {
 
  //  Right arrow - increase rotation by 5 degree
  
	
	
	
	if (key == GLUT_KEY_RIGHT)
    rotate_z += 5;
 
  //  Left arrow - decrease rotation by 5 degree
  else if (key == GLUT_KEY_LEFT)
    rotate_z -= 5;
 
  else if (key == GLUT_KEY_UP)
    rotate_x += 5;
 
  else if (key == GLUT_KEY_DOWN)
    rotate_x -= 5;
 
  //  Request display update
  glutPostRedisplay();
 
}

int myFloor(double x){
	if((x-floor(x)) == 0){
		return x-1;
	}
	else{
		return floor(x);
	}
}

bool collisionDetection(double xcor, double ycor,int dir){
	int i,j;
	switch (dir){
		case 0:
			i=9+myFloor(xcor+0.5);
			j=7-myFloor(0.5+ycor);
			break;
		case 1:
			i=10+myFloor(0.5+xcor);
			j=6-myFloor(0.5+ycor);
			break;
		case 2:
			i=9+myFloor(0.5+xcor);
			j=5-myFloor(0.5+ycor);
			break;
		case 3:
			i=8+myFloor(0.5+xcor);
			j=6-myFloor(0.5+ycor);
			break;
	}
	//cout<<" "<<i<<"   "<<xpos<<" "<<j<<endl;
	return ARENA.block(i,j).empty;
}

void keyboardKeys(unsigned char key, int x, int y){
	switch (key){
		case 'w':
			if(heroYpos < 5.0 && (collisionDetection(heroXpos,heroYpos,2))){
				heroYpos+=0.1;
			}
			heroDirection=2;
			break;
		case 'a':
			if(heroXpos > -8 && (collisionDetection(heroXpos,heroYpos,3))){
				heroXpos-=0.1;
			}
			heroDirection=3;
			break;
		case 's':
			if(heroYpos > -5.0 && (collisionDetection(heroXpos,heroYpos,0))){
				heroYpos-=0.1;
			}
			heroDirection=0;
		break;
		case 'd':
			if(heroXpos < 8 && (collisionDetection(heroXpos,heroYpos,1))){
				heroXpos+=0.1;
			}
			heroDirection=1;
			break;
	}
	switch (key){
		case 'l':
			rotate_z+=5;
			break;
		case 'j':
			rotate_z-=5;
			break;
		case 'i':
			rotate_x+=5;
			break;
		case 'k':
			rotate_x-=5;
			break;
	}
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
  glutCreateWindow("Arena");
 
  //  Enable Z-buffer depth test
  glEnable(GL_DEPTH_TEST);
 
  // Callback functions
  glutDisplayFunc(display);
  glutKeyboardFunc(keyboardKeys);
  // glutSpecialFunc(specialKeys);
 
  //  Pass control to GLUT for events
  glutMainLoop();
 
  //  Return to OS
  return 0;
 
}
