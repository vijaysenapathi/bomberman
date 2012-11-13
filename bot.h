#ifndef BOT_H
#define BOT_H
#include <iostream>
#include <cstdlib>
#include <GL/freeglut.h>
#include <GL/glu.h>
#include <list>
#include <cstdlib>
#include "square.h"
using namespace std;

class bots{
	public:
		int ID;
		int ifrom,jfrom,ito,jto;//i's have values from 1 till 17 and j's from 1 till 11
		float Xpos,Ypos;
		int direction;
		bots(int x, int y){
			ifrom=x;
			jfrom=y;
			ito=x;
			jto=y;
			Xpos=x-9;
			Ypos=6-y;
			direction=rand()%4;
		}
		void directionToMove(int level,float heroXpos,float heroYpos,square arena[17][11]){
			ifrom=ito;jfrom=jto;
			int i;
			switch(level){
				case 0:
					while(true){
						i=int(rand()%5);
						if(i == 0){
							if(!((jfrom+1) <= 11)){
								continue;
							}
							else if(arena[ifrom-1][jfrom].empty){
								ito=ifrom;
								jto=jfrom+1;
								break;
							}
						}
						else if(i == 1){
							if(!((ifrom+1) <= 17)){
								continue;
							}
							else if(arena[ifrom][jfrom-1].empty){
								ito=ifrom+1;
								jto=jfrom;
								break;
							}
						}
						else if(i == 2){
							if(!((jfrom-1) >= 1)){
								continue;
							}
							else if(arena[ifrom-1][jfrom-2].empty){
								ito=ifrom;
								jto=jfrom-1;
								break;
							}
						}
						else if(i == 3){
							if(!((ifrom-1) >= 1)){
								continue;
							}
							else if(arena[ifrom-2][jfrom-1].empty){
								ito=ifrom-1;
								jto=jfrom;
								break;
							}
						}
						else if(i == 4){
							ito=ifrom;
							jto=jfrom;
							break;
						}
					}
			}
			if(i != 4){
				direction=i;
			}
		}

};

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


void displaybot(){
	face(0,0,0,0.35,0.25,0.3);
	hair(0,0.3,0,0.4,0.15,0.4);
	eye(-0.2,0.1,-0.325,0.05,0.03,0.0125);	
	eye(0.2,0.1,-0.325,0.05,0.03,0.0125);	
}


#endif
