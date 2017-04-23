/********************************************************
 * *Author:		Taylor Jones (jonest3)		*
 * *Date:		March 15, 2016			*
 * *Description:	Player.cpp 			*
 ********************************************************/

#include "Creature.hpp"
#include "Player.hpp"

#include <iostream>
#include <cstdlib>
#include <string>
#include <deque>
#include <ctime>

// Default Constructor
Player::Player()
{
   srand(time(NULL));
   this->attackDieCount = 2;
   this->attackDieSides = 6;
   this->defenseDieCount = 2;
   this->defenseDieSides = 6;
   this->armor = 5;
   this->strength = 10;
   this->maxStrength = 10;
   this->lifeCounter = 3;
   this->outfit = "leather jacket with a t-shirt";
   this->you_are_here = NULL;
   this->advice = false;
   this->screwdriver = false;
   this->watch = false;
   this->diary = false;
   
   do
   {
   	std::cout << "\n[Enter your name here ->] My name is: ";
   	getline(std::cin, creatureType);
   }while(creatureType == "");
}
/****************************************************************
 * 			void setStrength()			*
 * Takes an int. If int is greater than 0, it subtracts the 	*
 * creature's armor from the int and stores the difference in 	*
 * a variable.  If that variable is less than 1, prints the 	*
 * creatures was protected from damage. Else if variable is >=	*
 * to strength, prints that it was a fatal hit and sets strength*
 * = 0, subtracts 1 from lifeCounter, resets 'outfit' and prints*
 * certain statements based on what number the life counter is  *
 * on. If lifeCounter == 0, it sets strength == 0.  Else it 	*
 * subtracts the variable from the strength and sets the differ-*
 * ence as the new strength. Prints out the current strength.	*
 ****************************************************************/
void Player::setStrength(int inflicted)
{
   if(inflicted > 0)
   {
	int appliedDamage;
	appliedDamage = inflicted - armor;
	std::cout << std::endl << "The potential damage is: " << appliedDamage;
	if(appliedDamage < 1)
	{
		std::cout << std::endl << creatureType << " is able to duck out of the way and is protected from the damage!";
	}
	else if(appliedDamage >= strength)
	{
		std::cout << std::endl << creatureType << " takes a fatal hit!";
		strength = 0;
		lifeCounter--;
		setOutfit();
		if(lifeCounter == 3)
		{
			std::cout << "\n\nI... I don't want to go.. but I must.  I am... regenerating!";
			setOutfit();
			strength = maxStrength;
			sleep(2);
			std::cout << "\n\nIt's me! I am back! And I look fantastic with my new " << outfit << ". Let's do this! GERONIMO!!";
		}
		else if(lifeCounter == 2)
		{
			std::cout << "\n\n'Blimey, it's happening! I am.. regenerating,' you shout as your injured body turns into light!";
			setOutfit();
			strength = maxStrength;
			sleep(2);
			std::cout << "\n\n'Legs!  I've got legs!! Good. Arms, hands.  Ooh, fingers. Lots of fingers.";
			std::cout << "\nEars? Yes. Eyes: two. Nose.. eh, I've had worse.  Chin - blimey! Hair... I'm ";
			std::cout << "\na girl! No! No! I'm not a girl! But I do have a " << outfit << ".  Fantastic,' you say happy with your new appearance!";
		}
		else if(lifeCounter == 1)
		{
			std::cout << "\n\n'Sadly we all must change.  When you think about it, we're all different people, all";
			std::cout << "\nthroughout our lives...I will always remember when the Doctor was me.  Unfortunately, it's happening";
			std::cout << "\nagain... I am... regenerating,' you breathe as a beam of light shoots from your head and hands.";
			setOutfit();
			strength = maxStrength;

			sleep(2);
			std::cout << "\n\n'Kidneys!  I've got new kidneys!  And a " << outfit << ".  Bleh, but I don't like the colour,'";
			std::cout << "\nyou complain in your new, Scottish accent.\n";
		}
		else
		{
			strength = 0;
		}
   	}
	else
	{
		strength -= appliedDamage;
	}
	std::cout << std::endl << creatureType << "'s strength = " << strength << std::endl;
   } 
}
/****************************************************
 * 		void addItem()			    *
 * Uses the Compartment parsed as an argument to    *
 * get the item for the player's current location.  *
 * Prints out a statement that the item was gathered*
 * and adds the item to the back of the TARDIS.	    *
 ****************************************************/
void Player::addItem(Compartment* c)
{
   std::string i = (c->getItem());
   std::cout << "\n'I must carry on with my journey, but I will bring this " << i << " with me back to the TARDIS!'\n";
   TARDIS.push_back(i);
}
/************************************************
 * 		string removeItem()		*
 * If the TARDIS is not empty, it will copy the *
 * item in the front to string variable before  *
 * popping it off of the front.  That item is   *
 * then pushed back onto the back of the TARDIS *
 ************************************************/
std::string Player::removeItem()
{
   std::string removed;
   if(!(TARDIS.empty()))
   {
   	removed = TARDIS.front();
	TARDIS.pop_front();
	TARDIS.push_back(removed);
   }
   return removed;
}
/********************************************************************************
 * 				int attack()					*
 * Iterates through a while loop for the total number of 'attackDieCount' the 	*
 * creature has.  Each iteration adds a random number between 1 - attackDieSides*
 * to the sumOfDice.  After loop, it prints the total sum of the dice.		*
 *										*
 * If the player's current location is in the Parallel Universe:		*
 * -If advice is set to 'true', the number 'rolled' = '3', and the first thing  *
 *  in the 'TARDIS' is equal to the string, it will set advice to false to keep	*
 *  the player from being able to use this special feature, resets strength to 	*
 *  max strength, and prints that you used that item.				*
 * -If screwdriver is true, sum is equal to 6, and front matches string: set	*
 *  screwdriver to false, add an extra attack die, and print that you used the 	*
 *  item.									*
 * -If watch is true, sum is equal to 8, and front matches string: set watch as	*
 *  false, add an extra defense die, and print that you used the item.		*
 * -If diary is true, sum is equal to 11, and front matches string: set diary as*
 *  false, add an extra defense die, and print that you used the item.		*
 *										*
 *  Return the sum of dice.							* 
 ********************************************************************************/
int Player::attack()
{
   int sumOfDice = 0;
   int loop = 0;
   std::string front;
   front = removeItem();

   while(loop < attackDieCount)
   {
	sumOfDice += (rand() % attackDieSides) + 1;
	loop++;
   }
   std::cout << std::endl << creatureType << " rolled: " << sumOfDice << "." <<  std::endl;
   if((you_are_here)->getRoomType() == "Parallel Universe")
   {
   	// advice
   	if(advice && sumOfDice == 3 && front == "Advice from the Face of Boe")
   	{
		advice = false;
   		strength = maxStrength;
		std::cout << std::endl << creatureType << " thought of Boe and was reminded why he was here.  He has mustered more strength to continue.\n"; 
   	}
   	// screwdriver
   	else if(screwdriver && sumOfDice == 6 && front == "Sonic Screwdriver")
   	{
		screwdriver = false;
		attackDieCount += 1;
		std::cout << std::endl << creatureType << " remembers that he has his sonic screwdriver and begins using it against The Master!\n";
   	}
	// watch
   	else if(watch && sumOfDice == 8 && front == "fob watch with Chameleon Arch")
   	{
        	watch = false;
        	defenseDieCount += 1;
        	std::cout << std::endl << creatureType << " opens his " << front << " and releases his Time Lord essence to its fullest!\n";
   	}
	// diary
   	else if(diary && sumOfDice == 11 && front == "1200 Year-Old Diary")
   	{
        	diary = false;
        	lifeCounter += 1;
		setOutfit();
        	std::cout << "\nIt's like you are a whole new you. Fantastic!\n";
   	}
   }
   return sumOfDice;
}
// Mutator for you_are_here;
void Player::setLocation(Compartment* c)
{
   you_are_here = c;   
}
// Accessor for you_are_here;
Compartment* Player::getLocation()
{
   return you_are_here;
}
/********************************************************
 * 		void setOutfit()			*
 * Mutator used to set 'outfit'. If lifeCounter == 2, 	*
 * the outfit will be set to match the 10th doctor.  	*
 * If lifeCounter == 1 the outfit will be set to match	*
 * the 11th doctor. You start out with the outfit of the*
 * 9th doctor.						*
 ********************************************************/
void Player::setOutfit()
{
   if(lifeCounter == 4)
	outfit = "big, floppy, grey cravat and silky waistcoat";
   else if(lifeCounter == 3)
	outfit = "leather jacket and a t-shirt";
   else if(lifeCounter == 2)
	outfit = "brown trench coat and suit";
   else if(lifeCounter == 1)
        outfit = "red fez and a bowtie";
}
// Accessor for oufit;
std::string Player::getOutfit()
{
   return outfit;
}
// Mutator for creatureType;
void Player::setCreatureType(std::string n)
{
   creatureType = n;
}
// Accessor for creatureType;
std::string Player::getType()
{
   return creatureType;
}
/*************************************************
 * 		void setItems()			 *
 * Passes a string returned from the current     *
 * Compartment's challenge().  If the user beat  *
 * the challenge, it will pass the correct year  *
 * else, it will pass "1", therefore nothing 	 *
 * will happen.  It passes the current compar-	 *
 * ment to add the appropriate item to the TARDIS*
 *************************************************/
void Player::setItems(std::string s, Compartment* c)
{
   // future
   if(s == "5,000,000,023")
   {
	setAdvice();
	addItem(c);
   }
   // past
   else if(s == "1890")
   {
	setWatch();
	addItem(c);
   }
   // pocket universe
   else if(s == "2016.5")
   {
	setScrewdriver();
	addItem(c);
   }
   // space
   else if(s == "2016(ish)")
   {
	setDiary();
	addItem(c);
   }
}
// Mutator for 'advice' that prints how you got it. Ses it to 'true'
void Player::setAdvice()
{
   std::cout << "\nYou've done it! You have resisted Cyber-conversion and created a surge of emotion which destroyed the Cybermen!";
   std::cout << "\n\nAnd look, you've made it to the hospital and the Face of Boe is still alive!";
   std::cout << "\n\nThe Face of Boe nods you in close so they can say their final goodbyes.";
   std::cout << " '" << creatureType << ", it is time.  You are my oldest friend and I want you to know one thing,' says Boe.";
   std::cout << "\n" << creatureType << " walks over and leans down next to the Face of Boe as Boe begins to whisper something to them.";
   std::cout << "\n\n'Know this, Time Lord, you are not alone,' and with that, the Face of Boe closes their eyes.\n";

   advice = true;
}
// Accessor for advice;
bool Player::getAdvice()
{
   return advice;
}
// Mutator for 'screwdriver' that says you earned it back.  Sets it to 'true'
void Player::setScrewdriver()
{
   std::cout << "\n'My sonic screwdriver!  I am glad to have you back!  I haven't been without you  since that time I loaned you to Davros!";
   std::cout << "\nBut no time for long hellos, I must get out of here before the Angels touch me and take the TARDIS,' said " << creatureType << "!\n";
 
   screwdriver = true;
}
// Accessor for screwdriver
bool Player::getScrewdriver()
{
   return screwdriver;
}
// Mutator for 'watch' that prints the script of how you get it back. Sets it to 'true'.
void Player::setWatch()
{
   std::cout << "\nvan Gogh becomes emotional.  'It's dead.  We've killed it. I only meant to wound it,' he cries.";
   std::cout << "\n\n'You know, sometimes winning... winning is no fun at all,' " << creatureType << " says as they lay a comforting hand on van Gogh's shoulder.";
   std::cout << "\n'I must go now.  This is not the only beast that needs conquoring.'\n";
   std::cout << "\n\n'Thank you, " << creatureType << ", my friend!  We have fought monsters together and we have sadly won.'";
   std::cout << "\nVincent van Gogh reaches into his pocket and pulls out what appears to be a pocket watch.";
   std::cout << "\n'Please take this before you go.  I found it while painting haystacks and I somehow believe it belongs to you,' he says.\n";
   std::cout << "\nvan Gogh hands " << creatureType << " a Chameleon Arch fob watch.";
   std::cout << "\n\nYou hug him and say 'Thank you, Vincent.  Because of you, I can finally be me again! Thank you! Thank you for everything!";
   std::cout << "\n I've seen many things, my friend, but nothing quite as wonderful as the things you see.'";
   std::cout << "\n\n'No, thank you, " << creatureType << ".  I will miss you terribly. You've turned out to be the first doctor ever actually";
   std::cout << "\nto make a difference to my life!' and with that, start to you walk back with your head held high.";

   watch = true;
}
// Accessor for watch
bool Player::getWatch()
{
   return watch;
}
// Mutator for 'diary' that prints the script for finding it. Sets it to 'true'.
void Player::setDiary()
{
   std::cout << "\n\n'It's here! I've found it,' exclaims River!  '" << creatureType << ", quickly!  You must read it so you remember who you really are!'";
   std::cout << "\n\n" << creatureType << " hurriedly picks up the thick book and starts reading.  Much to " << creatureType << "'s surprise,";
   std::cout << " they are finished with the book in no time!";
   setCreatureType("The Doctor");
   std::cout << "\n\n'River! River, I remember!  I remember everything!  River!  I'm back!  It's me, " << creatureType;
   std::cout << "! \nBut... it's also not me.  I need my Chameleon arch to restore my Time Lord essence!  And my screwdriver!  Where is my sonic screwdriver?!'";
   std::cout << "\nyou shout!";
   std::cout << "\n\n'It's The Master, Doctor! He's back!  He wiped your memory and scattered your belongings throughout time and space so he could";
   std::cout << "\nrule the world! You have to stop him!'";
   std::cout << "\n\n'I must stop him and I will!  Before it's too late, not only for me but for the world!' you say as you begin to race back to the TARDIS.\n";

   diary = true;
}
// Accessor for diary;
bool Player::getDiary()
{
   return diary;
}
// Accessor for lifeCounter;
int Player::getLifeCounter()
{
   return lifeCounter;
}
