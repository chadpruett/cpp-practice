#include<iostream>
using namespace std;

const int MAX = 30;


void getWord(char text[]);
int findChar(const char text[], char target);
void printResult(const int index);

int main()
{
	int index = 0;
	char text[MAX];
	char target;
	
	getWord(text);
	index =	findChar(text, target);	
	printResult(index);

	return 0;
}

void getWord(char text[])
{
	std::cout << "\nEnter text: ";
	cin >> text;
}

int findChar(const char text[], char target)
{

	std::cout << "\nEnter character: ";
	cin >> target;

	for (int i = 0; text[i] != '\0'; i++)
	{
		if (text[i] == target)
		{
			return i;
		}
	} 
	
	return -1;
}

void printResult(const int index)
{
	if (index == -1)
	{
		std::cout << "\nCharacter not found.\n";
	}
	else
	{
		std::cout << "\nFound at index " << index << endl;
	}
}


