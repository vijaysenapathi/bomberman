#ifndef POWERUPS_H
#define POWERUPS_H
#include<iostream>
#include<GL/glu.h>
#include<GL/freeglut.h>
#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#include "grid.h"

void cuboidfunc(float cx,float cy, float cz ,float lx,float ly,float lz,float colors[]){

  //FRONT
  glBegin(GL_POLYGON);
  glColor3f(   (colors[0]/255.0),  (colors[1]/255.0), (colors[2]/255.0));
  glVertex3f(  cx+lx, cy-ly, cz-lz );
  glVertex3f(  cx+lx,  cy+ly, cz-lz );
  glVertex3f( cx-lx,  cy+ly, cz-lz );
  glVertex3f( cx-lx, cy-ly, cz-lz );
  glEnd();

 
  //BACK
  glBegin(GL_POLYGON);
  glColor3f(   (colors[0]/255.0),  (colors[1]/255.0), (colors[2]/255.0));
  glVertex3f(  cx+lx, cy-ly, cz+lz );
  glVertex3f(  cx+lx,  cy+ly, cz+lz );
  glVertex3f( cx-lx,  cy+ly, cz+lz );
  glVertex3f( cx-lx, cy-ly, cz+lz );
  glEnd();
 
 
  //RIGHT
  glBegin(GL_POLYGON);
  glColor3f(   (colors[3]/255.0),  (colors[4]/255.0), (colors[5]/255.0));
  glVertex3f( cx+lx, cy-ly, cz-lz );
  glVertex3f( cx+lx,  cy+ly, cz-lz );
  glVertex3f( cx+lx,  cy+ly,  cz+lz );
  glVertex3f( cx+lx, cy-ly,  cz+lz );
  glEnd();
 
 
  //LEFT
  glBegin(GL_POLYGON);
  glColor3f(   (colors[3]/255.0),  (colors[4]/255.0), (colors[5]/255.0));
  glVertex3f( cx-lx, cy-ly,  cz+lz );
  glVertex3f( cx-lx,  cy+ly,  cz+lz );
  glVertex3f( cx-lx,  cy+ly, cz-lz );
  glVertex3f( cx-lx, cy-ly, cz-lz );
  glEnd();
 
  //TOP
  glBegin(GL_POLYGON);
  glColor3f(   (colors[6]/255.0),  (colors[7]/255.0), (colors[8]/255.0));
  glVertex3f(  cx+lx,  cy+ly,  cz+lz );
  glVertex3f(  cx+lx,  cy+ly, cz-lz );
  glVertex3f( cx-lx,  cy+ly, cz-lz );
  glVertex3f( cx-lx,  cy+ly,  cz+lz );
  glEnd();
 
  //BOTTOM
  glBegin(GL_POLYGON);
  glColor3f(   (colors[6]/255.0),  (colors[7]/255.0), (colors[8]/255.0));
  glVertex3f(  cx+lx, cy-ly, cz-lz );
  glVertex3f(  cx+lx, cy-ly,  cz+lz );
  glVertex3f( cx-lx, cy-ly,  cz+lz );
  glVertex3f( cx-lx, cy-ly, cz-lz );
  glEnd();

}

void displaypowerup(){
	glPushMatrix();
	glScalef(0.4,0.4,0.4);
	float colors[9]={218,112,214,255,131,250,238,122,233};
	cuboidfunc(0,0,0,1,1,1,colors);
	float upperpart[]={255,255,255,255,255,255,255,255,255};
	cuboidfunc(0.4,0,-1.3,0.3,0.3,0.2,upperpart);
	cuboidfunc(-0.4,0,-1.3,0.3,0.3,0.2,upperpart);
	cuboidfunc(0,0,-1.3,0.1,0.1,0.2,upperpart);
	glPopMatrix();
}

void displaypowerup(int i){
	if(i == 4){//infinite bombs
		glPushMatrix();
		glScalef(0.4,0.4,0.4);
		float colors[9]={218,112,214,255,131,250,238,122,233};
		cuboidfunc(0,0,0,1,1,1,colors);
		float upperpart[]={255,255,255,255,255,255,255,255,255};
		cuboidfunc(0.4,0,-1.3,0.3,0.3,0.2,upperpart);
		cuboidfunc(-0.4,0,-1.3,0.3,0.3,0.2,upperpart);
		cuboidfunc(0,0,-1.3,0.1,0.1,0.2,upperpart);
		glPopMatrix();
	}
	else if(i == 3){//increase player speed
		glPushMatrix();
		glScalef(0.4,0.4,0.4);
		float colors[9]={218,112,214,255,131,250,238,122,233};
		cuboidfunc(0,0,0,1,1,1,colors);
		float upperpart[]={255,255,255,255,255,255,255,255,255};
		cuboidfunc(0.4,-0.3,-1.3,0.2,0.5,0.2,upperpart);
		cuboidfunc(-0.4,-0.3,-1.3,0.2,0.5,0.2,upperpart);
		cuboidfunc(0,0.3,-1.3,0.2,0.5,0.2,upperpart);
		glPopMatrix();
	}
	else if(i == 5){//invincibility to bombs
		glPushMatrix();
		glScalef(0.4,0.4,0.4);
		float colors[9]={218,112,214,255,131,250,238,122,233};
		cuboidfunc(0,0,0,1,1,1,colors);
		float upperpart[]={255,255,255,255,255,255,255,255,255};
		glPushMatrix();
		glRotatef(45,0,0,1);
		cuboidfunc(0,0,-1.3,0.5,0.5,0.2,upperpart);
		glPopMatrix();
		glPopMatrix();
	}
	else if(i == 2){//the exit
		glPushMatrix();
		glScalef(0.4,0.4,0.4);
		float colors[9]={218,112,214,255,131,250,238,122,233};
		cuboidfunc(0,0,0,1,1,1,colors);
		float upperpart[]={255,255,255,255,255,255,255,255,255};
		cuboidfunc(0,0,-1.3,0.9,0.1,0.2,upperpart);
		cuboidfunc(0,0.3,-1.3,0.9,0.1,0.2,upperpart);
		cuboidfunc(0,-0.3,-1.3,0.9,0.1,0.2,upperpart);
		glPushMatrix();
		glRotatef(90,0,0,1);
		cuboidfunc(0,0,-1.3,0.9,0.1,0.2,upperpart);
		cuboidfunc(0,0.3,-1.3,0.9,0.1,0.2,upperpart);
		cuboidfunc(0,-0.3,-1.3,0.9,0.1,0.2,upperpart);
		glPopMatrix();
		glPopMatrix();
	}
}

#endif
