

#ifndef PLAYER_H
#define PLAYER_H

// These classes are dummy classes, to be removed when the real classes are ready.

class Territory {
	public:
	int* num;
	
	Territory();
	Territory(Territory & t);
	};
	
class Order{
	
	public:
	int* ordertype;
	Territory* target;
	
	Order();
	Order(Order & ord);
};
class Hand{
	public:
		Order* ord;
		int* cardno;
		
	Hand();
	 Hand (Hand & hd);
	
};
class OrderList{
	public:
		Order* ord;
		int* num_ords;
		OrderList();
   
   		OrderList( OrderList & olst);
};




class Player
{
	
	// Components of the Player object: owned territories, a hand of cards, and a list of (non-card) orders
	Territory* owned;
		Hand* cards;
		OrderList* orders;
	public:
		// The Player API: default constructor, copy constructor
  Player();
  Player(Player &plr);
        // Lists of territories to attack or defend as derived from the Player's list of orders and cards
  Territory* toAttack();
  Territory* toDefend();
        // Adds an order to the Player's OrderList
  void issueOrder(Order & ord);
       // Prints out a listing of the player's components
  friend std::ostream& operator<<(std::ostream & stream, const Player & plr);
       // Assigns components to another Player object.
  void operator=(Player & plr);
};

#endif