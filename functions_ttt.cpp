//Gronflax this is a game of Tic-Tac-Toe which i was requested by my online course to create. I was asked to use functions, vectors & loops. 
//I also made the game replayable without closing the game, with a score tracker, and resetable in the event of a draw.

#include <iostream>
#include <vector>
#include "functions_ttt.h";


// Some global variables I used in some of the functions. Some of these could have been localised to tidy them up slightly, but I left them up here as I kep coming back to alter them slightly. 
std::vector<std::string> move(9, " "); //used for the grid patterns and storing current placement of players moves. 
std::string player_name1, player_name2; //self explanitory variable names
bool player = false; //used for swapping player after turns
int p1score = 0, p2score = 0, current = 0;  // scoring & loop varible.

void welcome()   //self explanitory naming
{
	std::cout << "===========\n";
	std::cout << "Tic-Tac-Toe\n";
	std::cout << "===========\n\n";
}

void getnames()  //more self explanitory functions
{
	std::cout << "Enter Player 1's name: ";
	std::cin >> player_name1;
	std::cout << "Enter Player 2's name: ";
	std::cin >> player_name2;
	std::cout << "Thank you " << player_name1 << " and " << player_name2 << " let's begin!\n\n\n";

}

void gridsetup() // inital grid setup but also used within the game function to display current game progress
{
	std::cout << "\n " << move[0] << " | " << move[1] << " | " << move[2] << "\n";
	std::cout << " - - - - - \n";
	std::cout << " " << move[3] << " | " << move[4] << " | " << move[5] << "\n";
	std::cout << " - - - - - \n";
	std::cout << " " << move[6] << " | " << move[7] << " | " << move[8] << "\n\n";

	return;
}

void game()  // main game function.
{
	int selection = 0;  //variable used for keeping track of the players current move selection. 

	while (current == 0)  // while loop for playing the game
	{
		if (move[0] == "X" && move[1] == "X" && move[2] == "X")  //these 8 if and 8 else if statements check for wins from either player
		{
			p1score++; //adds to player score (repeated in the other if and else if statements regarding checking for winning conditions. 
			current = 1; //ends the loop.
		}
		else if (move[0] == "O" && move[1] == "O" && move[2] == "O")
		{
			p2score++;
			current = 1;
		}

		if (move[3] == "X" && move[4] == "X" && move[5] == "X")
		{
			p1score++;
			current = 1;
		}
		else if (move[3] == "O" && move[4] == "O" && move[5] == "O")
		{
			p2score++;
			current = 1;
		}

		if (move[6] == "X" && move[7] == "X" && move[8] == "X")
		{
			p1score++;
			current = 1;
		}
		else if (move[6] == "O" && move[7] == "O" && move[8] == "O")
		{
			p2score++;
			current = 1;
		}

		if (move[0] == "X" && move[3] == "X" && move[6] == "X")
		{
			p1score++;
			current = 1;
		}
		else if (move[0] == "O" && move[3] == "O" && move[6] == "O")
		{
			p2score++;
			current = 1;
		}

		if (move[1] == "X" && move[4] == "X" && move[7] == "X")
		{
			p1score++;
			current = 1;
		}
		else if (move[1] == "O" && move[4] == "O" && move[7] == "O")
		{
			p2score++;
			current = 1;
		}

		if (move[2] == "X" && move[5] == "X" && move[8] == "X")
		{
			p1score++;
			current = 1;
		}
		else if (move[2] == "O" && move[5] == "O" && move[8] == "O")
		{
			p2score++;
			current = 1;
		}

		if (move[0] == "X" && move[4] == "X" && move[8] == "X")
		{
			p1score++;
			current = 1;
		}
		else if (move[0] == "O" && move[4] == "O" && move[8] == "O")
		{
			p2score++;
			current = 1;
		}

		if (move[2] == "X" && move[4] == "X" && move[6] == "X")
		{
			p1score++;
			current = 1;
		}
		else if (move[2] == "O" && move[4] == "O" && move[6] == "O")
		{
			p2score++;
			current = 1;
		}

		
		std::cout << "\n " << "1" << " | " << "2" << " | " << "3" << "\n"; //simple method of displaying the options to the players
		std::cout << " - - - - - \n";
		std::cout << " " << "4" << " | " << "5" << " | " << "6" << "\n";
		std::cout << " - - - - - \n";
		std::cout << " " << "7" << " | " << "8" << " | " << "9" << "\n\n";

		gridsetup();  //displays current progress

		if (player == false && current == 0)  // checks player turn and takes their selection.
		{
			std::cout << player_name1 << " select a number to insert your piece into: ";
			std::cin >> selection;
		}
		else if (player == true && current == 0)
		{
			std::cout << player_name2 << " select a number to insert your piece into: ";
			std::cin >> selection;
		}


		if (player == false)  //changes the grid patter according to the player selection and alternates player
		{
			move[selection - 1] = "X";
			player = true;
		}
		else if (player == true)
		{
			move[selection - 1] = "O";
			player = false;
		}
		else
		{
			move[selection - 1] = " ";
		}
		//this if statement checks for a drawn game and offers for the game to begin again. 
		if (move[0] != " " && move[1] != " " && move[2] != " " && move[3] != " " && move[4] != " " && move[5] != " " && move[6] != " " && move[7] != " " && move[8] != " ")
		{
			std::string restart;
			std::cout << "\nNo more move can be made, no winner. Try again? Y/N\n";
			std::cin >> restart;
			if (restart == "Y")
			{
				for (int i = 0; i < 9; i++) // reset of the game
				{
					move[i] = " ";
				}
			}
			else if (restart == "N")
			{
				current = 1;
			}
		}
	}

	current = 0;
	for (int i = 0; i < 9; i++)
	{
		move[i] = " ";
	}
	std::cout << player_name1 << " score = " << p1score << "\n"; //displays the scores
	std::cout << player_name2 << " score = " << p2score << "\n";

}
