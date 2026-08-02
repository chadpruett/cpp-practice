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

	ofstream oFile;
	oFile.open("guests.txt", ios::app);

	oFile << guest;
	oFile.close();
}

void readGuests()
{
	char guest[MAX];

	ifstream iFile;
	iFile.open("guests.txt");

	while (iFile.getline(guest, MAX))
	{
		std::cout << "\nGuest: " << guest << endl;	
	}

	iFile.close();
}
