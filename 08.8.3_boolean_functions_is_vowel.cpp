#include<iostream>
#include<cctype>
using namespace std;

void getLetter(char& letter);
bool isVowel(char letter);
void printResult(char letter);
void keepGoing(char& letter);

int main()
{

	
	char userLetter;
	char userContinue;
	
	do
	{
		getLetter(userLetter);
		printResult(userLetter);
		keepGoing(userContinue);

	} while (userContinue != 'n');

	return 0;
}

void getLetter(char& letter)
{
	std::cout << "\nEnter a letter: ";
	std::cin >> letter;
	letter = tolower(letter);
}

bool isVowel(char letter)
{
	return 
	letter == 'a' ||
	letter == 'e' ||
	letter == 'i' ||
	letter == 'o' ||
	letter == 'u';
}

void printResult(char letter)
{
	
	if (isVowel(letter))
	{
		std::cout << '\n' << letter << " is a vowel" << endl;
	}	
	else
	{
		std::cout << '\n' << letter << " is NOT a vowel" << endl;
	}

}

void keepGoing(char& letter)
{
	std::cout << "\nWould you like to keep going? (y/n): ";
	std::cin >> letter;
	letter = tolower(letter);
}



