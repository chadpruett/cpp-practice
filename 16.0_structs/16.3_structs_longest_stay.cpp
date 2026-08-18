#include<iostream>
using namespace std;

const int CAP = 3;
const int MAX = 50;

struct Guests
{
	char name[MAX];
	int room;
	int nights;
};

void getGuests(Guests guest[]);
int findLongestStay(const Guests guest[]);
void printGuest(const Guests& guest);

int main()
{
	Guests guest[CAP];

	getGuests(guest);

	int index = findLongestStay(guest);
	
	printGuest(guest[index]);
	

	return 0;
}


void getGuests(Guests guest[])
{
	for (int i = 0; i < CAP; i++)
	{
		std::cout << "\nGuest " << i + 1 << " name: ";
		cin >> guest[i].name;
		std::cout << "\nRoom Number: ";
		cin >> guest[i].room;
		std::cout << "\nNights: ";
		cin >> guest[i].nights;
	}
}

int findLongestStay(const Guests guest[])
{
	int longestStay = guest[0].nights;
	int index = 0;

	for (int i = 1; i < CAP; i++)
	{
		if (guest[i].nights > longestStay)
		{
			longestStay = guest[i].nights;
			index = i;
		}
	}
	
	return index;
}

void printGuest(const Guests& guest)
{
		std::cout << '\n' << guest.name << " has the longest stay at "
		<< guest.nights << " nights in room " << guest.room << '\n';	
}
