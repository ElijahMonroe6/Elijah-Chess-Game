#include "Board.h"
#include "StringExtension.h"

using namespace std;

const string Board::DEFAULT_BOARD = "";

Board::Board() : width(8), height(8) { makeBoard(Board::DEFAULT_BOARD); };

void Board::makeBoard(string constructor) {

	for (int i = 0; i < this->width * this->height; i++) {

		this->board.push_back(nullptr);
	
	}

	list<string> pieces = stringExtension::split(constructor, ',');

	for (string piece : pieces) {

		//constuctor 

	}

};