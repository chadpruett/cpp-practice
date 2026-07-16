#include <iostream>
using namespace std;

const int SIZE = 5;

int intVal();
int getHighest(int scores[]);
void getScores(int scores[]);
void printScoresAndHighest(int scores[], int highest);

int main()
{
	int scores[SIZE] = {0};
	int highest = 0;

	getScores(scores);
	printScoresAndHighest(scores, highest);

return 0;
}

void getScores(int scores[])
{
	for (int i = 0; i <= SIZE; i++)
	{
		std::cout << "\nEnter Score " << i << ": ";
		scores[i] = intVal();
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

int getHighest(int scores[])
{
	int i = 0;
	int highest = scores[i];

	for (int i = 1; i <= SIZE; i++)
	{
		if (scores[i] > highest)
		{	
			highest = scores[i];
		}
	}
	return highest;		
}

void printScoresAndHighest(int scores[], int highest)
{
	std::cout << "\nScores:" << endl;
	
	for (int i = 0; i <= SIZE; i++)
	{
		std::cout << scores[i] << '\n';
	}
	
	std::cout << "\nHighest Score: " << highest << endl;
}
