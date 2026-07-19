#include <iostream>
using namespace std;

int getTimes();
int getNums(int times);
int intVal();
void printLargestNum(int largestNum);

int main()
{
	int times = 0, largestNum = 0;

	times = getTimes();
	largestNum = getNums(times);
	
	printLargestNum(largestNum);

	return 0;
}

int getTimes()
{	
	std::cout << "\nHow many numbers?: ";
	int times = intVal();
	return times;	
}
int getNums(int times)
{
	int number = 0, i = 1;
	
	std::cout << "\nEnter number " << i << ": ";
	int largestNum = intVal();
	
	for (i = i+1; i <= times; i++)
	{
		std::cout << "\nEnter number " << i << ": ";
		number = intVal();

		if (number > largestNum)
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
