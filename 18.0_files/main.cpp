#include "Room.h"

int main()
{
	Room suite("Moonlight Suite", 150.0f);

	suite.display();
	suite.setPrice(175.0f);
	suite.display();

	Room lounge("Tabloid", 500.0f);
	lounge.display();

	return 0;
}
