#include "card.h"
#include <iostream>
#include <string>
using namespace std;

// Card default constructor 
// pre: A card object was made
// post: the Ace of Spades was created
Card::Card()
{
  myRank = 1;
  mySuit = spades;
} // end Card()

// Card copy constructor
// pre: A card object was loaded with specific values
// post: A card of the specified values was created
Card::Card(int rank, Suit s)
{
  myRank = rank;
  mySuit = s;
} // end Card(rank, s)

// toString()
// pre: A card object has been created 
// post: The cards value in tring format is returned
string Card::toString() const
{
  string rank = "";
  string suit = "";

  // Convert the card rank and suit to a string and add together
  rank = rankString(myRank);
  suit = suitString(mySuit);

  return rank + suit;
} // end toString()

// sameSuitAs()
// pre: Another card object is passed to the function
// post: Returns true if the two cards have the same suit, otherwise 
//       returns false
bool Card::sameSuitAs( const Card& c ) const
{
  bool compare;
  if(  mySuit == c.mySuit )
   compare = true;
  else
   compare = false;

  return compare;
} // end sameSuitAs()

// getRank()
// pre: Card object has been created
// post: returns the card's rank as an integer
int Card::getRank() const
{
  return myRank;
} // end getRank()

// suitString()
// pre: A Suit type is passed to the function
// post: Returns the suit value as a string
string Card::suitString(Suit s) const
{
  string suit = "";
  switch( s )
  {
    case spades:
           suit = "s";
           break;
    case hearts:
           suit = "h";
           break;
    case diamonds:
           suit = "d";
           break;
    case clubs:
           suit = "c";
           break;
   default:
           suit = "s";
           break;
  }
  
  return suit;
} // end suitString()

// rankString()
// pre: An integer is passed to the function
// post: The integer value is returned as a string for the corrct rank
string Card::rankString(int r) const
{
  string rank = "";

  switch( r )
  {
    case 1:
           rank = "A";
           break;
    case 2:
           rank = "2";
           break;
    case 3:
           rank = "3";
           break;
    case 4:
           rank = "4";
           break;
    case 5:
           rank = "5";
           break;
    case 6:
           rank = "6";
           break;
    case 7:
           rank = "7";
           break;
    case 8:
           rank = "8";
           break;
    case 9:
           rank = "9";
           break;
    case 10:
           rank = "10";
           break;
    case 11:
           rank = "J";
           break;
    case 12:
           rank = "Q";
           break;
    case 13:
           rank = "K";
           break;
    default:
           rank = "A";
           break;
  }

  return rank;
} // end rankString()

// operator ==
// pre: Card object is being compared to another
// post: Returns true if they are the same card otherwise return false
bool Card::operator == (const Card& rhs) const
{
  bool compare;
  if( myRank == rhs.myRank && mySuit == rhs.mySuit )
   compare = true;
  else
   compare = false;

  return compare;   
} // end operator ==

// operator !=
// pre: A Card object is being compare to another
// post: Returns true if they are different cards otherwise returns false
bool Card::operator != (const Card& rhs) const
{
  bool compare;
  if( myRank == rhs.myRank && mySuit == rhs.mySuit )
   compare = false;
  else
   compare = true;

  return compare;
} // end operator !=

// operator <<
// pre: A Card object is being output to the screen
// post: A card object is output to the screen
ostream& operator << (ostream& out, const Card& c)
{
  //string card = c.toString();
  out << c.toString();
} // end operator <<
