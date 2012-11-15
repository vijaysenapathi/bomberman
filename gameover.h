#ifndef GAMEOVER_H
#define GAMEOVER_H
#include <GL/glu.h>
#include <GL/freeglut.h>

void letter_g();
void letter_a();
void letter_m();
void letter_e();
void letter_o();
void letter_v();
void letter_r();
void letter_y();
void letter_u();
void letter_w();
void letter_i();
void letter_n();
void letter_l();
void letter_s();

void youwin(){
	glEnable(GL_POINT_SMOOTH | GL_LINE_SMOOTH | GL_POLYGON_SMOOTH);
	//setting the background color to a shade of sky blue
	glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLineWidth(3);
	//setting the transformation matrix to identity	
  	glLoadIdentity();

	glPushMatrix();
	glScalef(0.0625,0.0625,1);
	glPushMatrix();
	glTranslatef(1.5,3,0);

	glColor3f(1,0,0);
	glPushMatrix();
	glTranslatef(-15,0,0);
	letter_g();
	glPopMatrix();

	glColor3f(0,0,1);
	glPushMatrix();
	glTranslatef(-12,0,0);
	letter_a();
	glPopMatrix();

	glColor3f(0,1,0);
	glPushMatrix();
	glTranslatef(-9,0,0);
	letter_m();
	glPopMatrix();

	glColor3f(0,1,1);
	glPushMatrix();
	glTranslatef(-6,0,0);
	letter_e();
	glPopMatrix();

	glColor3f(1,1,0);
	glPushMatrix();
	glTranslatef(0,0,0);
	letter_o();
	glPopMatrix();

	glColor3f(1,0,0);
	glPushMatrix();
	glTranslatef(3,0,0);
	letter_v();
	glPopMatrix();

	glColor3f(0,1,0);
	glPushMatrix();
	glTranslatef(6,0,0);
	letter_e();
	glPopMatrix();

	glColor3f(1,0,1);
	glPushMatrix();
	glTranslatef(9,0,0);
	letter_r();
	glPopMatrix();

	glPopMatrix();

	glPushMatrix();
	glTranslatef(3,-2,0);

	glColor3f(0,1,0);
	glPushMatrix();
	glTranslatef(-15,0,0);
	letter_y();
	glPopMatrix();

	glColor3f(0,1,0);
	glPushMatrix();
	glTranslatef(-12,0,0);
	letter_o();
	glPopMatrix();

	glColor3f(0,1,0);
	glPushMatrix();
	glTranslatef(-9,0,0);
	letter_u();
	glPopMatrix();

	glColor3f(0,0,1);
	glPushMatrix();
	glTranslatef(-3,0,0);
	letter_w();
	glPopMatrix();

	glColor3f(0,0,1);
	glPushMatrix();
	glTranslatef(0,0,0);
	letter_i();
	glPopMatrix();

	glColor3f(0,0,1);
	glPushMatrix();
	glTranslatef(3,0,0);
	letter_n();
	glPopMatrix();

	glPopMatrix();
	glPopMatrix();

	
}

void youlose(){
	glEnable(GL_POINT_SMOOTH | GL_LINE_SMOOTH | GL_POLYGON_SMOOTH);
	//setting the background color to a shade of sky blue
	glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLineWidth(3);
	//setting the transformation matrix to identity	
  	glLoadIdentity();

	glPushMatrix();
	glScalef(0.0625,0.0625,1);
	glPushMatrix();
	glTranslatef(1.5,3,0);

	glColor3f(1,0,0);
	glPushMatrix();
	glTranslatef(-15,0,0);
	letter_g();
	glPopMatrix();

	glColor3f(0,0,1);
	glPushMatrix();
	glTranslatef(-12,0,0);
	letter_a();
	glPopMatrix();

	glColor3f(0,1,0);
	glPushMatrix();
	glTranslatef(-9,0,0);
	letter_m();
	glPopMatrix();

	glColor3f(0,1,1);
	glPushMatrix();
	glTranslatef(-6,0,0);
	letter_e();
	glPopMatrix();

	glColor3f(1,1,0);
	glPushMatrix();
	glTranslatef(0,0,0);
	letter_o();
	glPopMatrix();

	glColor3f(1,0,0);
	glPushMatrix();
	glTranslatef(3,0,0);
	letter_v();
	glPopMatrix();

	glColor3f(0,1,0);
	glPushMatrix();
	glTranslatef(6,0,0);
	letter_e();
	glPopMatrix();

	glColor3f(1,0,1);
	glPushMatrix();
	glTranslatef(9,0,0);
	letter_r();
	glPopMatrix();

	glPopMatrix();

	glPushMatrix();
	glTranslatef(3,-2,0);

	glColor3f(0,1,0);
	glPushMatrix();
	glTranslatef(-15,0,0);
	letter_y();
	glPopMatrix();

	glColor3f(0,1,0);
	glPushMatrix();
	glTranslatef(-12,0,0);
	letter_o();
	glPopMatrix();

	glColor3f(0,1,0);
	glPushMatrix();
	glTranslatef(-9,0,0);
	letter_u();
	glPopMatrix();

	glColor3f(0,0,1);
	glPushMatrix();
	glTranslatef(-3,0,0);
	letter_l();
	glPopMatrix();

	glColor3f(0,0,1);
	glPushMatrix();
	glTranslatef(0,0,0);
	letter_o();
	glPopMatrix();

	glColor3f(0,0,1);
	glPushMatrix();
	glTranslatef(3,0,0);
	letter_s();
	glPopMatrix();

	glColor3f(0,0,1);
	glPushMatrix();
	glTranslatef(6,0,0);
	letter_e();
	glPopMatrix();

	glPopMatrix();
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
	glVertex2f(0,0);
	glVertex2f(0.5,0);
	glVertex2f(0.5,2);
	glVertex2f(1,1.5);
	glVertex2f(1.5,1.5);
	glVertex2f(2,2);
	glVertex2f(2,0);
	glVertex2f(2.5,0);
	glVertex2f(2.5,3);
	glVertex2f(2,3);
	glVertex2f(1.25,2);
	glVertex2f(0.5,3);
	glVertex2f(0,3);
	glVertex2f(0,0);
	glEnd();
}

void letter_e(){
	glBegin(GL_LINE_STRIP);
	glVertex2f(0,0);
	glVertex2f(2,0);
	glVertex2f(2,0.5);
	glVertex2f(0.5,0.5);
	glVertex2f(0.5,1.2);
	glVertex2f(1.2,1.2);
	glVertex2f(1.2,1.8);
	glVertex2f(0.5,1.8);
	glVertex2f(0.5,2.5);
	glVertex2f(2,2.5);
	glVertex2f(2,3);
	glVertex2f(0,3);
	glVertex2f(0,0);
	glEnd();
}

void letter_o(){
	glBegin(GL_LINE_STRIP);
	glVertex2f(0,0);
	glVertex2f(2,0);
	glVertex2f(2,3);
	glVertex2f(0,3);
	glVertex2f(0,0);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2f(0.5,0.5);
	glVertex2f(1.5,0.5);
	glVertex2f(1.5,2.5);
	glVertex2f(0.5,2.5);
	glVertex2f(0.5,0.5);
	glEnd();

}

void letter_v(){
	glBegin(GL_LINE_STRIP);
	glVertex2f(0.7,0);
	glVertex2f(1.3,0);
	glVertex2f(2,3);
	glVertex2f(1.5,3);
	glVertex2f(1,1);
	glVertex2f(0.5,3);
	glVertex2f(0,3);
	glVertex2f(0.7,0);
	glEnd();
}

void letter_r(){
	glBegin(GL_LINE_STRIP);
	glVertex2f(0,0);
	glVertex2f(0.5,0);
	glVertex2f(0.5,1);
	glVertex2f(1.5,1);
	glVertex2f(1.5,0);
	glVertex2f(2,0);
	glVertex2f(2,1);
	glVertex2f(1.5,1);
	glVertex2f(1.5,2.5);
	glVertex2f(2,2.5);
	glVertex2f(2,1.5);
	glVertex2f(0.5,1.5);
	glVertex2f(0.5,2.5);
	glVertex2f(1.5,2.5);
	glVertex2f(1.5,3);
	glVertex2f(0,3);
	glVertex2f(0,0);
	glEnd();
}


void letter_y(){
	glBegin(GL_LINE_STRIP);
	glVertex2f(0.7,0);
	glVertex2f(1.3,0);
	glVertex2f(1.3,1.3);
	glVertex2f(0.7,1.3);
	glVertex2f(0.7,0);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2f(1.2,1.3);
	glVertex2f(1.7,1.3);
	glVertex2f(1.7,1.8);
	glVertex2f(1.2,1.8);
	glVertex2f(1.2,1.3);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2f(0.3,1.3);
	glVertex2f(0.8,1.3);
	glVertex2f(0.8,1.8);
	glVertex2f(0.3,1.8);
	glVertex2f(0.3,1.3);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2f(1.5,1.8);
	glVertex2f(2.0,1.8);
	glVertex2f(2.0,3);
	glVertex2f(1.5,3);
	glVertex2f(1.5,1.8);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2f(0,1.8);
	glVertex2f(0.5,1.8);
	glVertex2f(0.5,3);
	glVertex2f(0,3);
	glVertex2f(0,1.8);
	glEnd();
}

void letter_u(){
	glBegin(GL_LINE_STRIP);
	glVertex2f(2,0.5);
	glVertex2f(0,0.5);
	glVertex2f(0,3);
	glVertex2f(0.5,3);
	glVertex2f(0.5,0);
	glVertex2f(1.5,0);
	glVertex2f(1.5,3);
	glVertex2f(2,3);
	glVertex2f(2,0.5);
	glEnd();

}

void letter_w(){
	glPushMatrix();
	glScalef(1,-1,1);
	glTranslatef(0,-3,0);
	letter_m();
	glPopMatrix();
}

void letter_i(){
	glBegin(GL_LINE_STRIP);
	glVertex2f(0,0);
	glVertex2f(2,0);
	glVertex2f(2,0.5);
	glVertex2f(0,0.5);
	glVertex2f(0,0);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2f(0.7,0.5);
	glVertex2f(1.3,0.5);
	glVertex2f(1.3,2.5);
	glVertex2f(0.7,2.5);
	glVertex2f(0.7,0.5);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2f(0,2.5);
	glVertex2f(2,2.5);
	glVertex2f(2,3.0);
	glVertex2f(0,3.0);
	glVertex2f(0,2.5);
	glEnd();
}

void letter_n(){
	glBegin(GL_LINE_STRIP);
	glVertex2f(0,0);
	glVertex2f(0.5,0);
	glVertex2f(0.5,2);
	glVertex2f(1.3,0);
	glVertex2f(2,0);
	glVertex2f(2,3);
	glVertex2f(1.5,3);
	glVertex2f(1.5,1);
	glVertex2f(0.7,3);
	glVertex2f(0,3);
	glVertex2f(0,0);
	glEnd();
}

void letter_l(){
	glBegin(GL_LINE_STRIP);
	glVertex2f(0,0);
	glVertex2f(2,0);
	glVertex2f(2,0.5);
	glVertex2f(0.5,0.5);
	glVertex2f(0.5,3);
	glVertex2f(0,3);
	glVertex2f(0,0);
	glEnd();
}

void letter_s(){
	glBegin(GL_LINE_STRIP);
	glVertex2f(0,0);
	glVertex2f(2,0);
	glVertex2f(2,1.7);
	glVertex2f(0.6,1.7);
	glVertex2f(0.6,2.4);
	glVertex2f(2,2.4);
	glVertex2f(2,3);
	glVertex2f(0,3);
	glVertex2f(0,1.1);
	glVertex2f(1.4,1.1);
	glVertex2f(1.4,0.6);
	glVertex2f(0,0.6);
	glVertex2f(0,0);
	glEnd();
}

#endif
