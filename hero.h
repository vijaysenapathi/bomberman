#include<iostream>
#include<GL/glu.h>
#include<GL/freeglut.h>
#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#include "grid.h"

using namespace std;

void limbs(float  cx,float cy, float cz ,float lx,float ly,float lz,float disp,float colors[]);

void cuboid(float cx,float cy, float cz ,float lx,float ly,float lz,float colors[]){

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
 
void hero(){
 	//glTranslatef(0,5,0);
	glRotatef(90,-1,0,0);
	glScalef(0.2,0.2,0.2);
	float face[9]={255,236,139,238,220,130,240,230,140};//colors for face
	cuboid(0,0,0,1,0.7,1,face);
	float capmain[9]={65,105,225,72,118,255,58,95,205};
	cuboid(0,1.05,0,1.2,0.35,1.2,capmain);
	float capfront[9]={65,105,225,58,95,205,72,118,255};
	cuboid(0,0.75,-1.5,1,0.05,0.3,capfront);
	float eyes[9]={255,255,255,255,255,255,255,255,255};
	cuboid(-0.5,0.3875,-1.025,0.075,0.0875,0.035,eyes);
	cuboid(0.5,0.3875,-1.025,0.075,0.0875,0.035,eyes);
	float eyeball[9]={70,130,180,99,184,255,92,172,238};
	cuboid(-0.5,0.2125,-1.025,0.075,0.0875,0.035,eyeball);
	cuboid(0.5,0.2125,-1.025,0.075,0.0875,0.035,eyeball);
	float mouth[9]={255,127,0,238,118,0,205,102,0};
	cuboid(0,-0.4,-1.025,0.350,0.035,0.035,mouth);
	float neck[9]={240,230,140,238,230,133,255,236,139};
	cuboid(0,-0.8,0,0.75,0.1,0.75,neck);
	float shirt[9]={255,48,48,205,38,38,238,44,44};
	cuboid(0,-2.8,0,2,1.9,0.8,shirt);//stomach
	cuboid(-2.375,-1.6,0,0.375,0.7,0.6,shirt);//left shoulder
	cuboid(2.375,-1.6,0,0.375,0.7,0.6,shirt);//right shoulder
	cuboid(2.375,-3.2,0,0.3,0.9,0.4,face);//left hand
	cuboid(-2.375,-3.2,0,0.3,0.9,0.4,face);//right hand
	cuboid(-2.375,-4.4,0,0.35,0.3,0.5,neck);//left palm
	cuboid(2.375,-4.4,0,0.35,0.3,0.5,neck);//right palm
	cuboid(0,-5.2,0,2,0.5,0.8,capmain);//upper pant
	cuboid(-1,-7,0,0.9,1.4,0.8,capmain);//left leg
	cuboid(1,-7,0,0.9,1.4,0.8,capmain);//right leg
	float shoes[9]={199,97,20,210,105,30,255,127,36};
	cuboid(-1,-8.8,-0.3,0.9,0.4,1.0,shoes);//left shoe	
	cuboid(1,-8.8,-0.3,0.9,0.4,1.0,shoes);//right shoe	
}
 
void limbs(float  cx,float cy, float cz ,float lx,float ly,float lz,float disp,float colors[]){
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
