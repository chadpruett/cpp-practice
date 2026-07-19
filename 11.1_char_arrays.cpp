#include<iostream>
using namespace std;

const int PEOPLE = 3;
const int SIZE = 20;

void getNames(char names[][SIZE]);
void printNames(const char names[][SIZE]);
void printFirstLetter(const char names[][SIZE]);

int main()
{
	char names[PEOPLE][SIZE];
	
	getNames(names);
	printNames(names);
	printFirstLetter(names);
	return 0;
}

void getNames(char names[][SIZE])
{
	for (int i = 0; i < PEOPLE; i++)
	{
		std::cout << "\nEnter name " << i + 1 << ": ";

		while(!(cin >> names[i]))
		{
			std::cout << "\nPlease input a valid entry: ";
			cin.clear();
			cin.ignore(10000,'\n');
		}
	}

}

void printNames(const char names[][SIZE])
{
	std::cout << "\n\nNames Entered:";
	
	for (int i = 0; i < PEOPLE; i++)
	{
		std::cout << names[i] << '\n';

	}
	std::cout << '\n';
}

void printFirstLetter(const char names[][SIZE])
{
	std::cout << "\n\nFirst Letters:";

	for (int i = 0; i < PEOPLE; i++)
	{
		std::cout << '\n' << names[i][0];

	}

	std::cout << '\n';
}
