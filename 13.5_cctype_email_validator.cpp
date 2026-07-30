#include<iostream>
#include<cctype>
#include<iomanip>
using namespace std;

const int SIZE = 30;


void getEmail(char email[]);
void validateEmail(const char email[],
		   bool& hasLetter,
		   bool& hasOneAt,
		   bool& hasDotAfterAt,
		   bool& hasNoSpaces,
		   bool& hasEightChars);
void printResult(bool hasLetter, bool hasOneAt, bool hasDotAfterAt, bool hasNoSpaces, bool hasEightChars);

int main()
{
	char email[SIZE];
	bool hasLetter = false;
	bool hasOneAt = false;
	bool hasDotAfterAt = false;
	bool hasNoSpaces = false;	
	bool hasEightChars = false;

	getEmail(email);
	validateEmail(email, hasLetter, hasOneAt, hasDotAfterAt, hasNoSpaces, hasEightChars);
	printResult(hasLetter, hasOneAt, hasDotAfterAt, hasNoSpaces, hasEightChars);

	return 0;
}

void getEmail(char email[])
{
	std::cout << "\nPlease enter your email: ";	
	cin >> email;
}

void validateEmail(const char email[],
		   bool& hasLetter,
		   bool& hasOneAt,
		   bool& hasDotAfterAt,
		   bool& hasNoSpaces,
		   bool& hasEightChars)
{
	int atCount = 0;
	
	for (int i = 0; email[i] != '\0'; i++)
	{
		if (isalpha(email[i]))
		{
			hasLetter = true;
		}
		if (email[i] == '@')
		{
			hasOneAt = true;
			atCount = i;
		}
		if (email[atCount + 1] == '@')
		{
			hasOneAt = false;
		}
		if (email[i] != ' ')
		{
			hasNoSpaces = true;
		}
		if (i == 7)
		{
			hasEightChars = true;
		}
		if (email[atCount + 1] == '.')
		{
			hasDotAfterAt = true;
		}
		else
		{
			atCount++;
		}
	}
}

void printResult(bool hasLetter, bool hasOneAt, bool hasDotAfterAt, bool hasNoSpaces, bool hasEightChars)
{
	if (hasLetter && hasOneAt && hasDotAfterAt && hasNoSpaces && hasEightChars)
	{
		std::cout << "\nValid\n";
	}
	else
	{
		std::cout << "\nInvalid\n";
	}

}
