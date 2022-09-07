#pragma once
#include <list>

enum class PieceType {KING,QUEEN,BISHOP,KNIGHT,ROOK,PAWN};

class Piece {

	int color;//should be 1 for white, -1 for black; also used for direction of movement
	std::pair<int, int> position;

public:
	int getColor() { return this->color; };
	void setColor(int color) { this->color = color; };
	std::pair<int, int> getPosition() { return this->position; };
	void setPosition() { this->position = position; };

	Piece();
	Piece(int isWhite, int x, int y);
	Piece(int isWhite, std::pair<int, int> position);
	virtual bool isValidMove(std::list<Piece*> board, std::pair<int, int> endPosition) = 0;
	
	static Piece* createPiece(PieceType pieceType);
	static Piece* createPiece(PieceType pieceType, int isWhite, int x, int y);
	static Piece* createPiece(PieceType pieceType, int isWhite, std::pair<int, int> position);

};

class King : public Piece {

	bool hasMovedPosition;

public:
	bool hasMoved() { return this->hasMovedPosition; };
	void itMoved() { this->hasMovedPosition = true; }

	King();
	King(int color, int x, int y);
	King(int color, std::pair<int, int> position);
	bool isValidMove(std::list<Piece*> board, std::pair<int, int> endPosition) override;

};

class Queen : public Piece {

public:
	Queen();
	Queen(int color, int x, int y);
	Queen(int color, std::pair<int, int> position);
	bool isValidMove(std::list<Piece*> board, std::pair<int, int> endPosition) override;

};

class Bishop : public Piece {

public:
	Bishop();
	Bishop(int color, int x, int y);
	Bishop(int color, std::pair<int, int> position);
	bool isValidMove(std::list<Piece*> board, std::pair<int, int> endPosition) override;

};

class Knight : public Piece {

public:
	Knight();
	Knight(int color, int x, int y);
	Knight(int color, std::pair<int, int> position);
	bool isValidMove(std::list<Piece*> board, std::pair<int, int> endPosition) override;

};

class Rook : public Piece {

	bool hasMovedPosition;

public:
	bool hasMoved() { return this->hasMovedPosition; };
	void itMoved() { this->hasMovedPosition = true; }

	Rook();
	Rook(int color, int x, int y);
	Rook(int color, std::pair<int, int> position);
	bool isValidMove(std::list<Piece*> board, std::pair<int, int> endPosition) override;

};

class Pawn : public Piece {

	bool hasMovedPosition;

public:
	bool hasMoved() { return this->hasMovedPosition; };
	void itMoved() { this->hasMovedPosition = true; }

	Pawn();
	Pawn(int color, int x, int y);
	Pawn(int color, std::pair<int, int> position);
	bool isValidMove(std::list<Piece*> board, std::pair<int, int> endPosition) override;

};