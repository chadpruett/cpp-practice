#include <iostream>
using namespace std;

const int MAX = 5;

void getScores(int testScores[]);
int intVal();
void printIfPassing(int testScores[]);
bool isPassing(int testScores);

int main()
{
	int testScores[MAX] = {0};
	getScores(testScores);
	printIfPassing(testScores);

	return 0;
}

void getScores(int testScores[])
{
	for (int i = 0; i < MAX; i++)
	{
		std::cout << "\nScore " << i + 1 << ": ";
		testScores[i] = intVal();	
	}
}

int intVal()
{
	int value = 0;

	while (!(cin >> value) ||  value < 0 || value > 100)
	{
		std::cout << "\nPlease input a valid entry: ";
		cin.clear();
		cin.ignore(10000,'\n');
	}

	return value;
}
void printIfPassing(int testScores[])
{
	for (int i = 0; i < MAX; i++)
	{
		if (isPassing(testScores[i]))
		{
			std::cout << "\nScore " << i + 1 << ": Passing";
		}
		else
		{
			std::cout << "\nScore " << i + 1 << ": Failing";
		}


	}
}

bool isPassing(int testScores)
{
	return testScores >= 70;
}
