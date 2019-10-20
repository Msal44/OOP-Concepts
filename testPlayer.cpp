//***************************************************************
//
// testPlayer.cpp
// CSCI 241 Assignment 2
// Created by Melvyn Salvatierra
//
//***************************************************************


//this code under was given in class, but is needed for the assignment
//After the code fallow the instructions at the bottom


#include <iostream>
#include "Player.h"

using std::cout;
using std::endl;

int main()
   {
   // Test default constructor.
   Player p1;

   // Test alternate constructor.
   Player p2("12", "Van Damme, Cletus", "P", 'R', 'L', 0, 0);

   // Test print() method and whether constructors
   // properly initialized objects.
   cout << "Printing first player\n\n";
   p1.print();
   cout << endl << endl;

   cout << "Printing second player\n\n";
   p2.print();
   cout << endl << endl;

   // Test accessor method.
   cout << p2.getName() << endl;

   p2.incrementHits(2);
   p2.incrementAtBats(9);

   // Test print() again with updated batting average.
   p2.print();

   return 0;
   }
   
   
   /*
    Once you've written testPlayer.cpp, you can compile and link your program to test your Player class using the following command:

    g++ -Wall -Werror -std=c++11 -o testPlayer testPlayer.cpp Player.cpp
    If everything compiles and links successfully, you can run the resulting executable program by typing:

   ./testPlayer
    Once your Player class has been thoroughly tested and debugged, you can move on to the next step and write the second class for this assignment.
   
   */
   
   
