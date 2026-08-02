#include<iostream>
#include<fstream>
using namespace std;

const int MAX = 50;


int main()
{
	char name[MAX];

	ifstream inFile;

	inFile.open("name.txt");
	
	while(inFile.getline(name, MAX))
	{
		std::cout << name << endl;
	}

	inFile.close();

	return 0;
}





