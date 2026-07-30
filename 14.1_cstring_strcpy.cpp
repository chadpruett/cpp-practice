#include<iostream>
using namespace std;

const int SIZE = 20;

void getWord(char source[]);
void myStrCpy(char destination[], const char source[]);
void printWords(const char source[], const char destination[]);

int main()
{
	char word[SIZE];
	char place[SIZE];

	getWord(word);
	myStrCpy(place, word);
	printWords(word, place);

	return 0;
}


void getWord(char source[])
{
	std::cout << "\nEnter a word: ";
	cin >> source;
}

void myStrCpy(char destination[], const char source[])
{
	int count = 0;
	
	for (int j = 0; source[j] != '\0'; j++)
	{
		count++;
	}
	
	for (int i = 0; i <= count; i++)
	{
		destination[i] = source[i];
	}

}
void printWords(const char source[], const char destination[])
{
	std::cout << '\n' << source << ' ' << destination << endl;
}



