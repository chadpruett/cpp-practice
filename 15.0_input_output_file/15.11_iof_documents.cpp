#include<iostream>
#include<fstream>
using namespace std;

const int MAX = 50;

void welcome();
void newDocument;
void addToDocument;
void readDocument;
void delDocument;
void goodbye();
void writeLines(ofstream& outFile);
bool foundDocument(char fileName[]);
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
			delDocument();
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
	cin >> docName;
	
	ofstream outFile;
	outFile.open(docName);

	if (!docName)
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

		while (outFile.getline(line,MAX))
		{
			writeLines(outFile)
		
		}
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
	char line[MAX];
	
	while (inFile.getline(line, MAX))
	{
		std::cout << line << endl;
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
