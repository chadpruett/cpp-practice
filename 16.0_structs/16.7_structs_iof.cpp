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

void loadGuests(Guest guests[]);
void printGuests(const Guest guests[]);

int main()
{
	Guest guests[CAP];

	loadGuests(guests);
	printGuests(guests);

	return 0;
}

void loadGuests(Guest guests[])
{
	for (int i = 0; i < CAP; i++)
	{
		std::cout << "\nGuest " << i + 1 << " name: ";
		cin >> guests[i].name;
		std::cout << "\nRoom Number: ";
		cin >> guests[i].room;
		std::cout << "\nNights: ";
		cin >> guests[i].nights;
		
		std::cout << "\n\nCheck-In Month: ";
		cin >> guests[i].checkIn.month;
		std::cout << "\nCheck-In Day: ";
		cin >> guests[i].checkIn.day;
		std::cout << "\nCheck-In Year: ";
		cin >> guests[i].checkIn.year;
	}
	
	ofstream outFile("guests_log.txt", ios::app);
	
	if (!outFile)
	{
		std::cout << "\nError opening file!\n";
		return;
	}

	for (int i = 0; i < CAP; i++)
	{
	outFile << guests[i].name << ' ' << guests[i].room << ' '
	<< guests[i].nights << ' ' << guests[i].checkIn.month
	<< ' ' << guests[i].checkIn.day << ' ' << guests[i].checkIn.year;
	}

	outFile.close();
}

void printGuests(const Guest guests[])
{
	ifstream inFile("guests_log.txt");

	if (!inFile)
	{
		std::cout << "\nError opening file!\n";
		return;
	}

	while(
	inFile >> guests[i].name >> guests[i].room
	>> guests[i].nights >> guests[i].checkIn.month
	>> guests[i].checkIn.day >> guests[i].checkIn.year);
	{
	
		std::cout << guests[i].name << " checked into room "
		<< guests[i].room << " on "
		<< guests[i].checkIn.month
		<< '-' << guests[i].checkIn.day
		<< '-' << guests[i].checkIn.year
		<< " for a total of " << guests[i].nights
		<< " nights.\n\n";

	}

	inFile.close();
}
