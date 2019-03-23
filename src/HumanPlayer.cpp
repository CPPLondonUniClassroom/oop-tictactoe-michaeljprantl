#include "HumanPlayer.h"

// Return the symbol of the current player ('X' or 'O')
char HumanPlayer::Symbol() const {
	return symbol;
}

// Let current player choose a board position
BoardPosition HumanPlayer::TakeTurn(const std::vector<BoardPosition>& pos) {
	int choice;

	// TODO: Show player currently available and validate choice
	choice = ReadNumber(0, 8);
	return NumberToBoardPosition(choice);
}


// Return the symbol of non-human player ('X' or 'O')
char NonHumanPlayer::Symbol() const {
	return symbol;
}

// Let non-human player make a move
BoardPosition NonHumanPlayer::TakeTurn(const std::vector<BoardPosition>& pos) {
	int choice;

	// TODO: Implement hard mode
	if (difficulty == Difficulty::hard) {

	}

	// TODO: Implement easy mode
	else {
		
	}

	return NumberToBoardPosition(choice);
}