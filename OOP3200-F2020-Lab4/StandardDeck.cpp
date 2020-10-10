/** OOP3200. F2020. StandardDeck.cpp
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

#include "StandardDeck.h"


//default constructor 
StandardDeck::StandardDeck() :m_card(PlayingCard())
{
	m_pointer = 0;
	StandardDeck::initialize();
}

//destructor
StandardDeck::~StandardDeck()
= default;

//copy constructor
StandardDeck::StandardDeck(const StandardDeck & other_card)
{
	SetCard(other_card.m_card);
}

//overloaded = operator
StandardDeck& StandardDeck::operator=(const StandardDeck & other_card)
{
	SetCard(other_card.m_card);
	return (*this);
}

//gets the card
std::vector<PlayingCard> StandardDeck::GetDeck() const
{
	return m_deck;
}

//sets the card
void StandardDeck::SetCard(const PlayingCard newCard)
{
	m_card = newCard;
}

//calls the initialize function to reset the deck
void StandardDeck::ResetDeck()
{
	initialize();
}

//shows the amount of cards remaining
int StandardDeck::CardsRemaining() const
{
	//gets the size of the deck and returns it
	const int remainingCards = m_deck.size();
	return remainingCards;

}

//Draws the next card in the deck
PlayingCard StandardDeck::DrawNextCard()
{
	//gets the card at the top of the deck
	PlayingCard currentCard = m_deck[0];
	//shifts all cards in vector forward
	for (int i = 0; i < m_deck.size()-1; i++)
	{
		m_deck[i] = m_deck[i + 1];
	}
	m_deck.pop_back();
	return currentCard;
	
}

//draws a random card
PlayingCard StandardDeck::DrawRandomCard()
{
	//generates random number
	int cardSelected = (rand() % m_deck.size()); 
	//gets the card with that random number index
	PlayingCard currentCard = m_deck[cardSelected];
	//shifts all cards behind that card forward
	for (int i = cardSelected; i < m_deck.size() - 1; i++)
	{
		m_deck[i] = m_deck[i + 1];
	}
	//deletes the empty last cell
	m_deck.pop_back();
	return currentCard;
}

//shuffles the deck
void StandardDeck::Shuffle()
{
	//loops through the deck
	for(auto i =0; i < m_deck.size()-1; i++)
	{
		//gets random number
		int j = i + rand() % (m_deck.size() - i);
		//swaps card in random number index with current card.
		std::swap(m_deck[i], m_deck[j]);
	}
}

//Initializes the deck and resets the deck if already exists
void StandardDeck::initialize()
{
	const int num = 52;
	int cardRankIndex = 1;
	int cardSuitIndex = 0;
	//checks to see if the pointer doesn't equal 0 and clears the deck.
	if (m_pointer != 0)
	{
		ClearDeck();
	}
	//intializes the deck, generating one of each card.
	for (int cardValue = 0; cardValue < num; cardValue++)
	{
		PlayingCard currentCard = PlayingCard(cardRankIndex, cardSuitIndex, cardValue, true);
		m_deck.push_back(currentCard);
		m_pointer = &cardValue;

		if (cardSuitIndex == 3)
		{
			cardRankIndex++;
			cardSuitIndex = 0;
		}
		else
		{
			cardSuitIndex++;
		}
	}
	
}

//clears the vector deck
void StandardDeck::ClearDeck()
{
	m_deck.clear();
}


