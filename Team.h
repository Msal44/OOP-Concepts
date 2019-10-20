#ifndef TEAM_H
#define TEAM_H
#include "Player.h"
#include  <string>
#include <iostream>
using std::string;
//***************************************************************
//
// Team.h
// CSCI 241 Assignment 2
//
// Created by Melvyn Salvatierra z1884312 & Abel Vega Arteaga z1883490
//
//***************************************************************

/*
The Team class represents a collection of Player objects. Like the Player class, the code for this class will be placed in two separate files.

Place the class declaration in a header file called Team.h. Like the file Player.h you wrote in Step 1, this file should begin and end with header guards to prevent it from accidentally being #included more than once in the same source code file.

After the header guard at the top of the file but before the class definition, make sure to #include "Player.h".

Data Members

The Team class should have the following two private data members:

A team name (a character array with room for 30 characters plus the null character)
An array of 40 Player objects
A symbolic constant representing the number of players, which may be declared like this:
   static const int NUM_PLAYERS = 40;
Note: Once again, make sure you code your data members in THE EXACT ORDER LISTED ABOVE and with THE EXACT SAME DATA TYPES.

Method Prototypes

The Team class declaration should (eventually) contain public prototypes for all of the methods in the Team.cpp source code file described in Step 5 below.
*/

class Team {
private:
        // data memebers

        char TeamName[31]{};
        Player playerArray[40];
        static const int NUM_PLAYERS = 40;

public:
        //method prototypes
        Team();
        Team(const string& fileName);
        void sortPlayers();
        int searchForPlayer(const char* searchName) const;
        void processGameData(const string& fileName);
        void print() const;
};

#endif
