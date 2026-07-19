#include <iostream>
using namespace std;

void getEmployeeInfo(int& employeeID, int& hoursWorked);
int intVal();
void printEmployeeInfo(int employeeID, int hoursWorked);

int main()
{
	int employeeID = 0, hoursWorked = 0;

	getEmployeeInfo(employeeID, hoursWorked);
	printEmployeeInfo(employeeID, hoursWorked);

	return 0;
}

void getEmployeeInfo(int& employeeID, int& hoursWorked)
{
	std::cout << "\nEmployee ID: ";
	employeeID = intVal();
	
	std::cout << "\nHours worked: ";
	hoursWorked = intVal();
}

int intVal()
{
	int value = 0;
	
	while (!(cin >> value))
	{
		std::cout << "\nPlease input a valid entry: ";
		cin.clear();
		cin.ignore(10000,'\n');
	}
	return value;
}

void printEmployeeInfo(int employeeID, int hoursWorked)
{
	std::cout << "\n\nEmployee ID: " << employeeID
	<< "\nYou worked: " << hoursWorked << " hours." << endl;
}
