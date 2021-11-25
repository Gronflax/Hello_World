//Gronflax, the comments for the code are mostly in the functions_ttt.cpp files as most of the coding is there. 

#include<iostream>
#include"functions_ttt.h"

int main()
{
	std::string check; // the two varibles needed and both the welcome and get names functions. 
	int play = 0;
	welcome();
	getnames();

	std::cout << "\n\n"; //some spacing

	while (play == 0) //while loop that calls the game and checks to see if the players wish to continue. 
	{
		
		game();
		std::cout << "\nDo you wish to continue? Y/N ";
		std::cin >> check;

		if (check == "Y")
		{
			play = 0;
		}
		else if (check == "N")
		{
			play = 1;
		}
		else
		{
			std::cout << "\nYou have enetered an invalid option!";
		}
	
	}
	
	
	return 0;
}
