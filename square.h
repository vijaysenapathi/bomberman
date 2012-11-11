#include<iostream>
using namespace std;


//The square class
class square{
	private:

	public:
		int powerup;
		//powerup is 0 for nothing
		//powerup is 1 for exit
		//powerup is 2 for

		bool destructible;
		bool empty;
		/*square(int Powerup,bool Destructible,bool Empty){//a generalized constructor
			powerup=Powerup;
			destructible=Destructible;
			empty=Empty;*/
		
		/*square(){//constructor if the square is empty
			powerup=0;
			destructible=false;
			empty=true;*/
		void setempty(bool val){
			empty=val;
		}		
		void setdestructible(bool val){
			destructible=val;
		}
		void setpowerup(int i){
			powerup=i;
		}
};
