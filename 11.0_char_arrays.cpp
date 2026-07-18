#include<iostream>
using namespace std;

const int SIZE = 20;

void getName(char name[]);
void printName(char name[]);
void printLetters(char name[]);
void getLength(char name[], int& length);
void printBackwards(char name[], int length);

int main()
{
	char name[SIZE];
	int length = 0;
	
	getName(name);
	printName(name);
	printLetters(name);
	getLength(name, length);
	printBackwards(name, length);

	return 0;
}

void getName(char name[])
{
	std::cout << "\nEnter you first name: ";
	
	while (!(cin >> name))
	{
		std::cout << "\nPlease input a valild entry: ";
		cin.clear();
		cin.ignore(10000,'\n');
		std::cout << "\nEnter your first name: ";
	}
}


void printName(char name[])
{
	std::cout << "\nYour name is: " << name << endl;
}

void printLetters(char name[])
{
	for (int i = 0; name[i] != '\0'; i++)
	{
		std::cout << "\n" << name[i];
	}
}

void getLength(char name[], int& length)
{

	for (int i = 0; name[i] != '\0'; i++)
	{
		length++;
	}

	std::cout << "\n\nLength: " << length << "\n\n";
}

void printBackwards(char name[], int length)
{
	for (int i = length; i > 0; i--)
	{
		std::cout << name[i - 1] << endl;
	}


}
