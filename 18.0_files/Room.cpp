#include "Room.h"
#include<cstring>
#include<iostream>

Room::Room()
{
	price = 0.0;
	name[0] = '\0';
}

Room::Room(const char roomName[], float nightlyPrice)
{
	std::strncpy(name, roomName, MAX - 1);
	name[MAX - 1] = '\0';
	
	price = nightlyPrice;
}

float Room::getPrice()
{
	return price;
}

void Room::setPrice(float nightlyPrice)
{
	price = nightlyPrice;
}

void Room::display()
{
	std::cout << '\n' << "You've ordered the "
	<< name << " for $" << price << '\n';

}

