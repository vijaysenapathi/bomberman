#ifndef GRID_H
#define GRID_H 
#include <iostream>
#include <vector>
#include "square.h"
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
	makedestructible(2,1,0);
	makedestructible(5,2,0);
}
void grid::makedestructible(int a,int b,int powerUp){
	arena[a-1][b-1].powerup=powerUp;
	arena[a-1][b-1].destructible=true;
	arena[a-1][b-1].empty=false;
}
square grid::block(int a,int b){
	return arena[a-1][b-1];
}
#endif
