/************************************************
 * *Author:		Taylor Jones (jonest3)	*
 * *Date:		March 15, 2016		*
 * *Description:	Cybermen.cpp 		*
 ************************************************/
#include "Creature.hpp"
#include "Cybermen.hpp"

#include <iostream>
#include <cstdlib>
#include <string>

// Default Constructor
Cybermen::Cybermen()
{
   this->creatureType = "Cybermen";
   this->attackDieCount = 2;
   this->attackDieSides = 6;
   this->defenseDieCount = 1;
   this->defenseDieSides = 6;
   this->armor = 2;
   this->strength = 10;
}
