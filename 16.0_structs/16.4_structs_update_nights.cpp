#include<iostream>
using namespace std;

const int CAP = 3;
const int MAX = 50;

struct Guests
{
	char name[MAX];
	int room;
	int nights;
};

void getGuests(Guests guests[]);
int findGuest(const Guests guests[], int room);
void updateGuest(Guests& guest);
void printGuest(const Guests& guest);

int main()
{	
	Guests guests[CAP];
	int index = 0;
	int roomSearch = 0;

	getGuests(guests);
	
	std::cout << "\n\nRoom to update: ";
	cin >> roomSearch;

	
	index = findGuest(guests, roomSearch);

	if (index != -1)
	{
		updateGuest(guests[index]);
		printGuest(guests[index]);
	}
	else if (index == -1)
	{
		std::cout << "\n\nRoom number not found\n\n";
	}

	return 0;
}

void getGuests(Guests guests[])
{
	for (int i = 0; i < CAP; i++)
	{
		std::cout << "\nEnter guest " << i + 1 << " name: ";
		cin >> guests[i].name;
		std::cout << "\nRoom Number: ";
		cin >> guests[i].room;
		std::cout << "\nNights stayed: ";
		cin >> guests[i].nights;
	}
}


int findGuest(const Guests guests[], int room)
{
	for (int i = 0; i < CAP; i++)
	{
		if (room == guests[i].room)
		{
			return i;
		}
	}
	
	return -1;
}

void updateGuest(Guests& guest)
{
	std::cout << "\nNew number of nights: ";
	cin >> guest.nights;
}

void printGuest(const Guests& guest)
{
	std::cout << "\n\nGuest " << guest.name << " is now staying in room " 
	<< guest.room << " for " << guest.nights << " nights.\n\n";
}
