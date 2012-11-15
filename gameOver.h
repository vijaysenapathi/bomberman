#ifndef GAMEOVER_H
#define GAMEOVER_H
#include <GL/glu.h>
#include <GL/freeglut.h>

void letter_g();
void letter_a();
void letter_m();

void youwin(){

}

void youlose(){
	glEnable(GL_POINT_SMOOTH | GL_LINE_SMOOTH | GL_POLYGON_SMOOTH);
	//setting the background color to a shade of sky blue
	glClearColor((176.0/255.0),(226.0/255.0),1,1);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	//setting the transformation matrix to identity	
  	glLoadIdentity();
	glPushMatrix();
	glScalef(0.125,0.1875,1);
	//letter_g();
	letter_a();
	glPopMatrix();
}

void letter_g(){
	glBegin(GL_LINE_STRIP);
	glVertex2f(0,0);
	glVertex2f(2,0);
	glVertex2f(2,1.4);
	glVertex2f(1,1.4);
	glVertex2f(1,1);
	glVertex2f(1.6,1);
	glVertex2f(1.6,0.4);
	glVertex2f(0.4,0.4);
	glVertex2f(0.4,2.6);
	glVertex2f(1.6,2.6);
	glVertex2f(1.6,2);
	glVertex2f(2,2);
	glVertex2f(2,3);
	glVertex2f(0,3);
	glVertex2f(0,0);
	glEnd();
}

void letter_a(){
	glBegin(GL_LINE_STRIP);
	glVertex2f(0,0);
	glVertex2f(0.5,0);
	glVertex2f(0.5,1.5);
	glVertex2f(1.5,1.5);
	glVertex2f(1.5,0);
	glVertex2f(2,0);
	glVertex2f(2,3);
	glVertex2f(0,3);
	glVertex2f(0,0);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex2f(0.5,2);
	glVertex2f(1.5,2);
	glVertex2f(1.5,2.5);
	glVertex2f(0.5,2.5);
	glVertex2f(0.5,2);
	glEnd();
}

void letter_m(){
	glBegin(GL_LINE_STRIP);

	glEnd();
}

#endif
