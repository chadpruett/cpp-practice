#include<iostream>
using namespace std;

char getChar();
bool isVowel(char letter);
void printResult(bool vowel);

int main()
{
	bool vowel = 'true';	

	char userChar = getChar();

	vowel = isVowel(userChar);
	
	printResult(vowel);

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
	return letter == 'a' || letter ==  'e' || letter == 'i' || letter == 'o' || letter == 'u';
}

void printResult(bool vowel)
{
	if (vowel)
	{
		std::cout << "\nThat character is a vowel\n";
	}
	else
	{
		std::cout << "\nThat character is NOT a vowel\n";
	}
}






