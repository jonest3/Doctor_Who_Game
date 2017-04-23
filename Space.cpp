/********************************************************
 * *Author:		Taylor Jones (jonest3)		*
 * *Date:		March 16, 2016			*
 * *Description:	Space.cpp - Child class of 	*
 * 			Compartment Class. For Final 	*
 * 			Project.			*
 ********************************************************/
#include "Compartment.hpp"
#include "Future.hpp"
#include "Past.hpp"
#include "Space.hpp"
#include "ParallelUniverse.hpp"
#include "PocketUniverse.hpp"
#include "Creature.hpp"
#include "VashtaNerada.hpp"
#include "Player.hpp"

#include <cstdlib>
#include <string>

// Default Constructor
Space::Space()
{
   this->north = NULL;
   this->south = NULL;
   this->east = NULL;
   this->west = NULL;
   roomType = "The Library";
   year = "2016(ish)";
   this->villain = new VashtaNerada();
   item = "1200 Year-Old Diary";
   visited = 0;
}
// Destructor
Space::~Space()
{
   delete villain;
   villain = NULL;
}
// Special Function
/********************************************************
 * 		string challenge()			*
 * If the player has not already beat this challenge,   *
 * they get 5 changes to roll a designated number. For  *
 * each attempt, they are attacked by the villain.  If  *
 * the player does not roll the number, they are can    *
 * either return to the TARDIS or try again.  If they   *
 * roll the number, the year is returned and visit = 1. *
 * If they give up and leave, "1" is returned.		*
 ********************************************************/
std::string Space::challenge(Creature *player)
{
   if(visited == 0)
   {
        std::cout << "\n\nOkay, " << player->getType() << ", you must find your diary, and fast!  You have 5 chances to find ";
        std::cout << "it before you must leave this planet.";
        std::cout << "\n\nIf you refuse to leave and keep searching, the " << villain->getType() << " will surely get you!\n";
        std::cout << "To find the diary, you must roll a '10', but don't worry!  You can return to this planet as many times as you need.\n\n";
        std::cout << "Good luck, " << player->getType() << "!\n\n";

	int goAgain = 1;
	do
	{
 		int round = 0;
	   	int damage;
	   	int inflicted;
		int attemptForDiary;
	  	int limit = 5;
		std::cin.ignore();
	   	while(player->getStrength() > 0 && round < limit)
   		{
                        std::cout << "\nPress [Enter] to search.";
		        std::cin.get();
			round++;
			std::cout << "\n\tSearch " << round << std::endl;
	 		std::cout << std::endl << std::endl << player->getType() << "'s Strength: " << player->getStrength() << "\n";
	
			attemptForDiary = player->attack();
	
			if(attemptForDiary == 10)
			{
				visited = 1;
				return year;			
			}
			else
			{
				std::cout << std::endl << villain->getType() << " narrows in on " << player->getType() << "\n\n";
				damage = villain->attack();
				inflicted = player->defense(damage);
				player->setStrength(inflicted);
	   		}	
   		}
		if(player->getStrength() > 0)
		{
			do
			{
				std::cout << "\n\nYou still haven't found the diary.";
				std::cout << "\nEnter '1' to return to the TARDIS or enter '0' to try again: ";
				std::cin  >> goAgain;
			}while(goAgain > 1 || goAgain < 0);
		}
	}while(goAgain == 0 && player->getStrength() > 0);
	std::cout << "\n\nYou are in such a hurry to find the diary, you forget to watch where you step and end up stepping into the shadows.";
	std::cout << "\nSuddenly you feel sharp pains all over your body. As you step into the light, you look down and notice you have 2 shadows. Now 3. Now 4.";
	std::cout << "\nIt's too late. The " << villain->getType() << " have latched on to you. This is the end, " << player->getType() << ".\n";
   }
   else
   	std::cout << "\nOnce you've seen one Planet, you've seen them all!\n";
   return "1";
}
