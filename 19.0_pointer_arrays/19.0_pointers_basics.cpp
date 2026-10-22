#include<iostream>
using namespace std;



int main()
{

	int health = 100;
	int armor = 50;
	int energy = 75;

	int* stats[3] = {&health, &armor, &energy};

	//change health to 80, change engery to 100
	*stats[0] = 80;
	*stats[2] = 100;
	
	std::cout << '\n' << health << '\n'
	<< armor << '\n'
	<< energy << '\n';


	return 0;
}
