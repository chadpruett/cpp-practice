#include <iostream>
using namespace std;

int getVal();
bool getsBonus(int yearsWorked);
void printResults(bool isBonusEligible, int yearsWorked);

int main()
{
	int yearsWorked = getVal();
	bool isBonusEligible = getsBonus(yearsWorked); 
	printResults(isBonusEligible, yearsWorked);

	return 0;
}

int getVal()
{
	int value = 0;
	
	std::cout << "\nHow many years have you worked?: ";
		
	while (!(cin >> value) || value < 0 || value > 70)
	{
		std::cout << "\nPlease input between 0 and 70 years: ";
		cin.clear();
		cin.ignore(10000,'\n');
	}

	return value;
}

bool getsBonus(int yearsWorked)
{
	return yearsWorked >= 5;
}

void printResults(bool isBonusEligible, int yearsWorked)
{
	if (isBonusEligible)
	{
		std::cout << "\nCongrats! You get a bonus this year!\n";
	}	
	else
	{
		std::cout << "\nSorry you won't get a bonus for another "
		<< 5 - yearsWorked;
		
		if (yearsWorked == 4)
		{
			std::cout << " year\n";
		}
		else 
		{
			std::cout << " years\n";	
		}
	}
}
