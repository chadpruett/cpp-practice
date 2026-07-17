#include <iostream>
using namespace std;

double getOrderTotal();
bool getsFreeShipping(double orderTotal);
void printFreeShipping(double orderTotal);

int main()
{
	double orderTotal = getOrderTotal();
	printFreeShipping(orderTotal);

	return 0;
}

double getOrderTotal()
{
	double value = 0;

	while (!(cin >> value) || value < 0)
	{
		std::cout << "\nPlease input a valid entry: ";
		cin.clear();
		cin.ignore(10000,'\n');
	}

	return value;
}

bool getsFreeShipping(double orderTotal)
{
	return orderTotal >= 35;
}

void printFreeShipping(double orderTotal)
{
	if (getsFreeShipping(orderTotal))
	{
		std::cout << "\nYou qualify for free shipping!\n";
	}
	else
	{
		std::cout << "\nYou do NOT qualify for free shipping.\n";
	}
}
