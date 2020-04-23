#include "Game.h"
#include <queue>

int main()
{
	std::priority_queue<Card, std::vector<Card>, Card> Cards;
	Cards.push(Card(SPADES,6));
	Cards.push(Card(SPADES, 5));
	Cards.push(Card(CUPS, 2));
	Cards.push(Card(COINS, 9));

	Game game;

	system("pause");

	return 0;
}