#include<iostream>
using namespace std;

const int SIZE = 5;

int intVal();
bool getsOvertime(int hoursWorked);
void getHoursWorked(int hours[]);
void welcomeMessage();
void printReport(int hours[]);

int main()
{
	int userOption = 0;
	int hours[SIZE] = {0};
	bool hoursEntered = false;

	do
	{
		welcomeMessage();
		userOption = intVal();

		if (userOption == 1)
		{
			getHoursWorked(hours);
			hoursEntered = true;
		}
		else if (userOption == 2)
		{
			if (hoursEntered)
			{
				printReport(hours);
			}
			else
			{
				std::cout << "\nPlease enter hours first\n";
			}
		}	

	} while (userOption != 3);

	return 0;
}

void welcomeMessage()
{
	std::cout << "\nWelcome to the employee payroll review"
	<< "\nWhat would you like to do?: "
	<< "\n1.Input employee hours" 
	<< "\n2.Compile overtime" 
	<< "\n3.Quit";
}

int intVal()
{
	int value = 0;

	std::cout << "\n>> ";

	while (!(cin >> value) || value < 0)
	{
		std::cout << "\nPlease input a valid option";
		cin.clear();
		cin.ignore(10000,'\n');
		std::cout << "\n>> ";
	}

	return value;
}

void getHoursWorked(int hours[])
{
	for (int i = 0; i < SIZE; i++)
	{
		std::cout << "\nEmployee " << i + 1 << ": ";
		hours[i] = intVal();
	}

		std::cout << "\nThank you for inputting your employee hours\n";
}

void printReport(int hours[])
{
	int overtimeCount = 0;
	int noOvertimeCount = 0;

	for (int i = 0; i < SIZE; i++)
	{
		if (getsOvertime(hours[i]))
		{
			std::cout << "\nEmployee " << i + 1 << " Hours: "
			<< hours[i] << " - Overtime\n";
			overtimeCount++;
		}
		else 
		{
			std::cout << "\nEmployee " << i + 1 << " Hours: "
			<< hours[i] << " - No Overtime\n";
			noOvertimeCount++;
		}
	}
		
		if (overtimeCount > 0)
		{
			std::cout << "\nEmployees with overtime: "
			<< overtimeCount << endl;
		}
		
		if (noOvertimeCount > 0)
		{
			std::cout << "\nEmployees with no overtime: "
			<< noOvertimeCount << endl;
		}

}

bool getsOvertime(int hoursWorked)
{
	return hoursWorked > 40;
}




