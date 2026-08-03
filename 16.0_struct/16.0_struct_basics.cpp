#include<iostream>
using namespace std;

const int MAX = 50;

struct Guest
{
	char name[MAX];
	int roomNumber;
	int nights;
};

void getGuest(Guest& guest);
void printGuest(Guest& guest);

int main()
{
	Guest guest;

	getGuest(guest);
	printGuest(guest);	

	return 0;
}

void getGuest(Guest& guest)
{
	std::cout << "\nEnter guest name: ";
	cin.getline(guest.name, MAX);
	std::cout << "\nEnter room number: ";
	cin >> guest.roomNumber;
	std::cout << "\nEnter number of nights: ";
	cin >> guest.nights;
}

void printGuest(Guest& guest)
{
	std::cout << "\n\nGuest Summary:\n"
	<< "\nName: " << guest.name
	<< "\nRoom: " << guest.roomNumber
	<< "\nNights: " << guest.nights << endl;
}




