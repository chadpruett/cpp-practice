#include<iostream>
using namespace std;

const int MAX = 40;

void getWords(char text[], char& target);
int countChar(const char text[], char target);
void printCount(int charCount);

int main()
{
	char text[MAX];
	char target;
	int charCount = 0;

	getWords(text, target);
	charCount = countChar(text, target);
	printCount(charCount);

	return 0;
}

void getWords(char text[], char& target)
{
	std::cout << "\nEnter text: ";
	cin >> text;
	std::cout << "\nEnter character: ";
	cin >> target;
}

int countChar(const char text[], char target)
{
	int charCount = 0;

	for (int i = 0; text[i] != '\0'; i++)
	{
		if (text[i] == target)
		{
			charCount++;
		}
	}
		return charCount;
}

void printCount(int charCount)
{
	std::cout << "\n\nCharacter appears " << charCount;

	if (charCount == 1)
	{
		std::cout << " time\n";
	}
	else
	{
		std::cout << " times\n";
	}
	
}



