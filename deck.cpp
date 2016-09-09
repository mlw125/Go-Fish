#include "deck.h"
#include <ctime>
#include <cstdlib>

// Deck default constructor
// pre: A Deck object is initialized
// post: A deck of 52 cards is created with te appropriate number
//       of suits and ranks.
Deck::Deck()
{
  int suitTracker = 1; // value to keep track of the suit
  int numTracker = 1; // value to keep track of the face value

  // This will loop 52 times to make a normal card deck
  for(int x = 0; x < 52; x++)
  {
     if(suitTracker == 1) // spades
     {
       myCards[x] = Card(numTracker, (Card::Suit) 0);
       suitTracker++;
     } // end if
     else if(suitTracker == 2) // hearts
     {
       myCards[x] = Card(numTracker, (Card::Suit) 1);
       suitTracker++;
     } // end else if
     else if(suitTracker == 3) // diamonds
     {
       myCards[x] = Card(numTracker, (Card::Suit) 2);
       suitTracker++;
     } // end else if
     else // clubs
     {
       myCards[x] = Card(numTracker, (Card::Suit) 3);
       suitTracker = 1; // reset the suitTracker to go through suits again
       numTracker++; // increase to the next card value
     } // end else
  } // end for
  myIndex = 0; // start at the first index
} // end Deck()

// shuffle()
// pre: A deck object was created
// post: A deck of shuffled cards is created
void Deck::shuffle()
{
  // seed the random generator
  srand(time(0));
  
  // Go through each card in the deck and replace it with another
  // randomly selected card
  for(int x = 0; x < 200; x++)
  {
    int randIndex = rand() % 51; // first random card
    int randIndex2 = rand() % 51; // second random card
    Card temp = myCards[randIndex]; // temporary card holder
    myCards[randIndex] = myCards[randIndex2];
    myCards[randIndex2] = temp;
  } // end for
} // end shuffle()

// dealCard
// pre: A deck object has been created
// post: Returns the top card of the deck (element 0 in this case)
Card Deck::dealCard()
{
  // Card object to hold the top card
  Card currentCard;
  // if the deck is not empty take the top card and return it
  if(myIndex < 52)
  {
     currentCard = myCards[myIndex];
     myIndex += 1; 
  } // end if 
  // esle return an Ace of Spades
  else
    currentCard = Card(0, (Card::Suit) 0); // end else
  
  return currentCard;
} // end dealCard()

// size()
// pre: A deck object has been created
// post: Returns the numbers of cards left in the deck
int Deck::size() const
{
  int size = 0;
  size = SIZE - myIndex; // get the numbers of cards left

  return size;
} // end size()

