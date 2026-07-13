#include <iostream>
#include <iomanip>
using namespace std;

const double TAX_RATE = 0.10;

int getInt();
int intVal();
double getDouble();
double doubVal();
void calculateOrder(int coffees, double coffeePrice, double& subtotal, double& tax, double& total);

int main()
{
	int coffees = 0;
	double coffeePrice = 0, subtotal = 0, tax = 0, total = 0;

	std::cout << "\nHow many coffees?: ";
	coffees = getInt();
	
	std::cout << "\nPrice per coffee?: $";
	coffeePrice = getDouble();

	calculateOrder(coffees, coffeePrice, subtotal, tax, total);

	std::cout << fixed << setprecision(2)	
	<< "\nSubtotal: $" << subtotal << "\nTax: $" << tax
	<< "\nTotal: $" << total << "\n\n";

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

double getDouble()
{
	double value = doubVal();
	return value;
}

double doubVal()
{
	double value = 0;

	while (!(cin >> value) || value < 0)
	{
		std::cout << "\nPlease input a valid entry: $";
		cin.clear();
		cin.ignore(10000,'\n');
	}
	return value;
}

void calculateOrder(int coffees, double coffeePrice, double& subtotal, double& tax, double& total)
{
	subtotal = coffees * coffeePrice;
	tax = subtotal * TAX_RATE;
	total = subtotal + tax;
}
