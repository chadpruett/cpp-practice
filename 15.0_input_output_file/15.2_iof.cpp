#include<iostream>
#include<fstream>
using namespace std;

const int MAX = 50;

void getGuest(char guest[]);
void writeGuest(const char guest[]);
void readGuests();

int main()
{
	char guest[MAX];
	
	getGuest(guest);
	writeGuest(guest);
	readGuests();

	return 0;
}

void getGuest(char guest[])
{
	std::cout << "\nGuest: ";
	cin.getline(guest, MAX);	
}


void writeGuest(const char guest[])
{
	ofstream outFile;
	outFile.open("guests.txt", ios::app);
	
	if (!outFile)
	{
		std::cout << "\nError";
		return;
	}

	outFile << guest << '\n';
	outFile.close();
}

void readGuests()
{
	char guest[MAX];

	ifstream inFile;
	inFile.open("guests.txt");

	if (!inFile)
	{
		std::cout << "\nError";
		return;
	}

	while (inFile.getline(guest, MAX))
	{
		std::cout << "\nGuest: " << guest << endl;	
	}

	inFile.close();
}
