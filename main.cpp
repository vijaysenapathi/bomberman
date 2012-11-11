#include<iostream>
#include<GL/glu.h>
#include<GL/freeglut.h>
#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#include "grid.h"
#include "hero.h"

using namespace std;

/*double rotate_z=0; 
double rotate_x=0;
double heroXpos=-8; 
double heroYpos=5;
int heroDirection=0;*/
heros neo;//the name of the player is neo

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
	glRotatef(neo.rotate_x, 1.0, 0.0, 0.0 );
	glRotatef(neo.rotate_z, 0.0, 0.0, 1.0 );
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
	glTranslatef(neo.heroXpos,neo.heroYpos,-1.34);
	glRotatef(90*(neo.heroDirection),0,0,1);
	neo.displayhero();
	glFlush();
	glutSwapBuffers(); 
}


void specialKeys( int key, int x, int y ) {
	//  Right arrow - increase rotation by 5 degree	
	if (key == GLUT_KEY_RIGHT)
		neo.rotate_z += 5;
 
  //  Left arrow - decrease rotation by 5 degree
  else if (key == GLUT_KEY_LEFT)
    neo.rotate_z -= 5;
 
  else if (key == GLUT_KEY_UP)
    neo.rotate_x += 5;
 
  else if (key == GLUT_KEY_DOWN)
    neo.rotate_x -= 5;
 
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

float fracpart(float x){
	return (x-floor(x));
}

bool collisionDetection(double xcor, double ycor){
	float xr=xcor+0.29,xl=xcor-0.29;
	float yu=ycor+0.29,yd=ycor-0.29;
	int i0,i1,i2,i3,j0,j1,j2,j3;
	i0=9+floor(xcor+0.5);j0=6-floor(yd+0.5);
	i1=9+floor(xr+0.5);j1=6-floor(ycor+0.5);
	i2=9+floor(xcor+0.5);j2=6-floor(yu+0.5);
	i3=9+floor(xl+0.5);j3=6-floor(ycor+0.5);
	return (ARENA.block(i0,j0).empty 
			&& ARENA.block(i1,j1).empty 
			&& ARENA.block(i2,j2).empty 
			&& ARENA.block(i3,j3).empty);
}

void movingLimbs(heros &hero){//a function for implementing the animation of walking of the players
	if(hero.legdisp >= MAX_FOOT_DISTANCE && hero.rightLeg){
		hero.rightLeg=false;
	}
	else if(hero.legdisp <= -(MAX_FOOT_DISTANCE) && !(hero.rightLeg)){
		hero.rightLeg=true;
	}
	else{
		if(hero.rightLeg){
			hero.legdisp+=0.2;
		}
		else{
			hero.legdisp-=0.2;
		}
	}

}

void keyboardKeys(unsigned char key, int x, int y){
	float dummyX,dummyY;
	switch (key){
		case 'w':
			dummyX=neo.heroXpos;
			dummyY=neo.heroYpos;
			dummyY+=neo.speed;
			if(neo.heroYpos < 5.0 && (collisionDetection(dummyX,dummyY))){
				neo.heroYpos+=neo.speed;
			}
			neo.heroDirection=2;
			if(neo.heroDirection != neo.heroPrevDirection){
				neo.legdisp=0;
				neo.heroPrevDirection=neo.heroDirection;
			}
			movingLimbs(neo);
			break;
		case 'a':
			dummyX=neo.heroXpos;
			dummyY=neo.heroYpos;
			dummyX-=neo.speed;
			if(neo.heroXpos > -8 && (collisionDetection(dummyX,dummyY))){
				neo.heroXpos-=neo.speed;
			}
			neo.heroDirection=3;
			if(neo.heroDirection != neo.heroPrevDirection){
				neo.legdisp=0;
				neo.heroPrevDirection=neo.heroDirection;
			}
			movingLimbs(neo);
			break;
		case 's':
			dummyX=neo.heroXpos;
			dummyY=neo.heroYpos;
			dummyY-=neo.speed;
			if(neo.heroYpos > -5.0 && (collisionDetection(dummyX,dummyY))){
				neo.heroYpos-=neo.speed;
			}
			neo.heroDirection=0;
			if(neo.heroDirection != neo.heroPrevDirection){
				neo.legdisp=0;
				neo.heroPrevDirection=neo.heroDirection;
			}
			movingLimbs(neo);
			break;
		case 'd':
			dummyX=neo.heroXpos;
			dummyY=neo.heroYpos;
			dummyX+=neo.speed;
			if(neo.heroXpos < 8 && (collisionDetection(dummyX,dummyY))){
				neo.heroXpos+=neo.speed;
			}
			neo.heroDirection=1;
			if(neo.heroDirection != neo.heroPrevDirection){
				neo.legdisp=0;
				neo.heroPrevDirection=neo.heroDirection;
			}
			movingLimbs(neo);
			break;
	}

	switch (key){
		case 'l':
			neo.rotate_z+=5;
			break;
		case 'j':
			neo.rotate_z-=5;
			break;
		case 'i':
			neo.rotate_x+=5;
			break;
		case 'k':
			neo.rotate_x-=5;
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
  glutSpecialFunc(specialKeys);
 
  //  Pass control to GLUT for events
  glutMainLoop();
 
  //  Return to OS
  return 0;
 
}
