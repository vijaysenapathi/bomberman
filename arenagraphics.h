#ifndef ARENAGRAPHICS_H
#define ARENAGRAPHICS_H
#include<GL/glu.h>
#include<GL/freeglut.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/*describing the geometry of undestructable blocks*/
void undestructibles(float cx,float cy, float cz ){

  //FRONT
  glBegin(GL_POLYGON);
  glColor3f(   0,  (100.0/255.0), 0 );
  glVertex3f(  cx+0.5, cy-0.5, cz-0.5 );
  glVertex3f(  cx+0.5,  cy+0.5, cz-0.5 );
  glVertex3f( cx-0.5,  cy+0.5, cz-0.5 );
  glVertex3f( cx-0.5, cy-0.5, cz-0.5 );
  glEnd();

 
  //BACK
  glBegin(GL_POLYGON);
  glColor3f(   1.0,  1.0, 1.0 );
  glVertex3f(  cx+0.5, cy-0.5, cz+0.5 );
  glVertex3f(  cx+0.5,  cy+0.5, cz+0.5 );
  glVertex3f( cx-0.5,  cy+0.5, cz+0.5 );
  glVertex3f( cx-0.5, cy-0.5, cz+0.5 );
  glEnd();
 
 
  //RIGHT
  glBegin(GL_POLYGON);
  glColor3f(  0.0,  1.0,  0.0 );
  glVertex3f( cx+0.5, cy-0.5, cz-0.5 );
  glVertex3f( cx+0.5,  cy+0.5, cz-0.5 );
  glVertex3f( cx+0.5,  cy+0.5,  cz+0.5 );
  glVertex3f( cx+0.5, cy-0.5,  cz+0.5 );
  glEnd();
 
 
  //LEFT
  glBegin(GL_POLYGON);
  glColor3f(   0.0,  1.0,  0.0 );
  glVertex3f( cx-0.5, cy-0.5,  cz+0.5 );
  glVertex3f( cx-0.5,  cy+0.5,  cz+0.5 );
  glVertex3f( cx-0.5,  cy+0.5, cz-0.5 );
  glVertex3f( cx-0.5, cy-0.5, cz-0.5 );
  glEnd();
 
  //TOP
  glBegin(GL_POLYGON);
  glColor3f(   0.0,  (205.0/255.0),  0 );
  glVertex3f(  cx+0.5,  cy+0.5,  cz+0.5 );
  glVertex3f(  cx+0.5,  cy+0.5, cz-0.5 );
  glVertex3f( cx-0.5,  cy+0.5, cz-0.5 );
  glVertex3f( cx-0.5,  cy+0.5,  cz+0.5 );
  glEnd();
 
  //BOTTOM
  glBegin(GL_POLYGON);
  glColor3f(   0.0,  (205.0/255.0),  0.0 );
  glVertex3f(  cx+0.5, cy-0.5, cz-0.5 );
  glVertex3f(  cx+0.5, cy-0.5,  cz+0.5 );
  glVertex3f( cx-0.5, cy-0.5,  cz+0.5 );
  glVertex3f( cx-0.5, cy-0.5, cz-0.5 );
  glEnd();

}

/* describing the geometry of the base */
void base(float cx,float cy, float cz ,float lx,float ly,float lz){

  //FRONT
  glBegin(GL_POLYGON);
  glColor3f(   1.0,  1.0, 0 );
  glVertex3f(  cx+lx, cy-ly, cz-lz );
  glVertex3f(  cx+lx,  cy+ly, cz-lz );
  glVertex3f( cx-lx,  cy+ly, cz-lz );
  glVertex3f( cx-lx, cy-ly, cz-lz );
  glEnd();

 
  //BACK
  glBegin(GL_POLYGON);
  glColor3f(   1.0,  1.0, 0 );
  glVertex3f(  cx+lx, cy-ly, cz+lz );
  glVertex3f(  cx+lx,  cy+ly, cz+lz );
  glVertex3f( cx-lx,  cy+ly, cz+lz );
  glVertex3f( cx-lx, cy-ly, cz+lz );
  glEnd();
 
 
  //RIGHT
  glBegin(GL_POLYGON);
  glColor3f(  1.0,  0.0,  0.0 );
  glVertex3f( cx+lx, cy-ly, cz-lz );
  glVertex3f( cx+lx,  cy+ly, cz-lz );
  glVertex3f( cx+lx,  cy+ly,  cz+lz );
  glVertex3f( cx+lx, cy-ly,  cz+lz );
  glEnd();
 
 
  //LEFT
  glBegin(GL_POLYGON);
  glColor3f(   1.0,  0.0,  0.0 );
  glVertex3f( cx-lx, cy-ly,  cz+lz );
  glVertex3f( cx-lx,  cy+ly,  cz+lz );
  glVertex3f( cx-lx,  cy+ly, cz-lz );
  glVertex3f( cx-lx, cy-ly, cz-lz );
  glEnd();
 
  //TOP
  glBegin(GL_POLYGON);
  glColor3f(   (205.0/255.0),  0.0,  0.0 );
  glVertex3f(  cx+lx,  cy+ly,  cz+lz );
  glVertex3f(  cx+lx,  cy+ly, cz-lz );
  glVertex3f( cx-lx,  cy+ly, cz-lz );
  glVertex3f( cx-lx,  cy+ly,  cz+lz );
  glEnd();
 
  //BOTTOM
  glBegin(GL_POLYGON);
  glColor3f(   (205.0/255.0),  0.0,  0.0 );
  glVertex3f(  cx+lx, cy-ly, cz-lz );
  glVertex3f(  cx+lx, cy-ly,  cz+lz );
  glVertex3f( cx-lx, cy-ly,  cz+lz );
  glVertex3f( cx-lx, cy-ly, cz-lz );
  glEnd();

}

/* the borders around the base */
void borders(float cx,float cy, float cz ,float lx,float ly,float lz){

  //FRONT
  glBegin(GL_POLYGON);
  glColor4f(   0.0,  0.0, 1.0 ,0.1);
  glVertex3f(  cx+lx, cy-ly, cz-lz );
  glVertex3f(  cx+lx,  cy+ly, cz-lz );
  glVertex3f( cx-lx,  cy+ly, cz-lz );
  glVertex3f( cx-lx, cy-ly, cz-lz );
  glEnd();

 
  //BACK
  glBegin(GL_POLYGON);
  glColor4f(   0,  0, 1.0,0.1 );
  glVertex3f(  cx+lx, cy-ly, cz+lz );
  glVertex3f(  cx+lx,  cy+ly, cz+lz );
  glVertex3f( cx-lx,  cy+ly, cz+lz );
  glVertex3f( cx-lx, cy-ly, cz+lz );
  glEnd();
 
 
  //RIGHT
  glBegin(GL_POLYGON);
  glColor4f(  (65.0/255.0),  (105.0/255.0),  (225.0/255.0),0.1 );
  glVertex3f( cx+lx, cy-ly, cz-lz );
  glVertex3f( cx+lx,  cy+ly, cz-lz );
  glVertex3f( cx+lx,  cy+ly,  cz+lz );
  glVertex3f( cx+lx, cy-ly,  cz+lz );
  glEnd();
 
 
  //LEFT
  glBegin(GL_POLYGON);
  glColor4f(   (65.0/255.0),  (105.0/255.0),  (225.0/255.0) ,0.1);
  glVertex3f( cx-lx, cy-ly,  cz+lz );
  glVertex3f( cx-lx,  cy+ly,  cz+lz );
  glVertex3f( cx-lx,  cy+ly, cz-lz );
  glVertex3f( cx-lx, cy-ly, cz-lz );
  glEnd();
 
  //TOP
  glBegin(GL_POLYGON);
  glColor4f(   (65.0/255.0),  (105.0/255.0),  (225./255.0) ,0.1);
  glVertex3f(  cx+lx,  cy+ly,  cz+lz );
  glVertex3f(  cx+lx,  cy+ly, cz-lz );
  glVertex3f( cx-lx,  cy+ly, cz-lz );
  glVertex3f( cx-lx,  cy+ly,  cz+lz );
  glEnd();
 
  //BOTTOM
  glBegin(GL_POLYGON);
  glColor4f(   (65.0/255.0),  (105.0/255.0),  (225.0/255.0),0.1 );
  glVertex3f(  cx+lx, cy-ly, cz-lz );
  glVertex3f(  cx+lx, cy-ly,  cz+lz );
  glVertex3f( cx-lx, cy-ly,  cz+lz );
  glVertex3f( cx-lx, cy-ly, cz-lz );
  glEnd();

}

/*geometry of the destructible bloacks*/
void destructibles(float cx,float cy, float cz ,float lx,float ly,float lz){

  //FRONT
  glBegin(GL_POLYGON);
  glColor3f(   1.0,  (165.0/255.0), 0 );
  glVertex3f(  cx+lx, cy-ly, cz-lz );
  glVertex3f(  cx+lx,  cy+ly, cz-lz );
  glVertex3f( cx-lx,  cy+ly, cz-lz );
  glVertex3f( cx-lx, cy-ly, cz-lz );
  glEnd();

 
  //BACK
  glBegin(GL_POLYGON);
  glColor3f(   1.0,  1.0, 0 );
  glVertex3f(  cx+lx, cy-ly, cz+lz );
  glVertex3f(  cx+lx,  cy+ly, cz+lz );
  glVertex3f( cx-lx,  cy+ly, cz+lz );
  glVertex3f( cx-lx, cy-ly, cz+lz );
  glEnd();
 
 
  //RIGHT
  glBegin(GL_POLYGON);
  glColor3f(  (205.0/255.0),  (133.0/255.0),  0.0 );
  glVertex3f( cx+lx, cy-ly, cz-lz );
  glVertex3f( cx+lx,  cy+ly, cz-lz );
  glVertex3f( cx+lx,  cy+ly,  cz+lz );
  glVertex3f( cx+lx, cy-ly,  cz+lz );
  glEnd();
 
 
  //LEFT
  glBegin(GL_POLYGON);
  glColor3f(   (205.0/255.0),  (133.0/255.0),  0.0 );
  glVertex3f( cx-lx, cy-ly,  cz+lz );
  glVertex3f( cx-lx,  cy+ly,  cz+lz );
  glVertex3f( cx-lx,  cy+ly, cz-lz );
  glVertex3f( cx-lx, cy-ly, cz-lz );
  glEnd();
 
  //TOP
  glBegin(GL_POLYGON);
  glColor3f(   (238.0/255.0),  (154.0/255.0),  0.0 );
  glVertex3f(  cx+lx,  cy+ly,  cz+lz );
  glVertex3f(  cx+lx,  cy+ly, cz-lz );
  glVertex3f( cx-lx,  cy+ly, cz-lz );
  glVertex3f( cx-lx,  cy+ly,  cz+lz );
  glEnd();
 
  //BOTTOM
  glBegin(GL_POLYGON);
  glColor3f(   (238.0/255.0),  (154.0/255.0),  0.0 );
  glVertex3f(  cx+lx, cy-ly, cz-lz );
  glVertex3f(  cx+lx, cy-ly,  cz+lz );
  glVertex3f( cx-lx, cy-ly,  cz+lz );
  glVertex3f( cx-lx, cy-ly, cz-lz );
  glEnd();

}

#endif
