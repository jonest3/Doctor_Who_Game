/*************************************************
 * *Author:		Taylor Jones (jonest3)	 *
 * *Date:		March 15, 2016		 *
 * *Description:	Future.cpp - child class *
 * 			of Compartment for Final *
 * 			Project.		 *
 *************************************************/
#include "Compartment.hpp"
#include "Future.hpp"
#include "Past.hpp"
#include "Space.hpp"
#include "ParallelUniverse.hpp"
#include "PocketUniverse.hpp"
#include "Creature.hpp"
#include "Cybermen.hpp"
#include "Player.hpp"

#include <cstdlib>
#include <stdlib.h>
#include <string>

// Default Constructor
Future::Future()
{
   this->north = NULL;
   this->south = NULL;
   this->east = NULL;
   this->west = NULL;
   roomType = "New New York"; 
   year = "5,000,000,023";
   this->villain = new Cybermen();
   item = "Advice from the Face of Boe";
   visited = 0;
}
// Deconstructor
Future::~Future()
{
   delete villain;
   villain = NULL;
}
// Special Function
/************************************************
 * 		string challenge()		*
 * This is a true or false game.  User enters 1 *
 * for 'True' and 0 for 'False'.  There are 8   *
 * questions, with the correct anwsers being 	*
 * stored in an array of ints.  If the player   *
 * inputs the correct answer, the counter is    *
 * incremented and they get to move on to the   *
 * next question.  If they get it wrong, they   *
 * must battle a Cyberman to the death.  If they*
 * do not answer all of the questions right, 	*
 * they do not win the item they need. It allows*
 * the player to try again.			*
 ************************************************/
std::string Future::challenge(Creature* player)
{
   if(visited == 0)
   {
	std::cout << "\n\nUnbelievable!  You, " << player->getType() << ", have landed in the future miles under New New York in a gridlock with thousands";
	std::cout << "\nof other cars trying to escape to the surface.";
	std::cout << "\n\nNone of your belongings seem to be here but you have heard that the Face of Boe is very ill and is in the hospital here.";
	std::cout << "\nYou need to see them before it is too late, or you will be too upset to carry on with your journey.";
 	std::cout << "\n\nTo help you pass the time, let's play a trivia game!";
	std::cout << "\n\nIf you get all of the trivia questions correct, you will survive gridlock and escape to the exit in time to see Boe.";
	std::cout << "\n\nIf you get a question wrong... well, there are rumors that Cybermen are attacking cars and taking recruits.";
	std::cout << "\nIf you get too many wrong, you might not survive the journey.";  
	std::cout << "\n\nHopefully, you can evade the Cybermen and make it to Boe.  You can always come back to try again if you need a quick getaway.";
	std::cin.ignore();
	int goAgain = 1;
	do
	{	
		int correctAnswers[8] = {0,0,1,1,0,0,1,1};
		int usersAnswer;
		int round = 0;
		int limit = 8;
		int right = 0;	// Keeps track of the number user gets right
	   	int damage;
	  	int inflicted;
		int i = 0;
	   	Creature *attacker;
	   	Creature *defender;
		std::cout << "\n\nEnter '1' for 'True' and '0' for False.";
		while(i < limit && player->getStrength() > 0)
		{
			std::cout << "\n\n\n\tTrue or False";
			if(i == 0 && player->getStrength() > 0)
			{
				// False (0)
				std::cout << "\nThe noise the TARDIS makes was created by rubbing harp strings with a key.";
			}
			else if(i == 1 && player->getStrength() > 0)
			{
				// False (0)
				std::cout << "\nThe Doctor has never been married.";
			}
                        else if(i == 2 && player->getStrength() > 0)
                        {
				// True (1)
				std::cout << "\nThe Weeping Angels are real actresses that just stand very, very still.";
                        }	
                        else if(i == 3 && player->getStrength() > 0)
                        {
				// True (1)
				std::cout << "\nThe TARDIS is a 'her'.";
                        }
                        else if(i == 4 && player->getStrength() > 0)
                        {
				// False (0)
				std::cout << "\nThere have only been 5 different Doctors in total.";
                        }
                        else if(i == 5 && player->getStrength() > 0)
                        {
				// False (0)
				std::cout << "\nThe TARDIS is known for changing colors.";
                        }
                        else if(i == 6 && player->getStrength() > 0)
                        {
				// True (1)
 				std::cout << "\nYou can find the word 'TARDIS' in the Oxford English Dictionary.";
                        }
                        else if(i == 7 && player->getStrength() > 0)
                        {
				// True (1)
				std::cout << "\nBesides the TARDIS, Handles the disembodied Cyberman head was the Doctor's longest companion.";
                        }
			do
			{
				std::cout << "\n\nYour answer: ";
				std::cin  >> usersAnswer;
			}while(usersAnswer > 1 || usersAnswer < 0);
			if(usersAnswer == correctAnswers[i])
			{
				std::cout << "\n\nCorrect!";
				right++;
			}
			if(usersAnswer == correctAnswers[i] && i < 7)
				std::cout << "\nNext question!";
			else if(usersAnswer != correctAnswers[i])
			{
				std::cout << "\n\nWrong answer! and Oh no!  A Cyberman! You must fight it off!\n";
				sleep(2);
				round = 0;
				while(player->getStrength() > 0 && villain->getStrength() > 0)
				{
					round++;
					std::cout << "\n\n\tRound " << round << std::endl;
					std::cout << std::endl << player->getType() << "'s Strength: " << player->getStrength() << ".";
                                        std::cout << std::endl << villain->getType() << "'s Strength: " << villain->getStrength() << ".";
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
					std::cout << std::endl << attacker->getType() << " charges at " << defender->getType() << ".";
					damage = attacker->attack();
					inflicted = defender->defense(damage);
					defender->setStrength(inflicted);
	   			}
				if(villain->getStrength() == 0)
				{
					std::cout << "\n\nWe've lost him!";
					delete villain;
					villain = new Cybermen();
                                        if(i != 7)
                                        	std::cout << "\nWe can keep moving forward!  Next question!";
				}
				else if(player->getStrength() == 0)
				{
					std::cout << "\n\nOh no! You have been caught by the Cybermen!  They have converted you...";
					std::cout << "\nSadly, this is the end of the road for you, " << player->getType() << ".\n";
				}
	   		}
			i++;
		}
		if(player->getStrength() != 0 && right == 8)
   		{
                	std::cout << "\n\n\tYou answered all 8 questions correctly!";
			std::cout << "\n\nCongratulations!  You can see the light at the end of the tunnel which means you've made it out of the gridlock!";
			visited = 1;
			return year;
		}
		else if(player->getStrength() != 0 && right != 8)
		{
                	std::cout << "\n\n\tYou only got " << right << "/8 questions correct.";
			std::cout << "\n\nOh no, you got trapped underground!";
			std::cout << "\nMaybe if you had gotten all of the questions right, this wouldn't have happened.";
		
			do
			{
				std::cout << "\n\nYou're still stuck in traffic and haven't gotten to see the Face of Boe.";
				std::cout << "\n\nEnter '1' to return to the TARDIS or enter '0' to try again: ";
				std::cin  >> goAgain;
			}while(goAgain > 1 || goAgain < 0);
		}
   	}while(goAgain == 0 && player->getStrength() > 0);
   }
   else
   {
	std::cout << "\nI think I've already checked there.  No need to dabble in the past.... or future in this case!\n";
   }   
   return "1";
}
