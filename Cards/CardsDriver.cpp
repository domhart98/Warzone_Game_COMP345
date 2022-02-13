#include <iostream>
#include "Cards.h"

using namespace std;

int main() {
	Deck test;

	Card card1("bomb");
	test.deckAdd(&card1);

	Card card2("reinforcement");
	test.deckAdd(&card1);

	Card card3("blockade");
	test.deckAdd(&card1);

	Card card4("airlift");
	test.deckAdd(&card1);

	Card card5("diplomacy");
	test.deckAdd(&card1);

	Hand testHand;

	testHand.handAdd(&card1);
	testHand.handAdd(&card2);
	testHand.handAdd(&card3);

	cout << test << endl;
	cout << testHand << endl;
	cin.get();
}
