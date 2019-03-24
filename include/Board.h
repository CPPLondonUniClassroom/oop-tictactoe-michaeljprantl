#pragma once

#include "BoardPosition.h"
#include "interface/IPlayer.h"

#include <vector>

class Board {
	std::vector<char> board{ 0, 0, 0, 0, 0, 0, 0, 0, 0 };
public:
	std::vector<BoardPosition> FreePositions() const;
	void OccupyPosition(const BoardPosition& pos, const IPlayer& player);
	std::vector<char> CurrentState() const;
};