#include<iostream>
using namespace std;



int main()
{
	char name[20];
	int length = 0;

	std::cout << "\nEnter your first name: ";
	
	while (!(cin >> name))
	{
		std::cout << "\nPlease input a valid entry: ";
	cin.clear();
	cin.ignore(10000,'\n');
	}
	
	cout << "\n\nYour name is: " << name << "\n\n";

	for (int i = 0; name[i] != '\0'; i++)
	{
		std::cout << name[i] << endl;
		length++;
	}

	std::cout << "\n\nLength: " << length << endl;

	return 0;
}
