#include"gold.h"
#include<iostream>
using namespace std;
// default constructor
Gold::Gold(){
	x = -1;
	y = -1;
}
// constructor w/ parameters
Gold::Gold(int new_x, int new_y){
	x = new_x;
	y = new_y;
}
// percept gold
void Gold::percept(){
	cout << "You see a glimmer nearby." << endl;
}
// encounter gold
void Gold::encounter(){
	cout << "You got the gold, and picked it up." <<endl;
}
