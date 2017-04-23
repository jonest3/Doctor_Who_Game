/********************************************************
 * *Author:		Taylor Jones (jonest3)		* 
 * *Date:		February 14, 2016		*
 * *Description:	Creature.hpp 			*
 ********************************************************/
#ifndef CREATURE_HPP
#define CREATURE_HPP

#include <string>
#include <cstdlib>

class Creature	// abstract parent class
{
protected:
   std::string creatureType;
   int attackDieCount;	// keeps track of the number of dice for 'attack'
   int attackDieSides;	// keeps track of the number of sides for 'attack die'

   int defenseDieCount;	// keeps track of the number of dice for 'defense'
   int defenseDieSides;	// keeps trakc of the number of sides for 'defense die'

   int armor;		// stores the armor number for each creature
   int strength;	// keeps track of that creature's strength

public:
   Creature();
   virtual int attack();	// rolls dice for each creature
   virtual int defense(int);
   virtual void setStrength(int); 
   virtual std::string getType();
   virtual int getStrength();
};

#endif
