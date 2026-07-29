#include<iostream>
#include<iomanip>
#include<cctype>
using namespace std;

void getProductCode(char code[]);
bool isValidProductCode(const char code[]);
void printResult(bool isValid);


int main()
{
	char code[8];
	bool isValid = false;
	
	getProductCode(code);
	isValid = isValidProductCode(code);
	printResult(isValid);
	
	return 0;
}



void getProductCode(char code[])
{
	std::cout << "\nEnter a code with exactly three letters followed "
	<< "by three numbers\n";
	
	cin >> setw(8) >> code;
}
bool isValidProductCode(const char code[])
{
	return isalpha(code[0]) &&
	       isalpha(code[1]) &&
	       isalpha(code[2]) &&
	       isdigit(code[3]) &&
	       isdigit(code[4]) &&
	       isdigit(code[5]) &&
  	       code[6] == '\0';
}


void printResult(bool isValid)
{

	if (isValid)
	{
		std::cout << "\nValid";
	}	
	else
	{
		std::cout << "\nInvalid";
	}

}


