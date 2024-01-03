#include"wumpus.h"
#include <iostream>
using namespace std;
//default constructor
Wumpus::Wumpus(){
	x = -1;
	y = -1;
}
//constructor w/ parameters
Wumpus::Wumpus(int new_x, int new_y){
	x = new_x;
	y = new_y;
}
// percept wumpus
void Wumpus::percept(){
	cout << "You smell a terrible stench." << endl;
}
// encounter wumpus 
void Wumpus::encounter(){
	cout << "You encountered Wumpus, you were killed." << endl;
}
