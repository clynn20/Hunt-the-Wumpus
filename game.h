#ifndef GAME_H
#define GAME_H
#include"game.h"
#include"room.h"
#include"event.h"
#include"gold.h"
#include"pit.h"
#include"bats.h"
#include"wumpus.h"
#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Game{
	protected:
		int x;
		int y;
		int rope_x;
		int rope_y;
		int arrow;
		int map_grid;
		bool debug_mode;
		bool take_gold;
		bool kill_wumpus;
		Event *events[6];
		vector<vector<Room>> cave;
		bool is_alive;


	public: 
		Game();
		Game(int,bool);
		Game& operator=(const Game&);
		~Game();
		int get_x();
		int get_y();
		int get_map_grid();
		bool get_debug_mode();
		void start_pos(int&,int&);
		void print_map(Game&);
		void fill_cave();
		void assign_event();
		void choose();
		void move(string);
		bool check_move(char);
		void fire(string);
		bool check_fire(string);
		void kill();
		void move_wumpus();
		void show_event();
		void show_percept();
		bool game_over(); 
		void reset();
		vector<vector<Room>> get_cave();
		
};
#endif
		
		
		
