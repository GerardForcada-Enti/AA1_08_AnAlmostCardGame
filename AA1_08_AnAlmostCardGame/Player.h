#pragma once
#include "Card.h"
#include <vector>
#include <string>

class Player 
{
public:
	Player();

	void InsertCard(Card c);
	Card GetCard();
	Card GetCard(Suit s);
	void PrintHand();
	void SetName(std::string name);

private:
	std::string m_name;
	std::vector<Card> m_hand;

	void Order();
};