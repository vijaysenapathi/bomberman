#ifndef SQUARE_H
#define SQUARE_H
#include<iostream>
using namespace std;

//The square class
class square{
	private:

	public:
		int powerup;
		//2 for exit
		//3 for increase player speed
		//4 for player bombs number
		//5 invincibility to a bomb

		//true if it has a destructible block
		bool destructible;

		//true if the square is empty
		bool empty;

		//true if the square has a bomb
		bool bomb;

		//constructor
		square(){
			bomb=false;
		}

		//function for manipulating empty variable
		void setempty(bool val){
			empty=val;
		}		

		//function for manipulating destructible variable
		void setdestructible(bool val){
			destructible=val;
		}

		//function for manipulating powerup variable
		void setpowerup(int i){
			powerup=i;
		}
};
#endif
