#include <iostream>
using namespace std;

int getTimes();
int getNumbers(int times);
int intVal();
void printLargestNum(int largestNum);

int main()
{
	int times = 0;
	int largestNum = 0;

	times = getTimes();
	largestNum = getNumbers(times);
	printLargestNum(largestNum);

	return 0;
}

int getTimes()
{
	int times = 0;

	std::cout << "\nHow many numbers?: ";
	
	while (!(cin >> times) || times < 0)
	{
		std::cout << "\nPlease enter a positive integer: ";
		cin.clear();
		cin.ignore(10000,'\n');
	}

	return times;
}

int getNumbers(int times)
{
	int largestNum = 0;
	int number = 0;
	int i = 1;

	std::cout << "\nEnter number " << i << ": ";
	number = intVal();
	largestNum = number;

	for (i = i + 1; i <= times; i++)
	{
		std::cout << "\nEnter number " << i << ": ";
		number = intVal();

		if(number > largestNum)
		{
			largestNum = number;
		}
	}

	return largestNum;
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

void printLargestNum(int largestNum)
{
	std::cout << "\nLargest number: " << largestNum << endl;
}
