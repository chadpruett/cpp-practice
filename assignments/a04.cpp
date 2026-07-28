#include<iomanip>
#include<cctype>
#include<iostream>
using namespace std;

void welcome();
void getVehicle(char& vehicle);
int getInt();
void getTickets(int& adults, int& seniors, int& youth);
double calculateCost(char vehicle, int adults, int seniors, int youth);
void printTotals(double total);

int main()
{
	char vehicle;
	int adults = 0;
	int seniors = 0;
	int youth = 0;
	double total = 0;


	
	welcome();
	getVehicle(vehicle);
	getTickets(adults, seniors, youth);
	total = calculateCost(vehicle, adults, seniors, youth);
	printTotals(total);
	return 0;

}

void welcome()
{
	std::cout << "\nWelcome to the Washington State Ferries Fare Calculator!"
	<< left << setw(30) << "\nFare Description" <<  right << setw(50) << "Ticket $"
	
	<< '\n' << setfill('_') << setw(30) << ""
	<< right << setfill ('_') << "" << setw(50)
	<< setfill(' ');

	std::cout << left << setw(30) << "\nVehicle Under 14' (less than 168" << '"' << ')' << " & Driver"
	<< right << setw(50) << "$57.90"
	<< left << setw(30) << "\nAdult (age 19 - 64)" << right << setw(50) << "$14.95"
	<< left << setw(30) << "\nSenior (age 65 & over) / Disability" << right << setw(50) << "$7.40"
	<< left << setw(30) << "\nYouth (age 6 - 18)" << right << setw(50) << "$5.55"
	<< left << setw(30) << "\nBicycle Surcharge (included with Vehicle)"
	<< right <<  setw(50) << "$4.00" << endl;
}

void getVehicle(char& vehicle)
{
	std::cout << "\nAre you riding a vehicle on the Ferry (Y/N): ";
	
	cin >> vehicle;
	vehicle = toupper(vehicle);
}

int getInt()
{
	int value = 0;
	
	while (!(cin >> value) || value < 0 || value > 50)
	{
		std::cout << "\nPlease enter an amount between 0 and 50: ";
		cin.clear();
		cin.ignore(10000,'\n');
	}
	return value;
}


void getTickets(int& adults, int& seniors, int& youth)
{
	std::cout << "\nHow many adults?: ";
	adults = getInt();
	
	std::cout << "\nHow many seniors?: ";
	seniors = getInt();

	std::cout << "\nHow many youths?: ";
	youth = getInt();

}

double calculateCost(char vehicle, int adults, int seniors, int youth)
{
	double vehicleCost = 57.90;
	double total = 0;
	
	if (vehicle == 'Y')
	{
		total += vehicleCost;
	}

	if (adults > 0)
	{
		total += (adults * 14.95);
	}
	if (seniors > 0)
	{
		total += (seniors * 7.40);
	}	
	if (youth > 0)
	{
		total += (youth * 5.55);
	}

	return total;
}

void printTotals(double total)
{
	std::cout << fixed << setprecision(2) <<  "\nYour total charge is " << total;
	
	if (total > 100)
	{
		std::cout << "\nYou get a free adult ticket for the next trip!";
	}
	else
	{
		std::cout << "\nIf you spend " << 100 - total << " more, you are "
		<< "eligible for a free adult ticket for the next trip.\n" << endl;
	}
		
}
