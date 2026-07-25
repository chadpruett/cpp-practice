#include<iostream>
#include<cctype>
using namespace std;

const int MAX = 20;

void getUsername(char username[]);
void validateUsername(const char username[], bool& hasFiveChar, bool& hasLetter, bool& hasDigit, bool& hasPunct);
void printResult(bool hasFiveChar, bool hasLetter, bool hasDigit, bool hasPunct);

int main()
{
	bool hasFiveChar = false;
	bool hasLetter = false;
	bool hasDigit = false;
	bool hasPunct = false;
	
	char username[MAX];

	getUsername(username);
	validateUsername(username, hasFiveChar, hasLetter, hasDigit, hasPunct);
	printResult(hasFiveChar, hasLetter, hasDigit, hasPunct);

	return 0;
}

void getUsername(char username[])
{
	std::cout << "\nEnter username: ";
	cin >> username;	
}

void validateUsername(const char username[], bool& hasFiveChar, bool& hasLetter, bool& hasDigit, bool& hasPunct)
{

	for (int i = 0; username[i] != '\0';i++)
	{
		if (i == 4)
		{
			hasFiveChar = true;
		}
		if (isalpha(username[i]))
		{
			hasLetter = true;
		}
		else if (isdigit(username[i]))
		{
			hasDigit = true;
		}
		else if (ispunct(username[i]))
		{
			hasPunct = true;
		}
	}

}

void printResult(bool hasFiveChar, bool hasLetter, bool hasDigit, bool hasPunct)
{
	if (hasFiveChar && hasLetter && hasDigit && !hasPunct)
	{
		std::cout << "\nValid username." << endl;
	}
	else
	{
		std::cout << "\nInvalid username." << endl;
	}
}

