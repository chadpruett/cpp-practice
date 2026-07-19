#include <iostream>
using namespace std;

const int SIZE = 5;

bool getsFreeShipping(double totals);
double doubleVal();
void getTotals(double totals[]);
void printResults(double totals[]);

int main()
{
	double totals[SIZE] = {0};
	
	getTotals(totals);
	
	printResults(totals);
	return 0;
}

void getTotals(double totals[])
{
	for (int i = 0; i < SIZE; i++)
	{
		std::cout << "\nOrder " << i + 1 << ": ";
		totals[i] = doubleVal();
	}
}

double doubleVal()
{
	double value = 0;

	while (!(cin >> value) || value < 0)
	{
		std::cout << "\nPlease input a valid entry: ";
		cin.clear();
		cin.ignore(10000,'\n');
	}

	return value;
}

bool getsFreeShipping(double totals)
{
	return totals >= 35.00;
}

void printResults(double totals[])
{

	for (int i = 0; i < SIZE; i++)
	{
		if(getsFreeShipping(totals[i]))
		{	
			std::cout << "\nOrder " << i + 1 << ": Free Shipping\n";
		}
		else
		{
			std::cout << "\nOrder " << i + 1 << ": No Free Shipping\n";
		}
	}
}


