#include<iostream>
using namespace std;

const int PEOPLE = 5;
const int SIZE = 20;

void getNames(char names[][SIZE]);
int getLength(const char names[]);
void printSummary(const char names[][SIZE]);


int main()
{
	char names[PEOPLE][SIZE];
	
	getNames(names);
	printSummary(names);

	return 0;
}

void getNames(char names[][SIZE])
{
	for (int i = 0; i < PEOPLE; i++)
	{
		std::cout << "\nEnter name " << i + 1 << ": ";
		cin >> names[i];
	}
}

int getLength(const char names[])
{
	int length = 0;

	for (int i = 0; names[i] != '\0'; i++)
	{
		length++;
	}
	return length;
}

void printSummary(const char names[][SIZE])
{	
	int length = 0;
	int longestIndex = 0;
	int longestLength = getLength(names[0]);
	int shortestIndex = 0;
	int shortestLength = getLength(names[0]);
 	int totalLetters = 0;

	for (int i = 0; i < PEOPLE; i++)
	{
		length = getLength(names[i]);
		totalLetters += length; 
				
		if (length > longestLength)
		{
			longestLength = length;
			longestIndex = i;
		}		
		else if (length < shortestLength)
		{
			shortestLength = length;
			shortestIndex = i;
		}

	}
		std::cout << "\nLongest name: " << names[longestIndex]
		<< "\nShortest name: " << names[shortestIndex]
		<< "\nTotal letters: " << totalLetters
		<< "\nAverage Length: " << static_cast<double>(totalLetters) / PEOPLE << endl;
}


