#include<iostream>
using namespace std;

const int MAX = 5;

int intVal();
void getScores(int scores[]);
bool isPassing(int score);
void printResults(int scores[]);

int main()
{
	int scores[MAX] = {0};
	
	getScores(scores);

	printResults(scores);

	return 0;
}

void getScores(int scores[])
{
	for(int i = 0; i < MAX; i++)
	{
		std::cout << "\nEnter score " << i + 1 << ": ";
		scores[i] = intVal();
	}

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

bool isPassing(int score)
{
	return score > 70;
}

void printResults(int scores[])
{
	std::cout << "\nResults:";

	for (int i = 0; i < MAX; i++)
	{
		std::cout << "\nScore " << i + 1 << ": " << scores[i];
		
		if(isPassing(scores[i]))
		{
			std::cout << " - Passing\n";
		}
		else
		{
			std::cout << " - Failing\n";
		}

	}
}



