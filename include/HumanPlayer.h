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

// TODO: Implement NonHumanPlayer
class NonHumanPlayer : public IPlayer {
	char symbol;
	Difficulty difficulty;
public:
	NonHumanPlayer(char symbol, Difficulty difficulty) : symbol(symbol), difficulty(difficulty) {}
	char Symbol() const override;
	BoardPosition TakeTurn(const std::vector<BoardPosition>& pos) override;
};