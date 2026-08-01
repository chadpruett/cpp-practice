#include<iostream>
using namespace std;

const int MAX = 30;

void getText(char text[]);
void myStrReverse(char text[]);

int main()
{
	char text[MAX];

	getText(text);
	myStrReverse(text);
	//printResult(text);

	return 0;
}

void getText(char text[])
{
	std::cout << "\nEnter word: ";
	cin >> text;
}

void myStrReverse(char text[])
{
	int length = 0;

	std::cout << "\nWord backwards: ";

	while (text[length] != '\0')
	{
		length++;
	}
	
	for (int i = length - 1; i >= 0; i--)
	{
		std::cout << text[i];
	}

	std::cout << endl;
}
