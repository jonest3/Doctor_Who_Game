/************************************************
 * *Author:		Taylor Jones (jonest3)	*
 * *Date:		March 15, 2016		*
 * *Description:	Future.hpp 		*
 ************************************************/
#ifndef FUTURE_HPP
#define FUTURE_HPP

#include "Compartment.hpp"
#include "Past.hpp"
#include "Space.hpp"
#include "ParallelUniverse.hpp"
#include "PocketUniverse.hpp"
#include "Creature.hpp"
#include "Player.hpp"

#include <iostream>
#include <string>

class Future:public Compartment
{
private:

public:
   Future();
   ~Future();
   virtual std::string challenge(Creature*);
};
#endif
