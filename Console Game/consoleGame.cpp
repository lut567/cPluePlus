#include <iostream>
#include <string>
#include <cstdlib>


/* TO DO
Add User Item system
Add three NPC types to fight
Add a basic user/NPC stats that affect the attack phases.
Remove rand after stats are added
Clean up the user interface

*/




// This is the player attack phase
int playerAttackPhase(int z, std::string attack) 
{
	if (attack == "Quick") // if the attack string pass is Quick or Spicial
	{
		int x = rand() % 12; /// TO DO I want to no use rand but makew it more stat based for both the npc and user. For now quick = 12
		if (x == 0) // while low if rand = 0 the user will miss
		{
			std::cout << "You missed! :(";
		}
		else // Any other rand attack will land here quick attack currently set to max of 11 dmg
		{
			std::cout << "\nQuick Attack: You hit " << x << " DMG!" << '\n';
			z = z - x;
		}
	}

	else // Spicial attack | More flushed out including potential critial hits
	{
		int x = rand() % 20; // SP attack has high dmg pot of 19
		if (x == 0)
		{
			std::cout << "\nYou missed! :("; // Skill issue if rand is a 0. lol
		}
		else if (x > 15) // Critial Hit if rand is above 15 - 19
		{
			std::cout << "Critical Hit!";
			x = (x * 2) + x; //// To do its set to int so I just temp set to rand * 2 dmg. Want to fluse this out based on the player stats
			std::cout << "\nSpicial Attack: Critical hit dealing " << x << " DMG!" << '\n';
			z = z - x;
		}
		else // If it is not a critial hit it acts like a quick attack.
		{
			std::cout << "\nSpicial Attack: You hit " << x << " DMG!" << '\n';
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
		std::cout << "\nNPC did a quick attack on you!\n";
		std::cout << "\nNPC Qucik Attack: NPC hit " << dmg << " DMG!" << '\n';
		z = z - dmg;
	}
	else if (x == 2) // NPC SP attack | currently set to dmg 14 with critial hit set to occur on 12
	{
		int dmg = rand() % 15;
		std::cout << "\nNPC did a spicial attack on you!\n";
		if (x > 12)
		{
			std::cout << "Critical Hit!";
			dmg = (dmg * 2) + dmg;
			std::cout << "\nNPC Spicial Attack: Critical hit dealing " << dmg << " DMG!" << '\n';
		}
		else
		{
			std::cout << "\nNPC Spicial Attack: NPC hit " << x << " DMG!" << '\n';
			z = z - dmg;
		}
	}
	else // If rand gives a 0 the NPC misses.
	{
		std::cout << "\nHe missed. What a loser!";
	} 
	return z; // Return the user health
}




int main()
{
	// Needed vars include a string to determin the type | user hp | NPC hp | user sp tokens on how many SP attacks they can do.
	std::string attackType = "void";
	int hp = 100;
	int npchp = 100;
	int sp = 5;

	//While loop to check the user hp, this needs to be replaced.
	while (hp > 0 or npchp > 0) 
	{
		// This desplaies the main stats for both the user and NPC
		std::cout << '\n';
		std::cout << "Your HP is: " << hp << '\n';
		std::cout << "The NPC HP is: " << npchp << '\n';
		std::cout << "Choose an attack: Quick | Special: " << sp << " left\n\n"; // Desplay the user SP
		std::cin >> attackType; // User input on what type of attack they want.

		if (attackType == "Quick") /// TO DO: allow Quick and quick to pass though ///
		{
			std::cout << "\nYou quickly attacked the NPC!\n";
			npchp = playerAttackPhase(npchp, attackType); // Call the player attack phase | attackType is passing a string in the call | Return the updated NPC HP
			hp = npcAttackStage(hp);// Call the NPC attack phase | Return the updated user HP

			
		}
		else if (attackType == "Special")
		{
			// If loop that determines if the user can use a SP attack
			if (sp > 0)
			{
				std::cout << "You used your Special attack on the NPC!";
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
	
	//////////// TO DO ////////////
	// Fix this to give proper who won thingy 
	std::cout << "\n\nEnd of while main loop";
	
	return 0;
}