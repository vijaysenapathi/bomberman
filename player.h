#ifndef PLAYER_H
#define PLAYER_H
#include<iostream>
#include<list>
using namespace std;
 class player
  {
   public:
   /*******       Varibles        *********/
      
    int Id;//unique id for Bomberman usefull in case of multiplayer
    float Xpos;//'Xpos,Ypos' stores the current position of this Bomberman.
    float Ypos;
    float speed;//speed of the Bomberman per key stroke.
    float score;
    list<int> powerup;//contains list of powerup ID's of the Bomberman.
    int capacity;//capacity of bombs he can put at once
    char dir;//'dir' stores current face direction of the Bomberman.(left,right,up,down)
  /********        methods         ********/
  
   
    void moveL();//methods to move the bomberman Left,Right,Up,Down
    void moveR();
    void moveU();
    void moveD();
 
    void placeBomb();//takes current position of Bomberman and places bomb there
   // void kickBomb();//power up that allows Bomberman to kick the Bomb
    void Dead();//in case of multiplayer removes thisplayer from vector containing players
  
  player();//default constructor
  };
  player::player()
  {
    Xpos =0.5;
    Ypos =0.5;
    speed=10;
    score=0;
    capacity=1;
    dir='D';
    
  }

#endif
