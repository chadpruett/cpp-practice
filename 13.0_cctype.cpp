#include<iostream>
#include<cctype>
using namespace std;


char getCharacter();
void printResult(char userInput);


int main()
{
	
	char userInput;

	std::cout << "\nEnter a character: ";
	userInput = getCharacter();
	
	printResult(userInput);

	return 0;
}

char getCharacter()
{
	char userInput;
	cin >> userInput;
	return userInput;
}

void printResult(char userInput)
{
	if (isdigit(userInput))
	{
		std::cout << "\nThat is a digit.";
	}
	else if (isalpha(userInput))
	{
		char upperCase = toupper(userInput);
		char lowerCase = tolower(userInput);

		std::cout << "\nThat is a letter."
		<< "\nOriginal: " << userInput
		<< "\nUppercase: " << upperCase
		<< "\nLowercase: " << lowerCase << endl;  
	}
	else if (isspace(userInput))
	{
		std::cout << "\nThat is a space.";
	}
	else if (ispunct(userInput))
	{
		std::cout << "\nthat is a punctuation.";
	}
	else
	{
		std::cout << "\nThat is something else.";
	}

	std::cout << '\n';
}








