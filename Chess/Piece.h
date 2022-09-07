#pragma once
#include <list>

enum class PieceType {KING,QUEEN,BISHOP,KNIGHT,ROOK,PAWN};

class Piece {

	//Piece Private Members
	int color;//should be 1 for white, -1 for black; also used for direction of movement of pawns
	std::pair<int, int> position;

public:
	//Piece Getters and Setters
	int getColor() { return this->color; };
	void setColor(int color) { this->color = color; };
	std::pair<int, int> getPosition() { return this->position; };
	void setPosition() { this->position = position; };

	//Piece Constructors
	Piece();
	Piece(int color, int x, int y);
	Piece(int color, std::pair<int, int> position);

	//Piece Public Methods
	virtual bool isValidMove(std::list<Piece*> board, std::pair<int, int> endPosition) = 0;//checks if the endPosition would be a valid move given the board; Assumes that endPosition is within the board and isn't the same as the current position
	
	//Piece Public Static Class Methods
	static Piece* createPiece(PieceType pieceType);//Use this to construct pieces so that there is no conversion issues
	static Piece* createPiece(PieceType pieceType, int color, int x, int y);//Use this to construct pieces so that there is no conversion issues; allows you to set color of piece and position
	static Piece* createPiece(PieceType pieceType, int color, std::pair<int, int> position);//Use this to construct pieces so that there is no conversion issues; allows you to set color of piece and position

};

class King : public Piece {

	//King Private Members
	bool hasMovedPosition;//is false if the king hasn't moved yet, true otherwise; really only useful for castles

public:
	//King Getters and Setters
	bool hasMoved() { return this->hasMovedPosition; };//returns whether the king has moved yet; really only useful for castles
	void itMoved() { this->hasMovedPosition = true; }//sets hasMovedPosition to true; really only useful for castles

	//King Constructors
	King();
	King(int color, int x, int y);
	King(int color, std::pair<int, int> position);

	//King Public Methods
	bool isValidMove(std::list<Piece*> board, std::pair<int, int> endPosition) override;//Kings can move one square away from itself, and castles; read comment for Piece for more info on method

};

class Queen : public Piece {

public:
	//Queen Constructors
	Queen();
	Queen(int color, int x, int y);
	Queen(int color, std::pair<int, int> position);

	//Queen Public Methods
	bool isValidMove(std::list<Piece*> board, std::pair<int, int> endPosition) override;//Queens can move diagonally, vertically, and horizontally; read comment for Piece for more info on method

};

class Bishop : public Piece {

public:
	//Bishop Constructors
	Bishop();
	Bishop(int color, int x, int y);
	Bishop(int color, std::pair<int, int> position);

	//Bishop Public Methods
	bool isValidMove(std::list<Piece*> board, std::pair<int, int> endPosition) override;//Bishops can move diagonally; read comment for Piece for more info on method

};

class Knight : public Piece {

public:
	//Knight Constructors
	Knight();
	Knight(int color, int x, int y);
	Knight(int color, std::pair<int, int> position);

	//Knight Public Methods
	bool isValidMove(std::list<Piece*> board, std::pair<int, int> endPosition) override;//Knights can move in L shape through pieces; read comment for Piece for more info on method

};

class Rook : public Piece {

	//Rook Private Members
	bool hasMovedPosition;//is false if the rook hasn't moved yet, true otherwise; really only useful for castles

public:
	//Rook Getters and Setters
	bool hasMoved() { return this->hasMovedPosition; };//returns whether the rook has moved yet; really only useful for castles
	void itMoved() { this->hasMovedPosition = true; }//sets hasMovedPosition to true; really only useful for castles

	//Rook Constructors
	Rook();
	Rook(int color, int x, int y);
	Rook(int color, std::pair<int, int> position);

	//Rook Public Methods
	bool isValidMove(std::list<Piece*> board, std::pair<int, int> endPosition) override;//Rooks can move vertically, horizontally, and castles; read comment for Piece for more info on method

};

class Pawn : public Piece {

	//Pawn Private Members
	bool hasMovedPosition;

public:
	//Pawn Getters and Setters
	bool hasMoved() { return this->hasMovedPosition; };
	void itMoved() { this->hasMovedPosition = true; }

	//Pawn Constructors
	Pawn();
	Pawn(int color, int x, int y);
	Pawn(int color, std::pair<int, int> position);

	//Pawn Public Methods
	bool isValidMove(std::list<Piece*> board, std::pair<int, int> endPosition) override;//Pawns can move forward one space, en passant, and two spaces on first move; read comment for Piece for more info on method

};