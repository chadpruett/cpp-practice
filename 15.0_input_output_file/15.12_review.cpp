#include<iostream>
#include<fstream>
using namespace std;

const int MAX = 50;

void welcome();
void addLog();
void readLogs();
int intVal(int minimum, int maximum);


int main ()
{

	int userOption = 0;

	do
	{
		welcome();
		userOption = intVal(1, 3);

		if (userOption == 1)
		{
			addLog();	
		}
		else if (userOption == 2)
		{
			readLogs();
		}

	} while (userOption != 3);


	return 0;
}

void welcome()
{
	std::cout << "\n\nBOOTING LOG MODULE.........."
	<< "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n"
	<< "\n1. ADD A LOG"
	<< "\n2. READ ALL LOGS"
	<< "\n3. QUIT"
	<< "\n>> ";
}

void addLog()
{
	char author[MAX];
	int roomNumber = 0;
	char line[MAX];

	ofstream outFile("logs.txt", ios::app);

	if (!outFile)
	{
		std::cout << "\nError opening file!\n\n";
		return;
	}

	std::cout << "\nAuthor: ";
	cin >> author;
	std::cout << "\nRoom number: ";
	roomNumber = intVal(1, 500);
	cin.ignore(10000,'\n');
	std::cout << "\nMessage: ";
	cin >> line;
	
	outFile << author << '\n'
		<< roomNumber << '\n'
		<< line << '\n';
	
	outFile.close();

}

void readLogs()
{
	char author[MAX];
	char line[MAX];
	int roomNumber = 0;		

	ifstream inFile("logs.txt");

	if (!inFile)
	{
		std::cout << "\nError opening file!\n\n";
		return;
	}

	while (inFile >> author >> roomNumber >> line)
	{
		inFile.ignore(10000,'\n');
		inFile.getline(line, MAX);

		std::cout << author
		<< '\n' << roomNumber
		<< '\n' << line << endl;
	}

	inFile.close();
}

int intVal(int minimum, int maximum)
{
	int value = 0;
	
	while (!(cin >> value) || value < minimum  || value > maximum)
	{
		std::cout << "\nPlease input the correct entry "
		<< "\n>> ";
		cin.clear();
		cin.ignore(10000,'\n');
	}

	return value;
}


