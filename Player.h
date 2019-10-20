#ifndef PLAYER_H
#define PLAYER_H

// Player.h
// CSCI 241 Assignment 2
// Created by Melvyn Salvatierra 

/*
Data Members

The Player class should have the following seven private data members:

A jersey number (a character array with room for 2 characters plus the null character
A name (a character array with room for 30 characters plus the null character)
A position (a character array with room for 2 characters plus the null character
Batting handedness (a single character)
Throwing handedness (a single character)
Number of hits (an integer)
Number of at bats (an integer)

*/


class Player
{
private:

    // Data members for the Player class go here.

        char JearsyNumber[3]{};//check this later
        char Name[31]{}; //these are characters plus null
        char Position[3]{};
        char BatHand = 'R';
        char ThrowHand = 'R';
        int numHits = 0;
        int numBats = 0;

public:

    // Method prototypes for the Player class.

    Player();
    Player(const char*, const char*, const char*, char, char, int, int);//The Player class declaration contains public prototypes for all of the methods in the Player.cpp
    const char* getName() const;
    double computeAverage() const;
    void incrementHits(int);
    void incrementAtBats(int);
    void print() const;
};

#endif

