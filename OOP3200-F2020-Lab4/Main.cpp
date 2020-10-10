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
	
	// Show the deck object as initialized

	
	// Draw the next card and show it
	std::cout << std::string(deck1.DrawNextCard()) << std::endl;
	// Draw a random card and show it
	Pause();
	std::cout << std::string(deck1.DrawRandomCard()) << std::endl;
	//DisplayDeck(deck1);
	

	Pause();
	// Show the deck with the remaining cards
	std::cout << "There are " << deck1.CardsRemaining() << " cards remaining." << std::endl;
	// Shuffle the deck and show the result
	Pause();
	std::cout << "\nSHUFFLE DECK" << std::endl;
	deck1.Shuffle();
	DisplayDeck(deck1);


	Pause();
	std::cout << "RESET THE DECK" << std::endl;
	deck1.ResetDeck();
	DisplayDeck(deck1);
	
	/*for (int i = 0; i < deck1.GetDeck().size(); i++)
	{
		std::cout << std::string(deck1.GetDeck()[i]) << std::endl;
	}*/
	// Reset the deck and show the result
	//Pause();
	//std::cout << "\n\n\nRESET DECK" << std::endl;
	//deck1.initialize();
	//DisplayDeck(deck1);
}	


