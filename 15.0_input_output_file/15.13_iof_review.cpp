#include<iostream>
#include<fstream>
using namespace std;

const int MAX = 500;

int intVal(int minimum, int maximum);
void welcome();
void addLog();
void readAllLogs();
void searchLogs();
void printLog(const char author[], int roomNumber, const char message[]);
void goodbye();

int main()
{
	int userOption = 0;

	do
	{
		welcome();
		userOption = intVal(1, 4);

		if (userOption == 1)
		{
			addLog();
		}
		else if (userOption == 2)
		{
			readAllLogs();
		}
		else if (userOption == 3)
		{
			searchLogs();
		}

	} while (userOption != 4);

	goodbye();

	return 0;
}

void welcome()
{
	std::cout << "\nBOOTING LOG MODULE........."
	<< "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"
	<< "MODULE....STAUS....OKAY"
	<< "\n1. ADD A LOG"	
	<< "\n2. READ ALL LOGS"
	<< "\n3. SEARCH LOGS BY ROOM"
	<< "\n4. QUIT"
	<< "\n>> ";
}

int intVal(int minimum, int maximum)
{
	int value = 0;
	
	while (!(cin >> value) || value < minimum || value > maximum)
	{
		std::cout << "\nPlease input a valid entry: "
		<< "\n>> ";
		cin.clear();
		cin.ignore(10000, '\n');
	}

	return value;
}

void addLog()
{
	char author[MAX];
	char message[MAX];
	int roomNumber = 0;

	std::cout << "\nAuthor: ";
	cin >> author;
	std::cout << "\nRoom Number: ";
	roomNumber = intVal(1, 500);
	cin.ignore(10000, '\n');
	std::cout << "\nMessage:";
	cin.getline(message, MAX);

	ofstream outFile("logs.txt", ios::app);

	if (!outFile)
	{
		std::cout << "\nError opening file!";
		return;
	}

	outFile << author
	<< '\n' << roomNumber
	<< '\n' << message << '\n';

	outFile.close();
}

void readAllLogs()
{
	char author[MAX];
	char message[MAX];
	int roomNumber = 0;

	ifstream inFile("logs.txt");

	if (!inFile)
	{
		std::cout << "\nError opening file";
		return;
	}

	while (inFile >> author >> roomNumber)
	{
		inFile.ignore(10000,'\n');
		inFile.getline(message,MAX);
		
		printLog(author, roomNumber, message);
	}
}

void searchLogs()
{
	char author[MAX];
	char message[MAX];
	int roomNumber = 0;
	int searchNumber = 0;
	bool foundRoom = false;

	std::cout << "\nWhich room number would you like to read?: ";
	cin >> searchNumber;

	ifstream inFile("logs.txt");

	while (inFile >> author >> roomNumber)
	{
		inFile.ignore(10000, '\n');
		inFile.getline(message, MAX);
		
		if (searchNumber == roomNumber)
		{
			printLog(author, roomNumber, message);
			foundRoom = true;
		}
	}
	
	if (!foundRoom)
	{
		std::cout << "\nRoom does not exist";
	}

}

void printLog(const char author[], int roomNumber, const char message[])
{
	std::cout << "\nAuthor: " << author
	<< "\nRoom Number: " << roomNumber
	<< "\nMessage: " << message << '\n' << endl;
}

void goodbye()
{
	std::cout << "\n\nLOG MODULE TERMINATING....\n\n";
}


