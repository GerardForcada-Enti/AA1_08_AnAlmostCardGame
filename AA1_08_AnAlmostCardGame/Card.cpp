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
