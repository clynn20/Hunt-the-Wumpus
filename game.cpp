#include "game.h"
#include "room.h"
#include "event.h"
#include "gold.h"
#include "pit.h"
#include "bats.h"
#include "wumpus.h"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
using namespace std;

//default constructor 
Game::Game(){
	map_grid = 4;
	debug_mode = false;
	kill_wumpus = false;
	take_gold = false;
	is_alive = true;
	arrow = 3;
}
// constructor w/ parameters
Game::Game(int grid, bool mode){
	map_grid = grid;
	debug_mode = mode;
	kill_wumpus = false;
	take_gold = false;
	is_alive = true;
	arrow = 3;
	events[0] = new Gold();
	events[1] = new Pit();
	events[2] = new Pit();
	events[3] = new Bats();
	events[4] = new Bats();
	events[5] = new Wumpus();
	fill_cave();
	assign_event();
	start_pos(x,y);
	rope_x = x;
	rope_y = y;
}
//assignment operator overload
Game& Game::operator=(const Game& old){
	if(this!=&old){
		for(int i=0;i<6;i++){
			delete events[i];
		}
	}
	map_grid = old.map_grid;
	debug_mode = old.debug_mode;
	kill_wumpus = false;
	take_gold = false;
	is_alive = true;
	arrow = 3;
	events[0] = new Gold();
	events[1] = new Pit();
	events[2] = new Pit();
	events[3] = new Bats();
	events[4] = new Bats();
	events[5] = new Wumpus();
	cave = vector<vector<Room>>();
	fill_cave();
	assign_event();
	start_pos(x,y);
	rope_x = x;
	rope_y = y;
	return *this;
}
//destructor
Game::~Game(){
	for(int i=0;i<6;i++){
		delete events[i];
	}
}
//get x 
int Game::get_x(){
	return x;
}
//get y 
int Game::get_y(){
	return y;
}
//get map grid
int Game::get_map_grid(){
	return map_grid;
}
//get debug mode
bool Game::get_debug_mode(){
	return debug_mode;
}
vector<vector<Room>> Game::get_cave(){
	return cave;
}
//print map 
void Game::print_map(Game& g1){
	int map_grid = g1.get_map_grid();
	for(int i=0;i<map_grid;i++){
		for(int n=0;n<map_grid;n++){
			cout << "+---";
		}
		cout <<"+" << endl;
		for(int n=0;n<3;n++){
			for(int j=0;j<map_grid;j++){
				if(g1.get_debug_mode() == true && n == 0){
					cout << "|  " << g1.get_cave()[i][j].get_room_content();
				}
				else if(i == g1.get_y() && j == g1.get_x() && n == 1){
					cout << "|*  ";
				}
				else{
					cout << "|   ";
				}
			}
			cout << "|" <<endl;
		}
	}
	for(int i=0;i<map_grid;i++){
		cout << "+---" ;
	}
	cout << "+" <<endl;
}
//fill the cave with room
void Game::fill_cave(){
	for(int i=0;i<map_grid;i++){
		cave.push_back(vector<Room>());
		for(int j=0;j<map_grid;j++)
			cave[i].push_back(Room());
	}
}
//assign event in each room
void Game::assign_event(){
	string content[6];
	content[0] = "G";
	content[1] = "P";
	content[2] = "P";
	content[3] = "B";
	content[4] = "B";
	content[5] = "W";
	srand(time(NULL));
	for(int n=1;n<=6;n++){
		int i = rand() % map_grid;
		int j = rand() % map_grid;
		if(cave[i][j].get_has_event()){
			n--;
		}
		else{
			cave[i][j].set_event(events[n-1]);
			cave[i][j].set_room_content(content[n-1]);
			events[n-1]->set_x(j);
			events[n-1]->set_y(i);
		}
	}
}
//choose to move or fire
void Game::choose(){
	string str = "x";
	do{
		cout << "If you want to move, press w(north), a(west), s(south), d(east) to choose one direction."<< endl;
		cout << "If you want to fire, place a space in front of the direction, eg: w, s, a, d, you have "<< arrow <<" arrow(s)."<< endl;
		cout << "Your choice: ";
		getline(cin,str);
	}
	while((str!="a" && str!="s" && str!="w" && str!="d" && str!=" a" && str!=" d" && str!=" s" && str!=" w") || !check_move(str[0]) || !check_fire(str));
	if(str == " w" || str == " s" || str == " a" || str == " d"){
		fire(str);
	}
	else{
		move(str);
	}
}
//move adventurer
void Game::move(string str){
	if(str == "w"){
		y--;
	}
	else if(str == "s"){
		y++;
	}
	else if(str == "a"){
		x--;
	}
	else if(str == "d"){
		x++;
	}
}
//check if the move is valid 
bool Game::check_move(char str){
	if(str == 'w'){
		if(y-1 >= 0){
			return true;
		}
	}
	else if(str == 's'){
		if(y+1 < map_grid){
			return true;
		}
	}
	else if(str == 'a'){
		if(x-1 >= 0){
			return true;
		}
	}
	else if(str == 'd'){
		if(x+1 < map_grid){
			return true;
		}
	}
	else if(str == ' '){
		return true; 
	}
	cout << "Invalid move, out of the " << map_grid <<"x" << map_grid << " map grid. Try again!" << endl;
	return false;
}
//fire an arrow
void Game::fire(string str){
	arrow--;
	int wx = events[5]->get_x();
	int wy = events[5]->get_y();
	if((wx == x && ((wy == y-1) || (wy == y-2) || (wy == y-3))) && (str == " w")){
		kill();
		kill_wumpus = true;
	}
	else if((wx == x && ((wy == y+1) || (wy == y+2) || (wy == y+3))) && (str == " s")){
		kill();
		kill_wumpus = true;
	}
	else if((wy == y && ((wx == x-1) || (wx == x-2) || (wx == x-3))) && (str == " a")){
		kill();
		kill_wumpus = true;
	}
	else if((wy == y && ((wx == x+1) || (wx == x+2) || (wx == x+3))) && (str == " d")){
		kill();
		kill_wumpus = true;
	}
	else if(kill_wumpus == false){
		move_wumpus();
	}
}
//check if have enough arrow to fire
bool Game::check_fire(string str){
	if(arrow > 0){
		return true;
	}
	else if(arrow < 0){
		cout << "You don't have enough arrow." << endl;
		return false;
	}
	if(str.size() < 2){
		return true;
	}
	return false;
}
//kill wumpus
void Game::kill(){
	cout << "You successfully kill the wumpus!" <<endl; 
	cave[events[5]->get_y()][events[5]->get_x()].set_room_content("n");
}
//move wumpus to random empty cave
void Game::move_wumpus(){
	cave[events[5]->get_y()][events[5]->get_x()].set_room_content("n");
	srand(time(NULL));
	int rand_x,rand_y;
	do{
		rand_x = rand() % map_grid;
		rand_y = rand() % map_grid;
	}
	while(cave[rand_y][rand_x].get_has_event());
	events[5]->set_x(rand_x);
	events[5]->set_y(rand_y);
	cave[rand_y][rand_x].set_room_content("W");
}
//show the room event
void Game::show_event(){
	string str = cave[y][x].get_room_content();
	if(str == "G"){
		events[0]->encounter();
		take_gold = true;
		is_alive = true;
		cave[events[0]->get_y()][events[0]->get_x()].set_room_content("n");
	}
	else if(str == "B"){
		events[3]->encounter();
		srand(time(NULL));
		int new_x = rand() % map_grid;
		int new_y = rand() % map_grid;
		x = new_x;
		y = new_y;
		show_event();
		show_percept();
	}
	else if(str == "P"){
		events[2]->encounter();
		is_alive = false;
	}
	else if(str == "W"){
		events[5]->encounter();
		is_alive = false;
	}
}
//show room percept
void Game::show_percept(){
	Room up,low,right,left;
	if(x+1 < map_grid){
		right = cave[y][x+1];
	}
	if(x-1 >= 0){
		left = cave[y][x-1];
	}
	if(y+1 < map_grid){
		up = cave[y+1][x];
	}
	if(y-1 >= 0){
		low = cave[y-1][x];
	}
	else{
		up = Room();
		low = Room();
		left = Room();
		right = Room();
	}
	if(right.get_room_content() == "G" || left.get_room_content() == "G" || up.get_room_content() == "G" || low.get_room_content() == "G"){
		events[0]->percept();
	}
	if(right.get_room_content() == "B" || left.get_room_content() == "B" || up.get_room_content() == "B" || low.get_room_content() == "B"){
		events[3]->percept();
	}
	if(right.get_room_content() == "P" || left.get_room_content() == "P" || up.get_room_content() == "P" || low.get_room_content() == "P"){
		events[2]->percept();
	}
	if(right.get_room_content() == "W" || left.get_room_content() == "W" || up.get_room_content() == "W"|| low.get_room_content() == "W"){
		events[5]->percept();
	}
}
// set start position
void Game::start_pos(int &x, int&y){
	srand(time(NULL));
	int rand_x,rand_y;
	do{
		rand_x = rand() % map_grid;
		rand_y = rand() % map_grid;
	}
	while(cave[rand_y][rand_x].get_has_event());
	x = rand_x;
	rope_x = x;
	y = rand_y;
	rope_y = y;
}
//track the status of the game
bool Game::game_over(){
	if((take_gold == true) && (x == rope_x) && (y == rope_y)){
		cout<< "You win." <<endl;
		return true;
	}
	else if((take_gold == true) && (kill_wumpus == true) && (x == rope_x) && (y == rope_y)){
		cout << "You win." <<endl;
		return true;
	}
	else if(is_alive == false){
		cout << "You lose." <<endl;
		return true;
	}
	return false;
}
//reset game
void Game::reset(){
	kill_wumpus = false;
	take_gold = false;
	start_pos(x,y);
	rope_x = x;
	rope_y = y;
	arrow = 3;
	is_alive = true;
}





	


