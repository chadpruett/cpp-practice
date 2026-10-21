#include<iostream>
#include<cstring>
#include<ctime>
#include<cstdlib>
using namespace std;

const int MAX = 40;

struct Monster
{
	char name[MAX];
	int room;
	int nights;
};

void getMonster(Monster& monster);
void printMonster(const Monster& monster);

int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));

	Monster monster;

	getMonster(monster);
	printMonster(monster);

	return 0;
}

void getMonster(Monster& monster)
{
	Monster monsters[3] = {
	{"mirror", 101, 20},
	{"chandelier", 227, 30},
	{"hallway rug", 4, 400}
	};

	int index = rand() %3;
	monster = monsters[index];
}

void printMonster(const Monster& monster)
{

	std::cout << '\n' << monster.name << " is staying in room "
	<< monster.room << " for " << monster.nights << " nights. " << endl; 
}


