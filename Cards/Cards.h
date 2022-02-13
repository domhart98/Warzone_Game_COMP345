#include <list>
#include <string>
#include <iostream>

class Card;
class Deck;
class Hand;

using namespace std;

class Card {
public:
	Card();
	Card(string effect);
	Card(const Card& cardToCopy);

	~Card();

	string toString();

	void play(Card* card, int pos);
	virtual Card& operator=(const Card& c);
	friend ostream& operator<<(ostream& out, const Card& c);
protected:
	string* effect;
};

class Deck {
public:
	Deck();
	Deck(const Deck& deckToCopy);

	~Deck();

	void deckAdd(Card* cardToAdd);
	void deckRemove(int pos);
	string toString();

	void draw();

	Deck& operator=(Deck& cardsToAssign);
	list<Card*> deckCards;
	virtual Deck& operator=(const Deck& d);
	friend ostream& operator<<(ostream& out, const Deck& d);
};

class Hand {
public:
	Hand();
	Hand(const Hand& handToCopy);

	~Hand();

	void handAdd(Card* cardToAdd);
	void handRemove(int pos);
	string toString();

	Hand& operator=(Hand& cardsToAssign);
	list<Card*> handCards;
	virtual Hand& operator=(const Hand& h);
	friend ostream& operator<<(ostream& out, const Hand& h);
};
