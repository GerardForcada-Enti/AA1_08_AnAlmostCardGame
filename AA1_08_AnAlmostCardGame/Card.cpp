#include "Card.h"

Card::Card()
{
	this->m_suit = (Suit)(rand() % (int)Suit::MAX);
	this->m_value = rand() % MAX_VALUE;
}
Card::Card(Suit s, short v)
{
	this->m_suit = s;
	this->m_value = v;
}

bool Card::operator() (const Card& card1, const Card& card2)
{
	return ((card1.m_suit == card2.m_suit) && (card1.m_value == card2.m_value));
}