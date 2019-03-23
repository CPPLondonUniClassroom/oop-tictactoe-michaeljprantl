#include "Controller.h"

// TODO: Enum class "winner" with two states: IPlayer winner, Draw
enum class Winner: char {
	none,
	player1,
	player2,
	draw
};

// Control main game Loop, determine winner and roll up the game
void Controller::PlayGame() {
	BoardPosition choice;
	Winner winner = Winner::none;
	do {
		// Player 1 take turn
		choice = player1.TakeTurn(board.FreePositions());

		// Update board with Player 1 move
		board.OccupyPosition(choice, player1);

		// Print new state of the board
		renderer.RenderBoard(board.CurrentState());

		// Check victory on Player 1
		if (/* victory condition */) {
			winner = Winner::player1;
			continue;
		}
		else if (board.FreePositions().empty()) {
			winner = Winner::draw;
			continue;
		}

		// Player 2 take turn
		choice = player2.TakeTurn(board.FreePositions());

		// Update board with Player 2 move
		board.OccupyPosition(choice, player2);

		// Print new state of the board
		renderer.RenderBoard(board.CurrentState());

		// Check victory on Player 2
		if (/* victory condition */) {
			winner = Winner::player2;
			continue;
		}
		else if (board.FreePositions().empty()) {
			winner = Winner::draw;
			continue;
		}

	} while (winner == Winner::none);

	// TODO: Announce winner, wrap up game, return to main menu
}