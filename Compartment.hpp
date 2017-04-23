/********************************************************
 * *Author:		Taylor Jones (jonest3)		*
 * *Date:		March 15, 2016			*
 * *Description:	Compartment.hpp 		*
 ********************************************************/
#ifndef COMPARTMENT_HPP
#define COMPARTMENT_HPP

#include "Creature.hpp"

#include <string>

class Compartment
{
protected:
   Compartment *north;
   Compartment *south;
   Compartment *east;
   Compartment *west;
   std::string roomType;	// Will hold Room's name
   std::string year;		// Will hold the year the player is in
   Creature *villain;		// Each room will have its own creature to battle the player.
   std::string item;		// Each room will have an item for the user to win
   int visited;			// Will keep track of if the player can re-enter the room
public:
   Compartment();
   ~Compartment();
   virtual std::string challenge(Creature*) = 0; // Will return room's year to use to identify which item is collected
   virtual void setCompass(Compartment*, Compartment*, Compartment*, Compartment*);
   virtual Compartment* menu();
   virtual std::string getRoomType();
   virtual std::string getItem();
   virtual std::string getYear();
};
#endif 
