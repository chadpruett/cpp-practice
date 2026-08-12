#include<iostream>
using namespace std;

const int MAX = 50;
const int GUESTS = 3;

struct Guest
{
	char name[MAX];
	int room;
	int nights;
};

void getGuests(Guest guest[]);
void printGuests(const Guest guest[]);


int main()
{
	Guest guest[GUESTS];
	
	getGuests(guest);
	printGuests(guest);

	return 0;
}

void getGuests(Guest guest[])
{
	for (int i = 0; i < GUESTS; i++)
	{
		std::cout << "\nGuest " << i + 1 << " name: ";
		cin >> guest[i].name;
		std::cout << "\nRoom number: ";
		cin >> guest[i].room;
		std::cout << "\nHow many nights?: ";
		cin << guest[i].nights;
		std::cout << "\n\n";
	}
}

void printGuests(const Guest guest[])
{
	for (int i = 0; i < GUESTS; i++)
	{
		std::cout << '\n' << guest[i].name << " is staying in room "
		<< guest[i].room << " for " << guest[i].nights
		<< " nights.\n";
	}
}
