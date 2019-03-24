#pragma once

#include "BoardPosition.h"

#include <vector>

class IPlayer {
public:
	virtual char Symbol() const = 0;
	virtual BoardPosition TakeTurn(const std::vector<BoardPosition>& pos) = 0;
};