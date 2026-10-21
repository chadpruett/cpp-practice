#include<iostream>
#include<fstream>
using namespace std;

const int CAP = 3;
const int MAX = 50;

struct Date
{
	int day;
	int month;
	int year;
};

struct Guest
{
	char name[MAX];
	int room;
	int nights;
	Date checkIn;
};

void getGuests(Guest guest[]);
void saveGuests(const Guest guest[]);

int main()
{
	Guest guest[CAP];

	getGuests(guest);
	saveGuests(guest);

	return 0;
}

void getGuests(Guest guest[])
{
	for (int i = 0; i < CAP; i++)
	{
		std::cout << "\n\nGuest " << i + 1 << " name: ";
		cin >> guest[i].name;
		std::cout << "\nRoom number: ";
		cin >> guest[i].room;
		std::cout << "\nNights: ";
		cin >> guest[i].nights;

		std::cout << "\n\nCheck-in month: ";
		cin >> guest[i].checkIn.month;
		std::cout << "\nCheck-in day: ";
		cin >> guest[i].checkIn.day;
		std::cout << "\nCheck-int year: ";
		cin >> guest[i].checkIn.year;
	}
}

void saveGuests(const Guest guest[])
{
	ofstream outFile("guest_list.txt");

	if (!outFile)
	{
		std::cout << "\nFile does not exist!\n";
		return;
	}

	for (int i = 0; i < CAP; i++)
	{
		outFile << guest[i].name << ' ' << guest[i].room << ' ' << guest[i].nights
		<< ' ' << guest[i].checkIn.month << ' ' << guest[i].checkIn.day << ' '
		<< guest[i].checkIn.year << endl;
	}
	
	outFile.close();
}
