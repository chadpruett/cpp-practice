#include<iostream>
using namespace std;

const int MAX = 40;

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
	std::cout << "\nRoom number: ";
	cin >> guest.room;
	std::cout << "\nNights: ";
	cin >> guest.nights;

}

void printGuest(const Guest& guest)
{

	std::cout << '\n' << guest.name << " is staying in room "
	<< guest.room << " for " << guest.nights << " nights. " << endl; 
}

