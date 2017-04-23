/****************************************************************
 * *Author:		Taylor Jones (jonest3)			*
 * *Date:		March 15, 2016				*
 * *Description:	main.cpp - for Final Project		*
 ****************************************************************/
#include "Compartment.hpp"
#include "Future.hpp"
#include "ParallelUniverse.hpp"
#include "Past.hpp"
#include "PocketUniverse.hpp"
#include "Space.hpp"

#include <string>
#include <iostream>
#include "Creature.hpp"
#include "Player.hpp"
#include <cstdlib>
#include <fstream>

int main()
{
   int gameRun = 0;

   do
   {
	system("clear");
	int seeKey;
   	std::cout << "\tDoctor Who? (aka Day of The Master)";
  	std::cout << "\nAn epic journey through time and space based on the series 'Doctor Who'";
	do
	{
		std::cout << "\n\n\nEnter 1 to see the Game's Key or 0 to continue to the game: ";
		std::cin  >> seeKey;
	}while(seeKey < 0 || seeKey > 1);

	if(seeKey == 1)
	{
		std::cout << "\n\n\t\t\t\tGame Key: ";
		std::cout << "\n      The Library: 	You get 5 chances to roll a '10'.			Reward: 1200 Year-Old Diary";
		std::cout << "\n     New New York: 	You must answer all 8 questions correctly.		Reward:	Advice from The Face of Boe";
		std::cout << "\n        		The correct answers are {0,0,1,1,0,0,1,1}.";
		std::cout << "\n         The Past:	You must defeat the Krafayis before it defeats you.	Reward: fob watch with Chameleon Arch";
		std::cout << "\n Pocket Dimension:	You must roll a total of '70' points with your dice.	Reward: Your Sonic Screwdriver";
		std::cout << "\nParallel Universe:	You must WATCH you fight The Master to the death.	Reward: You win the game/save the world\n\n\n"; 
	}

   	Compartment *fut = new Future();
   	Compartment *parUn = new ParallelUniverse();
   	Compartment *past = new Past();
   	Compartment *pockUn = new PocketUniverse();
   	Compartment *space = new Space();

	std::string line;

	std::cout << "\n\nTo skip straight to challenges enter '1'.  To see the text (highly recommended) enter 0: ";
	do
	{
		std::cin >> gameRun;
	}while(gameRun > 1 || gameRun < 0);
	std::cin.ignore();
	if(gameRun == 0)
	{
	   	std::ifstream myfile("Library.txt");
	   	std::cout << "\n\nPress [Enter] to begin and keep pressing it to continue through the dialogue.\n";
		std::cin.ignore();
	   	if(myfile.is_open())
   		{
			while(getline(myfile,line))
	 		{
				std::cin.get();
				std::cout << line;
			}
			myfile.close();
	   	}
	   	else
	   	{
			std::cout << "Unable to open file\n\n";
	   	}
	}
	Player *player = new Player();
	if(gameRun == 0)
	{
   		std::ifstream nextfile("Library_part2.txt");
	   	if(nextfile.is_open())
   		{
	        	while(getline(nextfile,line))
	        	{
	                	std::cin.get();
	                	std::cout << line;
	        	}
	        	nextfile.close();
	   	}
	   	else
	   	{
	        	std::cout << "Unable to open file\n\n";
	   	}
	}	
   	std::string option = "1";

   	fut->setCompass(parUn, past, pockUn, space);
   	parUn->setCompass(past, pockUn, space, fut);
   	past->setCompass(pockUn, space, fut, parUn);
   	pockUn->setCompass(space, fut, parUn, past);
   	space->setCompass(fut, parUn, past, pockUn);
  
   	player->setLocation(space);
  
   	do
   	{
		if((player->getLocation() != parUn) || ((player->getDiary() == true) && (player->getWatch() ==  true) && (player->getAdvice() == true)))
     		{
			system("clear");
			std::cout << "\nCurrent Location: " << (player->getLocation())->getRoomType();
			std::cout << "\nCurrent Year: " << (player->getLocation())->getYear();
			std::cout << "\nCurrently Wearing: A " << player->getOutfit() << std::endl;
			option = ((player->getLocation())->challenge(player));
			player->setItems(option, (player->getLocation()));
		}
		else
		{
			std::cout << "\nHmm... I can't seem to cross over the wormhole into the Parallel Universe yet... maybe I am still missing something...\n";
		}
		if(option != "0" && player->getLifeCounter() > 0)
		{
			system("clear");
		        player->setLocation((player->getLocation())->menu());
		}
   	}while(option != "0" && player->getLifeCounter() > 0);
  
   	if(player->getLifeCounter() == 0 && (player->getLocation() == parUn))
   	{
		std::cout << "\nWhich will it be?";
		std::cout << "\n\nEnter either 1, 2, or 3: ";
		do
		{
			std::cin  >> gameRun;
		}while(gameRun < 1 || gameRun > 3);
	}
	else if(player->getLifeCounter() == 0)
	{
		std::cout << "\n\nWould you like to regenerate and try again?";
		std::cout << "\nEnter 2 to exit or 3 to regenerate and play again: ";
		do
		{
			std::cin  >> gameRun;
		}while(gameRun > 3 || gameRun < 2);
	} 

	delete player;
	player = NULL;
   	delete fut;
	fut = NULL;
   	delete parUn;
	parUn = NULL;
   	delete past;
	past = NULL;
   	delete pockUn;
	pockUn = NULL;
   	delete space;
	space = NULL;

   }while(gameRun == 3);
   return 0;
}
