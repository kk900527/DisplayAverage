/*
   Author     : Sujan Bhandari
   Date       : 11/16/2017
   Description: This program reads number form an input file and calculates the average
                of the numbers after checking for the validity of the number.This program
                has a readfunction that reads in the input data and return boolean value of
                true or false, the function totalvalue adds the total value of the valid input
                numbers, the function validInput counts the number of valid inputs as well as
                invalid inputs and the display function prints the invalid data to the file
                andDisplaayresult function calculates the average of the valid input data
                and displays it to the user.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>


using namespace std;

//function Prototype

bool readFunction(ifstream &, double &);
void totValue (double &, double &);
void validInvalidInput(double &,int &,int &);
void displayToFile(ofstream &,double &);
void displayToUser(int &,int &, string &,double &, double &);

//main function start here
int main()
{
    // declaring variables
    double value, average;
    double  totalSum = 0.0;
    int validInput =0;
    int invalidInput = 0;
    string fileName;
    ofstream outputFile;
    ifstream inputFile;

    // get the input file from user

    getline(cin, fileName);


    // open an output file

    outputFile.open("invalid-numbers.txt");

    // open an input file

    inputFile.open(fileName.c_str());



     // If statement is used to check if the file name is valid.

     if ( !(inputFile.fail()))
    {
     // while loop is used to make sure functions are called till the input remains valid.

        while (readFunction(inputFile,value))
        {
          //functions are called

            totValue (value,totalSum);
            validInvalidInput(value,validInput,invalidInput);
            displayToFile(outputFile,value);

        }

        displayToUser(validInput,invalidInput,fileName,totalSum,average );

    }

    else
    {
        cout << "File \""<< fileName <<"\" could not be opened"<< endl;
    }


    // close both input and ouput file.

     inputFile.close();
     outputFile.close();
    return 0;
}
// end of main function

/* This function  gets the value from the file linked with input file
   and returns the boolean value of true when data is read and stored in the
   value argument or returns the false otherwise
    Params: ifstream &inputfile, double &value
*/

bool readFunction(ifstream &inputFile, double &value)
{
    bool result = false;


        if (inputFile >> value)
        {
         if( (value >= 0) && (value <= 110))
         {

         }

            result = true;
        }
return result;
}

/* This  function gets the  value and total sum  from main function through pass by
   reference and keep adding the number to the total sum if the value is in correct range.

    Params: double &value, double &totalsum

*/


void totValue (double &value, double &totalSum)
{
  // validating the input value
  if ((value >= 0) && (value <= 110))
  {
     totalSum = totalSum + value;

  }
 return;
}

/* This function gets the value , validinput and invalidinput from main function
   through pass by reference and keeps tally of valid input and invalid input and pass
   it to the main function through pass by reference.

    Params: double &value, int &validinput,int &invalidinput

    Returns: non it's a void type function
*/

void validInvalidInput(double &value,int &validInput,int &invalidInput )
{

  if ((value >= 0) && (value <= 110))
  {
     validInput++;

  }
  else
  {
     invalidInput++;
  }


}

/*This function gets the value from the input file and save the invalid input to the
  file.
    Returns: non it's a void type function

    Paramaters: ofstream & outputfile,double &value

*/


void displayToFile(ofstream & outputFile ,double &value)
{
   if ((value < 0) || (value > 110))
   {
     outputFile << setprecision(2) << showpoint << fixed;
    outputFile << value << endl;

   }

}

/*  This function gets validinput, invalidinput, as well as the Totalsum,average and name of the file
    the  from main function and calculate the average of the data and displays it to the user.

    Params: int &validinput,int &invalidinput,string &filename,double &Totalsum,double &average

    Returns: non it's a void type function
*/

void displayToUser(int &validInput,int &invalidInput,string &fileName, double &totalSum,double &average)
{
    // displaying message for the user
    cout << "Reading from file \"" << fileName <<"\"" << endl;
    cout << "Total values: " << invalidInput + validInput << endl;
    cout << "Invalid values: " << invalidInput << endl;
    cout << "Valid values: " << validInput<< endl;
    cout << setprecision(2) << showpoint << fixed;

   // to calculate the average valid input must be greater than zero

       if (validInput >0)
       {
             // calculating the average
            average = totalSum / validInput;

            cout << "Average of valid values: " << average << endl;
       }
       else
       {     // if the valid input is zero error message will display
            cout << "An average cannot be calculated" << endl;
       }




}
