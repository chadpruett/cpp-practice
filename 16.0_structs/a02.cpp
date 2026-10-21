#include<iostream>
#include<cstring>
#include<ctime>
#include<cstdlib>
using namespace std;

const int MAX = 50;

struct Treasure
{
	char name[MAX];
	int gil;
};

void getTreasure(Treasure& treasure);
void printTreasure(const Treasure& treasure);

int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));
	
	Treasure treasure;

	getTreasure(treasure);
	printTreasure(treasure);

	return 0;
}


void getTreasure(Treasure& treasure)
{
	int index = rand() % 3;
	
	Treasure treasures[3] = 
	{
		{"Martini", 400},
		{"Lighter", 30},
		{"Pillow", 5}
	};
	
	treasure = treasures[index];
}

void printTreasure(const Treasure& treasure)
{

	std::cout << "\nYou received " << treasure.name
	<< ", worth " << treasure.gil << " gil.\n" << endl;

}
