#include<iostream>
using namespace std;

const int PEOPLE = 5;
const int SIZE = 20;

void getNames(char names[][SIZE]);
int getLength(const char name[]);
void printLengths(const char names[][SIZE]);

int main()
{
	char names[PEOPLE][SIZE];

	getNames(names);

	printLengths(names);

	return 0;
}

void getNames(char names[][SIZE])
{

	for (int i = 0; i < PEOPLE; i++ )
	{
		std::cout << "\nEnter name " << i + 1 << ": ";
		cin >> names[i];
	}
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

void printLengths(const char names[][SIZE])
{
	int length = 0;
	int total = 0;

	for (int i = 0; i < PEOPLE; i++)
	{
		length = getLength(names[i]);
		total += length;

		if (length > 1)
		{
			std::cout << '\n' << names[i] << " has " << length
			<< " letters.";
		}
		else
		{
			std::cout << '\n' << names[i] << " has " << length
			<< " letter.";
		}

	}

	std::cout << "\n\nTotal letters: " << total << endl;
}
