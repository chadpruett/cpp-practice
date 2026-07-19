#include <iostream>
using namespace std;

int getNumber();
int intVal();
bool isEven(int number);
void printResult(bool isEvenNumber);

int main()
{
	int number = getNumber();

	bool isEvenNumber = isEven(number);	

	printResult(isEvenNumber);

	return 0;
}

int getNumber()
{
	int number = 0;
	
	std::cout << "\nPlease enter a number: ";
	number = intVal();

	return number;
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


bool isEven(int number)
{
	return number % 2 == 0;
}

void printResult(bool isEvenNumber)
{
	if (isEvenNumber)
	{
		std::cout << "\nThe number is even\n";
	}
	else
	{
		std:cout << "\nThe number is odd\n";
	}
}
