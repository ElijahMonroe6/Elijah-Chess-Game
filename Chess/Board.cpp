#include "Board.h"
#include "StringExtension.h"

using namespace std;

const string Board::DEFAULT_BOARD = "white,rook,0,0;white,knight,1,0;white,bishop,2,0;white,queen,3,0;white,king,4,0;white,bishop,5,0;white,knight,6,0;white,rook,7,0;white,pawn,0,1;white,pawn,1,1;white,pawn,2,1;white,pawn,3,1;white,pawn,4,1;white,pawn,5,1;white,pawn,6,1;white,pawn,7,1;black,rook,7,0;black,knight,7,1;black,bishop,7,2;black,queen,7,3;black,king,7,4;black,bishop,7,5;black,knight,7,6;black,rook,7,7;black,pawn,6,0;black,pawn,6,1;black,pawn,6,1;black,pawn,6,2;black,pawn,6,3;black,pawn,6,4;black,pawn,6,5;black,pawn,6,6;black,pawn,6,7";

Board::Board() : width(8), height(8) { makeBoard(Board::DEFAULT_BOARD); };

void Board::makeBoard(string constructor) {

	for (int i = 0; i < this->width * this->height; i++) {

		this->board.push_back(nullptr);
	
	}

	list<string> pieces = stringExtension::split(constructor, ';');

	for (string piece : pieces) {

		//constuctor 

	}

};