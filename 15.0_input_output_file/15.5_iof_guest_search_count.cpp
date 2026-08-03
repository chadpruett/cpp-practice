#include<iostream>
#include<fstream>
using namespace std;

const int MAX = 50;

void getSearch(char search[]);
bool myStrCompare(const char search[], const char guests[]);
int countGuest(const char search[]);
void printResult(const char search[], int count);

int main()
{
	char search[MAX];
	int count = 0;

	getSearch(search);
	count = countGuest(search);
	printResult(search, count);

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
		if (search[i] == guests[i])
		{
			i++;
		}
		else
		{
			return false;
		}
	}

	return search[i] == '\0' && guests[i] == '\0';
}

int countGuest(const char search[])
{
	char guests[MAX];
	int count = 0;

	ifstream inFile("guests.txt");

	if (!inFile)
	{
		std::cout << "\nError opening file!\n";
		return -1;
	}
	
	while (inFile.getline(guests, MAX))
	{
		if (myStrCompare(search, guests))
		{
			count++;
		}
	}

	inFile.close();

	return count;
}

void printResult(const char search[], int count)
{
	if (count == -1)
	{
		std::cout << "\nProgram failed to open\n";
	}
	else
	{
		std::cout << '\n' << search << " appears " << count
		<< " time(s).\n";
	}
}
