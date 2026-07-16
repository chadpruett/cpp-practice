#include <iostream>
using namespace std;

bool canVote(int age);

int main()
{
	int age = 0;
	bool vote = true;

	std::cout << "\nWhat's your age?: ";
	cin >> age;

	vote = canVote(age);

	if (vote)
	{
		std::cout << "\nYou're old enough to vote!";
	}
	else
	{
		std::cout << "\nYou're can not vote yet.";
	}

	return 0;
}

bool canVote(int age)
{
	if (age >= 18)
	{
		return true;
	}
	else
	{
		return false;
	}

}
