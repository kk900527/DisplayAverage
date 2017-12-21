/*============================================================================
   Name     : lesson9part1.cpp
   Author   : sujan Bhandari
   Date     : 11/24/2017
   description:The program reads sales information from a file and writes out a bar chart for
               each of the stores which is created by writing out a sequence of X characters.
               This program has a read function that reads in the value and returns the boolean
               value of true for valid input and false for the invalid input. There is another
               function that reads in the store number and amount of sales from the file linked
               with inputfill and puts the data in the argument variables from the calling function.
               DisplayFunction gets &storeNumber,long long int &sales and ofstream &outputFill
               the  from main function and assign X for every 1000 dollar sales
               and writes the number of X to the fill.

=========================================================================== */
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

//function Prototype
bool readFunction(ifstream &inputFile, unsigned int &storeNumber, long long int &sales);
void displayFunction (unsigned int &storeNumber, long long int &sales, ofstream &outputFile);

//main function start here
int main()
{

    long long int sales = 0;
    string fileName; // hold filen name iinput from the user
    unsigned int storeNumber = 0; //store number from the file
    ofstream outputFile;
    ifstream inputFile;


     //get the file name input from the user
     getline(cin, fileName);

     //open the file input from the user
     inputFile.open(fileName);


     //open the output file where data is printed
     outputFile.open("saleschart.txt");

     // check if the file exist or not.
    if ( !(inputFile.fail()))
    {

        if (readFunction(inputFile,storeNumber,sales)== true)
         {
          // out put the header and firest value if it's true
         outputFile <<"SALES BAR CHART" << endl;
         outputFile <<"(Each X equals 1,000 dollars)"<< endl;
         displayFunction (storeNumber,sales,outputFile);

         }
             while(readFunction(inputFile,storeNumber,sales))
             {
                 // calling a function
                displayFunction (storeNumber,sales,outputFile);
             }

    }
    else
    {
        // print for the user if the fill name could not find
      cout << "File \""<< fileName <<"\" could not be opened"<< endl;
    }



    // close both input and out fill
    inputFile.close();
    outputFile.close();
return 0;
} // end of main function

/* This function readFunction gets the  store number sale amount  from the file through inputFile
   and pass the data in the argument of the function and returns boolean value of true or false
   according to the validity of the data.
    Params: ifstream &inputfill, unsigned int &storeNumber ,long long int &sales

*/


bool readFunction(ifstream &inputFile, unsigned int &storeNumber ,long long int &sales)
{
    bool result = false;


        if (inputFile >> storeNumber >> sales)
        {

             if( (storeNumber > 0) && (storeNumber < 100))
             {
                        if (sales >= 0)
                        {

                        }
                        else
                        {
                            // display the error message

                          cout << "The sales value for store " << storeNumber <<" is negative" << endl;

                        }

                }
                else
                {   // display the store number is invalid.

                    cout <<"The store number " << storeNumber << " is not valid" << endl;
                }

                    result = true;
        }
        else
        {
           result = false;
        }

return result;
}

/* This function gets the store number and sales as well as  and ofstream &outputFill
    the  from main function. It assigns X for every 1000 dollar sales and the function
    writes the number of X  to the fill.

    Params: unsigned int &storeNumber, long long int &sales,ofstream &outputFill

*/

void displayFunction (unsigned int &storeNumber, long long int &sales,ofstream &outputFile)
{
    int numofX;

     if( (storeNumber > 0) && (storeNumber < 100))
         {
             if (sales >= 0)
                {

                    numofX = sales/1000;
                    outputFile << setw(2)<< "Store " << setw(2) << storeNumber<<": ";

                     for( int counter = 1 ; counter <= numofX ; counter++ )
                          {
                            outputFile <<  "X" ;

                          }

                    outputFile << endl;
                }
          }

}
