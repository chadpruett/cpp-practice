#include<iostream>
#include<fstream>
using namespace std;

const int MAX = 50;

void welcome();
void addAssignment();
void viewAssignments();
void searchAssignedRoom();
int intVal(int minimum, int maximum);
int roomVal(int minimum, int maximum);
bool findRoom(int searchRoom, char foundGuest[]);
void goodbye();

int main()
{
	char guest[MAX];
	int room = 0;	
	int userOption = 0;

	do
	{
		welcome();
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
			searchAssignedRoom();
		}

	} while (userOption != 4);

	return 0;
}


void welcome()
{
	std::cout << "\nWOO HOO!\nWelcome To Outer Space!"
	<< "\nWhat can I do you for?:\n"
	<< "\n1. Add room assignment"
	<< "\n2. View all assignments"
	<< "\n3. Search by room number"
	<< "\n4. Quit"
	<< "\n>> ";
}

void addAssignment()
{
	char guest[MAX];
	int room = 0;

	std::cout << "\nGuest: ";
	cin >> guest;
	std::cout << "\nRoom: ";
	cin >> room;

	ofstream outFile("room_assignments.txt", ios::app);

	if (!outFile)
	{
		std::cout << "\nError opening file!\n";
		return;
	}


	outFile << guest << ' ' << room << endl;
	
	outFile.close();
}

void viewAssignments()
{

	char guest[MAX];
	int room = 0;

	ifstream inFile("room_assignments.txt");

	if (!inFile)
	{
		std::cout << "\nError opening file!\n";
		return;
	}
	
	while (inFile >> guest >> room)
	{
		std::cout << "\nRoom " << room << " belongs to " << guest << '.' << endl;
	}

	inFile.close();
}

void searchAssignedRoom()
{
	char guest[MAX];
	int room = 0;
	int searchRoom = 0;
	bool hasGuest = false;

	std::cout << "\nWhich room would you like to search?: ";
	searchRoom = roomVal(1, 500);
	
	hasGuest = findRoom(searchRoom, guest);

	if (hasGuest)
	{
		std::cout << "\nRoom " << searchRoom << " belongs to " << guest << '.' << endl;
	}
	else
	{
		std::cout << "\nThat room has no guest.. yet"
		<< "\nWon't you stay here for awhile?\n";
	}	
}

int intVal(int minimum, int maximum)
{
	int value = 0;

	while (!(cin >> value) || value < minimum || value > maximum)
	{
		std::cout << "\nPlease, enter a number between 1 and 4, would ya?"
		<< "\n>> ";
		cin.clear();
		cin.ignore(10000,'\n');
	}
	
	return value;
}

int roomVal(int minimum, int maximum)
{
	int value = 0;

	while (!(cin >> value) || value < minimum || value > maximum)
	{
		std::cout << "\nPlease, enter a room between 1 and 500, would ya?"
		<< "\n>> ";
		cin.clear();
		cin.ignore(10000,'\n');
	}
	
	return value;
}

bool findRoom(int searchRoom, char foundGuest[])
{
	int room = 0;

	ifstream inFile("room_assignments.txt");
	
	if (!inFile)
	{
		std::cout << "\nError opening file!\n";
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

	return false;

}

void goodbye()
{
	std::cout << "\n\nGoodbye from Outer Space!\n\n";
}

