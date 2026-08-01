#include<iostream>
using namespace std;

const int MAX = 30;

void getText(char text[]);
void myStrReverse(char text[]);
void printReverse(const char text[]);

int main()
{
	char text[MAX];

	getText(text);
	myStrReverse(text);
	printReverse(text);

	return 0;
}

void getText(char text[])
{
	std::cout << "\nEnter word: ";
	cin >> text;
}

void myStrReverse(char text[])
{
	int length = 0;
	int index = 0;
	char tempChar;

	while (text[length] != '\0')
	{
		length++;
	}

	index = length;

	for (int i = 0; i < length / 2; i++)
	{
		tempChar = text[i];
		text[i] = text[index - 1];
		text[index - 1] = tempChar;
		index--;
	}

	std::cout << endl;
}

void printReverse(const char text[])
{
	std::cout << "\nWord Backwards: ";
	
	for (int i = 0; text[i] != '\0'; i++)
	{
		std::cout << text[i];
	}

	std::cout << "\n\n";
}

