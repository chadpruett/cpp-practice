#include<iostream>
#include<fstream>
using namespace std;

const int MAX = 50;

void welcome();
void newDocument();
void addToDocument();
void readDocument();
//void delDocument();
void goodbye();
void writeLines(ofstream& outFile);
bool foundDocument(char fileName[]);
bool myStrCompare(const char first[], const char second[]);
int intVal(int min, int max);

int main()
{
	int userOption = 0;

	do
	{
		welcome();
		userOption = intVal(1, 5);
		
		if (userOption == 1)
		{
			newDocument();
		}
		else if (userOption == 2)
		{
			addToDocument();
		}
		else if (userOption == 3)
		{
			readDocument();
		}
		else if (userOption == 4)
		{
//			delDocument();
		}


	} while (userOption != 5);

	return 0;
}

void welcome()
{
	std::cout << "\nEcho booting >>>>>>>>>>"
	<< "\nStatus . . . . Online"
	<< "\n1. Create a new entry"
	<< "\n2. Add to an entry"
	<< "\n3. Read an entry"
	<< "\n4. Delete an entry"
	<< "\n5. Close Terminal\n"
	<< ">> ";
}

void newDocument()
{
	char docName[MAX];

	std::cout << "\nEnter a document name: ";
	cin.clear();
	cin >> docName;
	
	ofstream outFile;
	outFile.open(docName);

	if (!outFile)
	{
		std::cout << "\nError opening file!\n";
		return;
	}
	
	writeLines(outFile);

	outFile.close();
}

void addToDocument()
{
	char fileSearch[MAX];
	bool isFile = false;

	std::cout << "\nWhich file do you want to add to?: ";
	cin >> fileSearch;

	isFile = foundDocument(fileSearch);	
	
	if (isFile)
	{
		ofstream outFile;
		outFile.open(fileSearch, ios::app);

		writeLines(outFile);

		outFile.close();
	}
	else
	{
		std::cout << "\nError finding file!\n";
	}	

}

bool foundDocument(char fileName[])
{
	ofstream outFile;
	outFile.open(fileName);

	if (!fileName)
	{
		return false;
	}

	return true;
}


void readDocument()
{
	char fileSearch[MAX];
	char line[MAX];
	bool isFile = false;

	std::cout << "\nWhich file do you want to read?: ";
	cin.clear();
	cin >> fileSearch;

	isFile = foundDocument(fileSearch);

	if (isFile)
	{
		ifstream inFile;
		inFile.open(fileSearch);

		while (inFile.getline(line, MAX))
		{
			std::cout << line << endl;
		}

		inFile.close();
	}
	else
	{
		std::cout << "\nError opening file!\n";
	}

}

int intVal(int min, int max)
{
	int value = 0;

	while (!(cin >> value) || value < min || value > max)
	{
		std::cout << "\nPlease input a value between 1 and 5\n"
		<< ">> ";
		cin.clear();
		cin.ignore(10000,'\n');
	}
	
	return value;
}

void writeLines(ofstream& outFile)
{
	char line[MAX];

	std::cout << "\nBegin writing. Enter /save to finish.\n";
	cin.ignore(10000,'\n');

	while (true)
	{
		cin.getline(line, MAX);
	
		if (myStrCompare(line, "/save"))
		{
			break;
		}
		
		outFile << line << '\n';
	}
}

bool myStrCompare(const char first[], const char second[])
{
	int i = 0;

	while (first[i] != '\0' && second[i] != '\0')
	{
		if (first[i] != second[i])
		{
			return false;
		}
	
		i++;
	}

	return first[i] == '\0' && second[i] == '\0';
}

void goodbye()
{
	std::cout << "\n\nGoodbye from Outer Space!\n\n";
}
