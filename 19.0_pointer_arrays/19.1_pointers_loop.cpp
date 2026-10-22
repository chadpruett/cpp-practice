#include<iostream>
using namespace std;



int main()
{

	int health = 100;
	int armor = 50;
	int energy = 75;

	int* stats[3] = {&health, &armor, &energy};

	//print before loop
	std::cout << '\n' << health << '\n'
	<< armor << '\n'
	<< energy << '\n';
	
	//subtract 10 from all variables using a loop
	for (int i = 0; i < 3; i++)
	{
		*stats[i] -= 10;
	}
	
	//print after loop
	std::cout << '\n' << health << '\n'
	<< armor << '\n'
	<< energy << '\n';

	return 0;
}
