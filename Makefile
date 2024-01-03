CC = g++ -std=c++11
exe_file = hunt
$(exe_file): gold.o pit.o bats.o wumpus.o event.o room.o game.o prog.o
		$(CC) gold.o pit.o bats.o wumpus.o event.o room.o game.o prog.o -o $(exe_file)
gold.o: gold.cpp
		$(CC) -c gold.cpp
pit.o: pit.cpp
		$(CC) -c pit.cpp
bats.o: bats.cpp
		$(CC) -c bats.cpp
wumpus.o: wumpus.cpp
		$(CC) -c wumpus.cpp
event.o: event.cpp
		$(CC) -c event.cpp
room.o: room.cpp
		$(CC) -c room.cpp
game.o: game.cpp
		$(CC) -c game.cpp
prog.o: prog.cpp
		$(CC) -c prog.cpp
clean:
		rm -f *.out *.o $(exe_file)
