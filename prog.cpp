
#include "gold.h"
#include "pit.h"
#include "wumpus.h"
#include "bats.h"
#include "event.h"
#include "room.h"
#include "game.h"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main(int argc, char**argv){
	int map_grid = atoi(argv[1]);
	string debug_str(argv[2]);
	if((argc < 3 || map_grid < 4 ) && (debug_str.compare("true")!=0 && debug_str.compare("false")!=0)){
		cout << "Invalid" << endl;
		cout << "The argc should be 3, the map grid should larger than 4, the debug mode should be either true or false." << endl;
		return -1;
	}
	bool get_debug = true;
	if(debug_str == "true"){
		get_debug = true;
	}
	else if(debug_str == "false"){
		get_debug = false;
	}
	Game game(map_grid, get_debug);
	string input = "1";
	while(input == "1" || input == "2"){
		while(!game.game_over()){
			game.print_map(game);
			game.choose();
			game.show_percept();
			game.show_event();
		}
		input="";
		while(input!="1" && input!="2" && input!="3"){
			cout << "Do you want to play again?" << endl;
			cout << "Press 1 to play the same grid, press 2 to play different grid, press 3 to quit the game." << endl;
			cout << "Your choice: " ;
			getline(cin,input);
		}
		if(input == "2"){
			game = Game(map_grid, get_debug);
		}
		else if(input == "1"){
			game.reset();
		}
		else if(input == "3"){
			exit(1);
		}
	}
	return 0;
}
