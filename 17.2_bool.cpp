#include<iostream>
using namespace std;

class Creature
{
	private:
		int health = 100;
	public:
		Creature(int startingHealth)
		{
			health = startingHealth;
		}

		int getHealth()
		{
			return health;
		}

		void takeDamage(int damage)
		{
			health -= damage;

			if (health < 0)
			{
				health = 0;
			}
		}

		bool isAlive()
		{
			return health > 0;
		}
	
};

int main()
{
	Creature chandelier(50);

	while (chandelier.isAlive())
	{
	chandelier.takeDamage(15);

	std::cout << '\n' << chandelier.getHealth() << '\n';
	}

	if (chandelier.isAlive())
	{
		std::cout << "\nThe chandelier is still alive.\n";
	}
	else
		std::cout << "\nThe chandelier has been defeated.\n";

	return 0;
}
