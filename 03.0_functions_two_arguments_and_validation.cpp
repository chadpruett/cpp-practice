#include <iostream>
using namespace std;

int getInt();
int intVal();
int calculateWeeklyCoffees(int perDay, int perWeek);
int calculateYearlyCoffees(int perWeek);

int main()
{	
	int perDay = 0, perWeek = 0, result = 0;


	std::cout << "\nHow many cofffees do you drink per day?: ";
	perDay = getInt();
	
	std::cout << "\nHow many days per week do you drink coffee?: ";
	perWeek = getInt();

	result = calculateWeeklyCoffees(perDay, perWeek);
	std::cout << "\n\nYou drink " << result << " coffees per week.\n";
	
	result = calculateYearlyCoffees(result);
	std::cout <<"\nYou drink " << result << " coffees per year.\n\n";

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

int calculateWeeklyCoffees(int perDay, int perWeek)
{
	int result = perDay * perWeek;	
	return result;
}

int calculateYearlyCoffees(int perWeek)
{
	return perWeek * 52;
}
