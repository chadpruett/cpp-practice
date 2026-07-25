#include<iostream>
using namespace std;

const int PEOPLE = 5;
const int SIZE = 20;


void getNames(char names[][SIZE]);
int getLength(char name[]);
void printLastLetter(char names[][SIZE]);


int main()
{
	char names[PEOPLE][SIZE];

	getNames(names);

	printLastLetter(names);


	return 0;
}

void getNames(char names[][SIZE])
{

	for (int i = 0; i < PEOPLE; i++)
	{
		std::cout << "\nEnter name " << i + 1 << ": ";
		cin >> names[i];
	}
}

int getLength(char name[])
{
	int length = 0;

	for (int i = 0; name[i] != '\0'; i++)
	{
		length++;
	}
	
	return length;
}

void printLastLetter(char names[][SIZE])
{
	std::cout << "\nLast letter of each name:\n";
	
	for (int i = 0; i < PEOPLE; i++)
	{
		int length = getLength(names[i]);
		std::cout << names[i][length - 1] << endl;
	}

}




