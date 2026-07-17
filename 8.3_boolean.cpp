#include <iostream>
using namespace std;

int getVal();
bool isFullTime(int hours);
void printResult(bool fullTime);

int main()
{
	std::cout << "\nHow many hours worked per week?: ";
	int hours = getVal();

	bool fullTime = isFullTime(hours);
	printResult(fullTime);

	return 0;
}

int getVal()
{
	int value = 0;

	while (!(cin >> value) || value < 0 || value > 50)
	{
		std::cout << "\nPlease input a valid entry: ";
		cin.clear();
		cin.ignore(10000,'\n');
	}

	return value;
}

bool isFullTime(int hours)
{
	return hours >= 20;

}

void printResult(bool fullTime)
{
	if (fullTime)
	{	
		std::cout << "\nYou've worked enough hours for benefits!" << endl;
	}
	else 
	{
		std::cout << "\nYou need to work at least 20 hours for benefits." << endl;
	}
}
