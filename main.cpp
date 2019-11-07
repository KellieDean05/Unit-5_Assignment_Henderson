



#include <cstdlib>  // Provides EXIT_SUCCESS
#include <iostream>  // Provides cout, cerr, endl
#include "Input_Validation_Extended.h" // Provides getValidatedInput<T>(), a header File with a Template Class
                              // Extended 2-11-2016 by Dr. McMillan to add validation methods by datatype
#include<string> //for string manipulation
#include<sstream> //for string manipulation and comparison
#include <iomanip>
#include <locale> // this is to use toupper() transform char
using namespace std;

double weeklyPay(double, double,string,int);// function prototype
void convert (string);
int main( )
{    
  string tR= "Tcc-TR IS COOL.";
   
         //a function call for each person - no input from the console for part 1
         cout << fixed << setprecision(2) << endl; 
         cout << weeklyPay (47.00, 505.75,"Kellie", 1 ) << endl;
         cout << weeklyPay (45.00, 55.25,"Melvin", 1) << endl;
         cout << weeklyPay (15.00, 65.25,"Susan", 2) << endl;
         cout << weeklyPay (41.00, 14.75,"Mika", 1) << endl;
         cout << weeklyPay (25.00, 15.00, "Eldridge", 2) << endl;
         cout << weeklyPay (55.00, 203.50,"Freedom", 1) << endl;
         cout << weeklyPay (32.50, 100.25,"kingofGreenTea", 1) << endl;
convert (tR); //Dr_T edit no "int" TR is only needed argument value
  return 0;
}



double weeklyPay(double hours, double rate, string name, int empType)
{ // complete the function definition
double netPay = 0.0, grossPay = 0.0, taxableWages = 0.0;
double ss = 0.062, med = 0.0145, sSwages = 0.00, medWages =0.0;
double FIT = 0.0, fitTax = 0.10, /*dental = 0.0,*/ retirement = 0.0;
double clockHours = 40.0, overtimeRate = 2.0;
locale loc;
string status = " ";
string reset = "\x1b[0m";
string color = "\x1b[" + to_string(32) + ";4m"; // green underlined
// display the name on screen CAP in colore
cout << color << endl; // format a new line before each name.
for(int i = 0; i < name.length(); i++ )
{
  cout << toupper (name[i], loc);
}
cout << reset << endl; // a line afer the name

  // determine status 
  status = (empType == 1) ? "Fulltime" : "Parttime";
 /* if(empType == 1)
  {
    status = "Fulltime";
  }
  else if (empType == 2)
  {
    status = "Parttime";
  }
  else 
  {
    status = "Error";
  }*/
  cout << "Status: " << status << endl;

FIT = (rate < 15.0) ? 0.12 : 0.15; // set FIT based upson rate
cout << "FIT Rate: " << FIT << endl;
// if rate is less than 15 set FIT to equal .12 else set FIT to equal to .15.

/*dental = (empType == 1) ? 17.00 : 0.00; // deduction for fulltime employees*/
retirement = (empType == 1) ? 77.00 : 0.00; // deduction for parttime employees
/*cout << "Dental Deduction is: $" << dental << endl;*/
cout << "Retirment Deduction is: $" << retirement << endl;

grossPay = (hours <= clockHours) ? (hours * rate) : 
(( clockHours * rate) + ((hours - clockHours) * (overtimeRate * rate)));

cout << "Gross Pay: $" << grossPay << endl;

taxableWages = grossPay - /*dental +*/ (retirement);
cout << "Taxable Wages are: $" << taxableWages << endl;
fitTax = taxableWages * FIT; // less pre-tax deductions
sSwages = grossPay * ss;
medWages = grossPay * med;

cout << "SSDed is : $" << sSwages << endl;
cout << "Medicare Deductions is: $" << medWages << endl;

netPay = grossPay - (/*dental + */ retirement + fitTax + sSwages + medWages);
cout << "Net Pay is: $" ;
    return netPay;
}

void convert (string tR) //removed int int... Dr_T edit
{
  locale loc;

 // tR = "TCC-TR IS COOL."; //removed Dr_T
    for (int i = 0; i < tR.length(); i++)
  { 
    cout << tolower(tR[i], loc);
}
}
