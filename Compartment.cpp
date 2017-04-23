/********************************************************
 * *Author:		Taylor Jones (jonest3)		*
 * *Date:		March 15, 2016			*
 * *Description:	Compartment.cpp  - Abstract     *
 * 			parent class for Final Project. *
 ********************************************************/
#include "Compartment.hpp"
#include "Creature.hpp"

#include <iostream>
#include <cstdlib>
#include <string>

/* Default Constructor */
Compartment::Compartment()
{
   this->north = NULL;
   this->south = NULL;
   this->east = NULL;
   this->west = NULL;
   roomType = "NoName";
   year = "0";
   item = "Empty ";
   visited = 0;
}
// Destructor
Compartment::~Compartment()
{
}
/**************************************************
 * 		void setCompass()	 	  *
 * Takes 4 pointers to Compartments and sets      *
 * one to each of the 4 pointers within the class *
 * creating the game's setup/layout.		  *
 **************************************************/
void Compartment::setCompass(Compartment* n, Compartment* s, Compartment* e, Compartment* w)
{  this->north = n;
   this->south = s;
   this->east = e;
   this->west = w;
}
/************************************************
 * 		Compartment* menu()		*
 * Prints a menu for the user to select which   *
 * Compartment they want to visit next.  Each   *
 * Compartment's menue will be based on which   *
 * pointer is pointing to which compartment. It	*
 * will return a pointer corresponding to the 	*
 * location the user wishes to visit next.	*
 * Includes input validation.			*
 ************************************************/
Compartment* Compartment::menu()
{
   int usersChoice;
   do
   {
   	std::cout << "\nYou are back in the TARDIS, your wibbily, wobbly, timey, wimey machine.\n\n";
   	std::cout << "\t1. " << north->getRoomType();
   	std::cout << "\n\t2. " << south->getRoomType();
   	std::cout << "\n\t3. " << east->getRoomType();
   	std::cout << "\n\t4. " << west->getRoomType();
	std::cout << "\n\nWhere do you want to travel to next?";
	std::cout << "\nEnter either 1, 2, 3, or 4: ";
	std::cin  >> usersChoice;
   }while(usersChoice > 4 || usersChoice < 1);

   if(usersChoice == 1)
	return north;
   else if(usersChoice == 2)
	return south;
   else if(usersChoice == 3)
	return east;
   else if(usersChoice == 4)
	return west;
}
// Accessor for roomType
std::string Compartment::getRoomType()
{
   return roomType;
}
// Accessor for item
std::string Compartment::getItem()
{
   return item;
}
// Pure virtual function (Special Function)
std::string Compartment::challenge(Creature* player)
{
}
// Accessor for year
std::string Compartment::getYear()
{
   return year;
}
