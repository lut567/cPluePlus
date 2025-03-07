#include <iostream>
#include <string> // To add and mess with strings

#include <random>
#include <cstdlib> // For random # gen rand
#include <ctime> // srand to use time to generate a random num


/* TO DO
Add three NPC types to fight
Add a basic user/NPC stats that affect the attack phases.
Remove rand after stats are added
*/







// This is the player attack phase
int playerAttackPhase(int z, std::string attack) 
{
	if (attack == "Quick" || attack == "quick") // if the attack string pass is Quick or Spicial
	{
		int x = rand() % 12; /// TO DO I want to no use rand but makew it more stat based for both the npc and user. For now quick = 12
		std::cout << "PLAYER TURN: You quickly attacked the NPC!";
		if (x == 0) // while low if rand = 0 the user will miss
		{
			std::cout << " Your attack missed!";
		}
		else // Any other rand attack will land here quick attack currently set to max of 11 dmg
		{
			std::cout << " Dmg delt to NPC: " << x << " DMG!" << '\n';
			z = z - x;
		}
	}

	else // Spicial attack | More flushed out including potential critial hits
	{
		int x = rand() % 20; // SP attack has high dmg pot of 19
		if (x == 0)
		{
			std::cout << "PLAYER TURN: You missed! :("; // Skill issue if rand is a 0. lol
		}
		else if (x > 15) // Critial Hit if rand is above 15 - 19
		{
			std::cout << "";
			x = (x * 2) + x; //// To do its set to int so I just temp set to rand * 2 dmg. Want to fluse this out based on the player stats
			std::cout << "PLAYER TURN: Critical Hit! Special Dmg delt to NPC: " << x << " DMG!" << '\n';
			z = z - x;
		}
		else // If it is not a critial hit it acts like a quick attack.
		{
			std::cout << "PLAYER TURN: Special Dmg delt to NPC: " << x << " DMG!" << '\n';
			z = z - x;
		}
	}		
	return z; // Returns the NPC health
}


// This is the NPC attack phase
int npcAttackStage(int z)
{
	int x = rand() % 3; ///// TO DO, flush this out, x is what type of attack the NPC uses against the palayer. 
	// Need to add lower chance for the NPC to choose SP attack and its own SP counter.

		
	if (x == 1) // NPC quick attack
	{
		int dmg = rand() % 8;
		std::cout << "\nNPC TURN: NPC did a quick attack on you!: Dmg delt to player: " << dmg << " DMG!" << '\n';
		z = z - dmg;
	}
	else if (x == 2) // NPC SP attack | currently set to dmg 14 with critial hit set to occur on 12
	{
		int dmg = rand() % 15;
		std::cout << "\nNPC TURN: NPC did a spicial attack on you! ";
		if (x > 10)
		{
			std::cout << "";
			dmg = (dmg * 2) + dmg;
			std::cout << "Critical Hit! Dmg delt to player: " << dmg << " DMG!" << '\n';
		}
		else
		{
			std::cout << "Dmg delt to player: " << x << " DMG!" << '\n';
			z = z - dmg;
		}
	}
	else // If rand gives a 0 the NPC misses.
	{
		std::cout << "\nNPC TURN: NPC missed. What a loser!";
	} 
	return z; // Return the user health
}

void slime()
{
	/*
	Low HP
	Mostly uses quick attack
	rare uses special attack
	standard run of the mill monster
	*/
}

void bear()
{
	/*
	Mid HP
	Almost only uses special attack but needs to rest a turn after each attack.
	If hp is low it switches to only useing quick attacks
	*/
}

void chicken()
{
	/*
	High HP
	double attack quick attacks.
	Small size = higher chances of player missing attacks
	rare chance that the flock is called in. If so, the player is fucking steamrolled
	*/
}

void npc(int x)
{
	std::string npc;
	
	if (x == 1)
	{
		npc = "chicken";
	}
	else if (x == 2)
	{
		npc = "bear";
	}
	else
	{
		npc = "slime";
	}

	std::cout << "A wild " << npc << " Appears!" << '\n' << '\n';
}


void stats(int userHp, int npcHp, int sp)
{
	std::cout << "\nYour HP is: " << userHp << " || NPC HP is: " << npcHp << '\n';
	std::cout << "Choose an attack: Quick | Special: " << sp << " left\n\n"; // Desplay the user SP
}


int main()
{
	// Needed vars include a string to determin the type | user hp | NPC hp | user sp tokens on how many SP attacks they can do.
	std::string attackType = "void";
	int hp = 100;
	int npchp = 100;
	int sp = 5;
	

	/* Big thing below. DONT USE RAND()!! Instead use the below*/

	std::random_device rd; // This generates a number seed
	std::uniform_int_distribution<int> x(1, 3); // This is the more flexable version then rand()

	npc(x(rd)); // Calling the npc funciton with a random num from a random seed






	

	//While loop to check the user hp, this needs to be replaced.
	while (hp > 0 && npchp > 0)
	{
		// This call the stats function for both the user and NPC
		stats(hp, npchp, sp); // Calls the stats header
		std::cin >> attackType; // User input on what type of attack they want.
		system("cls"); // This clears the screen

		if (attackType == "Quick" || attackType == "quick") 
		{
			npchp = playerAttackPhase(npchp, attackType); // Call the player attack phase | attackType is passing a string in the call | Return the updated NPC HP
			hp = npcAttackStage(hp);// Call the NPC attack phase | Return the updated user HP

			
		}
		else if (attackType == "Special" || attackType == "special")
		{
			// If loop that determines if the user can use a SP attack
			if (sp > 0)
			{
				npchp = playerAttackPhase(npchp, attackType); // Call the player attack phase | Return the updated NPC HP
				hp = npcAttackStage(hp); // Call the NPC attack phase | Return the updated user HP
				sp = sp - 1; // Removes an SP from the user
			}
			else // If the user dose not have enough SP to attack, cycle back main Add items?
			{
				
				std::cout << "You do not have enough SP to preform a spicial attack!";
			}
		}
		else
		{
			// Standard error thrown if the user misspells or dose not choose a proper attack
			std::cout << "Error: attack type incorrect";
		}

	}
	
	if (npchp < 0)
	{
		system("cls"); // This clears the screen
		std::cout << "You win!";
	}
	else
	{
		system("cls"); // This clears the screen
		std::cout << "You died!";
	}



	return 0;
}