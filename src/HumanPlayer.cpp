#include "HumanPlayer.h"

#include <set>
#include <algorithm>
#include <thread>
#include <chrono>

// Return the symbol of the current player ('X' or 'O')
char HumanPlayer::Symbol() const {
	return symbol;
}

// Let current player choose a board position
BoardPosition HumanPlayer::TakeTurn(const std::vector<BoardPosition>& pos) {
	int choice;
	std::set<int> free{ 0, 1, 2, 3, 4, 5, 6, 7, 8 };

	auto show_available = [&]() {
		PrintMessage(" | ");
		for (int elem : free) {
			if (std::find(pos.begin(), pos.end(), NumberToBoardPosition(elem)) == pos.end()) {
				PrintMessage('-', " | ");
			}
			else {
				PrintMessage(elem + 1, " | ");
			}
		}
	};

	PrintMessage("Please choose one of the following available positions:\n");

	show_available();

	while (true) {
		choice = ReadNumber(1, 9) - 1;

		if (std::find(pos.begin(), pos.end(), NumberToBoardPosition(choice)) != pos.end()) {
			break;
		}
		PrintMessage(
			"The selected position is already occupied.",
			" Please choose a different position.\n"
		);
		show_available();
	}

	return NumberToBoardPosition(choice);
}


// Return the symbol of non-human player ('X' or 'O')
char NonHumanPlayer::Symbol() const {
	return symbol;
}

// Let non-human player make a move
BoardPosition NonHumanPlayer::TakeTurn(const std::vector<BoardPosition>& pos) {
	int choice;

	// TODO: Implement random pause to simulate thinking process

	// TODO: Implement hard mode
	if (difficulty == Difficulty::hard) {

	}

	// TODO: Implement easy mode
	else {
		int sample = rand() % pos.size();
		choice = BoardPositionToInt(pos[sample]);
	}

	return NumberToBoardPosition(choice);
}