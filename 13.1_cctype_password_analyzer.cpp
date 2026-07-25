#include<iostream>
#include<cctype>
using namespace std;


const int MAX = 20;

void getPassword(char password[]);
void analyzePassword(const char password[], bool& isUpper, bool& isLower, bool& isDigit, bool& isPunct);
void printResults(const char password[], bool isUpper, bool isLower, bool isDigit, bool isPunct);

int main()
{
	char password[MAX];
	bool isUpper = false;
	bool isLower = false;
	bool isDigit = false;
	bool isPunct = false;

	getPassword(password);
	analyzePassword(password, isUpper, isLower, isDigit, isPunct);
	printResults(password, isUpper, isLower, isDigit, isPunct);
	
	return 0;
}

void getPassword(char password[])
{
	std::cout << "\nEnter a password: ";
	cin >> password;
}

void analyzePassword(const char password[], bool& isUpper, bool& isLower, bool& isDigit, bool& isPunct)
{
	for (int i = 0; password[i] != '\0'; i++)
	{
		if (isupper(password[i]))
		{
			isUpper = true;
		}
		else if (isdigit(password[i]))
		{
			isDigit = true;
		}
		else if (islower(password[i]))
		{
			isLower = true;
		}
		else if (ispunct(password[i]))
		{
			isPunct = true;
		}
	}

}


void printResults(const char password[], bool isUpper, bool isLower, bool isDigit, bool isPunct)
{
	std::cout << "\nContains uppercase: ";
	if (isUpper)
	{
		std::cout << "Yes";
	}
	else
	{
		std::cout << "No";
	}
	std::cout << "\nContains lowercase: ";
	if (isLower)
	{
		std::cout << "Yes";
	}
	else
	{
		std::cout << "No";
	}

	std::cout << "\nContains Digit: ";
	if (isDigit)
	{
		std::cout << "Yes";
	}
	else
	{
		std::cout << "No";
	}

	std::cout << "\nContains Punctuation: ";
	if (isPunct)
	{
		std::cout << "Yes";
	}
	else
	{	
		std::cout << "No";
	}
	
	std::cout << endl;	
}
