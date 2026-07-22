#include<iostream>
using namespace std;

char getChar();
bool isVowel(char letter);
void printResult(char userChar);

int main()
{
	char userChar = getChar();

	printResult(userChar);

	return 0;
}

char getChar()
{
	char value;
	
	cin >> value;

	return value;
}

bool isVowel(char letter)
{
	return letter == 'a' || letter == 'A' ||
	letter == 'e' || letter == 'E' ||
	letter == 'i' || letter == 'I' ||
	letter == 'o' || letter == 'O' ||
	letter == 'u' || letter == 'U';
}

void printResult(char userChar)
{
	if (isVowel(userChar))
	{
		std::cout << "\nThat character is a vowel\n";
	}
	else
	{
		std::cout << "\nThat character is NOT a vowel\n";
	}
}






