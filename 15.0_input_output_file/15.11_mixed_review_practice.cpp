#include<iostream>
#include<fstream>
using namespace std;

const int MAX = 50;

void welcomeMenu();
void addAssignment();
void viewAssignments();
void searchAssignment();
bool findRoom(int searchRoom, char foundGuest[]);
int intVal(int minimum, int maximum);
int roomVal(int minimum, int maximum);
void goodbye();

int main()
{
	int userOption = 0;

	do
	{
		welcomeMenu();
		userOption = intVal(1, 4);
		
		if (userOption == 1)
		{
			addAssignment();
		}
		else if (userOption == 2)
		{
			viewAssignments();
		}
		else if (userOption == 3)
		{
			searchAssignment();
		}

	} while (userOption != 4);

	goodbye();

	return 0;
}


void welcomeMenu()
{
	std::cout << "\nWelcome To Outer Space!"
	<< "\nHow can I help you?:"
	<< "\n1. Add room assignment"
	<< "\n2. View all assignments"
	<< "\n3. Search by room number"
	<< "\n4. Quit\n"
	<< ">> ";
}


int intVal(int minimum, int maximum)
{
	int value = 0;

	while (!(cin >> value) || value < minimum || value > maximum)
	{
		std::cout << "\nPlease enter a value between 1 and 4, would ya?: ";
		cin.clear();
		cin.ignore(10000,'\n');
	}
	
	return value;
}

void addAssignment()
{
	char guest[MAX];
	int room = 0;

	std::cout << "\nGuest name: ";
	cin >> guest;
	std::cout << "\nRoom number: ";
	cin >> room;

	ofstream outFile("room_assignments.txt", ios::app);
	
	if (!outFile)
	{
		std::cout << "\nError opening file!";
		return;
	}
	
	outFile << guest << ' ' <<  room << endl;
	
	outFile.close();	

}

void viewAssignments()
{
	char guest[MAX];
	int room = 0;

	ifstream inFile("room_assignments.txt");
	
	if (!inFile)
	{
		std::cout << "\nError opening file!";
		return;
	}
	
	while (inFile >> guest >> room)
	{
		std::cout << "\nRoom: " << room << " belongs to " << guest << '.' << endl;	
	}
	
	inFile.close();
}

void searchAssignment()
{
	char guest[MAX];
	int room = 0;
	int roomSearch = 0;
	bool foundRoom = false;

	std::cout << "\nWhich room would you like to look up?: ";
	roomSearch = roomVal(1, 500);

	foundRoom = findRoom(roomSearch, guest);
	
	if (foundRoom)
	{
		std::cout << "\nRoom " << roomSearch << " belongs to " << guest << endl;
	}
	else
	{
		std::cout << "\nRoom not found.\n";
	}

}

int roomVal(int minimum, int maximum)
{
	int value = 0;

	while (!(cin >> value) || value < minimum || value > maximum)
	{
		std::cout << "\nPlease enter a room between 1 and 500: ";
		cin.clear();
		cin.ignore(10000,'\n');
	}

	return value;
}

bool findRoom(int searchRoom, char foundGuest[])
{
	int room = 0;
	bool foundRoom = false;

	ifstream inFile("room_assignments.txt");	
		
	if (!inFile)
	{
		std::cout << "\nError opening file!";
		return false;
	}

	while (inFile >> foundGuest >> room)
	{
		if (searchRoom == room)
		{
			return true;
		}
	}

	inFile.close();

	return foundRoom;	
}

void goodbye()
{
	std::cout << "\n\nGoodbye from Outer Space!\n\n";
}
