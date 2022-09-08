#pragma once
#include "Piece.h"

class Board {

	const int width;//width of the board
	const int height;//height of the board
	std::list<Piece*> board;//inner representation of the board

	void makeBoard(std::string constructor);

public:
	const static std::string DEFAULT_BOARD;//default 8x8 chess setup;each piece is listed in this format: ;color,x,y;

	Board();//default board size and construction
	Board(int width, int height, std::string constructor);//TO BE IMPLEMENTED; non-standard board with specified size and contruction
	void doMove(std::pair<int,int> start, std::pair<int,int> end);//changes location of piece at start to end location
	~Board();

};