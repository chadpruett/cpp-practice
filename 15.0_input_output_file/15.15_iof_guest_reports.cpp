#include<iostream>
#include<fstream>
using namespace std;

const int MAX = 500;

void displayMenu();
int intVal(int minimum, int maximum);
void addReport();
void viewReports();
void searchReports();
bool isRoom(int searchRoom, int room);
void printReport(int room, const char guest[], const char report[]);

int main()
{
	int userOption = 0;	

	do
	{
		displayMenu();
		userOption = intVal(1, 4);

		if (userOption == 1)
		{
			addReport();
		}
		else if (userOption == 2)
		{
			viewReports();
		}
		else if (userOption == 3)
		{
			searchReports();
		}

	} while (userOption != 4);

	std::cout << '\n';

	return 0;
}


void displayMenu()
{
	std::cout << "\nWelcome to the Guest Report Registry"
	<< "\nSelect from  the following"
	<< "\n1. Add report"
	<< "\n2. View all reports"
	<< "\n3. Search reports by room"
	<< "\n4. Quit"
	<< "\n>> ";
}

int intVal(int minimum, int maximum)
{
	int value = 0;

	while (!(cin >> value) || value < minimum || value > maximum)
	{
		std::cout << "\nPlease input a valid entry!\n"
		<< ">> ";
		cin.clear();
		cin.ignore(10000, '\n');
	}
	
	return value;
}

void addReport()
{
	char guest[MAX];
	char report[MAX];
	int room = 0;

	std::cout << "\nGuest name: ";
	cin >> guest;
	std::cout << "\nRoom number: ";
	room = intVal(1, 500);
	cin.ignore(10000, '\n');
	std::cout << "\nReport: ";
	cin.getline(report, MAX);

	ofstream outFile("reports.txt", ios::app);

	if (!outFile)
	{
		std::cout << "\nThat file does not exist!\n";
		return;
	}

	outFile << guest << '\n' << room << '\n' << report << '\n';
	
	outFile.close();
}

void viewReports()
{
	char guest[MAX];
	char report[MAX];
	int room = 0;

	ifstream inFile("reports.txt");

	if (!inFile)
	{
		std::cout << "\nThat file does not exist!\n";
		return;
	}

	while (inFile >> guest >> room)
	{
		inFile.ignore(10000, '\n');
		inFile.getline(report, MAX);
		
		printReport(room, guest, report);
	}
	
	inFile.close();
}

void searchReports()
{

	int searchRoom = 0;
	int room = 0;
	char guest[MAX];
	char report[MAX];
	bool foundRoom = false;
	
	std::cout << "\nWhich room would you like to search for?: ";
	searchRoom = intVal(1, 500);

	ifstream inFile("reports.txt");

	if (!inFile)
	{
		std::cout << "\nFile does not exist!";
		return;
	}

	while (inFile >> guest >> room)
	{
		inFile.ignore(10000, '\n');
		inFile.getline(report, MAX);

		foundRoom = isRoom(searchRoom, room);

		if (isRoom(searchRoom, room))
		{
			printReport(searchRoom, guest, report);
			foundRoom = true;
		}
	}
		
		if (!foundRoom)
		{
			std::cout << "\nNo one is in that room.. yet";
		}

}

bool isRoom(int searchRoom, int room)
{
	if (searchRoom == room)
	{
		return true;
	}
	
	return false;
}


void printReport(int room, const char guest[], const char report[])
{
	std::cout << "\nGuest name: " << guest
	<< "\n\nRoom Number: " << room
	<< "\n\nReport: " << report << "\n\n";
}
