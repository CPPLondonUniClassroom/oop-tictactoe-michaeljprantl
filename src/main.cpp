#include "Board.h"
#include "BoardPosition.h"
#include "Controller.h"
#include "HumanPlayer.h"
#include "Renderer.h"
#include "utility.h"

#include <iostream>
#include <cctype>

int main() {
	while (true) {
		// Main menu, choose symbols, players etc.
		PrintMessage(
			"Welcome to CPPLondonUni TicTacToe!\n",
			"This game is played with 2 players ",
			"on a 3x3 game board. The players\n",
			"take turns in placing their tokens ",
			"on the field until one player has\n",
			"managed to place 3 tokens in a row ",
			"or until there is no free position",
			"\nleft.\n\n",
			"How many players would like to play? Please press 1 or 2."
		);

		int no_players = ReadNumber(0, 2);

		// Choose Symbol
		std::vector<char> symbol{ 'X', 'O' };
		char ans = NULL;

		PrintMessage(
			"Player 1, please choose your symbol from the following: ", 
			symbol[0], " or ", symbol[1], ".\n > "
		);

		std::cin >> ans;
		while (std::cin.fail() || !(std::toupper(ans) == symbol[0] || std::toupper(ans) == symbol[1])) {
			std::cout << "ERROR: Please choose either " << symbol[0] << " or " << symbol[1] << ".\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << " > ";
			std::cin >> ans;
		}

		if (ans != symbol[0]) {
			std::swap(symbol[0], symbol[1]);
		};

		// TODO: Initialize variables, account for AI players
		IPlayer *player1 = nullptr;
		IPlayer *player2 = nullptr;

		HumanPlayer pc1(symbol[0]);
		HumanPlayer pc2(symbol[1]);
		NonHumanPlayer npc1(symbol[1]);
		NonHumanPlayer npc2(symbol[0]);

		switch (no_players) {
		case 2:
			player1 = &pc1;
			player2 = &pc2;
			break;
		case 1:
			player1 = &pc1;
			player2 = &npc1;
			break;
		default:
			player1 = &npc2;
			player2 = &npc1;
			break;
		}

		Renderer renderer;
		Board board;

		// Initialize Game
		Controller controller(*player1, *player2, renderer, board);

		controller.PlayGame();

		// Wrap up game, ask whether to go back to main
		PrintMessage(
			"Game finished. That was fun! \nWould ",
			"you like to play another round? (y/N)",
			"\n > "
		);
		
		std::cin >> ans;
		while (std::cin.fail() || !(std::tolower(ans) == 'y' || std::tolower(ans) == 'n')) {
			std::cout << "ERROR: Please enter y (Yes) or N (No)\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << " > ";
			std::cin >> ans;
		}

		if (std::tolower(ans) != 'y') {
			PrintMessage(
				"\nYou chose '", ans, "'. Such a "
				"pity. It was a lot of fun with ",
				"you. See you next time!\n"
			);
			break;
		}

		PrintMessage("Cool! Let's get back to the start then.\n\n");
	}
	PrintMessage("Exiting...");
}