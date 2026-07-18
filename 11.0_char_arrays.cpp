#include<iostream>
using namespace std;

const int SIZE = 20;

void getName(char name[]);
void printName(const char name[]);
void printLetters(const char name[]);
int getLength(const char name[]);
void printBackwards(const char name[], int length);

int main()
{
	char name[SIZE];
	int length = 0;
	
	getName(name);
	printName(name);
	printLetters(name);
	length = getLength(name);
	printBackwards(name, length);

	return 0;
}

void getName(char name[])
{
	std::cout << "\nEnter you first name: ";
	
	while (!(cin >> name))
	{
		std::cout << "\nPlease input a valid entry: ";
		cin.clear();
		cin.ignore(10000,'\n');
		std::cout << "\nEnter your first name: ";
	}
}


void printName(const char name[])
{
	std::cout << "\nYour name is: " << name << endl;
}

void printLetters(const char name[])
{
	for (int i = 0; name[i] != '\0'; i++)
	{
		std::cout << "\n" << name[i];
	}
}

int getLength(const char name[])
{
	int value = 0;

	for (int i = 0; name[i] != '\0'; i++)
	{
		value++;
	}

	std::cout << "\n\nLength: " << value << "\n\n";
	
	return value;
}

void printBackwards(const char name[], int length)
{
	for (int i = length; i > 0; i--)
	{
		std::cout << name[i - 1] << endl;
	}


}
