#include<iostream>
#include<cctype>
using namespace std;

const int SIZE = 20;

void getPassword(char password[]);
void analyzePassword(const char password[],
		     bool& hasUpper,
		     bool& hasLower,
		     bool& hasDigit,
		     bool& hasPunct,
		     bool& hasEightChars);
void printResults(bool hasUpper,
		  bool hasLower,
		  bool hasDigit,
		  bool hasPunct,
		  bool hasEightChars);
int main()
{
	bool hasUpper = false;
	bool hasLower = false;
	bool hasDigit = false;
	bool hasPunct = false;
	bool hasEightChars = false;
	char password[SIZE];

	getPassword(password);
	analyzePassword(password, hasUpper, hasLower, hasDigit, hasPunct, hasEightChars);
	printResults(hasUpper, hasLower, hasDigit, hasPunct, hasEightChars);


	return 0;
}

void getPassword(char password[])
{
	std::cout << "\nEnter password: ";
	cin >> password;
}

void analyzePassword(const char password[],
		     bool& hasUpper,
		     bool& hasLower,
		     bool& hasDigit,
		     bool& hasPunct,
		     bool& hasEightChars) {
	
	int length = 0;
		
	for (int i = 0; password[i] != '\0'; i++)
	{
		length++;
		
		if (isupper(password[i]))
		{
			hasUpper = true;
		}
		else if (islower(password[i]))
		{
			hasLower = true;
		}
		else if (isdigit(password[i]))
		{
			hasDigit = true;
		}	
		else if (ispunct(password[i]))
		{
			hasPunct = true;
		}
	}
	
	if (length >= 8)
	{
		hasEightChars = true;
	}

}

void printResults(bool hasUpper,
		  bool hasLower,
		  bool hasDigit,
		  bool hasPunct,
		  bool hasEightChars)
{
	std::cout << "\n\nUppercase: " << (hasUpper ? "Yes" : "No")
	<< "\nLowercase: " << (hasLower ? "Yes" : "No")
	<< "\nDigit: " << (hasDigit ? "Yes" : "No")
	<< "\nPunctuation: " << (hasPunct ? "Yes" : "No")
	<< "\nLength: " << (hasPunct ? "Yes" : "No")
	<< "\n\nStrength: " << (hasEightChars ? "Strong" : "Weak") << "\n\n";
}
