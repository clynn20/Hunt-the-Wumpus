#include"event.h"
#include<iostream>
using namespace std;
// set x position 
void Event::set_x(int new_x){
	x = new_x;
}
//set y position
void Event::set_y(int new_y){
	y = new_y;
}
//get x position
int Event::get_x(){
	return x;
}
//get y position 
int Event::get_y(){
	return y;
}

