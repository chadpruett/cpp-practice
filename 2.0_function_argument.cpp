#include <iostream>
#include <cctype>
using namespace std;

char getChar();
double getValidDouble();
void checkTemperature(double temp);

int main()
{
	char option = ' ';
	double temp = 0;

	do
	{	
	std::cout << "\nEnter a temperature: ";
	temp = getValidDouble();	
	
	checkTemperature(temp);

	std::cout << "\nWould you like to continue? Enter y or n: ";
	option = getChar();

	} while (option != 'n');

	return 0;
}

char getChar()
{
	char option = ' ';
	
	cin >> option;
	option = tolower(option);
	while (option != 'y' && option != 'n')
	{
		std::cout << "\nPlease enter y or n: ";
		cin.clear();
		cin.ignore(10000, '\n');
		cin >> option;
		option = tolower(option);
	}
	return option;
}

double getValidDouble()
{
	double temp = 0;
	
	while (!(cin >> temp))
	{
		std::cout << "\nPlease input a valid entry: ";
		cin.clear();
		cin.ignore(10000, '\n');
	}
	return temp;
}

void checkTemperature(double temp)
{
	if (temp < 32)
	{
		std::cout << '\n' << temp << " is considered Freezing!\n";
	}
	else if (temp <= 59)
	{	
		std::cout << '\n' << temp << " is considered Cold!\n";
	}
	else if (temp <= 79)
	{
		std::cout << '\n' << temp << " is considered Warm!\n";
	}
	else
	{
		std::cout << '\n' << temp << " is considered Hot!\n";
	}
}
