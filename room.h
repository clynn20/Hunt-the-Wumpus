#ifndef ROOM_H
#define ROOM_H
#include "event.h"
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Room{
	protected:
		Event *event;
		bool has_event;
		string room_content;

	public:
		Room();
		Room(Event*);
		void set_event(Event*);
		Event* get_event();
		bool get_has_event();
		void set_room_content(string);
		string get_room_content();

};
#endif

