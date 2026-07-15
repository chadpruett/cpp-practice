#include <iostream>
#include <iomanip>
using namespace std;

const int SIZE = 5;

int intVal();
void getScores(int scores[]);
void calcTotAvg(int scores[], int& total, double& avg);
void printScorTotAvg(int scores[], int total, double avg);

int main()
{

	int total = 0;
	double avg = 0;
	int scores[SIZE] = {0};

	getScores(scores);
	calcTotAvg(scores, total, avg);
	printScorTotAvg(scores, total, avg);

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

	while (!(cin >> value) || value < 0)
	{
		std::cout << "\nPlease input a valid entry: ";
		cin.clear();
		cin.ignore(10000,'\n');
	}

	return value;
}

void calcTotAvg(int scores[], int& total, double& avg)
{
	for (int i = 0; i < SIZE; i++)
	{
		total += scores[i];
	}
	
	avg = static_cast<double> (total) / SIZE;
}

void printScorTotAvg(int scores[], int total, double avg)
{
	
	std::cout << fixed << setprecision(1) << "\n\nScores:\n";
	
	for (int i = 0; i < SIZE; i++)
	{
		std::cout << scores[i] << endl;
	}
	
	std::cout << "\nTotal: " << total << "\nAverage: " << avg << endl;
}
