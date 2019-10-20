PART 1

Assignment Overview
In Part 1 of this assignment, you will write a main program and several classes to create and print a small database of baseball player data. The assignment has been split into two parts to encourage you to code your program in an incremental fashion, a technique that will be increasingly important as the semester goes on.

Purpose
This assignment reviews object-oriented programming concepts such as classes, methods, constructors, accessor methods, and access modifiers. It makes use of an array of objects as a class data member, and introduces the concept of object serialization or "binary I/O".

Set Up
As with Assignment 1, you should create a subdirectory to hold your files for Assignment 2.

In that directory, make a symbolic link to the data file for this part of the assignment:

   ln -s /home/turing/t90kjm1/CS241/Data/Fall2019/Assign2/teamData
In this assignment, you will be creating several source code and header files, as described below. You can create each of these files separately using the nano editor, just as you did on Assignment 1.

Program
For this assignment, you will need to write three source code files as well as two header files. Each of these files is relatively short, but many inexperienced programmers are overwhelmed by the idea of writing a program as multiple files. "Where do I start?!!" is a common refrain. This assignment sheet attempts to walk you through the steps of writing a multi-file program.

The steps outlined below should not be thought of as a purely linear process, but rather an iterative one - For example, work a little on Step 1, then a little on Step 2, then test what you've written (Step 3).

Step 1: Write the Player class declaration
The Player class represents information about a baseball player. The code for the Player class will be placed in two separate files, which is the norm for non-template C++ classes.

The header file for a class contains the class declaration, including declarations of any data members and prototypes for the methods of the class. The name of the header file should be of the form ClassName.h (for example, Player.h for the header file of the Player class).

A skeleton for the Player.h file is given below. As shown, a header file should begin and end with header guards to prevent it from accidentally being #included more than once in the same source code file (which would produce duplicate symbol definition errors). The symbol name used in the header guards can be any valid C++ name that is not already in use in your program or the C/C++ libraries. Using a name of the format CLASSNAME_H (like SELLER_H in the code below) is recommended to avoid naming conflicts.

#ifndef PLAYER_H
#define PLAYER_H

   //***************************************************************
   //
   // Player.h
   // CSCI 241 Assignment 2
   //
   // Created by name(s) and z-ID(s)
   //
   //***************************************************************

   class Player
   {
   private:
 
      // Data members for the Player class go here.

   public:

       // Method prototypes for the Player class.

    Player();
    Player(const char*, const char*, const char*, char, char, int, int);
    const char* getName() const;
    double computeAverage() const;
    void incrementHits(int);
    void incrementAtBats(int);
    void print() const;
     };

      #endif
      
      
Data Members

The Player class should have the following seven private data members:

A jersey number (a character array with room for 2 characters plus the null character
A name (a character array with room for 30 characters plus the null character)
A position (a character array with room for 2 characters plus the null character
Batting handedness (a single character)
Throwing handedness (a single character)
Number of hits (an integer)
Number of at bats (an integer)
Note: Make sure that you code your data members in THE EXACT ORDER LISTED ABOVE and with THE EXACT SAME DATA TYPES. For example, if you make the name array 30 characters long instead of 31, your final program will not work correctly.

C++11 Initialization Option for Data Members

C++11 adds the ability to initialize the non-static data members of a class at the time you declare them using a "brace-or-equal" syntax. This is very convenient, and can eliminate most or all of the code from your default constructor. Here are a few examples of the kind of initializations you can do in a class declaration:

      class Foo
      {
          private:

          // Data members
          int x = 0;                                  // Initialize x to 0
          double y = 9.9;                             // Initialize y to 9.9
          char text[21]{};                            // Initialize text to an empty string
          char name[11]{'J', 'o', 'h', 'n', '\0'};    // Initialize name to "John"
         string s{"Hello"};                          // Initialize s to "Hello"
      };

Feel free to use this option if you like.

Method Prototypes

The Player class declaration contains public prototypes for all of the methods in the Player.cpp source code file described in Step 2 below.

Step 2: Write the Player class implementation
The source code file for a class contains the method definitions for the class. The name of the source code file should be of the form ClassName.cpp (for example, Player.cpp for the source code file of the Player class).

The Player class implementation should (eventually) contain definitions for all of the methods described below. Make sure to #include "Player.h" at the top of this file.

Player::Player()

Parameters: None.

Returns: Constructors do not have a return data type.

A "default" constructor in C++ is a constructor that has no parameters. If no parameters are supplied when a Player object is created, this constructor will be called to set the object's data members to valid default values.

This method should set the number, name, and position data members to "null" or "empty" strings. This can be done by copying a null string literal ("") into the character array using strcpy() or by setting element 0 of the array to a null character ('\0'). The two handedness data members should be set to 'R'). The hits and at bats data members should be set to 0.

(If you're working in C++11 and you initialized the data members at declaration as described above under C++11 Initialization Option for Data Members, this method's body can be empty. You still need to code the method definition, even though it won't actually do anything.)

Player::Player(const char* newNumber, const char* newName, const char* newPosition, char newBats, char newThrows, int newHits, int newAtBats)

Parameters: 1) a C string that will not be changed by this method that contains a new jersey number, 2) a C string that will not be changed by this method that contains a new name, 3) a C string that will not be changed by this method that contains a new position, 4) a character that contains a new batting handedness, 5) a character that contains a new throwing handedness, 6) an integer that contains a new number of hits, and 7) an integer that contains a new number of at bats. DO NOT GIVE THESE PARAMETERS THE SAME NAMES AS YOUR DATA MEMBERS..

Returns: Constructors do not have a return data type.

Use strcpy() to copy the new number and new name parameters into the object's number and name data members. Assign the new hits and new at bats parameters to their corresponding data members.

const char* Player::getName() const

Parameters: None.

Returns: The name data member.

This method does not modify the object for which it is called and is therefore declared to be const.

This accessor method should return the name data member. In C++, the usual return data type specified when you are returning a C string is const char* or "pointer to a character constant" (since returning an array's name will convert the name into a pointer to the first element of the array, which in this case is data type char; the "const" part means that the calling function will not be able to use the pointer to modify the data that it points to).

double Player::computeAverage() const

Parameters: None.

Returns: The player's batting average.

This method does not modify the object for which it is called and is therefore declared to be const.

This method should compute and return the player's batting average. This is simply the player's number of hits divided by their number of at bats. If the player has never batted, that formula will cause a "division by zero" runtime error; in that case, the method should return 0.0 for the player's batting average.

void Player::incrementHits(int newHits)

Parameters: An integer that contains a new number of hits to be added to the player's hits.

Returns: Nothing.

This mutator method should add the new hits parameter to the number of hits data member.

void Player::incrementAtBats(int newAtBats)

Parameters: An integer that contains a new number of at bats to be added to the player's at bats.

Returns: Nothing.

This mutator method should add the new at bats parameter to the number of at bats data member.

void Player::print() const

Parameters: None.

Returns: Nothing.

This method does not modify the object for which it is called and is therefore declared to be const.

This method should print the seven data members of the object on the console using cout. Use setw() to line the printed values up in columns. Call the computeAverage() method to obtain the player's batting average. The batting average should be printed using fixed-point notation with three places after the decimal point. Consult the sample output for an example of how to space and justify the output from this method.

Step 3: Test and debug the Player class
As you write your declaration and implementation of the Player class, you should begin testing the code you've written. Create a basic main program called testPlayer.cpp that tests your class. This is not the final version of main() that you will eventually submit. In fact, you'll end up discarding it entirely by the time you're done with the assignment. An example test program is given below.

You do not have to have written all of the methods for the Player class before you begin testing it. Simply comment out the parts of your test program that call methods you haven't written yet. Write one method definition, add its prototype to the class declaration, uncomment the corresponding test code in your test program, and then compile and link your program. If you get syntax errors, fix them before you attempt to write additional code. A larger amount of code that does not compile is not useful - it just makes debugging harder! The goal here is to constantly maintain a working program.

//***************************************************************
//
// testPlayer.cpp
// CSCI 241 Assignment 2
//
// Created by name(s) and z-ID(s)
//
//***************************************************************

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
Once you've written testPlayer.cpp, you can compile and link your program to test your Player class using the following command:

   g++ -Wall -Werror -std=c++11 -o testPlayer testPlayer.cpp Player.cpp
If everything compiles and links successfully, you can run the resulting executable program by typing:

   ./testPlayer
Once your Player class has been thoroughly tested and debugged, you can move on to the next step and write the second class for this assignment.

Step 4: Write the Team class declaration
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

Step 5: Write the Team class implementation
The Team class implementation should (eventually) contain definitions for all of the methods described below. Make sure to #include "Team.h" at the top of this file.

Team::Team()

Parameters: None.

Returns: Constructors do not have a return data type.

This constructor is called to create an empty database. The method should set the team name to a "null" or "empty" string.

(As with the Player class, if you initialize the team name when you declare it, this method's body can be empty. You still need to code the method with an empty body.)

Team::Team(const string& fileName)

Parameters: 1) A C++ string that will not be changed by this method that contains the name of an input file of team data.

Returns: Constructors do not have a return data type.

This constructor should do the following:

Declare an input file stream variable (the code below assumes it is named inFile).

Open the file stream for the file name passed in as the fileName parameter. Check to make sure that the file was opened successfully. If not, print an error message and exit the program.

Read the database file into your Team object. You can do this with a single statement:

   inFile.read((char*) this, sizeof(Team));
Close the file stream.

The read() method will read the team name and all 40 Player objects into your Team object.

void Team::print() const

Parameters: None.

Returns: Nothing.

This method does not modify the object for which it is called and is therefore declared to be const.

This method should first print a descriptive header line (e.g., "team name Roster"), followed by column headers for the various data members of the Player class. See the sample output for an example of how this should look.

It should then loop through the array of Player objects and print the data for each element of the array, with one player's data per line. Here we see some of the power of object-oriented programming: since each element of the array is an object, we can call a method for that object. We've already written a print() method for the Player class, so printing an element of the array is as easy as calling print() for the array element. The syntax for calling a method using an array element that is an object is simple:

   playerArray[subscript].methodName(arguments);
Step 6: Write the main program
Once you have at least the skeleton of the Team written, you can write your real main program. Create the file assign2.cpp. This file will need to #include "Team.h" and will contain nothing but the function main().

Since most of the logic of the program is embedded in the two classes you already wrote, the main() function's logic will be extremely short:

Create a Team object using the alternate constructor you wrote. Pass the filename string "teamData" as an argument to the constructor.
Call the print() method for the Team object.
Step 7: Write a makefile, and then test and debug your program
The file named makefile tells the make utility how to build the final executable file from your collection of C++ source code and header files. The makefile for this assignment is given in its entirety below. Makefiles for future assignments will follow this basic pattern.

IMPORTANT NOTE: The commands that appear in the makefile below MUST be indented as shown. Furthermore, the indentation MUST be done using a tab character, not spaces. If you don't indent your makefile commands, or indent using spaces, your makefile WILL NOT WORK.

      #
      # PROGRAM:  assign2
      # AUTHOR:   your name
      # Z-ID:     your z-id
      # DATE DUE: due date of program
      #

      # Compiler variables
      CCFLAGS = -Wall -std=c++11

      # Rule to link object code files to create executable file
      assign2: assign2.o Player.o Team.o
         g++ $(CCFLAGS) -o assign2 assign2.o Player.o Team.o

      # Rules to compile source code files to object code
      assign2.o: assign2.cpp Team.h
	      g++ $(CCFLAGS) -c assign2.cpp

      Player.o: Player.cpp Player.h
	      g++ $(CCFLAGS) -c Player.cpp

      Team.o: Team.cpp Team.h
	        g++ $(CCFLAGS) -c Team.cpp

      Team.h: Player.h

      # Pseudo-target to remove object code and executable files
      clean:
	      -rm *.o assign2
         
Once you've written your makefile, you can build the program simply by typing the command make and run it by typing ./assign2.

Other Points
If your program code creates objects of any C++ library classes (and it will), remember to include the required header files and using statements. Failure to do so will result in a syntax error that says "[variable name] was not declared in this scope".

You do not need to submit this part of the assignment, only Part 2.

Once you've finished this part of the assignment, you can delete the file testPlayer.cpp.

Make sure to document your program according to the standards listed on the course website. In particular, each class method or function should have a documentation box describing its purpose, the input parameters (if any), and the return value (if any). There should also be a doc





PART 2

Assignment Overview
In Part 2 of this assignment, you will add some functionality to the Team class and add some logic to your main() routine to test that functionality.

Purpose
This part of the assignment introduces the insertion sort and binary search algorithms.

Set Up
In your Assignment 2 directory, make a symbolic link to the data file for this part of the assignment:

   ln -s /home/turing/t90kjm1/CS241/Data/Fall2019/Assign2/gameData.txt
Building and running the executable file is unchanged from Part 1.

To remove the executable and object code files for your program (conserving disk space), you can type:

   make clean
Program
For this part of the assignment, you'll need to modify two of the files you wrote for Part 1.

Step 2: Add the following methods to the Team class
void Team::sortPlayers()

Parameters: None.

Returns: Nothing.

This method should sort the array of Player objects in ascending order by name using the insertion sort algorithm.

The sort code linked to above sorts an array of integers called numbers of size size. You will need to make a substantial number of changes to that code to make it work in this program:

This will be a method, not a function. Change the parameters for the method to those described above. This method can be private.

In the method body, change the data type of bucket to Player. This temporary storage will be used to swap elements of the array of Player objects.

In the method body, change any occurrence of numbers to the name of your array of Player objects and size to NUM_PLAYERS (or whatever you called the data member that specifies the number of Player objects in the array).

The comparison of playerArray[j-1] and bucket will need to use the C string library function strcmp() to perform the comparison. Also, you'll need to use the getName() method to access the name data member within each Player object. The final version of the inner for loop should look something like this:

   for (j = i; (j > 0) && (strcmp(playerArray[j-1].getName(), bucket.getName()) > 0); j--)
      ...
It is legal to assign one Player object to another; you don't need to write code to copy individual data members.

Add a call to the sortPlayers() method to the end of the alternate constructor you wrote for the SalesDB class. This will sort the array of Player objects that were read in from the input file.

int Team::searchForPlayer(const char* searchName) const

Parameters: 1) a C string that will not be changed by this method that contains a name to search for.

Returns: If the search was successful, returns the index of the array element that contains the player name that was searched for, or -1 if the search fails.

This method does not modify the object for which it is called and is therefore declared to be const. The method can be private.

The logic for this method is a variation of the binary search of a sorted list strategy.

      int low = 0;
      int high = NUM_PLAYERS - 1;
      int mid;

      while (low <= high)
       {
       mid = (low + high) / 2;

         if (searchName is equal to name data member of playerArray[mid])
         return mid;

         if (searchName is less than name data member of playerArray[mid])
            high = mid - 1;
         else
            low = mid + 1;
         }

      return -1;
      
As in sortPlayers(), you'll need to use strcmp() to perform the comparison of names.

void Team::processGameData(const string& fileName)

Parameters: A C++ string that will not be changed by this method and that contains the name of a file of game data.

Returns: Nothing.

This method will read a series of records, each containing a last name, a first name, a number of hits, and a number of at bats. For each record, the method should search for the player name and, if found, should increment the hits and at bats for that player. If a player name is not found, an error message should be printed.

Pseudocode for the method logic is given below.

    ifstream inFile;
    char lastName[21];
    char firstName[11];
    int hits;
    int atBats;
    char name[31];

    Open inFile using the file name passed in as a parameter
    Check for successful open

    Read lastName from inFile
    while (not end of file)
    {
        Read firstName from inFile
        Read hits from inFile
        Read atBats from inFile

        Concatenate lastName, ", ", and firstName together to form name
      
        int index = searchForPlayer(name);
        if (index == -1)
            Print an error message
        else
        {
            Print a message listing the name, hits, and atBats
            Call incrementHits() for the Player object at element index of the array of Player objects, passing it hits
            Call incrementAtBats() for the Player object at element index of the array of Player objects, passing it atBats
            
        }
            
        Read lastName from inFile
    }

    Close input file
Step 3: Add two method calls the main program
The main() routine logic will now look like this:

Create a Team object using the alternate constructor you wrote. Pass the filename string "teamData" as an argument to the constructor.
Call the print() method for the Team object.
Call the processGameData() method for the Team object. Pass the filename string "gameData.txt" as an argument to the method.
Call the print() method for the Team object.
Other Points
If your program code creates objects of any C++ library classes (and it will), remember to include the required header files and using statements. Failure to do so will result in a syntax error that says "[variable name] was not declared in this scope".

As always, programs that do not compile on turing/hopper automatically receive 0 points.

Make sure to document your program according to the standards listed on the course website. In particular, each function or method should have a documentation box describing the purpose of the function, the input parameters, and the return value (if any). There should also be a documentation box for the program as a whole.

Submit the final version of your program u
