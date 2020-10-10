#include <ctime>
#include <iostream>
#include "StandardDeck.h"

void Pause() {
	std::cout << "\nPress \'ENTER\' to continue..." << std::endl;
	std::cin.ignore();	fflush(stdin);
}

int main()
{
	/*	Your main() function should demonstrate each of the features of the StandardDeck class*/
	srand(time(nullptr)); // seed the random number generator

	// create a deck
	 StandardDeck deck1;

	for (int i=0; i < deck1.GetDeck().size(); i++)
	{
		std::cout << std::string(deck1.GetDeck()[i]) << std::endl;
	}
	std::cout << "There are " << deck1.CardsRemaining() << " cards remaining.";
	Pause();
	
	std::cout << std::string(deck1.DrawNextCard()) << std::endl;
	
	std::cout <<"There are " <<  deck1.CardsRemaining() << " cards remaining.";
	// PlayingCard.std::string(deck1.GetDeck()[0]);
	// Show the deck object as initialized
	Pause();
	
	std::cout << std::string(deck1.DrawRandomCard()) << std::endl;
	for (int i = 0; i < deck1.GetDeck().size(); i++)
	{
		std::cout << std::string(deck1.GetDeck()[i]) << std::endl;
	}
	std::cout << "There are " << deck1.CardsRemaining() << " cards remaining.";
	// Draw the next card and show it

	// Draw a random card and show it
	
	// Show the deck with the remaining cards

	// Shuffle the deck and show the result

	// Reset the deck and show the result
}


