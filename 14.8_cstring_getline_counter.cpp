#include<cctype>
#include<iostream>
using namespace std;

const int MAX = 40;

void getWord(char text[]);
int countWords(const char text[]);
void printResult(int wordCount);

int main()
{
	char text[MAX];
	int wordCount = 0;

	getWord(text);
	wordCount = countWords(text);
	printResult(wordCount);

	return 0;
}

void getWord(char text[])
{
	std::cout << "\nEnter word: ";
	cin.getline(text, MAX);
}

int countWords(const char text[])
{
	int i = 0;
	int wordCount = 0;
	bool insideWord = false;

	for (int i = 0; text[i] != '\0'; i++)
	{
		if (!isspace(text[i]) && !insideWord)
		{
			wordCount++;
			insideWord = true;
		}
		else if (isspace(text[i]))
		{
			insideWord = false;
		}
	}
	
	return wordCount;
}

void printResult(int wordCount)
{
	std::cout << "\nWords: " << wordCount << endl;
}


