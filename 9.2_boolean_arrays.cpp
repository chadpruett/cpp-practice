#include <iostream>
using namespace std;

const int SIZE = 5;

bool isAdult(int age);

int intVal();

void getAges(int ages[]);
void printResults(int ages[]);

int main()
{
	int ages[SIZE] = {0};
	
	getAges(ages);
	printResults(ages);

	return 0;
}

void getAges(int ages[])
{
	for (int i = 0; i < SIZE; i++)
	{
		
		std::cout << "\nAge " << i + 1 << ": ";
		ages[i] = intVal();
	}
}

int intVal()
{
	int value = 0;

	while (!(cin >> value) || value < 0 || value > 120)
	{
		std::cout << "\nPlease input a valid entry: ";
		cin.clear();
		cin.ignore(10000,'\n');
	}

	return value;
}

bool isAdult(int age)
{
	return age >= 18;
}

void printResults(int ages[])
{
	for(int i = 0; i < SIZE; i++)
	{
		if (isAdult(ages[i]))
		{		
			std::cout << "\nAge " << i + 1 << ": Adult\n";
		}
		else
		{
			std::cout << "\nAge " << i + 1 << ": Minor\n";
		}
	}
}
