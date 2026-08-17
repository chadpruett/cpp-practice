#include<iostream>
using namespace std;


const int GUESTS = 3;
const int MAX = 50;

struct Guests
{
	char name[MAX];
	int room;
	int nights;
};

void getGuests(Guests guests[]);
void printGuests(const Guests guests[]);

int main()
{
	Guests guests[GUESTS];

	getGuests(guests);
	printGuests(guests);

	return 0;
}

void getGuests(Guests guests[])
{
	for (int i = 0; i < GUESTS; i++)
	{
		std::cout << "\nEnter guest " << i + 1 << " name: ";
		cin >> guests[i].name;
		std::cout << "\nEnter room number: ";
		cin >> guests[i].room;
		std::cout << "\nEnter nights: ";
		cin >> guests[i].nights;
	}
}

void printGuests(const Guests guests[])
{
	std::cout << "\nGuest Summary:\n";

	for (int i = 0; i < GUESTS; i++)
	{
		std::cout << "\nName: " << guests[i].name
		<< "\nRoom: " << guests[i].room
		<< "\nNights: " << guests[i].nights << endl;
	}
}



