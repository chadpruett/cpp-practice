#include<iostream>
using namespace std;

const int MAX = 20;

void getWords(char destination[], char source[]);
void myStrCat(char destination[], const char source[]);
void printedWords(const char destination[]);

int main()
{
	char source[MAX];
	char destination[MAX];

	getWords(destination, source);
	myStrCat(destination, source);
	printedWords(destination);

	return 0;
}

void getWords(char destination[], char source[])
{
	std::cout << "\nEnter destination word: ";
	cin >> destination;
	std::cout << "\nEnter source word: ";
	cin >> source;
}

void myStrCat(char destination[], const char source[])
{
	int i = 0;

	for (i = 0; destination[i] != '\0'; i++)
	{
		i++;
	}

	for (int j = 0; source[j] != '\0'; j++)
	{
		destination[i] = source[j];
	}
}

void printedWords(const char destination[])
{
	std::cout << "\nYour new word: ";

	for (int i = 0; destination[i] != '\0'; i++)
	{
		std::cout <<  destination[i];
	}
}




