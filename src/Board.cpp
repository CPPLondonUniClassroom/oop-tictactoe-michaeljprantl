#include "Board.h"
#include "utility.h"

// Return a vector of available fields on the board
std::vector<BoardPosition> Board::FreePositions() const {
	std::vector<BoardPosition> free;

	for (int i = 0; i < 9; ++i) {
		if (board[i] != 'X' || board[i] != 'O') {
			free.emplace_back(NumberToBoardPosition(i));
		}
	}

	return free;
}

// Place the current players choice on the board
void Board::OccupyPosition(const BoardPosition& pos, const IPlayer& player) {
	// TODO
}

// Dump the current state of the board
std::vector<char> Board::CurrentState() const {
	return board;
}