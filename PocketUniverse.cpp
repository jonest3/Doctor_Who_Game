/********************************************************
 * *Author:		Taylor Jones (jonest3)		*
 * *Date:		March 15, 2016			*
 * *Description:	PocketUniverse.cpp - child class*
 * 			of Compartmnet class. For Final *
 * 			Project.			*
 ********************************************************/
#include "PocketUniverse.hpp"
#include "Compartment.hpp"
#include "Future.hpp"
#include "ParallelUniverse.hpp"
#include "Past.hpp"
#include "Space.hpp"
#include "Creature.hpp"
#include "WeepingAngels.hpp"
#include "Player.hpp"

#include <cstdlib>
#include <string>

// Default Constructor
PocketUniverse::PocketUniverse()
{
   this->north = NULL;
   this->south = NULL;
   this->east = NULL;
   this->west = NULL;
   roomType = "Pocket Dimension";
   year = "2016.5";
   this->villain = new WeepingAngels();
   item = "Sonic Screwdriver";
   visited = 0;
}
// Destructor
PocketUniverse::~PocketUniverse()
{
   delete villain;
   villain = NULL;
}

/************************************************
 * 		string challenge()		*
 *If the player has not tried this challenge 3  *
 *times, they can play.  They must roll a desig-*
 *nated number in under a designated limit. With*
 *every roll is totalled to the overall sum.    *
 *If the player rolls an odd number, the villain*
 *attacks. This continuous until either the 	*
 *limit of rounds is reached, the designated sum*
 *is met, the player dies, or the player has 	*
 *already played this challenge 3 times.  If the*
 *player wins, it returns the year and sets	*
 *visits to 4.  Else, it returns "1".		*
 ************************************************/
std::string PocketUniverse::challenge(Creature *player)
{
   if(visited < 3) 
   {
        std::cout << "\n\nYour sonic screwdriver is being held for ransom somewhere in this Pocket Dimension that is full of Weeping Angels.\n";
        std::cout << "\nYou will have 10 chances to roll a total of 70 points with your dice to earn back your screwdriver.\n";
        std::cout << "Pocket dimensions are distorted echos of our own universe that have occurred spontaneously but never last for long, ";
        std::cout << "\nso you are limited to the number of times you can return to this dimension.\n\n";
        std::cout << "As for the Weeping Angels...Don't blink.  Blink and you're dead.  They are fast.  Faster than you can believe.\n";
        std::cout << "Don't turn your back.  Don't look away.  And don't blink. Good luck.\n";

   	std::cin.ignore();
	int goAgain = 1;
	do
	{
   		int round = 0;
   		int damage = 0;
  		int inflicted = 0;
   		int totalDieCount = 0;
		int limit = 10;
		int roll = 0;		
		int maxCount = 70;

   		do
	   	{
			std::cout << "\nPress [Enter] to roll.";
			std::cin.get();
			round++;
			std::cout << "\n\tChance " << round << std::endl;
			std::cout << std::endl << player->getType() << "'s Strength: " << player->getStrength() << "\n";
			std::cout << "Total Points Earned: " << totalDieCount << "\n\n";

			roll = player->attack();
			totalDieCount += roll;

			if(roll % 2 != 0)
			{
				std::cout << std::endl << player->getType() << " blinked!\n";
				std::cout << std::endl << villain->getType() << " get a step closer to " << player->getType() << ".\n";
				damage = villain->attack();
				inflicted = player->defense(damage);
				player->setStrength(inflicted);
		   	}

		}while(player->getStrength() > 0 && round < limit && totalDieCount < maxCount);		
		visited++;
		if(player->getStrength() > 0)
		{
			std::cout << std::endl << std::endl << player->getType() << "'s Final Points Earned: " << totalDieCount << ".\n";

                	if(totalDieCount >= maxCount)
                	{
                        	visited = 4;
                        	return year;
                	}
			else if(visited < 3)
			{
				do
				{
					std::cout << "\n\nYou still haven't retrieved your screwdriver!";
					std::cout << "\nPress '1' to return to the TARDIS or press '0' to try again: ";
					std::cin  >> goAgain;	
				}while(goAgain > 1 || goAgain < 0);
			}
			else if(visited == 3)
			{
				std::cout << "\n\nOh no, this Pocket Dimension is collapsing!  You must leave. NOW!";
			}
		}
		else
		{
			std::cout << "\n\nOh no!  The Angels... they touched you! You have been sent back in time without your TARDIS!";
			std::cout << "\nYou're now stuck in the past, plagued to live out your life and die before your actual life begins.";
			std::cout << "\n\nThe world is in The Master's hands now.  This is the end of the road for you.\n";
		}
	}while(goAgain == 0 && visited < 3 && player->getStrength() > 0);
   }
   else
	std::cout << "\nThis Pocket Dimension has collapsed!  You can't go back there.\n";
   return "1";
}
