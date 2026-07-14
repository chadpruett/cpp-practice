#include <iostream>
using namespace std;

int getRows();
void printTriangle(int rows);

int main()
{
	int rows = 0;

	rows = getRows();
	printTriangle(rows);

	return 0;
}

int getRows()
{
	int rows = 0;

	std::cout << "\nRows: ";

	while (!(cin >> rows) || rows <= 0)
	{
		std::cout << "\nPlease input a valid entry: ";
		cin.clear();
		cin.ignore(10000,'\n');
	}

	return rows;
}

void printTriangle(int rows)
{
	for (int row = 1; row <= rows; row++)
	{
		for (int star = rows; star >= row; star--)
		{
			std::cout << "* ";

		}

		std::cout << endl;
	}
}
