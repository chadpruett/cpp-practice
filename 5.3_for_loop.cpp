#include <iostream>
using namespace std;

int getVal();
int getNums(int times, int& oddNums);
int intVal();

void printNums(int evenNums, int oddNums);

int main()
{
	int times = 0;
	int evenNums = 0;
	int oddNums = 0;
	
	times = getVal();
	evenNums = getNums(times, oddNums);
	printNums (evenNums, oddNums);

	return 0;
}

int getVal()
{
	int times = 0;

	std::cout << "\nHow many numbers?: ";

	while (!(cin >> times) || times <= 0)
	{
		std::cout << "\nPlease enter a valid integer above 0: ";
		cin.clear();
		cin.ignore(10000, '\n');
	}

	return times;
}

int getNums(int times, int& oddNums)
{
	int number = 0;
	int evenNums = 0;

	for (int i = 1; i <= times; i++)
	{
		std::cout << "\nEnter number " << i << ": ";
		number = intVal();
		
		if (number % 2 == 0)
		{
			evenNums++;
		}
		else 
		{
			oddNums++;
		}	
	}

	return evenNums;
}

int intVal()
{
	int value = 0;

	while (!(cin >> value))
	{
		std::cout << "\nPlease input a valid entry: ";
		cin.clear();
		cin.ignore(10000,'\n');
	}
	return value;
}

void printNums(int evenNums, int oddNums)
{
	std::cout << "\nEven numbers entered: " << evenNums
	<< "\nOdd number entered: " << oddNums << endl;
}
