#ifndef BOT_H
#define BOT_H
#include<iostream>
#include<list>
using namespace std;

class bot{

int Id;
float Xpos;
float Ypos;
float speed;
char dir;
 
 
 void MoveL();
 void MoveR();
 void MoveU();
 void MoveD();
 
 void NextMove();
 
 
 bot();
 };
 /**bot::bot()
 {
 
 Xpos;
 Ypos;
 speed;
 dir;
 
 
 }
**/








#endif
