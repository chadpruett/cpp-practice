#include<iostream>
using namespace std;

const int MAX = 50;

struct Guest
{
	char name[MAX];
	int room;
	int nights;
};

void getGuest(Guest& guest);
void printGuest(const Guest& guest);

int main()
{
	Guest guest;

	getGuest(guest);
	printGuest(guest);

	return 0;
}


void getGuest(Guest& guest)
{
	std::cout << "\nGuest name: ";
	cin >> guest.name;
	std::cout << "\nRoom Number: ";
	cin >> guest.room;
	std::cout << "\nHow many nights?: ";
	cin >> guest.nights;
}

void printGuest(const Guest& guest)
{
	std::cout << "\n\n" << guest.name << " is staying in room "
	<< guest.room << " for " << guest.nights << " nights." << endl;
}

