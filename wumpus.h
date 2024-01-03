#ifndef WUMPUS_H
#define WUMPUS_H
#include "event.h"

class Wumpus : public Event{
	public:
		Wumpus();
		Wumpus(int,int);
		void percept();
		void encounter();
};
#endif
