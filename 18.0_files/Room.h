#ifndef ROOM_H
#define ROOM_H

const int MAX = 50;

class Room
{
	private:
		char name[MAX];
		float price;	

	public:
		Room();
		Room(const char roomName[], float nightlyPrice);
		float getPrice();
		void setPrice(float price);
		void display();
};

#endif
