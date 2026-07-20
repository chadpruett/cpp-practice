#include <iostream>
using namespace std;

bool getsBonus(int yearsWorked);

int main()
{
	int yearsWorked[5] = {0};

	for (int i = 0; i < 5; i++)
	{
		std::cout << "Employee " << i + 1 << ": ";
		
		while (!(cin >> yearsWorked[i]) || yearsWorked[i] < 0)
		{	
			std::cout << "\nPlease input a valid entry: ";
			cin.clear();
			cin.ignore(10000,'\n');
		}
		
		getsBonus(yearsWorked[i]);
	}

	for (int j = 0; j < 5; j++)
	{
		if (getsBonus(yearsWorked[j]))
		{
			std::cout << "\nEmployee " << j + 1 << ": Eligible";
		}
		else
		{
			std::cout << "\nEmployee " << j + 1 << ": Ineligible";
		}
	}	

	return 0;
}

bool getsBonus(int yearsWorked)
{
	return yearsWorked >= 5;
}
