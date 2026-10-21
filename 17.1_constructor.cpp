#include<iostream>
using namespace std;

class Creature //class data type
{
	private:
		int health = 100;
	public:
			Creature(int startingHealth) //constructor
			{
				int health = startingHealth;
			}

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
	Creature player(100);
	Creature skeleton(80);
	
	skeleton.takeDamage(15);

	std::cout << player.getHealth() << "\n"
	<< skeleton.getHealth() << "\n";

	return 0;
}
