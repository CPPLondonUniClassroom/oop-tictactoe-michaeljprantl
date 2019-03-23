#pragma once

#include <vector>

#include "BoardPosition.h"
#include "interface/IPlayer.h"

class Board {
	std::vector<char> board;
public:
	std::vector<BoardPosition> FreePositions() const;
	void OccupyPosition(const BoardPosition& pos, const IPlayer& player);
	std::vector<char> CurrentState() const;
};