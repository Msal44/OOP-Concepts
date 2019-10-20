/*
CSCI 241 Assignment2
Created by: Melvyn Salvatierra 
*/

#include "Player.h"
#include "Team.h"

#include <cstring>
#include <iomanip>
#include <iostream>
#include <string.h>

using std::cout;
using std::endl;
using std::right;
using std::left;
using std::setw;

/*
Player::Player()

Parameters: None.

Returns: Constructors do not have a return data type.

A "default" constructor in C++ is a constructor that has no parameters. If no parameters are supplied when a Player object is created, this constructor will be called to set the object's data members to valid default values.

This method should set the number, name, and position data members to "null" or "empty" strings. This can be done by copying a null string literal ("") into the character array using strcpy() or by setting element 0 of the array to a null character ('\0'). The two handedness data members should be set to 'R'). The hits and at bats data members should be set to 0.

(If you're working in C++11 and you initialized the data members at declaration as described above under C++11 Initialization Option for Data Members, this method's body can be empty. You still need to code the method definition, even though it won't actually do anything.)
*/

Player::Player(){

}

/*
Player::Player(const char* newNumber, const char* newName, const char* newPosition, char newBats, char newThrows, int newHits, int newAtBats)

Parameters: 1) a C string that will not be changed by this method that contains a new jersey number, 2) a C string that will not be changed by this method that contains a new name, 3) a C string that will not be changed by this method that contains a new position, 4) a character that contains a new batting handedness, 5) a character that contains a new throwing handedness, 6) an integer that contains a new number of hits, and 7) an integer that contains a new number of at bats. DO NOT GIVE THESE PARAMETERS THE SAME NAMES AS YOUR DATA MEMBERS..

Returns: Constructors do not have a return data type.

Use strcpy() to copy the new number and new name parameters into the object's number and name data members. Assign the new hits and new at bats parameters to their corresponding data members.
*/


Player::Player(const char* newNumber, const char* newName, const char* newPosition, char newBats, char newThrows, int newHits, int newAtBats){

        strcpy(JearsyNumber, newNumber);
        strcpy(Name, newName);
        numHits =  newHits;
        numBats = newAtBats;
        BatHand = newBats;
        ThrowHand = newThrows;
}

/*
const char* Player::getName() const

Parameters: None.

Returns: The name data member.

This method does not modify the object for which it is called and is therefore declared to be const.

This accessor method should return the name data member. In C++, the usual return data type specified when you are returning a C string is const char* or "pointer to a character constant" (since returning an array's name will convert the name into a pointer to the first element of the array, which in this case is data type char; the "const" part means that the calling function will not be able to use the pointer to modify the data that it points to).

*/

const char* Player::getName() const {

        return Name; //please check this dont forget me Marvin
}

/*
double Player::computeAverage() const

Parameters: None.

Returns: The player's batting average.

This method does not modify the object for which it is called and is therefore declared to be const.

This method should compute and return the player's batting average. This is simply the player's number of hits divided by their number of at bats. If the player has never batted, that formula will cause a "division by zero" runtime error; in that case, the method should return 0.0 for the player's batting average.
*/

double Player::computeAverage() const {

        double avgBat = 0;
        double NewNumHits;
        double NewNumBats;

        NewNumHits = numHits;
        NewNumBats = numBats;

        std::cout << std::fixed;
        std::cout << std::setprecision(3);

        if(numBats == 0) {

        return 0.0;
        }

        else {
        avgBat = NewNumHits / NewNumBats;
        return avgBat;
        }
}

/*
void Player::incrementHits(int newHits)

Parameters: An integer that contains a new number of hits to be added to the player's hits.

Returns: Nothing.

This mutator met
*/

void Player::incrementHits(int newHits){


        numHits += newHits;

}

/*
void Player::incrementAtBats(int newAtBats)

Parameters: An integer that contains a new number of at bats to be added to the player's at bats.

Returns: Nothing.

This mutator method should add the new at bats parameter to the number of at bats data member.
*/
void Player::incrementAtBats(int newAtBats){


        numBats += newAtBats;


}

/*
void Player::print() const

Parameters: None.

Returns: Nothing.

This method does not modify the object for which it is called and is therefore declared to be const.

This method should print the seven data members of the object on the console using cout. Use setw() to line the printed values up in columns. Call the computeAverage() method to obtain the player's batting average. The batting average should be printed using fixed-point notation with three places after the decimal point. Consult the sample output for an example of how to space and justify the output from this method.
*/

void Player::print() const{

        cout << right << setw(2) << JearsyNumber << left << setw(8) << " " << setw(30) << Name << setw(11) << Position << setw(7) << BatHand;
        cout << setw(5) << ThrowHand;
        cout << right << setw(8) << numHits << setw(10) << numBats << setw(10) << computeAverage() << endl;
        // prints out all the date of each player
}
