#include<iostream>
#include<fstream>
using namespace std;

const int MAX = 50;

int countGuests();
void printTotal(int total);


int main()
{
	int total = 0;

	total = countGuests();
	printTotal(total);

	return 0;
}

int countGuests()
{
	int count = 0;
	char guests[MAX];

	ifstream inFile("guests.txt");

	if (!inFile)
	{
		std::cout << "\nError";
		return 1;
	}

	while (inFile.getline(guests,MAX))
	{
		std::cout << "\nGuest: " << guests;
		count++;
	}
	
	inFile.close();

	std::cout << "\n\n";

	

	return count;

}

void printTotal(int total)
{
	std::cout << "\nTotal guests: " << total << "\n\n";
}
