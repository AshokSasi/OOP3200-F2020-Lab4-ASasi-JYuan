#include "StandardDeck.h"



StandardDeck::StandardDeck() :m_card(PlayingCard())
{
	m_pointer = 0;
	StandardDeck::initialize();
}


StandardDeck::~StandardDeck()
= default;

StandardDeck::StandardDeck(const StandardDeck & other_card)
{
	SetCard(other_card.m_card);
}

StandardDeck& StandardDeck::operator=(const StandardDeck & other_card)
{
	SetCard(other_card.m_card);
	return (*this);
}

std::vector<PlayingCard> StandardDeck::GetDeck() const
{
	return m_deck;
}

void StandardDeck::SetCard(const PlayingCard newCard)
{
	m_card = newCard;
}

void StandardDeck::ResetDeck()
{
	initialize();
}


int StandardDeck::CardsRemaining() const
{
	const int remainingCards = m_deck.size();
	return remainingCards;

}


PlayingCard StandardDeck::DrawNextCard()
{
	PlayingCard currentCard = m_deck[0];
	for (int i = 0; i < m_deck.size()-1; i++)
	{
		m_deck[i] = m_deck[i + 1];
	}
	m_deck.pop_back();
	return currentCard;
	
}

PlayingCard StandardDeck::DrawRandomCard()
{
	int cardSelected = (rand() % m_deck.size());

	PlayingCard currentCard = m_deck[cardSelected];
	for (int i = cardSelected; i < m_deck.size() - 1; i++)
	{
		m_deck[i] = m_deck[i + 1];
	}
	m_deck.pop_back();
	return currentCard;
}

void StandardDeck::Shuffle()
{
	for(int i =0; i < m_deck.size()-1; i++)
	{
		int j = i + rand() % (m_deck.size() - i);
		std::swap(m_deck[i], m_deck[j]);
	}
}

void StandardDeck::initialize()
{
	const int num = 52;
	int cardRankIndex = 1;
	int cardSuitIndex = 0;
	if (m_pointer != 0)
	{
		ClearDeck();
	}
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

void StandardDeck::ClearDeck()
{
	m_deck.clear();
}


