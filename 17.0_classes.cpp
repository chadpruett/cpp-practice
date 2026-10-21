#include<iostream>
using namespace std;

class Creature
{
	private:
		int health = 100;
	public:
		int getHealth()
		{
			return health;
		}
		void takeDamage(int damage)
		{
			health -= damage;
		}
};

int main()
{
	Creature player;

	std::cout << "\nPlayer Health: " << player.getHealth() << "\n";
	
	std::cout << "\nPlayer took damage!\n";
	player.takeDamage(20);
	std::cout << "Player Health: " << player.getHealth() << "\n";

	return 0;
}
