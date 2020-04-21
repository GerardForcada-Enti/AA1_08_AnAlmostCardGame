#pragma once
#include "Player.h"
#include <stack>

class Game
{
public:
	Game();

	Card GetNewCard();
	void DiscardeCard(Card c);
	void PrintDiscarded();

private:
	Player m_players[4];
	std::stack<Card> m_deck;
	std::stack<Card> m_undeck;

	std::string m_rand_names[7] = { "Hipolito","Pancracia","Eustaquio","Socrates","Steve","Juliana", "Amanda" };
};