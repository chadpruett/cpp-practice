#include <iostream>
using namespace std;

const int SIZE = 5;

int intVal();
void getHighLow(int scores[], int& highest, int& lowest);
void getScores(int scores[]);
void printScoresAndHighLow(int scores[], int highest, int lowest);

int main()
{
	int scores[SIZE] = {0};
	int highest = 0;
	int lowest = 0;

	getScores(scores);
	getHighLow(scores, highest, lowest);
	printScoresAndHighLow(scores, highest, lowest);

return 0;
}

void getScores(int scores[])
{
	for (int i = 0; i < SIZE; i++)
	{
		std::cout << "\nEnter Score " << i + 1 << ": ";
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

void getHighLow(int scores[], int& highest, int& lowest)
{
	highest = scores[0];
	lowest = scores[0];

	for (int i = 1; i < SIZE; i++)
	{
		if (scores[i] > highest)
		{	
			highest = scores[i];
		}
		else if (scores[i] < lowest)
		{
			lowest = scores[i];
		}
	}
}

void printScoresAndHighLow(int scores[], int highest, int lowest)
{
	std::cout << "\nScores:" << endl;
	
	for (int i = 0; i < SIZE; i++)
	{
		std::cout << scores[i] << '\n';
	}
	
	std::cout << "\nHighest Score: " << highest
	<< "\nLowest Score: " << lowest << endl;
}
