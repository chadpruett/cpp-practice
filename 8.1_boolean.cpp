#include <iostream>
using namespace std;

bool isEven(int number);

int main()
{
	int number = 0;
	
	std::cout << "\nEnter a number: ";
	cin >> number;

	bool even = isEven(number);

	if (even)
	{
		std::cout << "\nThe number is even\n";
	}
	else
	{
		std::cout << "\nThe number is odd\n";
	}
	return 0;
}

bool isEven(int number)
{
	return number % 2 == 0;
}
