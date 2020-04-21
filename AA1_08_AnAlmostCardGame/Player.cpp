#include "Player.h"

Player::Player()
{
}

void Player::InsertCard(Card c)
{
	this->m_hand.insert(this->m_hand.begin(), c);
	this->Order();
}

Card Player::GetCard()
{
	return this->m_hand[rand() % this->m_hand.size()];
}

Card Player::GetCard(Suit s)
{
	std::vector<Card>::iterator it;
	for (it = this->m_hand.begin(); it != m_hand.end(); ++it)
	{
		if ((int)&it->m_suit == (int)s)break;
	}
	return *it;
}

void Player::PrintHand()
{
	std::cout << "Player hand: " << std::endl;
	for (std::vector<Card>::iterator it = this->m_hand.begin(); it != m_hand.end(); ++it)
	{
		switch (it->m_suit)
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
		std::cout << it->m_value << std::endl;
	}
}

void Player::SetName(std::string name)
{
	this->m_name = name;
}

void Player::Order()
{//Spades-coins-cups-clubs and 12-1
	std::vector<Card> spades;
	std::vector<Card> coins;
	std::vector<Card> cups;
	std::vector<Card> clups;
	for (std::vector<Card>::iterator it = this->m_hand.begin(); it != m_hand.end(); ++it)
	{
		if ((int)&it->m_suit == (int)Suit::SPADES)spades.push_back(*it);
		if ((int)&it->m_suit == (int)Suit::COINS)coins.push_back(*it);
		if ((int)&it->m_suit == (int)Suit::CUPS)cups.push_back(*it);
		if ((int)&it->m_suit == (int)Suit::CLUBS)clups.push_back(*it);
	}
	int i, j;
	for (i = 0; i < spades.size() - 1; i++)
	{
		for (j = 0; j < spades.size() - i - 1; j++)
			if (spades[j].m_value > spades[j + 1].m_value)
			{
				short aux = spades[j].m_value;
				spades[j].m_value = spades[j + 1].m_value;
				spades[j + 1].m_value = aux;
			}
	}
	for (i = 0; i < coins.size() - 1; i++)
	{
		for (j = 0; j < coins.size() - i - 1; j++)
			if (coins[j].m_value > coins[j + 1].m_value)
			{
				short aux = coins[j].m_value;
				coins[j].m_value = coins[j + 1].m_value;
				coins[j + 1].m_value = aux;
			}
	}
	for (i = 0; i < cups.size() - 1; i++)
	{
		for (j = 0; j < cups.size() - i - 1; j++)
			if (cups[j].m_value > cups[j + 1].m_value)
			{
				short aux = cups[j].m_value;
				cups[j].m_value = cups[j + 1].m_value;
				cups[j + 1].m_value = aux;
			}
	}
	for (i = 0; i < clups.size() - 1; i++)
	{
		for (j = 0; j < clups.size() - i - 1; j++)
			if (clups[j].m_value > clups[j + 1].m_value)
			{
				short aux = clups[j].m_value;
				clups[j].m_value = clups[j + 1].m_value;
				clups[j + 1].m_value = aux;
			}
	}

	this->m_hand.erase(this->m_hand.begin(), m_hand.end());

	this->m_hand.insert(this->m_hand.end(), spades.begin(), spades.end());
	this->m_hand.insert(this->m_hand.end(), coins.begin(), coins.end());
	this->m_hand.insert(this->m_hand.end(), cups.begin(), cups.end());
	this->m_hand.insert(this->m_hand.end(), clups.begin(), clups.end());
}
