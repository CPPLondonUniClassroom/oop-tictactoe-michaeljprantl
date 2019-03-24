#include "utility.h"
#include "Controller.h"

#include <set>
#include <algorithm>

// Enum class "winner" with two states: IPlayer winner, Draw
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

	// Lambda function to check victory condition
	auto victory = [this](IPlayer& player) -> bool { 
		std::vector<int> cross;
		std::vector<int> rows;
		std::vector<int> cols;

		for (unsigned int i = 0; i < 9; ++i) {
			if (this->board.CurrentState()[i] == player.Symbol()) {
				cross.emplace_back(i);
				rows.emplace_back(i / 3);
				cols.emplace_back(i % 3);
			}
		}

		// If center position is occupied, check diagonals
		if (std::find(cross.begin(), cross.end(), 4) != cross.end()) {
			if (std::find(cross.begin(), cross.end(), 0) != cross.end() && std::find(cross.begin(), cross.end(), 8) != cross.end()) {
				return true;
			}
			else if (std::find(cross.begin(), cross.end(), 2) != cross.end() && std::find(cross.begin(), cross.end(), 6) != cross.end()) {
				return true;
			}
		}

		// Check rows
		std::set<int> proof{ 0, 1, 2 };
		for (auto& elem : proof) {
			if (std::count(rows.begin(), rows.end(), elem) == 3) {
				return true;
			}
		}

		// Check columns
		for (auto& elem : proof) {
			if (std::count(cols.begin(), cols.end(), elem) == 3) {
				return true;
			}
		}

		return false;
	};

	do {
		// Player 1 take turn
		PrintMessage("\nIt's player 1's turn.");
		choice = player1.TakeTurn(board.FreePositions());

		// Update board with Player 1 move
		board.OccupyPosition(choice, player1);

		// Print new state of the board
		renderer.RenderBoard(board.CurrentState());

		// Check victory on Player 1
		if (victory(player1)) {
			winner = Winner::player1;
			continue;
		}
		else if (board.FreePositions().empty()) {
			winner = Winner::draw;
			continue;
		}


		// Player 2 take turn
		PrintMessage("\nIt's player 2's turn.");
		choice = player2.TakeTurn(board.FreePositions());

		// Update board with Player 2 move
		board.OccupyPosition(choice, player2);

		// Print new state of the board
		renderer.RenderBoard(board.CurrentState());

		// Check victory on Player 2
		if (victory(player2)) {
			winner = Winner::player2;
			continue;
		}
		else if (board.FreePositions().empty()) {
			winner = Winner::draw;
			continue;
		}

	} while (winner == Winner::none);

	// Announce winner, wrap up game, return to main menu
	switch (winner) {
	case Winner::player1:
		PrintMessage("Congratulations! Player 1 has won. ");
		break;
	case Winner::player2:
		PrintMessage("Congratulations! Player 2 has won. ");
		break;
	case Winner::draw:
		PrintMessage("Deuce! This party ended in a draw. ");
		break;
	}
}