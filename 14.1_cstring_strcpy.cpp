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
	int j = 0;
	
	for (int i = 0; source[i] != '\0'; i++)
	{
		destination[i] = source[i];
		j++;
	}

	destination[j] = '\0';

}
void printWords(const char source[], const char destination[])
{
	std::cout << '\n' << source << ' ' << destination << endl;
}



