#include <iostream>
using namespace std;

void getRowsColumns(int& rows, int& columns);
void printRowsColumns(int rows, int columns);
int intVal();


int main()
{
	int rows = 0;
	int columns = 0;

	getRowsColumns(rows, columns);
	printRowsColumns(rows, columns);
	
	return 0;
}

void getRowsColumns(int& rows, int& columns)
{
	std::cout << "\nRows: ";
	rows = intVal();
	std::cout << "\nColumns: ";
	columns = intVal();
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

void printRowsColumns(int rows, int columns)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			std::cout << "* ";
		}
		
		std::cout << endl;
	}

}
