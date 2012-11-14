#include<iostream>
#include<GL/glu.h>
#include<GL/freeglut.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <math.h>
#include <queue>
#include <list>
#include <ctime>
#include "grid.h"
#include "hero.h"
#include "bomb.h"
#include "powerups.h"
#include "bot.h"
#include "timer.h"

using namespace std;

heros neo;//the name of the player is neo

void display();
void specialKeys();

grid ARENA;
int hori=17,verti=11;

priority_queue<bombs> bombQueue;

list <bots> botsList;

void timer(int i);

timeval earlier,later,interval;

double prevTime=0;

int botSteps=0;

void undestructibles(float cx,float cy, float cz ){

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
		for(int j=1;j<=verti;j++){
			if(ARENA.block(i,j).empty){
				if(ARENA.block(i,j).powerup != 0){
						glPushMatrix();
						glTranslatef(i-9,6-j,0);
						displaypowerup(ARENA.block(i,j).powerup);
						glPopMatrix();
				}
			}
			else{
				if(ARENA.block(i,j).destructible){
					destructibles(i-9,6-j,0,0.45,0.45,0.45);
				}
				else if((i%2 == 0) && (j%2 == 0)){
					undestructibles(i-9,6-j,0);
				}
			}
			if(ARENA.block(i,j).bomb){
				glPushMatrix();
				glTranslatef(i-9,6-j,0);
				glScalef(1.5,1.5,1.5);
				displaybomb();
				glPopMatrix();
			}
		}
	}
	list<bots>::iterator itr;
	for(itr=botsList.begin();itr!=botsList.end();itr++){
		glPushMatrix();
		glTranslatef(itr->Xpos,itr->Ypos,0);
		glRotatef(90*(itr->direction),0,0,1);
		glRotatef(-90,1,0,0);
		displaybot();
		glPopMatrix();
	}
	base(0,0,0.7,8.5,5.5,0.2);
	borders(0,5.6,0.5,8.5,0.1,0.2);
	borders(0,-5.6,0.5,8.5,0.1,0.2);
	borders(8.6,0,0.5,0.1,5.5,0.2);
	borders(-8.6,0,0.5,0.1,5.5,0.2);
	glPushMatrix();
	glTranslatef(neo.heroXpos,neo.heroYpos,-1.34);
	glRotatef(90*(neo.heroDirection),0,0,1);
	neo.displayhero();
	glPopMatrix();	
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

void dropABomb();

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
		case ' ':
			if((!neo.bombPlaced) || (neo.infiBombs)){
				dropABomb();
			}
	}
	int ipos,jpos;
	ipos=9+floor(neo.heroXpos+0.5);
	jpos=6-floor(neo.heroYpos+0.5);
	if(ARENA.block(ipos,jpos).powerup != 0){
		neo.takePowerup(ARENA.block(ipos,jpos).powerup);
		ARENA.removePowerup(ipos,jpos);
	}
	glutPostRedisplay();
}

int bombsID=3;

void dropABomb(){
	float x=neo.heroXpos,y=neo.heroYpos;
	neo.bombPlaced=true; 
	int i,j;
	i=9+floor(x+0.5);
	j=6-floor(y+0.5);
	if(!ARENA.block(i,j).bomb){
		if(gettimeofday(&later,NULL)){
			perror("dropABomb error");
			exit(1);
		}
		double time=(timeval_diff(NULL,&later,&earlier)/1000000.0);
		if(!bombQueue.empty()){
			list<bombs> bombslist;
			for(;!bombQueue.empty();){
				bombslist.push_back(bombQueue.top());
				bombQueue.pop();
			}
			bombs tempbomb;
			list<bombs>::iterator it;
			for(it=bombslist.begin();it!=bombslist.end();it++){
				tempbomb=*it;
				tempbomb.timeToBlast-=time;
				bombQueue.push(tempbomb);
			}
		}
		if(gettimeofday(&earlier,NULL)){
			perror("second time in drobABomb()");
			exit(1);
		}
		bombs aBomb(i,j,4000);
		bombQueue.push(aBomb);
		ARENA.setbomb(i,j);
		glutPostRedisplay();
		glutTimerFunc(3000,timer,bombsID++);	
	}
}

void spawnABot(){
	int i=neo.heroXpos;
	if(i > 0){
		bots testBot(1,6);
		botsList.push_back(testBot);
	}
	else{
		bots testBot(17,6);
		botsList.push_back(testBot);
	}
}

void killBots(int i,int j){
	int i1,j1;
	list<bots>::iterator itr,itr1;
	for(itr = botsList.begin();itr != botsList.end();itr++){
		i1=9+floor((itr->Xpos)+0.5);
		j1=6-floor((itr->Ypos)+0.5);
		if(((abs(i-i1))+(abs(j-j1))) == 1 || ((abs(i-i1))+(abs(j-j1))) == 0){
			itr=botsList.erase(itr);
			itr--;
			spawnABot();
		}
	}
}

void blastBomb(){
	neo.bombPlaced=false;
	int i,j;
	i=bombQueue.top().Xpos;
	j=bombQueue.top().Ypos;
	ARENA.removebomb(i,j);
	bombQueue.pop();
	int powerupPos[]={i-1,j,i,j-1,i+1,j,i,j+1},temp1,temp2;
	for(int k=0;k<4;k++){
		temp1=powerupPos[2*k];
		temp2=powerupPos[2*k+1];
		if(1<=temp1 && 17>=temp1 && 1<=temp2 && 17>=temp2){
			glutTimerFunc(5000,timer,-(100*temp1+temp2));
		}
	}
	if(!bombQueue.empty()){
		list<bombs> bombslist;
		for(;!bombQueue.empty();){
			bombslist.push_back(bombQueue.top());
			bombQueue.pop();
		}
		bombs tempbomb;
		list<bombs>::iterator it;
		int i1,j1;
		for(it=bombslist.begin();it!=bombslist.end();it++){
			tempbomb=*it;
			//tempbomb.timeToBlast-=time;
			i1=tempbomb.Xpos;j1=tempbomb.Ypos;
			if((abs(i-i1)+abs(j-j1)) == 1){
				if(tempbomb.timeToBlast > 300){
					tempbomb.timeToBlast=300;
					glutTimerFunc(300,timer,tempbomb.ID);
				}
			}
			bombQueue.push(tempbomb);
		}
	}
	killBots(i,j);
	glutPostRedisplay();
}

void timer(int i){
	if(i< 0){
		i=-i;
		int a,b;
		a=i/100;
		b=i%100;
		ARENA.removePowerup(a,b);
	}
	else if(i == 2){
		//bots case
		list<bots>::iterator itr;
		if(botSteps == 0){
			for(itr=botsList.begin();itr != botsList.end();itr++){
				itr->directionToMove(0,neo.heroXpos,neo.heroYpos,ARENA.arena);
			}
		}
		else{
			for(itr=botsList.begin();itr != botsList.end();itr++){
				itr->Xpos=(itr->Xpos)+(((itr->ito)-(itr->ifrom))/10.0);
				itr->Ypos=(itr->Ypos)+(((itr->jfrom)-(itr->jto))/10.0);
			}
		}
		botSteps=(botSteps+1)%11;
		glutPostRedisplay();
		glutTimerFunc(30,timer,2);
	}
	else{
		if(!bombQueue.empty()){
			if(i == bombQueue.top().ID){
				double time;
				if(gettimeofday(&later,NULL)){
					perror("first time in timer");
					exit(1);
				}
				time=timeval_diff(NULL,&later,&earlier)/1000000.0;
				blastBomb();
				if(!bombQueue.empty()){
					list<bombs> bombslist;
					for(;!bombQueue.empty();){
						bombslist.push_back(bombQueue.top());
						bombQueue.pop();
					}
					bombs tempbomb;
					list<bombs>::iterator it;
					for(it=bombslist.begin();it!=bombslist.end();it++){
						tempbomb=*it;
						tempbomb.timeToBlast-=time;
						bombQueue.push(tempbomb);
					}
					if(gettimeofday(&earlier,NULL)){
						perror("second time in timer");
					exit(1);
					}
				}
			}
		}
	}
}

void addbots(){
	/*bots testbot1(8,1),testbot2(15,11);
	botsList.push_back(testbot1);
	botsList.push_back(testbot2);*/
	int a,b;
	for(int i=0;i<ARENA.botSpawns.size();i++){
		a=ARENA.botSpawns[i].first;
		b=ARENA.botSpawns[i].second;
		bots aBot(a,b);
		botsList.push_back(aBot);
	}
	glutPostRedisplay();
	glutTimerFunc(30,timer,2);
}

int main(int argc, char* argv[]){

  ARENA.readTheLevel("leveltest");
  if(gettimeofday(&earlier,NULL)){
	  perror("inmain");
	  exit(1);
  };

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
  //glutTimerFunc(0,timer,1);
 
  addbots();
  //  Pass control to GLUT for events
  glutMainLoop();
 
  //  Return to OS
  return 0;
 
}
