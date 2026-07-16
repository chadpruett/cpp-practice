#include <iostream>
using namespace std;

int getNumber();
int intVal();
bool isPositive(int number);
void printResult(bool posOrNeg);

int main ()
{
	int number = getNumber();
	bool posOrNeg = isPositive(number);
	printResult(posOrNeg);	
	

	return 0;
}

int getNumber()
{
	std::cout << "\nEnter a number: ";
	int number = intVal();
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

bool isPositive(int number)
{
	return number > 0;
}

void printResult(bool posOrNeg)
{
	if (posOrNeg)
	{
		std::cout << "\nThe number is positive\n";
	}
	else
	{
		std::cout << "\nThe number is NOT positive\n";
	}
}
