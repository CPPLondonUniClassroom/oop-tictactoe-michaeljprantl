#pragma once

#include "interface/IPlayer.h"
#include "interface/IRenderer.h"
#include "Board.h"

class Controller {
	IPlayer& player1;
	IPlayer& player2;
	IRenderer& renderer;
	Board board;
public:
	Controller(IPlayer& player1, IPlayer& player2, IRenderer& renderer, Board board)
		: player1(player1), player2(player2), renderer(renderer), board(board)
	{}
	void PlayGame();
};
