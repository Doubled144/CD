/*
  Filename   : CD.cc
  Author     : Dominic J. DuRant-Russell
  Course     : CSCI 362-02
  Assignment : 2
  Description: Calculate interest earned on a certificate 
               of deposit (CD) over a given period of time. 
*/

/************************************************************/
// System includes

#include <iostream>
#include <string>
#include <cstdlib>
#include <stdio.h>
#include <locale.h>

/************************************************************/
// Local includes

/************************************************************/
// Using declarations

using std::cout;
using std::cin;
using std::endl;
using std::string;

/************************************************************/
// Function prototypes/global vars/typedefs

void
printIntro ();

void
printTable (int numRows, double balance, double rate);

void
printRow (int rowNum, double balance, double interest);

double
calcInterest (double balance, double rate);

/************************************************************/

int
main (int argc, char* argv[])
{
  double balance, rate;
  int numRows;

  printIntro ();

  cout << "Please enter the initial balance: ";
  cin >> balance; 

  cout << "Please enter the interest rate  : ";
  cin >> rate;

  cout << "Please enter the number of years: ";
  cin >> numRows;

  cout << endl;

  setlocale(LC_NUMERIC, "");
  printTable (numRows, balance, rate);

  return EXIT_SUCCESS;
}

/************************************************************/

void
printIntro ()
{
  cout << "This program will calculate the interest earned\n";
  cout << "  on a CD over a period of several years.\n";
  cout << endl;
}

/************************************************************/

void
printTable (int numRows, double balance, double rate)
{
  cout << "Year       ";
  cout << "Balance      ";
  cout << "Interest   ";
  cout << "New Balance\n";
  cout << "----       -------      --------   -----------\n";

  printRow (numRows, balance, rate);
}

/************************************************************/

void
printRow (int rowNum, double balance, double interest)
{ 
  for (int i = 1; i <= rowNum; ++i)
  {
    // Value to hold the progressing interest by 
    // taking each new balance and redoing the calculation.
    double addInt = calcInterest (balance, interest);

    double newBal = addInt + balance;

    printf("%-4d", i);
    
    printf("%'14.2f", balance);
    
    printf("%'14.2f", addInt);
    
    printf("%'14.2f", newBal);
    

    cout << endl;

    // Balance will take the value of the new balance in order
    // for 'addInt' to obtain the next amount of interest
    balance = newBal; 
  }
}

/************************************************************/

double
calcInterest (double balance, double rate)
{
  double interest = balance * (rate / 100);

  return interest;
}

/************************************************************/
/************************************************************/