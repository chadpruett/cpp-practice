#include <iostream>
#include <iomanip>
using namespace std;

void welcome();
void submenu();
int getChoice();
double getCoffee();
double getDaily();
double getMonthly();
void dailySpending(double dailyCoffee);
void weeklySpending(double weeklyCoffee);
void annualSpending(double monthlyCoffee);
void goodbye();

int main()
{
	int option = 0, subOption = 0;
	double dailyCoffee = 0, weeklyCoffee = 0, monthlyCoffee = 0;

	do
	{
		welcome();
		option = getChoice();
		
		if (option == 1) 
		{
			do
			{
				submenu();
				subOption = getChoice();

				if (subOption == 1)
				{
					weeklyCoffee = getCoffee();
					weeklySpending(weeklyCoffee);
				} 
				else if (subOption == 2)
				{
					dailyCoffee = getDaily();
					dailySpending(dailyCoffee);
				}

			} while (subOption != 3);
		}
		else if (option == 2)
		{
		monthlyCoffee = getMonthly();
		annualSpending(monthlyCoffee);
		}

	} while (option != 3);

	goodbye();

	return 0;
}


void welcome()
{
	std::cout << "\nWelcome to the Coffee Spending Program!\n"
	<< "Please choose one of the following:\n"
	<< "1. Calculate coffee spending\n"
	<< "2. Estimate yearly spending\n"
	<< "3. Exit\n";
}

int getChoice()
{
	int choice = 0;

	std::cout << ">> ";
	cin >> choice;
	
	while (choice < 1 || choice > 3)
	{
		std::cout << "Please enter a valid entry: ";
		cin >> choice;
	}

	return choice;
}

double getCoffee()
{
	int coffee = 0;
	double avgCost = 0, weeklyCost = 0;

	std::cout << "\nHow many coffees do you buy per week?: ";
	cin >> coffee;

	while (coffee < 0)
	{
		std::cout << "\nPlease input a valid entry: ";
		cin >> coffee;
	}
		
	std::cout << "\nWhat is the average cost of your coffee?: $";
	cin >> avgCost;
		

	while (avgCost < 0)
	{
		std::cout << "\nPlease input a valid entry: ";
		cin >> avgCost;
	}

	weeklyCost = coffee * avgCost;
		
	return weeklyCost;
}

void weeklySpending(double weeklyCoffee)
{
	std::cout << fixed << setprecision(2)
	<< "\nYour weekly spending: $"
	<< weeklyCoffee << "\nYour monthly spending: $"
	<< weeklyCoffee * 4 << "\n\n";
}


double getDaily()
{
	double dailyCost = 0;

	std::cout << "\nHow much was your coffee today?: $";
	cin >> dailyCost;

	while (dailyCost < 0)
	{
		std::cout << "\nPlease input a valid entry: ";
		cin >> dailyCost;
	}

	return dailyCost;
}

void dailySpending(double dailyCoffee) 
{
	std::cout << fixed << setprecision(2)
	<< "\nYour daily coffee is $" << dailyCoffee
	<< "\nthat is $" << dailyCoffee * 7 << " per week and $"
	<< (dailyCoffee * 7) * 4 << " per month\n\n";
}

double getMonthly()
{
	double monthlyCost;

	std::cout << "\nWhat is your monthly coffee budget: $";
	cin >> monthlyCost;

	while (monthlyCost < 0)
	{
		std::cout << "\nPlease input a valid entry: ";
		cin >> monthlyCost;
	}

	return monthlyCost;
}

void annualSpending(double monthlyCoffee)
{
	std::cout << fixed << setprecision(2)
	<< "\nYour yearly estimated coffee spending is: $"
	<< monthlyCoffee * 12 << "\nThat is roughly $"
	<< monthlyCoffee / 4 << " per week at $"
	<< (monthlyCoffee / 4) / 7 << " per day\n\n";
}

void goodbye()
{
	std::cout << "\nThank you so much for using this Coffee Spending Program!\n"
	<< "\nTake care!";
}

void submenu()
{
	std::cout << "\nPlease pick from the following options:"
	<< "\n1. Calculate by week\n2. Calculate by day\n3. Back\n";

}
