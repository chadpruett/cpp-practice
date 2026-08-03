#include<iostream>
#include<fstream>
using namespace std;

const int MAX = 50;

int getRoom();
bool findRoom(int searchRoom, char foundGuest[]);
void printResult(bool found, int room, const char guest[]);

int main()
{
	char foundGuest[MAX];
	bool found = false;
	int searchRoom = 0;

	searchRoom = getRoom();
	found = findRoom(searchRoom, foundGuest);
	printResult(found, searchRoom, foundGuest);

	return 0;
}

int intVal()
{
	int value = 0;

	while (!(cin >> value) || value < 1 || value > 500)
	{
		std::cout << "\nPlease input a room between 1 and 500\n";
		cin.clear();
		cin.ignore(10000,'\n');
	}

	return value;
}

int getRoom()
{
	int searchRoom = 0;
	
	std::cout << "\nEnter room number: ";
	searchRoom = intVal();

	return searchRoom;
}

bool findRoom(int searchRoom, char foundGuest[])
{
	int roomNumber = 0;

	ifstream inFile("room_assignments.txt");

	if (!inFile)
	{
		std::cout << "\nError opening file!\n";
		return false;
	}
	
	while (inFile >> foundGuest >> roomNumber)
	{
		if (searchRoom == roomNumber)
		{
			return true;
		}
	}
	
	return false;
}

void printResult(bool found, int room, const char guest[])
{
	if (found)
	{
		std::cout << "\nRoom " << room << " belongs to " << guest << endl;
	}
	else
	{
		std::cout << "\nCould not find room or open file\n";
	}
}

