#include <iostream>
using namespace std;

int intVal();
void printTable(int number);

int main()
{
	int number = 0;

	std::cout << "\nEnter a number: ";
	number = intVal();

	printTable(number);

	return 0;
}

int intVal()
{
	int value = 0;
	
	while (!(cin >> value) || value < 0)
	{
		std::cout << "\nPlease input a valid entry: ";
		cin.clear();
		cin.ignore(10000,'\n');
	}

	return value;
}

void printTable(int number)
{
	for(int i = 0; i <= 10; i++)
	{
		std::cout << number << " x " << i << " = " << number * i << "\n";

	}

}
