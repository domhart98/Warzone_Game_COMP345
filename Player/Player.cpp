#include <iostream>
#include <ostream>
#include "Player.h"


	
// Until the real Territory, Hand and OrderList classes are implemented, here are some dummy classes:

	Territory::Territory(){
	       num = new int {0};
	}
	Territory::Territory(Territory & t)
		{
			num = t.num;
		}




	Order::Order(){}
	Order::Order(Order & ord)
		{
			ordertype = ord.ordertype;
			target = ord.target;
		}
	
	



	Hand::Hand(){
	}

	 Hand::Hand (Hand & hd)
	 {
	 	ord = hd.ord;
	 	cardno = hd.cardno;
	 }





        OrderList::OrderList(){}
   
   		OrderList::OrderList( OrderList & olst)
		{
			ord = olst.ord;
			num_ords = olst.num_ords;
		}
	





		Player::Player(){
		  
		   owned = new Territory();
		   cards = new Hand();
		   orders = new OrderList();
		  
		
		}
		// copy constructor
		Player::Player(Player &plr)
		{
			owned = plr.owned;
			cards = plr.cards;
			orders = plr.orders;
		}
		
		Territory* Player::toAttack()
		// Covers orders to Advance (on foreign territory) (type 5) and Bomb (type 6)
		// Covers cards for Bomb (type 14)
		{
			int cardno_local = *cards->cardno;
			int ordno_local = *orders->num_ords;
			Territory* t = new Territory[cardno_local + ordno_local];
			int p = 0;
			for(int i = 0; i < ordno_local; i++)
			{
				
				int* type = orders[i].ord->ordertype;
				if (*type == 5 || *type == 6)
				{
			    Territory* temp = orders[i].ord->target;
				t[p] = *temp;
				++p;
			}
		}
			
			for(int i = 0; i < cardno_local; i++)
			{
				int* type = cards[i].cardno;
				if (*type == 14)
				{
			    Territory* temp = cards[i].ord->target;
				t[p] = *temp;
				++p;
			}
			}
			return t;
		}
		
		Territory* Player::toDefend()
		// Covers orders to Deploy (type 0), Advance (if moved to owned territory - type 1), Blockade (type 2), Airlift (type 3), Negotiate (type 4)
		// Covers cards for Reinforcement (type 10), Blockade (type 11), Diplomacy (type 12), Airlift (type 13)
		{
			int cardno_local = *cards->cardno;
			int ordno_local = *orders->num_ords;
			Territory* t = new Territory[cardno_local + ordno_local];
			int p = 0;
			for(int i = 0; i < ordno_local; i++)
			{
				
				int* type = orders[i].ord->ordertype;
				if (*type >= 0 && *type < 5)
				{
			    Territory* temp = orders[i].ord->target;
				t[p] = *temp;
				++p;
			}
		}
			
			for(int i = 0; i < cardno_local; i++)
			{
				int* type = cards[i].cardno;
				if (*type > 9 && *type < 14)
				{
			    Territory* temp = cards[i].ord->target;
				t[p] = *temp;
				++p;
			}
			}
			return t;
		}
		
		void Player::issueOrder(Order & ord)
		{
			
			// add an order to the list
			
			int ordno_local = *orders->num_ords;
			
			Order* newlist = new Order[*orders->num_ords + 1];
			std::copy(orders->ord, (orders->ord + ordno_local), newlist);
			int new_num = *orders->num_ords + 1;
			delete [] orders;
			newlist[new_num] = ord;
			orders->ord = newlist;
			*orders->num_ords = new_num;
		}
		
	   std::ostream& operator<<(std::ostream & stream, const Player & plr)
		{
			stream<<"Owned territories: "<< plr.owned << "\n";
			stream<<"Cards: "<< plr.cards << "\n";
			stream<<"Orders: "<< plr.orders << "\n";
			
			return stream;
		}
		
		void Player::operator=(Player & plr)
		{
			owned = plr.owned;
			cards = plr.cards;
			orders = plr.orders;
			
		}
		



