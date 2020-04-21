#pragma once
#include <cstdlib>
#include <iostream>

enum Suit { SPADES, COINS, CUPS, CLUBS, MAX };

class Card
{ 
private:
	const short MAX_VALUE = 12; //tendria que ser una constante global

public:
	Card();
	Card(Suit s, short v);
	
	Suit m_suit;
	short m_value;

	friend bool operator== (const Card& card1, const Card& card2)
	{
		return card1.m_suit == card2.m_suit && card1.m_value == card2.m_value;
	}

};

