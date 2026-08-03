#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

double calculateAverage(int& roomCount);
void printResult(double average, int roomCount);

int main()
{
	int roomCount = 0;
	double average = 0.0;

	average = calculateAverage(roomCount);
	printResult(average, roomCount);

	return 0;
}


double calculateAverage(int& roomCount)
{
	int roomNumber = 0;
	double average = 0;
	
	ifstream inFile("rooms.txt");

	if (!inFile)
	{
		std::cout << "\nError opening file!";
		return -1;
	}

	while (inFile >> roomNumber)
	{
		roomCount++;
		average += roomNumber;
	}

	if (roomCount == 0)
	{
		return -1;
	}

	return average / roomCount;
}

void printResult(double average, int roomCount)
{

	if (average == -1)
	{
		std::cout << "\nProgram failed to open!";
		return;
	}
	std::cout << fixed << setprecision(0)
	<< "\nRooms read: " << roomCount
	<< "\n\nAverage room number: " << average << endl;

}






