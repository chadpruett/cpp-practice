#include <iostream>
using namespace std;

int getInt();
int intVal();

void calculateRectangle(int length, int width, int& area, int& perimeter);

int main()
{
	int length = 0, width = 0, area = 0, perimeter = 0;

	std::cout << "\nRectangle length: ";
	length = getInt();

	std::cout << "\nRectangle width: ";
	width = getInt();

	calculateRectangle(length, width, area, perimeter);

	std::cout << "\n\nArea: " << area
	<< "\nPerimeter: " << perimeter << endl;

	return 0;
}

int getInt()
{
	int value = intVal();
	return value;
}

int intVal()
{
	int value = 0;

	while (!(cin >> value) || value < 0)
	{
		std::cout << "\nPlease input a valid entry: ";
		cin.clear();
		cin.ignore(10000,'\n');
	}
	return value;
}

void calculateRectangle(int length, int width, int& area, int& perimeter)
{
	area = length * width;
	perimeter = 2 * (length + width);
}
