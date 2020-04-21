#include "Game.h"

Game::Game()
{
	for (short i = 0; i < 4; i++)
	{
		this->m_players[i].SetName(this->m_rand_names[rand() % 7]);
	}

	std::vector<Card> aux;
	for (short i = 0; i < (int)Suit::MAX-1; ++i)
	{
		for (short j = 0; j < 12; ++j)
		{
			switch (i)
			{
			case 0:
				aux.push_back(Card(Suit::SPADES,j));
				break;
			case 1:
				aux.push_back(Card(Suit::COINS, j));
				break;
			case 2:
				aux.push_back(Card(Suit::CUPS, j));
				break;
			case 3:
				aux.push_back(Card(Suit::CLUBS, j));
			default:
				break;
			}
		}
	}
	
	int maxSize = aux.size();
	for (int i = 0; i < maxSize; ++i) 
	{
		int var = rand() % aux.size();
		this->m_deck.push(aux[var]);
		aux.erase(aux.begin() + var - 1);
	}

	for (int i = 0; i < (4 * 7); ++i)
	{
		if (i % 4 == 0)
		{
			this->m_players[0].InsertCard(this->m_deck.top());
			this->m_deck.pop();
		}
		else if (i % 4 == 1)
		{
			this->m_players[1].InsertCard(this->m_deck.top());
			this->m_deck.pop();
		}
		else if (i % 4 == 2)
		{
			this->m_players[2].InsertCard(this->m_deck.top());
			this->m_deck.pop();
		}
		else if (i % 4 == 3)
		{
			this->m_players[3].InsertCard(this->m_deck.top());
			this->m_deck.pop();
		}
	}

}

Card Game::GetNewCard()
{
	Card aux = this->m_deck.top();
	this->m_deck.pop();
	return aux;
}

void Game::DiscardeCard(Card c)
{
	this->m_undeck.push(c);
}

void Game::PrintDiscarded()
{
	Card it = this->m_undeck.top();
	switch (it.m_suit)
	{
	case SPADES:
		std::cout << "SPADES";
		break;
	case COINS:
		std::cout << "COINS";
		break;
	case CUPS:
		std::cout << "CUPS";
		break;
	case CLUBS:
		std::cout << "CLUBS";
	case MAX:
	default:
		break;
	}
	std::cout << it.m_value << std::endl;
}
