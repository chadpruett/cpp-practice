#include <iostream>
using namespace std;

int intVal();

void getDimensions(int& length, int& width);

int calculateArea(int length, int width);


int main() 
{
	int result = 0, length = 0, width = 0;

	getDimensions(length, width);
	result = calculateArea(length, width);

	std::cout << "\nArea: " << result << endl;

	return 0;
}

void getDimensions(int& length, int& width)
{
	std::cout << "\nLength: ";
	length = intVal();
	
	std::cout << "\nWidth: ";
	width = intVal();
}


int intVal()
{
	int value = 0;

	while (!(cin >> value) || value <= 0)
	{
		std::cout << "\nPlease input a valid entry: ";
		cin.clear();
		cin.ignore(10000,'\n');
	}

	return value;
}

int calculateArea(int length, int width)
{
	return length * width;
}

