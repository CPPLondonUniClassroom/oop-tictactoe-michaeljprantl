#pragma once

#include "interface/IPlayer.h"
#include "BoardPosition.h"
#include "utility.h"

enum class Difficulty : char {
	none,
	easy,
	medium,
	hard
};

class HumanPlayer : public IPlayer {
	char symbol;
public:
	HumanPlayer(char symbol): symbol(symbol) {}
	char Symbol() const override;
	BoardPosition TakeTurn(const std::vector<BoardPosition>& pos) override;
};

class NonHumanPlayer : public IPlayer {
	char symbol;
public:
	NonHumanPlayer(char symbol) : symbol(symbol) {}
	char Symbol() const override;
	BoardPosition TakeTurn(const std::vector<BoardPosition>& pos) override;
};