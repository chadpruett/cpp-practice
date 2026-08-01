#include<iostream>
using namespace std;

const int MAX = 40;

void getText(char text[]);
bool isPalindrome(const char text[]);
void printResult(bool hasPalindrome);

int main()
{
	char text[MAX];
	bool hasPalindrome = false;

	getText(text);
	hasPalindrome = isPalindrome(text);
	printResult(hasPalindrome);

	return 0;
}


void getText(char text[])
{
	std::cout << "\nEnter text: ";
	cin >> text;
}

bool isPalindrome(const char text[])
{
	int length = 0;
	int right = 0;

	while (text[length] != '\0')
	{
		length++;
	}
 	
	right = length;

	for (int i = 0; i < length / 2; i++)
	{
		if (text[i] != text[right - 1])
		{
			return false;
		}

		right--;
	}

	return true;
}

void printResult(bool hasPalindrome)
{
	if (hasPalindrome)
	{
		std::cout << "\nIs a Palindrome\n";
	}
	else
	{
		std::cout << "\nIs not a palindrome\n";	
	}
	
}
