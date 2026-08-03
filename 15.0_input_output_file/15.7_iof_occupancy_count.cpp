#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

bool analyzeOccupancy(int& dayCount, int& lowest, int& highest, double& average);
void printResults(bool success, int dayCount, int lowest, int highest, double average);

int main()
{
	int dayCount = 0;
	int lowest = 0;
	int highest = 0;
	double average = 0;
	bool success = false;

	success = analyzeOccupancy(dayCount, lowest, highest, average);
	printResults(success, dayCount, lowest, highest, average);

	return 0;
}

bool analyzeOccupancy(int& dayCount, int& lowest, int& highest, double& average)
{
	int occupantCount = 0;
	int total = 0;

	ifstream inFile("occupancy.txt");

	if (!(inFile >> occupantCount))
	{
		std::cout << "\nError opening file!\n";
		return false;
	}

	dayCount++;
	lowest = occupantCount;
	highest = occupantCount;
	total += occupantCount;

	while (inFile >> occupantCount)
	{
		dayCount++;
		
		if (occupantCount < lowest)
		{
			lowest = occupantCount;
		}
		else if (occupantCount > highest)
		{
			highest = occupantCount;
		}

		total += occupantCount;	
	}

	average = static_cast<double>(total) / dayCount;

	return true;
}

void printResults(bool success, int dayCount, int lowest, int highest, double average)
{
	
	if (!success)
	{
		std::cout << "\nEither failed to load program or no occupants\n";
		return;
	}
	
	std::cout << fixed << setprecision(2)
	<< "\nDays recorded: " << dayCount
	<< "\nLowest occupancy: " << lowest
	<< "\nHighest occupancy: " << highest
	<< "\nAverage occupancy: " << average << endl;
}

