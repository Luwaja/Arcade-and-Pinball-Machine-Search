//------------------------------------------
// Purpose: Main
// Author: Luke James
//------------------------------------------

// Include statements
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "machine.h"
using namespace std;


//----------------------------------------------------------------------
// FUNCTION 1 - Reads the file sorted by title and puts info into vector
//----------------------------------------------------------------------
vector<Machine> readFileByTitle()
{
    vector<Machine> machineByTitle;
    
    // Open input file
    ifstream din;
    din.open("machines.txt");

    // Check for failure
    if (din.fail())
    {
        cout << "ERROR: Could not open file" << endl;
    }
    else
    {
        // Variables
        string title, manufacturer, type;
        string year;

        // Assign values
        while (!din.eof())
        {
            Machine machine;
            getline(din, title, ',');
            machine.setGameTitle(title);
            getline(din, manufacturer, ',');
            machine.setManufacturer(manufacturer);
            getline(din, year, ',');
            machine.setYear(stoi(year));
            getline(din, type);
            machine.setType(type);
            machineByTitle.push_back(machine);
        }
        din.close();
    }
    
    for(int i = 0; i < machineByTitle.size(); ++i)
        {
            cout << "Title: " << machineByTitle[i].getGameTitle() << endl
                 << "Maker:  " << machineByTitle[i].getManufacturer() << endl
                 << "Year:         " << machineByTitle[i].getYear() << endl
                 << "Type:        " << machineByTitle[i].getType() << endl
                 << "===============================================" << endl;
        }
    return machineByTitle;
}


//-------------------------------------------------------------------
// FUNCTION 2 - Reads the file sorted by year and puts info into vector
//-------------------------------------------------------------------
vector<Machine> readFileByYear()
{
    vector<Machine> machineByYear;
    
    // Open input file
    ifstream din;
    din.open("machines-by-year.txt");

    // Check for failure
    if (din.fail())
    {
        cout << "ERROR: Could not open file" << endl;
    }
    else
    {
        // Variables
        string title, manufacturer, type;
        string year;

        // Assign values
        while (!din.eof())
        {
            Machine machine;
            getline(din, title, ',');
            machine.setGameTitle(title);
            getline(din, manufacturer, ',');
            machine.setManufacturer(manufacturer);
            getline(din, year, ',');
            machine.setYear(stoi(year));
            getline(din, type);
            machine.setType(type);
            machineByYear.push_back(machine);
        }
        din.close();
    }
    
    return machineByYear;
}


//-------------------------------------------------------------------
// FUNCTION 3 - Recursive binary search
//-------------------------------------------------------------------
int recursiveSearch(vector<Machine>, string title, int low, int high)
{
    // Vector creation and filling
    vector<Machine> machineByTitle;
    machineByTitle = readFileByTitle();

    // Creating object for machine class
    Machine machine;

    // Calculate midpoint
    int mid = (low + high)/2;
    //cout << "L:" << low << " M:" << mid << " H:" << high << endl;

    // Check termination condition
    if(low > high)
    {
        return -1; //not found
    }
    
    // Check if value is found
    else if(machine.caseMatch(title) == machine.caseMatch(machineByTitle[mid].getGameTitle()))
    {
        return mid; // found
    } 
    
    // Search to the left
    else if(machine.caseMatch(title) < machine.caseMatch(machineByTitle[mid].getGameTitle())) 
    {
        return recursiveSearch(machineByTitle, title, low, mid - 1);
    }
    
    // Search to the right
    else
    {
        return recursiveSearch(machineByTitle, title, mid + 1, high);
    }
    
    return -1;
}

//-------------------------------------------------------------------
// FUNCTION 4 - Iterative binary search
//-------------------------------------------------------------------
int iterativeSearch(vector<Machine>, int year, int low, int high)
{
    //Variable
    int findBeg;
    
    // Vector creation and filling
    vector<Machine> machineByYear;
    machineByYear = readFileByYear();

    // Creating object for machine class
    Machine machine;

    

    // Check termination condition
    while(low <= high)
    {
        // Calculate midpoint
        int mid = (low + high)/2;
        //cout << "L:" << low << " M:" << mid << " H:" << high << endl;
        
        // Check if value is found
        if(year == machineByYear[mid].getYear())
        {
            // While value is equal find beginning is set to value
            while(year == machineByYear[mid].getYear())
            {
                findBeg = mid;
                
                // Find beginning by backtracking 1 index
                while(year == machineByYear[findBeg].getYear())
                {
                    findBeg = findBeg - 1;
                }
                return findBeg + 1;
            }
        } 

        // Search to the left
        else if(year < machineByYear[mid].getYear()) 
        {
            high = mid - 1;
        }

        // Search to the right
        else
        {
            low = mid + 1;
        } 
    }
    
    return -1;
}


//-------------------------------------------------------------------
// MAIN FUNCTION!
//-------------------------------------------------------------------
int main()
{ 
    // Interface variables + machine class object
    int choice;
    char yesNoSearch;
    Machine machine;

    // Vector declarations
    vector<Machine> machineByTitle;
    vector<Machine> machineByYear;

    // Assigning vectors values from the read functions
    machineByTitle = readFileByTitle();
    machineByYear = readFileByYear();
    
    do
    {
        // Main interface: prompt for user and input
        cout << endl
            << "****************************************************" << endl
            << "Welcome to the Arcade and Pinball Machine Searcher." << endl
            << "Please choose one of the following search functions:" << endl
            << "1. Search for game title (Recursive)" << endl
            << "2. Search for year made (Iterative)" << endl
            << "3. Exit program" << endl << endl
            << "Choice: ";
        cin >> choice;
        
        while(choice != 1 && choice != 2 && choice != 3)
        {
            // Notifies user of error. Prompts reselection.
            cout << endl
                << "ERROR: Invalid choice selection." << endl
                << "Please try again." << endl;
            
            // Reselection
            cout << endl
                << "Please choose one of the following search functions:" << endl
                << "1. Search for game title (Recursive)" << endl
                << "2. Search for year made (Iterative)" << endl
                << "3. Exit program" << endl << endl
                << "Choice: ";
            cin >> choice;
        }
        
        if(choice == 1)
        {
            string title;
            int result;
            
            // Prompt for user and input
            cout << endl
                << "You have chosen the recursive title search." << endl
                << "Enter the title you are searching for:" << endl
                << "Title: ";
            cin.ignore();
            getline(cin, title);
            cout << endl << "---------------------------------------------" << endl;
            cout << "Searching for: " << title << endl;
            cout << "---------------------------------------------" << endl << endl;
            cout << "Here are the results:" << endl;
            cout << "=============================================" << endl;
                
            // Recursive title search
            recursiveSearch(machineByTitle, title, 0, machineByTitle.size() - 1);
            result = recursiveSearch(machineByTitle, title, 0, machineByTitle.size() - 1);

            // Check if there are no results for title
            if (result >= 0)
            {
                 machineByTitle[result].print();
            }
            else
            {
                cout << "*There were no records for that title*" << endl;
                cout << "=============================================" << endl;
            }
        }

        if(choice == 2)
        {
            int year;
            int result;

            // Prompt for user and input
            cout << endl
                << "You have chosen the iterative year search." << endl
                << "Enter the year you are searching for:" << endl
                << "Year: ";
            cin >> year;
            cout << endl << "Searching for machines made in " << year << "." << endl << endl; 
            cout << "Here are the results:" << endl;
            cout << "=============================================" << endl;
            
            // Iterative year search
            iterativeSearch(machineByYear, year, 0, machineByYear.size() - 1);
            result = iterativeSearch(machineByYear, year, 0, machineByYear.size() - 1);

            // Starts at first machine in year then increases index until the year changes
            // If result is -1, then the output will say no records
            if (result >= 0)
            {
                while(machineByYear[result].getYear() == year)
                {
                    machineByYear[result].print();
                    result = result + 1;
                } 
            }
            else
                {
                    cout << "*There were no records for that year*" << endl;
                    cout << "=============================================" << endl;
                }
        }

        if(choice == 3)
        {
            cout << endl << "Thank you! Goodbye!";
            exit(-99);
        }
    
        // Asks user if they would like to keep searching or stop
        cout << endl << "Would you like to choose another function?" << endl
             << "(y/n):";
        cin >> yesNoSearch;
        
        // While loop to infinitely ask to keep searching until n
        while (yesNoSearch != 'y' && yesNoSearch != 'n')
        {
        cout << "Sorry. That's not a valid input. Please try again." << endl
             << "Would you like to choose another function?" << endl
             << "(y/n):";
        cin >> yesNoSearch;
        }

    }while(yesNoSearch == 'y');

    return 0;
}