#include<iostream>
#include<fstream>
using namespace std;

const int MAX = 50;

void getUser(char userName[]);
void writeFile(const char userName[]);

int main()
{
	char userName[MAX];

	getUser(userName);
	writeFile(userName);

	return 0;
}



void getUser(char userName[])
{
	std::cout << "\nEnter username: ";
	cin.getline(userName, MAX);
}

void writeFile(const char userName[])
{
	ofstream oFile;

	oFile.open("name.txt");
	
	oFile << userName << '\n';
	
	oFile.close();
}
