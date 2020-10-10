/** OOP3200. F2020. Main.cpp
 *
 *  In this lab you will create your own collection class called StandardDeck, which
 *	will 'contain' objects of the PlayingCard class.  The intent of the class is to
 *	represent a standard deck of 52 cards that might be useful in a card game type
 *	application.
 *
* Author: Jacky Yuan, 100520106
*         Ashok Sasitharan, 100745484
* Date: Oct 9, 2020
* Change Log: N/A
*/

#include <ctime>
#include <iostream>
#include "StandardDeck.h"

void Pause() {
	std::cout << "\nPress \'ENTER\' to continue..." << std::endl;
	std::cin.ignore();	fflush(stdin);
}

//function to output the deck
 void DisplayDeck(StandardDeck& tmpDeck)
{
	for(auto i =0; i < tmpDeck.GetDeck().size(); i++)
	{
		std::cout << std::string(tmpDeck.GetDeck()[i]) << std::endl;
	}
}

int main()
{
	/*	Your main() function should demonstrate each of the features of the StandardDeck class*/
	srand(time(nullptr)); // seed the random number generator

	// create a deck
	 StandardDeck deck1;

	//print out the deck
	 DisplayDeck(deck1);

	//show amount of remaining cards
	std::cout << "There are " << deck1.CardsRemaining() << " cards remaining." << std::endl;
	Pause();
	
	
	// Draw the next card and show it
	std::cout << std::string(deck1.DrawNextCard()) << std::endl;

	
	Pause();
	// Draw a random card and show it
	std::cout << std::string(deck1.DrawRandomCard()) << std::endl;
	
	

	Pause();
	// Show the deck with the remaining cards
	DisplayDeck(deck1);

	
	Pause();
	// Shuffle the deck and show the result
	std::cout << "\nSHUFFLE DECK" << std::endl;
	deck1.Shuffle();
	DisplayDeck(deck1);


	Pause();
	//reset the deck to default and display it
	std::cout << "\nRESET THE DECK" << std::endl;
	deck1.ResetDeck();
	DisplayDeck(deck1);
	
	
}	


