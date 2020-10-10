#include "StandardDeck.h"

StandardDeck::StandardDeck() :m_card(PlayingCard())
{
	StandardDeck::initialize();
}

StandardDeck::StandardDeck(const PlayingCard& card)
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


//int StandardDeck::CardsRemaining() const
//{
//}


//std::string StandardDeck::DrawNextCard()
//{
//}

//std::string StandardDeck::DrawRandomCard()
//{
//}

//void StandardDeck::Shuffle()
//{
//}

void StandardDeck::initialize()
{
	const int num = 52;
	int cardRankIndex = 1;
	int cardSuitIndex = 0;

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

void StandardDeck::SetDeck()
{
	initialize();
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

