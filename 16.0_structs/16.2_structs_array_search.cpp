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

void getGuests(Guests guest[]);
void searchGuest(const Guests guest[]);
void printGuest(const Guests guest[], int index);

int main()
{
	Guests guest[CAP];

	getGuests(guest);
	searchGuest(guest);
	
	return 0;
}

void getGuests(Guests guest[])
{
	for (int i = 0; i < CAP; i++)
	{
		std::cout << "\nGuest " << i + 1 << " name: ";
		cin >> guest[i].name;
		std::cout << "\nRoom Number: ";
		cin >> guest[i].room;
		std::cout << "\nNights: ";
		cin >> guest[i].nights;
	}
}

void searchGuest(const Guests guest[])
{
	int searchRoom = 0;
	int index = 0;
	bool foundGuest = false;

	std::cout << "\nWhich room number are you looking for?: ";
	cin >> searchRoom;

	for (int i = 0; i < CAP; i++)
	{

		if (searchRoom == guest[i].room)
		{	
			index = i;
			foundGuest = true;
		}
	}

	if (foundGuest)
	{
		printGuest(guest, index);
	}
	else if (!foundGuest)
	{
		std::cout << "\nNo one is staying in that room.. yet.\n";
	}
}

void printGuest(const Guests guest[], int index)
{
	

	std::cout << "\nGuest: " << guest[index].name
	<< " is staying in room " << guest[index].room
	<< " for " << guest[index].nights << " nights.\n";
}
