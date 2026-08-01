#include<iostream>
using namespace std;

const int MAX = 40;

void getText(char text[], char& oldChar, char& newChar);
void replaceChar(char text[], const char oldChar, const char newChar);
void printNewText(const char text[]);

int main()
{
	char text[MAX];
	char oldChar;
	char newChar;

	getText(text, oldChar, newChar);
	replaceChar(text, oldChar, newChar);
	printNewText(text);

	return 0;
}

void getText(char text[], char& oldChar, char& newChar)
{
	std::cout << "\nEnter text: ";
	cin >> text;
	std::cout << "\nReplace: ";
	cin >> oldChar;
	std::cout << "\nWith: ";
	cin >> newChar;
}

void replaceChar(char text[], const char oldChar, const char newChar)
{
	for (int i = 0; text[i] != '\0'; i++)
	{
		if (text[i] == oldChar)
		{
			text[i] = newChar;
		}
	}
}
void printNewText(const char text[])
{
	std::cout << "\n\nNew Word: ";

	for (int i = 0; text[i] != '\0'; i++)
	{
		std::cout << text[i];
	}
	std::cout << "\n\n";
}
