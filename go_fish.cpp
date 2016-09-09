// Driver file for Go Fish
// Created by Matthew Williams 8/18/14

#include "card.h"
#include "deck.h"
#include "player.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// Function Prototypes

// dealCard() deals a single card to a player
// parameter: Player and the deck to draw a card from
// returns: None
void dealCard(Player &, Deck &);
// bookFromHand() check if there is a pair and if so adds to a player's book
// parameter: Player object and variable to output to file
// returns: None
void bookFromHand(Player &, ofstream &);
// playerHands() outputs players ahnd to a file
// parameter: Player object and variabe to output to file
// returns: none
void playerHands(Player, Player, ofstream &);
// playerBooks() displays each player's book
// parameter: Player object and variable to output to file
void playerBooks(Player, Player, ofstream &);

int main()
{
 // Make two players
  Player p1("Greg");
  Player p2("Andrew");

  // Create the deck and shuffle it
  Deck deck;
  deck.shuffle();

  // Deal 7 cards to player one
  for(int x = 0; x < 7; x++)
    dealCard(p1, deck);

  // Deal 7 cards to player two
  for(int x = 0; x < 7; x++)
    dealCard(p2, deck);

  // Create a log to store the game data
  ofstream gameLog;
  gameLog.open("log.txt");

  // Display the hands of both players
  playerHands(p1, p2, gameLog);

  // Book any pairs from the newly dealt hand
  bookFromHand(p1, gameLog);
  bookFromHand(p2, gameLog);

  // Displays the players' books
  playerBooks (p1, p2, gameLog);

  gameLog << p1.getName() << " starts first." << endl << endl;

  // This will loop as long as both players have cards in their
  // hands and there still cards to draw from otherwise the game is over
  while (p1.getHandSize() != 0 && p2.getHandSize() != 0 && deck.size() > 0)
  {
    // These variables will check if pairs were
    // made during the players turn
    bool pairP1 = true;
    bool pairP2 = true;

    // Player 1's turn, will loop until pairP1 is false meaning there
    // were no more pairs gained.
    while(pairP1 == true)
    {
      // If the player as no cards in hand and the deck is not empty then
      // draw from the deck
      if(p1.getHandSize() == 0 && deck.size() > 0)
      {
        dealCard(p1, deck);
        bookFromHand(p1, gameLog);
      } // end if
      
      // If the player has card in their hand they can ask for cards
      // otherwise its the other player's turn.
      if(p1.getHandSize() != 0)
      {
        // Player 1 chooses a random card from their hand and asks if the
        // other player has one of the same suit.
        Card askCard = p1.chooseCardFromHand();
        gameLog << p1.getName() << " asks: Do you have a(n) ";
        gameLog << askCard.rankString(askCard.getRank()) << "?" << endl;

        // Card object to store the other player's match
        Card askCardPair;

        // If the other player has no cards in their hand then don't 
        // bother to check if there are matching pairs
        if(p2.getHandSize() == 0)
        {
          gameLog << p2.getName() << " replies: Go Fish." << endl;
          if(deck.size() > 0)
          {
            dealCard(p1, deck);
            bookFromHand(p1, gameLog);
          }
          pairP1 = false;
        } // end if
        // If the player two has a card of the same rank then it will
        // be removed and added to player 1's hand. That hand will be
        // then be checked for a pair.
        else if(p2.checkHandForPair(askCard, askCardPair) == true)
        {
          gameLog << p2.getName() << " replies: Yes." << endl;
          askCardPair = p2.removeCardFromHand(askCardPair);
          p1.addCard(askCardPair);
          bookFromHand(p1, gameLog);
        } // end if
        // If player 2 as no card of the same rank then
        // player 1 will draw a card fro the deck (if it isn't empty)
        // and then the hand will be checked for pairs.
        else
        {
          gameLog << p2.getName() << " replies: Go Fish." << endl;
          if(deck.size() > 0)
          {
            dealCard(p1, deck);
            bookFromHand(p1, gameLog);
          }
          pairP1 = false;
        } // end else
      }  // end if
      else
      {
        gameLog << p1.getName() << "'s hand is empty\n";
        pairP1 = false;
      }
     } // end while(pairP1 == true)

    // Displays the hands and books of each player
    gameLog << endl;
    playerHands(p1, p2, gameLog);
    playerBooks(p1, p2, gameLog);
    gameLog << endl;

    // This while loop works exactly the same as the loop for Player 1
    while (pairP2 == true)
    {
      if(p2.getHandSize() == 0 && deck.size() > 0)
      {  
        dealCard(p2, deck); 
        bookFromHand(p2, gameLog);
      } // end if
      
      if(p2.getHandSize() != 0)
      {
        Card askCard = p2.chooseCardFromHand();
        gameLog << p2.getName() << " asks: Do you have a(n) ";
        gameLog << askCard.rankString(askCard.getRank()) << "?" << endl;

        Card askCardPair;
        if(p1.getHandSize() == 0)
        {
          gameLog << p1.getName() << " replies: Go Fish." << endl;
          if(deck.size() > 0)
          {
            dealCard(p2, deck);
            bookFromHand(p2, gameLog);
          } // end if
          pairP2 = false;
        } // end if
        else if(p1.checkHandForPair(askCard, askCardPair) == true)
        {
          gameLog << p1.getName() << " replies: Yes." << endl;
          askCardPair = p1.removeCardFromHand(askCardPair);
          p2.addCard(askCardPair);
          bookFromHand(p2, gameLog);
        } // end if
        else
        {
          gameLog << p1.getName() << " replies: Go Fish." << endl;
          if(deck.size() > 0)
          {
            dealCard(p2, deck);
            bookFromHand(p2, gameLog);
          } // end if
          pairP2 = false;
        } // end else
      } // end if
      else
      {
        gameLog << p2.getName() << "'s hand is empty\n";
        pairP2 = false;
      } // end else
    } // end while(pairP2 == true)

    // Display players' hand and books
    gameLog << endl;
    playerHands(p1, p2, gameLog);
    playerBooks(p1, p2, gameLog);
    gameLog << endl;
  } // end while

  // Figure out who won the game (or if there was a tied)
  if((p1.getBookSize()/2) > (p2.getBookSize()/2))
    gameLog << endl << p1.getName() << " won the game." << endl;
  else if((p1.getBookSize()/2) < (p2.getBookSize()/2))
    gameLog << endl << p2.getName() << " won the game." << endl;
  else
    gameLog << endl << "The game was a tie!" << endl;

  // Display the number of pairs for each player
  gameLog << p1.getName() << "'s number of pairs: ";
  gameLog << (p1.getBookSize()/2) << endl;
  gameLog << p2.getName() << "'s number of pairs: ";
  gameLog << (p2.getBookSize()/2) << endl;
  gameLog.close();

  return 0;
}

void dealCard (Player &player, Deck &deck)
{
  // Gets a card object to store the card from the deck
  // and then puts it into the players hand
  Card card = deck.dealCard();
  player.addCard(card);
} // end dealCard()

void bookFromHand(Player &player, ofstream &log)
{
  // Card objects to hold the pair of cards to be
  // stored in a book
  Card tempCard1;
  Card tempCard2;
  
  // Will loop until the player has no more pairs inn their hand
  while(player.checkHandForBook(tempCard1, tempCard2) == true)
  {
     // Store the pair in a book and remove from hand
     player.bookCards(tempCard1, tempCard2);
     tempCard1 = player.removeCardFromHand(tempCard1);
     tempCard2 = player.removeCardFromHand(tempCard2);

     // Outputs info to file
     log << player.getName() << " added cards ";
     log << tempCard1.toString() << " and " << tempCard2.toString();
     log << " to their book" << endl;
  } // end while
} // end bookFromHand()

void playerHands( Player p1, Player p2, ofstream &log)
{
  // Outputs both players' hands to a file
  log << p1.getName() << "'s hand: " << p1.showHand() << endl;
  log << p2.getName() << "'s hand: " << p2.showHand() << endl;
} // end playerHands()

void playerBooks( Player p1, Player p2, ofstream &log)
{
  // Output both players' books to a file
  log << p1.getName() << "'s book: " << p1.showBooks() << endl;
  log << p2.getName() << "'s book: " << p2.showBooks() << endl;
} // end playerBooks()
