#ifndef BOT_H
#define BOT_H
#include <iostream>
#include <cstdlib>
#include <list>
#include "square.h"
using namespace std;

class bots{
	public:
		int ID;
		int ifrom,jfrom,ito,jto;
		bool transition;
		int steps;
		int direction;
		bots(int x, int y){
			ifrom=x;
			jfrom=y;
		}
		int directionToMove(int level,float heroXpos,float heroYpos,square arena[17][11]){
			int i;
			switch(level){
				case 0:
					while(true){
						i=rand()%5;
						if(i == 0){
							if(arena[ifrom-1][jfrom].empty){
								ito=ifrom;
								jto=jfrom+1;
								break;
							}
						}
						else if(i == 1){
							if(arena[ifrom][jfrom-1].empty){
								ito=ifrom+1;
								jto=jfrom;
								break;
							}
						}
						else if(i == 2){
							if(arena[ifrom-1][jfrom-2].empty){
								ito=ifrom;
								jto=jfrom-1;
								break;
							}
						}
						else if(i == 3){
							if(arena[ifrom-2][jfrom-1].empty){
								ito=ifrom-1;
								jto=jfrom;
								break;
							}
						}
						else{
							ito=ifrom;
							jto=jfrom;
							break;
						}
					}
			}
			return i;
		}
};


#endif
