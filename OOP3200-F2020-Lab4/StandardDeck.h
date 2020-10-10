/** OOP3200. F2020. StandardDeck.h
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

#pragma once
#ifndef __STANDARD_DECK__
#define __STANDARD_DECK__

#include <vector>
#include "PlayingCard.h"


class StandardDeck
{
public:

	// Initialization:
	StandardDeck();


	// Rule of three:
	~StandardDeck(); // Destructor

	StandardDeck(const StandardDeck& other_Deck); //Copy constructor

	StandardDeck& operator=(const StandardDeck& other_deck); //Assignment operator


	// Accessors:
	std::vector<PlayingCard> GetDeck() const;
	int CardsRemaining() const;


	// Mutators:
	virtual void initialize();
	void ClearDeck();
	PlayingCard DrawNextCard();
	PlayingCard DrawRandomCard();
	void Shuffle();
	void SetCard(PlayingCard newCard);
	void ResetDeck();

private:
	PlayingCard m_card;
	std::vector<PlayingCard> m_deck;
	int* m_pointer = 0;

};

#endif /* defined (__STANDARD_DECK__) */