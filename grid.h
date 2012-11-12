#ifndef GRID_H
#define GRID_H 
#include <iostream>
#include <vector>
#include "square.h"
#include <fstream>
using namespace std;
#define HORIZONTAL_LENGTH_ARENA 17
#define VERTICAL_LENGTH_ARENA 11

class grid{
	public:
		//vector<vector <square> > gridV;
		square arena[HORIZONTAL_LENGTH_ARENA][VERTICAL_LENGTH_ARENA];
		grid();
		square block(int a,int b);//access the block at i,j
		void makedestructible(int a,int b,int powerUp);
		void readTheLevel(string filename);
		void setbomb(int i,int j);
		void removebomb(int i,int j);
};


grid::grid(){
	for(int i=0;i<HORIZONTAL_LENGTH_ARENA;i++){
		for(int j=0;j<VERTICAL_LENGTH_ARENA;j++){
			if((i%2 == 1) && (j%2 == 1)){
				arena[i][j].powerup=0;
				arena[i][j].destructible=false;
				arena[i][j].empty=false;
			}
			else{
				arena[i][j].powerup=0;
				arena[i][j].destructible=false;
				arena[i][j].empty=true;
			}
		}
	}
	//makedestructible(2,1,0);
	//makedestructible(5,2,0);
}



void grid::makedestructible(int a,int b,int powerUp){
	arena[a-1][b-1].powerup=powerUp;
	arena[a-1][b-1].destructible=true;
	arena[a-1][b-1].empty=false;
}
square grid::block(int a,int b){
	return arena[a-1][b-1];
}
void grid::setbomb(int i,int j){
	arena[i-1][j-1].bomb=true;
}
void grid::removebomb(int i,int j){
	arena[i-1][j-1].bomb=false;
	int A[]={i-1,j,i,j-1,i+1,j,i,j+1},k=0;
	while(k <= 7){
		int I=A[k],J=A[k+1];
		if(I >= 1 && I <= 17 && J >= 1 && J <= 11){
			if(arena[I-1][J-1].destructible){
				arena[I-1][J-1].destructible=false;
				if(arena[I-1][J-1].powerup == 0){
					arena[I-1][J-1].empty=true;
				}
			}
		}
		k+=2;
	}


}
void grid::readTheLevel(string filename){
	      /*0 for nothing
		1 for just a destructible
		powerup
		2 for exit
		3 for increase player speed
		4 for player bombs number
		5 invincibility to a bomb*/
	fstream levelinput(&filename[0], fstream::in);
	int i,j,temp;
	for(i=1;i<=11;i++){
		for(j=1;j<=17;j++){
			levelinput>>temp;
			if(i % 2 == 0 && j % 2 == 0){
				block(j,i).powerup=0;
				block(j,i).destructible=false;
				block(j,i).empty=false;
				continue;
			}
			switch(temp){
				case 0:
					arena[j-1][i-1].powerup=0;
					arena[j-1][i-1].destructible=false;
					arena[j-1][i-1].empty=true;
					continue;				
					break;
				case 1:
					arena[j-1][i-1].empty=false;
					arena[j-1][i-1].destructible=true;
					arena[j-1][i-1].powerup=0;
					break;
				case 2:
					arena[j-1][i-1].empty=false;
					arena[j-1][i-1].destructible=true;
					arena[j-1][i-1].powerup=2;
					break;
				case 3:
					arena[j-1][i-1].empty=false;
					arena[j-1][i-1].destructible=true;
					arena[j-1][i-1].powerup=3;
					break;
				case 4:
					arena[j-1][i-1].empty=false;
					arena[j-1][i-1].destructible=true;
					arena[j-1][i-1].powerup=4;
					break;
				case 5:
					arena[j-1][i-1].empty=false;
					arena[j-1][i-1].destructible=true;
					arena[j-1][i-1].powerup=5;
					break;
			}
		}
	}
	levelinput.close();
}
#endif
