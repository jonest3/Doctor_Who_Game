/************************************************
 * *Author:		Taylor Jones (jonest3)	*
 * *Date:		March 15, 2016		*
 * *Description:	Space.hpp - Child class *
 * 			of Compartment class.   *
 * 			For Final Project.	*
 ************************************************/
#ifndef SPACE_HPP
#define SPACE_HPP

#include "Compartment.hpp"
#include "Future.hpp"
#include "Past.hpp"
#include "ParallelUniverse.hpp"
#include "PocketUniverse.hpp"
#include "Creature.hpp"
#include "Player.hpp"

#include <iostream>
#include <iostream>

class Space:public Compartment
{
private:

public:
   Space();
   ~Space();
   virtual std::string challenge(Creature*);
};
#endif
