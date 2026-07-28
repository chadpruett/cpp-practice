#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;
int main() {

  // DECLARE variables
  char vehicle;
  int adults = 0;
  int seniors = 0;
  int youths = 0;
  int bikes = 0;
  int totalPeople;
  double freeTicket;
  double total;
  double const VEHICLE_COST = 57.90;
  double const ADULT_COST = 14.95;
  double const SENIOR_COST = 7.40;
  double const YOUTH_COST = 5.55;
  double const BIKE_COST = 4.00;

  // DISPLAY greeting message to user
  cout << "Welcome to the Washington State Ferries Fare Calculator!" << endl;

  // DISPLAY and format fare descriptions
  cout << '\n' << "Fare Description" << setw(45) << "Ticket $" << endl;
  cout << setfill('-') << setw(35) << "";
  cout << setfill(' ') << setw(18) << "" << setfill('-') << setw(8) << "" << endl;
  cout << "Vehicle Under 14' (less than 168" << '"' << ") & Driver";
  cout << setfill(' ') << setw(17) << "$57.90" << endl;
  cout << "Adult (age 19 - 64)" << setw(41) << "$14.95" << endl;
  cout << "Senior (age 65 & over) / Disability" << setw(24) << "$7.40" << endl;
  cout << "Youth (age 6 - 18)" << setw(41) << "$5.55" << endl;
  cout << "Bicycle Surcharge (included with Vehicle)" << setw(18);
  cout << "$4.00" << '\n' << endl;

  // DISPLAY and prompt user for input
  cout << "Are you riding a vehicle on the Ferry (y/n): ";
  cin >> vehicle;

  // CONVERT input to lower case
  vehicle = tolower(vehicle);
  cout << '\n';

  // IF vehicle input is equal to 'y'
  if (vehicle == 'y') 
  {

    // PROMPT user for input
    cout << "How many adults?: ";
    cin >> adults;
    cout << "How many seniors?: ";
    cin >> seniors;
    cout << "How many youths?: ";
    cin >> youths;

    // SET totalPeople to adults + seniors + youths
    totalPeople = adults + seniors + youths;

    // IF totalPeople is >= 0 and <= 20
    if (totalPeople >= 0 && totalPeople <= 20)
    {
      cout << '\n';
      cout << "You have a total of " << totalPeople << " people." << '\n';
      cout << endl;

      // SET and DISPLAY total
      total = adults * ADULT_COST + seniors * SENIOR_COST + youths * YOUTH_COST;
      total = total + VEHICLE_COST;
      cout << "Your total is $" << fixed << setprecision(2);
      cout << total << "." << '\n' << endl;

      // IF total is < $100.00
      if (total < 100.00)
      {
        // SET and DISPLAY freeTicket to 100 - total
        freeTicket = (100 - total);
        cout << "If you spend $" << freeTicket << " more, you are eligible ";
        cout << "for a free adult ticket for the next trip." << endl;
      }

      // ELSE total is NOT < $100.00
      else
      {
        cout << "Congrats!! You have earned a free adult ticket for ";
        cout << "your next trip!!" << endl;
      }
    }

    // ELSE totalPeople is NOT >= 0 and <= 20
    else 
    {
      cout << '\n';
      cout << "Invalid amount of people! Please keep group to 20 or less.";
      cout << endl;
    }
  }

  // ELSE IF input is equal to 'n'
  else if (vehicle == 'n')
  {
    cout << "How many adults?: ";
    cin >> adults;
    cout << "How many seniors?: ";
    cin >> seniors;
    cout << "How many youths?: ";
    cin >> youths;
    cout << "How many bikes?: ";
    cin >> bikes;

    // SET totalPeople to adults + seniors + youths
    totalPeople = adults + seniors + youths;

    // IF totalPeople is >= 0 and <= 20 
    if (totalPeople >= 0 && totalPeople <= 20)
    {
      cout << '\n';
      cout << "You have a total of " << totalPeople << " people." << '\n';
      cout << endl;

      // SET and DISPLAY total
      total = ((adults * ADULT_COST) + (seniors * SENIOR_COST));
      total = total + ((youths * YOUTH_COST) + (bikes * BIKE_COST));
      cout << "Your total is $" << fixed << setprecision(2);
      cout << total << "." << '\n' << endl;

      // IF total is < $100.00
      if (total < 100)
      {
        freeTicket = 100.00 - total;
        cout << "If you spend $" << freeTicket << " more, you are eligible ";
        cout << "for a free adult ticket for the next trip." << endl;
      }

      // ELSE total is NOT < $100.00
      else
      {
        cout << "Congrats!! You have earned a free adult ticket for ";
        cout << "your next trip!!" << endl;
      }
    }

    // ELSE totalPeople is NOT >= 0 and <= 20
    else 
    {
      cout << '\n';
      cout << "Invalid amount of people! Please keep group to 20 or less.";
      cout << endl;
    }
  }

  // ELSE input is NOT 'y' or 'n'
  else
  {
    cout << "Invalid input! Please answer with y or n." << endl;
  }
  cout << '\n';

  // DISPLAY goodbye message
  cout << "Thank you for using Washington State Ferries Fare Calculator!" << endl;
  return 0;
}
