#include<iostream>
using namespace std;

const int SIZE = 15;

void getWord(char word[]);
int myStrLen(const char word[]);
void printLength(const int length, const char word[]);

int main()
{
	char word[SIZE];
	int length = 0;

	getWord(word);
	length = myStrLen(word);
	printLength(length, word);

	return 0;
}

void getWord(char word[])
{
	std::cout << "\nEnter a word: ";
	
	cin >> word;
}

int myStrLen(const char word[])
{
	int count = 0;

	for (int i = 0; word[i] != '\0'; i++)
	{
		count++;
	}
	
	return count;
}

void printLength(const int length, const char word[])
{
	
	std::cout << "\nWord: " << word
	<< "\nLength: " << length << endl;
}

