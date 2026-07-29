#include<iostream>
#include<iomanip>
using namespace std;


void welcome();
void readScore(string prompt, double& num);
int readInt(string prompt);
double assignAverage(int numAssigns);
void getInput(double& midTermScore, double& finalExamScore);
double calcFinalScore(double assignAvg, double midterm, double finalScore);
void calcLetterGrade(double finalScore, char& letter);

int main()
{
	int assignments = 0;
	char letterGrade;
	double averageScore = 0;
	double midTermScore = 0;
	double finalExamScore = 0;
	double finalScore = 0;
	double num = 0;
	
	welcome();
	assignments = readInt("\nEnter the number of assignments (0 - 10): ");
	averageScore = assignAverage(assignments);
	getInput(midTermScore, finalExamScore); 
	finalScore = calcFinalScore(averageScore, midTermScore, finalExamScore);
       	calcLetterGrade(finalScore, letterGrade);

	std::cout << fixed << setprecision(1)
	<< "\n\nYour Final Numeric Score is " << finalScore
	<< "\nYour Final Grade is " << letterGrade << "\n\n";

	return 0;
}

void welcome()
{
	std::cout << "\nWelcome to my Final Grade Calculator!"
	<< "\nPlease enter the following information and I will"
	<< " calculate your\nFinal Numerical Grade and Letter Grade for you!"
	<< "\nThe number of assignments must be between 0 and 10."
	<< "\nAll scores entered must be between 0 and 4.";
}

void readScore(string prompt, double& num)
{
	while (!(cin >> num) || num < 0 || num > 4)
	{
		std::cout << "\nPlease input a valid entry."
		<< prompt;
		cin.clear();
		cin.ignore(10000,'\n');
	}
}

int readInt(string prompt)
{
	int value = 0;
	
	std::cout << prompt;

	while (!(cin >> value) || value < 0 || value > 10)
	{
		std::cout << "\nPlease input a valid entry.\n"
		<< prompt;
		cin.clear();
		cin.ignore(10000,'\n');
	}

	return value;
}

double assignAverage(int numAssigns)
{
	double averageScore = 0;
	double scoreTotal = 0;
	double num = 0;
	
	for (int i = 0; i < numAssigns; i++)
	{
			
		readScore("\nEnter Score: ", num);
		scoreTotal += num;
	}
	
	averageScore = scoreTotal / numAssigns;
	
	return averageScore;
}

void getInput(double& midTermScore, double& finalExamScore)
{
	
	readScore("\nEnter your midterm exam score: ", midTermScore);
	readScore("\nEnter your final exam score: ", finalExamScore);

}

double calcFinalScore(double assignAvg, double midterm, double finalScore)
{
	double assignmentWeight = 0.60;
	double assignmentScore = 0;
	double examWeight = 0.20;
	double examScore = 0;
	
	assignmentScore = assignAvg * assignmentWeight;
	examScore = (midterm + finalScore) * examScore;

	return assignmentScore + examScore;
}

void calcLetterGrade(double finalScore, char& letter)
{
	if (finalScore >= 3.3 && finalScore <= 4.0)
	{
		letter = 'A';
	}
	else if (finalScore >= 2.8 && finalScore < 3.3)
	{
		letter = 'B';
	}
	else if (finalScore >= 2.0 && finalScore < 2.8)
	{
		letter = 'C';
	}
	else if (finalScore >= 1.2 && finalScore < 2.0)
	{
		letter = 'D';
	}
	else
	{
		letter = 'F';
	}
}
