#ifndef BOMB_H
#define BOMB_H

#include<iostream>
#include<GL/glu.h>
#include<GL/freeglut.h>
#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#include "grid.h"

//using namespace std;

double rotate_y=0; 
double rotate_x=0;

int bombID=3;

class bombs{
	public:
		float timeToBlast;
		int Xpos,Ypos;
		int ID;
		bombs(){

		}
		bombs(int i,int j,float time){
			Xpos=i;
			Ypos=j;
			timeToBlast=time;
			ID=bombID++;
		}
};

bool operator< (const bombs& b1, const bombs& b2){
	return b1.timeToBlast > b2.timeToBlast;
}


void chemical(float cx,float cy, float cz ,float lx,float ly,float lz){

  //Yellow size-FRONT
  glBegin(GL_POLYGON);
  glColor3f(   1, 0,0);
  glVertex3f(  cx+lx, cy-ly, cz-lz );
  glVertex3f(  cx+lx,  cy+ly, cz-lz );
  glVertex3f( cx-lx,  cy+ly, cz-lz );
  glVertex3f( cx-lx, cy-ly, cz-lz );
  glEnd();

 
  // White side - BACK
  glBegin(GL_POLYGON);
  glColor3f(   1, 0,0 );
  glVertex3f(  cx+lx, cy-ly, cz+lz );
  glVertex3f(  cx+lx,  cy+ly, cz+lz );
  glVertex3f( cx-lx,  cy+ly, cz+lz );
  glVertex3f( cx-lx, cy-ly, cz+lz );
  glEnd();
 
 
  // Purple side - RIGHT
  glBegin(GL_POLYGON);
  glColor3f(  (238.0/255.0), 0, 0 );
  glVertex3f( cx+lx, cy-ly, cz-lz );
  glVertex3f( cx+lx,  cy+ly, cz-lz );
  glVertex3f( cx+lx,  cy+ly,  cz+lz );
  glVertex3f( cx+lx, cy-ly,  cz+lz );
  glEnd();
 
 
  // Green side - LEFT
  glBegin(GL_POLYGON);
  glColor3f(   (238.0/255.0),0,  0 );
  glVertex3f( cx-lx, cy-ly,  cz+lz );
  glVertex3f( cx-lx,  cy+ly,  cz+lz );
  glVertex3f( cx-lx,  cy+ly, cz-lz );
  glVertex3f( cx-lx, cy-ly, cz-lz );
  glEnd();
 
  // Blue side - TOP
  glBegin(GL_POLYGON);
  glColor3f(   (205.0/255.0),  0,  0);
  glVertex3f(  cx+lx,  cy+ly,  cz+lz );
  glVertex3f(  cx+lx,  cy+ly, cz-lz );
  glVertex3f( cx-lx,  cy+ly, cz-lz );
  glVertex3f( cx-lx,  cy+ly,  cz+lz );
  glEnd();
 
  // Red side - BOTTOM
  glBegin(GL_POLYGON);
  glColor3f(   (205.0/255.0), 0, 0 );
  glVertex3f(  cx+lx, cy-ly, cz-lz );
  glVertex3f(  cx+lx, cy-ly,  cz+lz );
  glVertex3f( cx-lx, cy-ly,  cz+lz );
  glVertex3f( cx-lx, cy-ly, cz-lz );
  glEnd();

}

void wire(float cx,float cy, float cz ,float lx,float ly,float lz){

  //Yellow size-FRONT
  glBegin(GL_POLYGON);
  glColor3f(   0.0,  0.0, 1.0 );
  glVertex3f(  cx+lx, cy-ly, cz-lz );
  glVertex3f(  cx+lx,  cy+ly, cz-lz );
  glVertex3f( cx-lx,  cy+ly, cz-lz );
  glVertex3f( cx-lx, cy-ly, cz-lz );
  glEnd();

 
  // White side - BACK
  glBegin(GL_POLYGON);
  glColor3f(   0,  0, 1.0 );
  glVertex3f(  cx+lx, cy-ly, cz+lz );
  glVertex3f(  cx+lx,  cy+ly, cz+lz );
  glVertex3f( cx-lx,  cy+ly, cz+lz );
  glVertex3f( cx-lx, cy-ly, cz+lz );
  glEnd();
 
 
  // Purple side - RIGHT
  glBegin(GL_POLYGON);
  glColor3f(  (65.0/255.0),  (105.0/255.0),  (225.0/255.0) );
  glVertex3f( cx+lx, cy-ly, cz-lz );
  glVertex3f( cx+lx,  cy+ly, cz-lz );
  glVertex3f( cx+lx,  cy+ly,  cz+lz );
  glVertex3f( cx+lx, cy-ly,  cz+lz );
  glEnd();
 
 
  // Green side - LEFT
  glBegin(GL_POLYGON);
  glColor3f(   (65.0/255.0),  (105.0/255.0),  (225.0/255.0) );
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
  glColor3f(   (65.0/255.0),  (105.0/255.0),  (225.0/255.0) );
  glVertex3f(  cx+lx, cy-ly, cz-lz );
  glVertex3f(  cx+lx, cy-ly,  cz+lz );
  glVertex3f( cx-lx, cy-ly,  cz+lz );
  glVertex3f( cx-lx, cy-ly, cz-lz );
  glEnd();

}



void displaybomb(){
	//glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
  	//glLoadIdentity();
	chemical(0,0,0,0.25,0.25,0.25);
	/*wire(0.15,0,0.26,0.025,0.25,0.01);
	wire(-0.15,0,0.26,0.025,0.25,0.01);
	wire(0.15,0,-0.26,0.025,0.25,0.01);
	wire(-0.15,0,-0.26,0.025,0.25,0.01);
	wire(0.26,0,0.15,0.025,0.25,0.01);
	wire(-0.26,0,0.15,0.025,0.25,0.01);
	wire(-0.26,0,-0.15,0.025,0.25,0.01);
	wire(0.26,0,-0.15,0.025,0.25,0.01);
	wire(0.15,0,0.26,0.025,0.25,0.01);
	wire(0.15,0,0.26,0.025,0.25,0.01);
	wire(0.15,0,0.26,0.025,0.25,0.01);
	wire(0.15,0,0.26,0.025,0.25,0.01);
	glFlush();
	glutSwapBuffers();*/
}

#endif
