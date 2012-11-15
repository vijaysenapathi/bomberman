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
#include "arenagraphics.h"

using namespace std;

//the name of the player is neo
heros neo;

//the input for glutDisplay() function
void display();

//input for glutSpecialKeys function
void specialKeys();

//The grid object for storing elements of the arena played
grid ARENA;

//the number of columns and rows
int hori=17,verti=11;

//a priority queue for storing the bombs and minimum 
//is based on the time left to blast
priority_queue<bombs> bombQueue;

/* The list of bots */
list <bots> botsList;

/*The call back function for glutTimerFunc()*/
void timer(int i);

/*A timeval objects for storing time of
 * different events */
timeval earlier,later,interval;

double prevTime=0;

/* a variable which helps in 
 * the movement of bots between 2 squares */
int botSteps=0;

/* the glutDiaplay() function */
void display(){
	glEnable(GL_POINT_SMOOTH | GL_LINE_SMOOTH | GL_POLYGON_SMOOTH);
	//setting the background color to a shade of sky blue
	glClearColor((176.0/255.0),(226.0/255.0),1,1);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	//setting the transformation matrix to identity
  	glLoadIdentity();
	//setting the view point
	gluLookAt(0,0,0,0,0,-5,0,1,0);
	glFrustum(-10,10,6,-6,-5,10);
	//setting view of the game
	glRotatef(neo.rotate_x, 1.0, 0.0, 0.0 );
	glRotatef(neo.rotate_z, 0.0, 0.0, 1.0 );
	glScalef(0.1,0.1,0.1);
	//drawing the board and all its blocks
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
	//drawing the bots in their respective positions
	list<bots>::iterator itr;
	for(itr=botsList.begin();itr!=botsList.end();itr++){
		glPushMatrix();
		glTranslatef(itr->Xpos,itr->Ypos,0);
		glRotatef(90*(itr->direction),0,0,1);
		glRotatef(-90,1,0,0);
		displaybot();
		glPopMatrix();
	}
	//drawing the base
	base(0,0,0.7,8.5,5.5,0.2);
	//drawing the borders
	borders(0,5.6,0.5,8.5,0.1,0.2);
	borders(0,-5.6,0.5,8.5,0.1,0.2);
	borders(8.6,0,0.5,0.1,5.5,0.2);
	borders(-8.6,0,0.5,0.1,5.5,0.2);
	//displaying the hero
	glPushMatrix();
	glTranslatef(neo.heroXpos,neo.heroYpos,-1.34);
	glRotatef(90*(neo.heroDirection),0,0,1);
	neo.displayhero();
	glPopMatrix();	
	//drawing everything into the second buffer
	glFlush();
	//swapping the second buffe with the first
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

//just the fractional part of x
float fracpart(float x){
	return (x-floor(x));
}

//a good function for determining the collision detection of the player
bool collisionDetection(double xcor, double ycor){
	float xr=xcor+0.29,xl=xcor-0.29;
	float yu=ycor+0.29,yd=ycor-0.29;
	int i0,i1,i2,i3,j0,j1,j2,j3;
	//taking 4 points: above, below, left, right 
	//of the given point at a certain distance(0.29)
	i0=9+floor(xcor+0.5);j0=6-floor(yd+0.5);
	i1=9+floor(xr+0.5);j1=6-floor(ycor+0.5);
	i2=9+floor(xcor+0.5);j2=6-floor(yu+0.5);
	i3=9+floor(xl+0.5);j3=6-floor(ycor+0.5);
	//this returns true if all the above points are empty
	return (ARENA.block(i0,j0).empty 
			&& ARENA.block(i1,j1).empty 
			&& ARENA.block(i2,j2).empty 
			&& ARENA.block(i3,j3).empty);
}

//a function for implementing the animation of walking of the players
void movingLimbs(heros &hero){	
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

//a routine for dropping a bomb
void dropABomb();

//gameover and game pause routines
void finishGame(int i);

//the glutKeyboard keys func
void keyboardKeys(unsigned char key, int x, int y){
	float dummyX,dummyY;
	switch (key){
		case 'w'://going up
			dummyX=neo.heroXpos;
			dummyY=neo.heroYpos;
			dummyY+=neo.speed;
			if(neo.heroYpos < 5.0 && (collisionDetection(dummyX,dummyY))){
				neo.heroYpos+=neo.speed;
			}
			neo.heroDirection=2;
			if(neo.heroDirection != neo.heroPrevDirection){
				//changing the distance between legs to zero
				//whenever the hero turns
				neo.legdisp=0;
				neo.heroPrevDirection=neo.heroDirection;
			}
			//calling the function to move the players hands and legs
			movingLimbs(neo);
			break;
		case 'a'://going left
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
		case 's'://going down
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
		case 'd'://going right
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
		case ' '://placing a bomb
			if((!neo.bombPlaced) || (neo.infiBombs)){
				dropABomb();
			}
			break;
		case 27://pausing the game
			finishGame(2);
			break;
	}
	//assigning the square in which the player is present to 2 variables
	int ipos,jpos;
	ipos=9+floor(neo.heroXpos+0.5);
	jpos=6-floor(neo.heroYpos+0.5);
	//removing the powerup when ever the player comes to 
	//a place where a powerup is present
	if(ARENA.block(ipos,jpos).powerup != 0 && ARENA.block(ipos,jpos).powerup != 2){
		neo.takePowerup(ARENA.block(ipos,jpos).powerup);
		ARENA.removePowerup(ipos,jpos);
	}
	else if(ARENA.block(ipos,jpos).powerup == 2){
		finishGame(0);
	}
	glutPostRedisplay();
}

//the initial bombs ID
int bombsID=3;

//routine for dropping a bomb
void dropABomb(){
	float x=neo.heroXpos,y=neo.heroYpos;
	//setting bombplaced by neo to true
	neo.bombPlaced=true; 
	int i,j;
	i=9+floor(x+0.5);
	j=6-floor(y+0.5);
	//placing a bomb only if there's no bomb at that place
	if(!ARENA.block(i,j).bomb){
		if(gettimeofday(&later,NULL)){
			perror("dropABomb error");
			exit(1);
		}
		double time=(timeval_diff(NULL,&later,&earlier)/1000000.0);
		//updating the times of bomb placing only if the
		//the bomb queue is not empty 
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
		//inserting a bomb into the bomb queue
		bombs aBomb(i,j,4000);
		bombQueue.push(aBomb);
		ARENA.setbomb(i,j);
		glutPostRedisplay();
		glutTimerFunc(3000,timer,bombsID++);	
	}
}

//function for spawning bots if ever one dies
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

//routine for killing a bot
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

//rountine for blasting a bomb
void blastBomb(){
	neo.bombPlaced=false;
	int i,j;
	i=bombQueue.top().Xpos;
	j=bombQueue.top().Ypos;
	ARENA.removebomb(i,j);
	bombQueue.pop();
	int powerupPos[]={i-1,j,i,j-1,i+1,j,i,j+1},temp1,temp2;
	//staring a glutTimerFunction for countdown
	//of disappearance of the bomb
	for(int k=0;k<4;k++){
		temp1=powerupPos[2*k];
		temp2=powerupPos[2*k+1];
		if(1<=temp1 && 17>=temp1 && 1<=temp2 && 17>=temp2){
			glutTimerFunc(5000,timer,-(100*temp1+temp2));
		}
	}
	//implementation of chain bomb blasting
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
	//assigning the square in which the player is present to 2 variables
	int ipos,jpos;
	ipos=9+floor(neo.heroXpos+0.5);
	jpos=6-floor(neo.heroYpos+0.5);
	//killing the player if he is not invincible and present in the vicinity
	if(!(neo.invincible)){
		if((abs(i-ipos)+abs(j-jpos)) == 1 || (abs(i-ipos)+abs(j-jpos)) == 0){
			finishGame(1);
		}
	}
	//killing bots if ever they are in the vicinity
	killBots(i,j);
	glutPostRedisplay();
}

//the timer callback function for glutTimerFunc()
void timer(int i){
	if(i< 0){
		//removing a poweup if not taken within 5 sec
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
		//assigning the square in which the player is present to 2 variables
		int ipos,jpos;
		ipos=9+floor(neo.heroXpos+0.5);
		jpos=6-floor(neo.heroYpos+0.5);
		//finding whether player is in contact with any of the bots
		int ibot,jbot;
		for(itr=botsList.begin();itr != botsList.end();itr++){
		ibot=9+floor((itr->Xpos)+0.5);
		jbot=6-floor((itr->Ypos)+0.5);
		if((abs(ipos-ibot)+abs(jpos-jbot)) == 0){
			finishGame(1);
		}
		}
		glutPostRedisplay();
		glutTimerFunc(30,timer,2);
	}
	else{
		//callback function for blasting of bombs
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

//adding the bots at the beginning
void addbots(){
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


void finishGame(int i){
	//0 for gameover and won
	//1 for gameover and lost
	//2 for pausing the game
	if(i == 0){
		cout<<"finished first"<<endl;
	}
	else if(i == 1){
		cout<<"finished second"<<endl;
	}
	else if(i == 2){
		cout<<"finished third"<<endl;
	}
}

//the main() function
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
