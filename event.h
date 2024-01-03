#ifndef EVENT_H
#define EVENT_H

class Event {
	protected:
		int x;
		int y;

	public:
		virtual void percept()=0;
		virtual void encounter()=0;
		void set_x(int);
		void set_y(int);
		int get_x();
		int get_y();


};
#endif
