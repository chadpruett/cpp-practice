#include<iostream>
using namespace std;

const int PEOPLE = 5;
const int SIZE = 20;

void getNames(char names[][SIZE]);
int getLength(char names[]);
void printSummary(char names[][SIZE]);


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

int getLength(char names[])
{
	int length = 0;

	for (int i = 0; names[i] != '\0'; i++)
	{
		length++;
	}
	return length;
}

void printSummary(char names[][SIZE])
{	
	int length = 0;
	int longestName = 0;
	int shortestName = 0;
 	int totalLetters = 0;

	for (int i = 0; i < PEOPLE; i++)
	{
		length = getLength(names[i]);
		totalLetters += length; 
				
		if (length > longestName)
		{
			longestName = i;
		}		
		else if (length < shortestName)
		{
			shortestName = i;
		}

	}
		std::cout << "\nLongest name: " << names[longestName]
		<< "\nShortest name: " << names[shortestName]
		<< "\nTotal letters: " << totalLetters
		<< "\nAverage Length: " << totalLetters / PEOPLE << endl;
}


