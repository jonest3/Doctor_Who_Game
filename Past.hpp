/********************************************************
 * *Author:		Taylor Jones (jonest3)		*
 * *Date:		March 15, 2016			*
 * *Description:	Past.hpp 			*
 ********************************************************/
#ifndef PAST_HPP
#define PAST_HPP

#include "Compartment.hpp"
#include "Space.hpp"
#include "Future.hpp"
#include "ParallelUniverse.hpp"
#include "PocketUniverse.hpp"
#include "Creature.hpp"
#include "Player.hpp"

#include <string>
#include <iostream>

class Past:public Compartment
{
private:

public:
   Past();
   ~Past();
   virtual std::string challenge(Creature*);
};
#endif
