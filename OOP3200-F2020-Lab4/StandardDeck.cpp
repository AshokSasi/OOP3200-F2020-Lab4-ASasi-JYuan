#include "StandardDeck.h"



//StandardDeck::StandardDeck(const PlayingCard* sum_card =0)
//{
//	StandardDeck::initialize();
//}

StandardDeck::StandardDeck() :m_card(PlayingCard())
{
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


int StandardDeck::CardsRemaining() const
{
	const int remainingCards = m_deck.size();
	return remainingCards;

}


PlayingCard StandardDeck::DrawNextCard()
{
	PlayingCard currentCard = m_deck.front();
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

	ClearDeck();
	for (int cardValue = 0; cardValue < num; cardValue++)
	{
		PlayingCard currentCard =  PlayingCard(cardRankIndex, cardSuitIndex, cardValue, true);
		m_deck.push_back(currentCard);

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

//std::string StandardDeck::ToString() const
//{
//	std::string output_string;
//	for (int i = 0, i < 52, i++)
//	{
//		output_string += "card" + i + " " + std::string(Getdeck(i)) + "/n";
//	}
//	return output_string;
//}

