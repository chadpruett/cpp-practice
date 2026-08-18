#include<iostream>
#include<fstream>
using namespace std;

const int MAX = 50;

void displayMenu();
int intVal(int minimum, int maximum);
void registerGuest();
void viewGuest();
void searchGuest();
void printGuest(const char name[], int room, int nights);
bool myStrCompare(const char first[], const char second[]);


int main()
{
	int userOption = 0;

	do
	{
		displayMenu();
		userOption = intVal(1, 4);

		if (userOption == 1)
		{
			registerGuest();
		}
		else if (userOption == 2)
		{
			viewGuest();
		}
		else if (userOption == 3)
		{
			searchGuest();
		}

	} while (userOption != 4);

	return 0;
}

void displayMenu()
{
	std::cout << "\nWelcome To Outer Space!"
	<< "\nWhat would you like to do?"
	<< "\n1. Register guest"
	<< "\n2. View all guests"
	<< "\n3. Search guest by name"
	<< "\n4. Quit"
	<< "\n>> ";
}

int intVal(int minimum, int maximum)
{
	int value = 0;

	while (!(cin >> value) || value < minimum || value > maximum)
	{
		std::cout << "\nPlease ensure to input a number between " << minimum
			  << " and " << maximum
			  << "\n>> ";
		cin.clear();
		cin.ignore(10000, '\n');
	}

	return value;
}

void registerGuest()
{
	char guest[MAX];
	int room = 0;
	int nights = 0;

	std::cout << "\nGuest name: ";
	cin >> guest;
	std::cout << "\nRoom Number: ";
	cin >> room;
	std::cout << "\nHow many nights: ";
	cin >> nights;

	ofstream outFile("guests.txt", ios::app);

	if (!outFile)
	{
		std::cout << "\nFile does not exist!\n";
		return;
	}

	outFile << guest
		<< '\n' << room
		<< '\n' << nights << endl;
	
	outFile.close();
}

void viewGuest()
{
	char guest[MAX];
	int room = 0;
	int nights = 0;

	ifstream inFile("guests.txt");

	if (!inFile)
	{
		std::cout << "\nFile does not exist!\n";
		return;
	}

	while (inFile >> guest >> room >> nights)
	{
		printGuest(guest, room, nights);
	}

	inFile.close();
}

void searchGuest()
{
	char guest[MAX];
	char searchGuest[MAX];
	int room = 0;
	int nights = 0;
	bool foundGuest = false;

	std::cout << "\nWho are you searching for?: ";
	cin >> searchGuest;

	ifstream inFile("guests.txt");

	if (!inFile)
	{
		std::cout << "\nFile does not exist!\n";
		return;
	}

	while (inFile >> guest >> room >> nights)
	{

		if (myStrCompare(searchGuest, guest))
		{
			printGuest(searchGuest, room, nights);
			foundGuest = true;
		}
	}

		if (!foundGuest)
		{
			std::cout << "\nGuest does not exist\n";
		}
}

void printGuest(const char name[], int room, int nights)
{
	std::cout << "\nGuest: " << name
	          << "\nRoom Number: " << room
		  << "\nNights: " << nights << endl;
}

bool myStrCompare(const char first[], const char second[])
{
	int i = 0;
	
	while (first[i] != '\0' && second[i] != '\0')
	{
		if (first[i] != second[i])
		{
			return false;
		}		
		
	i++;
	
	}

	return first[i] == '\0' && second[i] == '\0';
}
