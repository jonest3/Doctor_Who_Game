/********************************************************
 * *Author:		Taylor Jones (jonest3)		*
 * *Date:		March 15, 2016			*
 * *Description:	Past.cpp - child class of 	*
 * 			Compartment class for Final 	*
 * 			Project.			*
 ********************************************************/
#include "Compartment.hpp"
#include "Past.hpp"
#include "Future.hpp"
#include "ParallelUniverse.hpp"
#include "PocketUniverse.hpp"
#include "Space.hpp"
#include "Creature.hpp"
#include "Krafayis.hpp"
#include "Player.hpp"

#include <cstdlib>
#include <string>

// Default Constructor
Past::Past()
{
   this->north = NULL;
   this->south = NULL;
   this->east = NULL;
   this->west = NULL;
   roomType = "The Past";
   year = "1890";
   this->villain = new Krafayis();
   item = "fob watch with Chameleon Arch";
   visited = 0;
}
// Destructor
Past::~Past()
{
   delete villain;
   villain = NULL;
}
// Special Function
/*************************************************
 * 		string challenge()		 *
 * The player and villain both roll their attack *
 * dice. They will keep rolling as long as they  *
 * both roll the same number.  Whomever rolls the*
 * highest number gets to attack the other. This *
 * continues until someone no longer has any 	 *
 * strength points.  If the player wins, it	 *
 * returns the year. Else, it returns "1".	 *
 *************************************************/
std::string Past::challenge(Creature *player)
{
   if(visited == 0)
   {
	std::cout << "\n\nYou have landed in a field near an old church.  There is a redheaded man running towards you.";
	std::cout << "\n\n'" << player->getType() << "! My name is Vincent van Gogh and I need your help!";
	std::cout << "\nI am a young artist here in Provence, which is being plagued by an invisible creature that apparently only I can see!";
	std::cout << "\nLook, I have painted it into my latest painting.  Please, I need your help to fight it so we can defeat it before it kills again!'";
	std::cout << "\n\nYou recognize it as a Krafayis!  To beat it, you must first find where it is hiding and attack it.  But be warned, although blinded, he can fight back.";
	std::cout << "\nWhomever rolls the highest dice number will be able to 'find' the other player to attack. Unfortunately, this is a battle to the death.";
	std::cout << "\n\nGood luck!";
	std::cin.ignore();
	int goAgain = 1;
	do
	{
   		int round = 0;
	   	int damage;
	   	int inflicted;
	   	Creature *attacker;
	   	Creature *defender;
	  	int playerRoll, villainRoll;

	   	while(player->getStrength() > 0 && villain->getStrength() > 0)
	   	{
			std::cout << "\nPress [Enter] to fight.";
			std::cin.get();
			round++;
			std::cout << "\n\tAttempt " << round << std::endl;
			std::cout << std::endl << player->getType() << "'s Strength: " << player->getStrength();
			std::cout << std::endl << villain->getType() << "'s Strength: "<< villain->getStrength() << std::endl << std::endl;
	
			do
			{
				playerRoll = player->attack();
				villainRoll = villain->attack();
			}while(playerRoll == villainRoll);

			if(playerRoll > villainRoll)
			{
				std::cout << std::endl << std::endl << player->getType() << " thinks they know where the " << villain->getType() << " is hiding!";
				defender = villain;
				attacker = player;
			}
			else if(playerRoll < villainRoll)
			{
				std::cout << std::endl << std::endl << villain->getType() << " sneaks up on " << player->getType();
				defender = player;
				attacker = villain;				
			}
			else if(playerRoll == villainRoll)
			{
				std::cout << "\n\n The " << villain->getType() << " overpowers " << player->getType();
				defender = player;
				attacker = villain;	
			}

			std::cout << std::endl << std::endl << attacker->getType() << " attacks " << defender->getType();
			damage = attacker->attack();
			inflicted = defender->defense(damage);
			defender->setStrength(inflicted);
	   	}
	   	if(player->getStrength() != 0)
	   	{
			std::cout << "\n\nVincent van Gogh sees " << player->getType() << " is not having much luck, so he picks up his artist easel and thrusts it into the " << villain->getType() << " side, fatally wounding it.";
			visited = 1;
			return year;
		}
		else
		{
			std::cout << "\n\nSuddenly, the " << villain->getType() << " gathers all of its strength and lunges at you!";
			std::cout << "\nIt was a fatal hit. Sadly, you did not survive. We will always remember when you were 'The Doctor', even if you didn't.\n";
		}
	}while(goAgain == 0 && player->getStrength() > 0);
   }
   else
	std::cout << "\nYou can't keep going to the past hoping to change the future.\n";
   return "1";
}
