#include <iostream>
#include <iomanip>
using namespace std;

int getCount();
int intVal();
void getScores(int scores[], int count);
void calcTotAvg(int scores[], int count, int&total, double& avg);
void printScorTotAvg(int scores[], int count, int total, double avg);

int main()
{
	int count = getCount();
	int total = 0;
	double avg = 0;
	int scores[count] = {0};

	getScores(scores, count);
	calcTotAvg(scores, count, total, avg);
	printScorTotAvg(scores, count, total, avg);

	return 0;
}

int getCount()
{
	int count = 0;

	std::cout << "\nHow many scores?: ";
	count = intVal();

	return count;
}
void getScores(int scores[], int count)
{
	for (int i = 0; i < count; i++)
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

void calcTotAvg(int scores[], int count, int& total, double& avg)
{
	for (int i = 0; i < count; i++)
	{
		total += scores[i];
	}
	
	avg = static_cast<double> (total) / count;
}

void printScorTotAvg(int scores[], int count, int total, double avg)
{
	for (int i = 0; i < count; i++)
	{
		std::cout << scores[i] << endl;
	}
	
	std::cout << fixed << setprecision(1) << "\n\nScores:\n";
	std::cout << "\nTotal: " << total << "\nAverage: " << avg << endl;
}
