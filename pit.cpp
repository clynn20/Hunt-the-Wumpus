#include"pit.h"
#include<iostream>
using namespace std;
//default constructor
Pit::Pit(){
	x = -1;
	y = -1;
}
//constructor w/ parameter
Pit::Pit(int new_x, int new_y){
	x = new_x;
	y = new_y;
}

//percept pit
void Pit::percept(){
	cout << "You feel a breeze." << endl;
}

//encounter pit
void Pit::encounter(){
	cout << "You fall into the pit and died." <<endl;
}

