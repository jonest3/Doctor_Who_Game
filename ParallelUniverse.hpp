/************************************************
 * *Author:		Taylor Jones (jonest3)	*
 * *Date:		March 15, 2016		*
 * *Description:	ParallelUniverse.hpp    *
 ************************************************/
#ifndef PARALLELUNIVERSE_HPP
#define PARALLELUNIVERSE_HPP

#include "Compartment.hpp"
#include "Future.hpp"
#include "Past.hpp"
#include "Space.hpp"
#include "PocketUniverse.hpp"
#include "Creature.hpp"
#include "Player.hpp"

class ParallelUniverse:public Compartment
{
private:

public:
   ParallelUniverse();
   ~ParallelUniverse();
   virtual std::string challenge(Creature*);
};
#endif
