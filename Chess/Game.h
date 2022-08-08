#pragma once
#include "Player.h"
#include "Board.h"

class Game{

	Player** players;
	Board gameBoard;

public:

	Game();
	void startGame();

};