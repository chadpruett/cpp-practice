#include<iostream>
#include<cctype>
using namespace std;

const int MAX = 20;

void getUsername(char username[]);

int main()
{
	char username[MAX];
	getUsername(username);


	return 0;
}

void getUsername(char username[])
{
	std::cout << "\nEnter username: ";
	cin >> username;
	while (username[i] >= 5)
	{
		std::cout << "\nUsername must be at least 5 characters long"
		cin.clear();
		cin.ignore(10000,'\n');
		std::cout <<  "\nEnter username: ";
		cin >> username;
	}
}

