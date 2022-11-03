#ifndef MACHINE_H
#define MACHINE_H
//------------------------------------------
// Purpose: Machine h
// Author: Luke James
//------------------------------------------

#include <iostream>
using namespace std;

class Machine
{
    public:
        // Constructor methods
        Machine();
        Machine(string GameType, string Manufacturer, int Year, string Type);
        Machine (const Machine & machine);
        ~Machine();

        // Get Methods
        string getGameTitle() const;
        string getManufacturer() const;
        int getYear() const;
        string getType() const;

        // Set methods
        void setGameTitle(string gametype);
        void setManufacturer(string manufacturer);
        void setYear(int year);
        void setType(string type);

        // Read and print methods
        void print();

        // Input error check method
        static string caseMatch(string text);

    private:
        // Object attributes
        string GameTitle;
        string Manufacturer;
        int Year;
        string Type;
};

#endif