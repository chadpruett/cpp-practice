#include<iostream>
using namespace std;

const int CAP = 3;
const int MAX = 50;

struct Date
{
	int month;
	int day;
	int year;
};

struct Guest
{
	char name[MAX];
	int room;
	int nights;
	Date checkIn;
};

void getGuests(Guest guests[]);
void printGuest(const Guest& guest);
int findGuest(const Guest guests[], int room);

int main()
{
	Guest guests[CAP];
	int roomSearch = 0;
	int index = 0;

	getGuests(guests);

	std::cout << "\n\nWhat room number would you like to search?: ";
	cin >> roomSearch;

	index = findGuest(guests, roomSearch);
	
	if (index != -1)
	{
		printGuest(guests[index]);
	}
	else if (index == -1)
	{
		std::cout << "\n\nNo one is in that room.. Yet.\n\n";
	}

	return 0;
}

void getGuests(Guest guests[])
{
	for (int i = 0; i < CAP; i++)
	{
		std::cout << "\n\nGuest " << i + 1 << " name: ";
		cin >> guests[i].name;
		std::cout << "\nRoom number: ";
		cin >> guests[i].room;
		std::cout << "\nNights: ";
		cin >> guests[i].nights;

		std::cout << "\nCheck-in month: ";
		cin >> guests[i].checkIn.month;
		std::cout << "\nCheck-in day: ";
		cin >> guests[i].checkIn.day;
		std::cout << "\nCheck-in year: ";
		cin >> guests[i].checkIn.year;
	}
}

void printGuest(const Guest& guest)
{
	std::cout << "\n\n" <<  guest.name << " checked into the hotel "
	<< guest.checkIn.month << '-' << guest.checkIn.day << '-' << guest.checkIn.year
	<< " for " << guest.nights << " nights.\n\n";
}

int findGuest(const Guest guests[], int room)
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
