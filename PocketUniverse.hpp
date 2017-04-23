/************************************************
 * *Author:		Taylor Jones (jonest3)	*
 * *Date:		March 15, 2016		*
 * *Description:	PocketUniverse.hpp 	*
 ************************************************/
#ifndef POCKETUNIVERSE_HPP
#define POCKETUNIVERSE_HPP

#include "Compartment.hpp"
#include "Future.hpp"
#include "ParallelUniverse.hpp"
#include "Past.hpp"
#include "Space.hpp"
#include "Creature.hpp"
#include "Player.hpp"

#include <iostream>
#include <string>

class PocketUniverse:public Compartment
{
private:

public:
   PocketUniverse();
   ~PocketUniverse();
   virtual std::string challenge(Creature*);
};
#endif
