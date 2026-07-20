#include <iostream>
using namespace std;

void getNumbers(int numbers[]);
int intVal();
void printNumbers(int numbers[]);

int main()
{
	int numbers[5] = {0};
	
	getNumbers(numbers);	
	printNumbers(numbers);
	return 0;
}

void getNumbers(int numbers[])
{
	for (int i = 0; i < 5; i++)
	{
	std::cout << "\nEnter Number " << i + 1 << ": ";
	numbers[i] = intVal();
	}
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

void printNumbers(int numbers[])
{
	std::cout << "\nYou Entered:\n";
	for (int i = 0; i < 5; i++)
	{
		std::cout << numbers[i] << endl;
	}

}
