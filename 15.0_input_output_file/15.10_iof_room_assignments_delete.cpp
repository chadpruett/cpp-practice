#include<iostream>
#include<fstream>
#include<cstdio>
using namespace std;

const int MAX = 50;

void welcome();
void addAssignment();
void viewAssignments();
void searchAssignedRoom();
void deleteAssignment();
int intVal(int minimum, int maximum);
int roomVal(int minimum, int maximum);
bool findRoom(int searchRoom, char foundGuest[]);
bool deleteRoom(int searchRoom);
void goodbye();

int main()
{
	char guest[MAX];
	int room = 0;	
	int userOption = 0;

	do
	{
		welcome();
		userOption = intVal(1, 5);
		
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
		else if (userOption == 4)
		{
			deleteAssignment();
		}

	} while (userOption != 5);

	return 0;
}


void welcome()
{
	std::cout << "\nWOO HOO!\nWelcome To Outer Space!"
	<< "\nWhat can I do you for?:\n"
	<< "\n1. Add room assignment"
	<< "\n2. View all assignments"
	<< "\n3. Search by room number"
	<< "\n4. Delete room assignment"
	<< "\n5. Quit"
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

void deleteAssignment()
{
	int searchRoom = 0;
	bool isRoom = false;
	
	std::cout << "\nEnter a room you want to remove from record: ";
	searchRoom = roomVal(1, 500);
	
	isRoom = deleteRoom(searchRoom);

	if (isRoom)
	{
		std::cout << "\nRoom information deleted\n";
	}
	else
	{
		std::cout << "\nCouldnt do that, i'm afraid\n";
	}

}

bool deleteRoom(int searchRoom)
{
	char guest[MAX];
	int room = 0;
	bool deleted = false;

	ifstream inFile("room_assignments.txt");
	ofstream tempFile("deleted.txt");

	if (!inFile || !tempFile)
	{
		std::cout << "\nError opening file!\n";
		return false;
	}


	while (inFile >> guest >> room)
	{
		if (searchRoom == room)
		{
			deleted = true;
		}
		else
		{
			tempFile << guest << ' ' << room << endl;
		}
	}

	inFile.close();
	tempFile.close();

	remove("room_assignments.txt");
	rename("deleted.txt", "room_assignments.txt");

	return deleted;

}

int intVal(int minimum, int maximum)
{
	int value = 0;

	while (!(cin >> value) || value < minimum || value > maximum)
	{
		std::cout << "\nPlease, enter a number between 1 and 5, would ya?"
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

