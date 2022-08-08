#pragma once
#include <string>
#include "Board.h"

class Player {

	string name;

public:

	virtual pair<int, int> getMove(Board gameBoard);

};

using namespace std;


class Human : Player{

	string name;

public:

	Human();
	pair<int, int> getMove(Board gameBoard);
	~Human();

};