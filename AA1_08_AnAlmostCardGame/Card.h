#pragma once
#include <cstdlib>
#include <iostream>

enum Suit { SPADES, COINS, CUPS, CLUBS, MAX };

class Card
{ 
private:
	int MAX_VALUE = 12; //tendria que ser una constante global

public:
	Card();
	Card(Suit s, short v);
	
	Suit m_suit;
	short m_value;

	bool operator () (const Card& card1, const Card& card2);

};


