/********************************************************
 * *Author:		Taylor Jones (jonest3)		*
 * *Date:		March 15, 2016			*
 * *Description:	ParallelUniverse.cpp - child 	*
 * 			class of of Compartment class.  *
 * 			For Final Project.		*
 ********************************************************/
#include "ParallelUniverse.hpp"
#include "Compartment.hpp"
#include "Future.hpp"
#include "Past.hpp"
#include "Space.hpp"
#include "PocketUniverse.hpp"
#include "Creature.hpp"
#include "TheMaster.hpp"
#include "Player.hpp"

#include <cstdlib>
#include <string>
#include <fstream>

// Default Constructor
ParallelUniverse::ParallelUniverse()
{
   this->north = NULL;
   this->south = NULL;
   this->east = NULL;
   this->west = NULL;
   roomType = "Parallel Universe";
   year = "0";
   this->villain = new TheMaster();
   item = " ";
   visited = 0;
}
// Destructor
ParallelUniverse::~ParallelUniverse()
{
   delete villain;
   villain = NULL;
}
// Special Function
/************************************************
 *		string challenge()		*
 * Player must fight the villain to the death.  *
 * They must read through a description before  *
 * the attack can begin.  The player and villain*
 * take turns attacking and defending until one *
 * is no longer strong enough to attack again.  *
 * If the player wins, the winning text is read.*
 * If the player losers, the losing text is read*
 ************************************************/ 	
std::string ParallelUniverse::challenge(Creature *player)
{
   if(visited == 0)
   {
	std::string line;
	std::ifstream myfile("Master.txt");
	if(myfile.is_open())
	{
		std::cout << "\n\nAs a helfpul tip, press [Enter] to go through the following script.\n\n";
		while(getline(myfile, line))
		{
			std::cin.get();
			std::cout << line;
		}
		myfile.close();
	}
	else
	{
		std::cout << "\n\nUnable to open 'Master.txt'";
	}
	std::cin.ignore(); 
  	int round = 0;
   	int damage;
   	int inflicted;
   	Creature *attacker;
   	Creature *defender;

        std::cout << "\nPress [Enter] to watch attack.";
        std::cin.get();

   	while(player->getStrength() > 0 && villain->getStrength() > 0)
   	{
		round++;
		std::cout << "\n\n\tAttack " << round;
		std::cout << std::endl << player->getType() << "'s Strength: " << player->getStrength();
		std::cout << std::endl << villain->getType() << "'s Strength: " << villain->getStrength();

		if(round % 2 != 0)
		{
			attacker = player;
			defender = villain;
		}
		else
		{
			attacker = villain;
			defender = player;
		}
		std::cout << std::endl << std::endl << attacker->getType() << " attacks " << defender->getType();
		damage = attacker->attack();
		inflicted = defender->defense(damage);
		defender->setStrength(inflicted);
		sleep(2);
   	}
   	if(player->getStrength() != 0)
   	{
		visited = 1; 
                std::ifstream winnerfile("Win.txt");
                if(winnerfile.is_open())
                {
                        std::cout << "\n\nPress [Enter] to continue through the script.\n\n";
                        while(getline(winnerfile, line))
                        {
                                std::cin.get();
                                std::cout << line;
                        }
                        winnerfile.close();
                }
                else
                {
	                std::cout << "\n\n\tCongratulations, " << player->getType() << ", you beat the Master!\n";
                        std::cout << "\n\nUnable to open 'Win.txt'";
                }
		return year;
  	}
	else
	{
        	std::ifstream loserfile("Lost.txt");
		if(loserfile.is_open())
		{
			std::cout << "\n\nPress [Enter] to continue through the script.\n\n";
			while(getline(loserfile, line))
			{
				std::cin.get();
				std::cout << line;
			}
			loserfile.close();
		}
		else
		{
			std::cout << "\n\n\t Oh no, you lost!  Press 3 to play again or 1 to exit.\n";
			std::cout << "\n\nUnable to open 'Lost.txt'";
		}
	}
   }
   else
   {
	std::cout << "\n\nI've already been to the parallel universe.. why not try a perpendicular one?\n" << std::endl;
   }
   return "1";
}
