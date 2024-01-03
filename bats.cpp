#include"bats.h"
#include<iostream>
using namespace std;
//default constructor
Bats::Bats(){
	x = -1;
	y = -1;
}
//constructor w/ parameters
Bats::Bats(int new_x, int new_y){
	x = new_x;
	y = new_y;
}
// percept bats
void Bats::percept(){
	cout <<"You hear wings flapping." << endl;
}
// encounter bats
void Bats::encounter(){
	cout <<"You encounter bats, and are carried to random room." <<endl;
}
