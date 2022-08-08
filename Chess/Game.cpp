#include "Game.h";

void Game::startGame() {

	while (!board.gameWon()) {

		std::pair <int, int> move = player.getMove(board);
		board.doMove(move);
		currentPlayer = (playerOne.name == player)

	}

};

Game::Game(){

	players = new Player * [2];
	players[0] = new Human();

};