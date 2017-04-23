/********************************************************
 * *Author:		Taylor Jones (jonest3)		* 
 * *Date:		February 14, 2016		*
 * *Description:	Creature.cpp - Abstract Class	*
 ********************************************************/
#include "Creature.hpp"

#include <iostream>
#include <cstdlib>
#include <string>

// Default Constructor
Creature::Creature()
{
}
/*****************************************
 * 		int attack()		 *
 * Generates a random number between 1 - *
 * the creature's attackDieSides.  It 	 *
 * adds this number to a running for 	 *
 * every attackDie the creature has. 	 *
 * Prints it to the screen and returns   *
 * the sum.				 *
 *****************************************/
int Creature::attack()	// Will return 'damage'
{
   int sumOfDice = 0;	// Keeps total for amount rolled
   int loop = 0;	// Counter for loop

   while(loop < attackDieCount)
   {
	sumOfDice += (rand() % attackDieSides) + 1;
	loop++;
   }
   std::cout << std::endl << creatureType << " rolled: " << sumOfDice << ".";
   return sumOfDice;
}
 /*****************************************************
 *              	int defense()	              *
 * Takes an int. Generates a rand number between 1 -  *
 * the creature's defenseDieSides. It adds this number*
 * to a running for every defenseDie the creature has.*
 * Prints it to the screen. If the int passed is less *
 * than or equal to the sum, prints the attack failed *
 * and returns 0. Else it returns the int - the sum.  *
 ******************************************************/
int Creature::defense(int damage)	// Will return 'inflicted'
{
   std::cout << std::endl << creatureType << " has " << defenseDieCount << " defense die!";
   int sumOfDice = 0;
   int loop = 0;

   while(loop < defenseDieCount)
   {
	sumOfDice += (rand() % defenseDieSides) + 1;
	loop++;
   }
   std::cout << std::endl << creatureType << " rolled a defense of " << sumOfDice << ".";
   if(damage <= sumOfDice)
   {
	std::cout << std::endl << "Attack on " << creatureType << " failed!\n";
	return 0;
   }
   return (damage - sumOfDice);
}
/************************************************
 * 		void setStrength()		*
 *Takes an int.  If int is larger than 0, print *
 *the armor.  Subtracts the armor from the int. *
 *If the difference < 1, print armor protected  *
 *creature. Else if difference >= to strength,  *
 *prints it was a fatal hit and sets strength to*
 *0. Else subtracts difference from the strength*
 *Prints the final strength to screen.		*
 ************************************************/
void Creature::setStrength(int inflicted)	// Sets strength
{
   if(inflicted > 0)
   {
	std::cout << std::endl << creatureType << " has an armor of: " << armor << ".";

	int appliedDamage;
	appliedDamage = inflicted - armor;
	std::cout << std::endl << "The inflicted damage is: " << appliedDamage << ".";
	if(appliedDamage < 1)
	{
		std::cout << std::endl << creatureType << "'s armor has protected them from the damage.";
	}
	else if(appliedDamage >= strength)
	{
		std::cout << std::endl << creatureType << " takes a fatal hit!";
		strength = 0; 
	}
	else
		strength -= appliedDamage;
	
   }
   std::cout << std::endl << creatureType << "'s strength = " << strength << ".";
}
// Accessor for strength variable
int Creature::getStrength()
{
   return strength;
}
// Accessor for creatureType variable
std::string Creature::getType()
{
   return creatureType;
}
