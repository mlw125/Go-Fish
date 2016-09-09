#include "player.h"
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>

// Player default constructor
// pre: A Player object has been created
// post: The player is named John
Player::Player()
{
  myName = "John";
} // end Player()

// addCard
// pre: A card object is passed to the function
// post: The card is pushed into myHand
void Player::addCard (Card c)
{
  myHand.push_back(c);
} // end addCard()

// bookCards()
// pre: Two cards are passed to the function
// post: The two cards are stored in myBook
void Player::bookCards (Card c1, Card c2)
{
  myBook.push_back(c1);
  myBook.push_back(c2);
} // end bookCards()

// checkHandForBook()
// pre: Two Cards are passed to the function
// post: If a pair was found then return true otherwie return false
bool Player::checkHandForBook (Card &c1, Card &c2)
{
  // This value was declared as using myHand.size() was giving
  // errors for some reason.
  int scroll1 = myHand.size() - 1;

  // Grabs the first card and compares it to every other card
  // and then repeats for the next card until it gets to one before the
  // last card in the hand.
  for( int x = 0; x < scroll1; x++)
  {
    c1 = myHand[x]; // holds the 
    int scroll2 = myHand.size();
    // Will loop through every card after the one found above and compares
    // them to each other to see if they share the same rank.
    for(int y = (x+1); y < scroll2; y++)
    {
      c2 = myHand[y];
      // If the cards share the same rank then return true
      if(c1.getRank() == c2.getRank())
        return true;
    } // end for
  } // end for
  return false;
} // end checkHandForBook()


// chooseCardFromHand()
// pre: A Player object has been created
// post: A randomly selected card from the player's hand is returned
Card Player::chooseCardFromHand() const
{
  srand(time(0));

  int handSize = myHand.size();
  int randomCard = rand() % handSize;
  return myHand[randomCard];
} // end chooseCardFromHand()

// removeCardFromHand(()
// pre: A Card is passed to the function
// post: The card is removed from the hand and then returned.
Card Player::removeCardFromHand (Card c)
{
  // Loops until the card is found in the hand and then deletes it.
  for(int x = 0; x < myHand.size(); x++)
  {
    if(myHand[x] == c)
      myHand.erase(myHand.begin()+x); // end if
  } // end for

  return c;
} // end removeCardFromHand()

// showHand()
// pre: A Player object ws created
// post: All the Cards in the hand are converted to a string and
//       then returned together as one string.
string Player::showHand() const
{
  string hand = "";
  Card cardTemp;
  // Loop through the player's hand
  for(int x = 0; x < myHand.size(); x++)
  {
    cardTemp = myHand[x];
    hand += cardTemp.toString();
    hand += " ";
  } // end for

  return hand;
} // end showHand()

// showBook()
// pre: A Player object has been created
// post: All the cards in the plaer's book are converted to 
//       one string and then returned.
string Player::showBooks() const
{
  string book = "";
  Card bookTemp;
  // Loops through the player's book
  for(int x = 0; x < myBook.size(); x++)
  {
    bookTemp = myBook[x];
    book += bookTemp.toString();
    book += " ";
  } // end for

  return book;
} // end showBooks()

// getHandSize()
// pre: A Player object has been created
// post: returns the number of cards in a player's hand
int Player::getHandSize() const
{
  return myHand.size();
} // end getHandSize()

// getBookSize()
// pre: A Player object has been created
// post: Returns the number of crads in a player's book
int Player::getBookSize() const
{
  return myBook.size();
} // end getBookSize()

// checkHandForPair()
// pre: Two Card objects are passed the function
// post: The hand is checked to see if the a card has the same
//       rank the first card. If so return true otherwise false.
bool Player::checkHandForPair (Card &c1, Card &c2)
{
  // Loops through a player's hand
  for(int x = 0; x < myHand.size(); x++)
  {
    c2 = myHand[x]; // Card to be compared and if needed, changed for use later
    // if a card has the ame rank as the other then return true.
    if(c2.getRank() == c1.getRank())
      return true; // end if
  } // end for
  return false;
} // end checkHandForPair
