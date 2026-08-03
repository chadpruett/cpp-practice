#include<iostream>
#include<fstream>
using namespace std;

const int MAX = 50;

bool myStrCompare(const char search[], const char guests[]);
void getSearch(char search[]);
bool findGuest(const char search[]);
void printResult(bool found);

int main()
{
	char search[MAX];
	bool hasGuest = false;

	getSearch(search);
	hasGuest = findGuest(search);
	printResult(hasGuest);

	return 0;
}

void getSearch(char search[])
{
	std::cout << "\nSearch for guest: ";
	cin.getline(search, MAX);
}

bool myStrCompare(const char search[], const char guests[])
{
	int i = 0;

	while (search[i] != '\0' && guests[i] != '\0')
	{
		if (search[i] != guests[i])
		{
			return false;
		}
		
		i++;
	}
	
	return search[i] == '\0' && guests[i] == '\0';
}


bool findGuest(const char search[])
{
	char guests[MAX];

	ifstream inFile("guests.txt");

	if (!inFile)
	{
		std::cout << "\nError opening file!";
		return false;
	}

	while (inFile.getline(guests, MAX))
	{
		if (myStrCompare(search, guests))
		{
			return true;
		}
	}

	inFile.close();
	
	return false;
}

void printResult(bool found)
{
	if (found)
	{
		std::cout << "\nGuest found\n";
	}
	else
	{
		std::cout << "\nGuest not found\n";
	}
}
