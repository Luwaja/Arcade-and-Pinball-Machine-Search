//------------------------------------------
// Purpose: Machine cpp
// Author: Luke James
//------------------------------------------

#include <iostream>
#include "machine.h"


//==========================================
// Constructors
//==========================================
Machine::Machine()
{
    string GameTitle = "";
    string Manufacturer = "";
    int Year = 0;
    string Type = "";

}

//------------------------------------------       
Machine::Machine(string GameType, string Manufacturer, int Year, string Type)
{

}

//------------------------------------------      
Machine::Machine (const Machine & machine)
{
    GameTitle = machine.GameTitle;
    Manufacturer = machine.Manufacturer;
    Year = machine.Year;
    Type = machine.Type;
}

//------------------------------------------        
Machine::~Machine()
{

}


//==========================================
// Getters
//==========================================
string Machine::getGameTitle() const
{
    return GameTitle;
}

//-------------------------------------------
string Machine::getManufacturer() const
{
    return Manufacturer;
}

//-------------------------------------------
int Machine::getYear() const
{
    return Year;
}

//-------------------------------------------
string Machine::getType() const
{
    return Type;
}


//===========================================
// Setters
//===========================================
void Machine::setGameTitle(string gametitle)
{
    GameTitle = gametitle;
}

//-------------------------------------------
void Machine::setManufacturer(string manufacturer)
{
    Manufacturer = manufacturer;
}

//-------------------------------------------
void Machine::setYear(int year)
{
    Year = year;
}

//-------------------------------------------
void Machine::setType(string type)
{
    Type = type;
}


//===========================================
// Print
//===========================================
void Machine::print()
{
    cout << "Title:        " << getGameTitle() << endl;
    cout << "Manufacturer: " << getManufacturer() << endl;
    cout << "Year:         " << getYear() << endl;
    cout << "Type:         " << getType() << endl;
    cout << "=============================================" << endl;
}


//===========================================
// Error check: Case Sensitivity
//===========================================
string Machine::caseMatch(string text)
{
    for (int i = 0; i < text.length(); i++)
    {
        text[i] = tolower(text[i]);
    }
    return text;
}