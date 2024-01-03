#include"room.h"
#include"event.h"
#include<iostream>
#include<string>
using namespace std;

//default constructor
Room::Room(){
	event = NULL;
	has_event = false;
	room_content ="n";
}
//constructor w/ parameters
Room::Room(Event *new_event){
	has_event = true;
	event = new_event;
}
// set event
void Room::set_event(Event* new_event){
	event = new_event;
	has_event = true;
}

//get event
Event* Room::get_event(){
	return event;
}
//get has event
bool Room::get_has_event(){
	return has_event;
}
void Room::set_room_content(string str){
	room_content = str;
}
string Room::get_room_content(){
	return room_content;
}
