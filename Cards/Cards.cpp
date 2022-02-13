#include "Cards.h"

//Card class
Card::Card() : Card("This is this card's effect"){

}
Card::Card(string effect) : effect(new string(effect)) {

}
Card::Card(const Card& cardToCopy) {
	this->effect = new string(*(cardToCopy.effect));
}
Card::~Card() {
	delete effect;
}
string Card::toString() {
	return *effect;
}
void Card::play(Card* card, int pos) {
	//create new order depending on effect
	handRemove(pos);
	deckAdd(card);
}
Card& Card::operator=(const Card& cardToAssign) {
	this->effect = new string(*(cardToAssign.effect));
	return *this;
}
ostream& operator<<(ostream& output, const Card& cardToStream) {
	output <<*(cardToStream.effect);
	return output;
}

//Deck class
Deck::Deck() {
	deckCards;
}
Deck::Deck(const Deck& deckToCopy) {
	for (auto deckIterator = deckToCopy.deckCards.begin(); deckIterator != deckToCopy.deckCards.end(); deckIterator++) {
			deckCards.push_back(*deckIterator);
		}
}
Deck::~Deck() {
	for (Card* card : deckCards) {
		delete card;
	}
	deckCards.clear();
}
void Deck::deckAdd(Card* cardToAdd) {
	deckCards.push_back(cardToAdd);
}
void Deck::deckRemove(int pos) {
	int i = 0;
	for (auto deckIterator = deckCards.begin(); deckIterator != deckCards.end(); deckIterator++) {
		if(i == pos) {
			deckCards.erase(deckIterator);
			return;
		}
		i++;
	}
}
string Deck::toString() {
	string output = "";
	for (auto deckIterator : deckCards) {
		output += deckIterator->toString() + " ";
	}
	return output;
}
void Deck::draw() {
	int deckLength = deckCards.size();
	int cardIndex = std::rand()%deckLength-1;
	list<Card*>::iterator it = deckCards.begin();
	advance(it, cardIndex);
	Card* tempCard = *it;
	handAdd(tempCard);
	deckRemove(std::rand()%deckLength-1);

}
Deck& Deck::operator=(Deck& cardsToAssign) {
	for (auto deckIterator = cardsToAssign.deckCards.begin(); deckIterator != cardsToAssign.deckCards.end(); deckIterator++) {
			deckCards.push_back(*deckIterator);
		}
		return *this;
}
ostream& operator<<(ostream& output, const Deck& deckToStream) {
	for (auto deckIterator = deckToStream.deckCards.begin(); deckIterator != deckToStream.deckCards.end(); deckIterator++) {
			output << **deckIterator << " ";
		}
		output << endl;
		return output;
}

//Hand class
Hand::Hand() {
	handCards;
}
Hand::Hand(const Hand& handToCopy) {
	for (auto handIterator = handToCopy.handCards.begin(); handIterator != handToCopy.handCards.end(); handIterator++) {
			handCards.push_back(*handIterator);
		}
}
Hand::~Hand() {
	for (Card* card : handCards) {
		delete card;
	}
	handCards.clear();
}
void Hand::handAdd(Card* cardToAdd) {
	handCards.push_back(cardToAdd);
}
void Hand::handRemove(int pos) {
	int i = 0;
	for (auto handIterator = handCards.begin(); handIterator != handCards.end(); handIterator++) {
		if(i == pos) {
			handCards.erase(handIterator);
			return;
		}
		i++;
	}
}
string Hand::toString() {
	string output = "";
	for (auto handIterator : handCards) {
		output += handIterator->toString() + " ";
	}
	return output;
}
Hand& Hand::operator=(Hand& cardsToAssign) {
	for (auto handIterator = cardsToAssign.handCards.begin(); handIterator != cardsToAssign.handCards.end(); handIterator++) {
			handCards.push_back(*handIterator);
		}
		return *this;
}
ostream& operator<<(ostream& output, const Hand& handToStream) {
	for (auto handIterator = handToStream.handCards.begin(); handIterator != handToStream.handCards.end(); handIterator++) {
			output << **handIterator << " ";
		}
		output << endl;
		return output;
}
