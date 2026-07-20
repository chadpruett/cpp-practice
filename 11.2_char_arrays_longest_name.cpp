#include<iostream>
using namespace std;

const int PEOPLE = 5;
const int SIZE = 20;

void getNames(char names[][SIZE]);
void printNames(const char names[][SIZE]);
int getLength(const char name[]);

int main()
{
	char names[PEOPLE][SIZE];
	
	getNames(names);
	printNames(names);

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

void printNames(const char names[][SIZE])
{
	int length = 0;
	int maxLength = 0;
	string longestName = " ";

	std::cout << "\n\nNames Entered:\n";

	for (int i = 0; i < PEOPLE; i++)
	{
		std::cout << names[i] << endl;
		length = getLength(names[i]);
		if (length > maxLength)
		{
			maxLength = length;
			longestName = names[i];
		}
	}

	std::cout << "\nLongest Name: " << longestName 
	<< "\nLength: " << maxLength << endl;
}

int getLength(const char name[])
{
	int length = 0;

	for (int i = 0; name[i] != '\0'; i++)
	{
		length++;
	}

	return length;
}
