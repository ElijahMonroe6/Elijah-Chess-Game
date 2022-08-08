#pragma once
#include <string>
#include <list>

enum class PieceType {KING,QUEEN,BISHOP,KNIGHT,ROOK,PAWN};

class Piece {

	std::string owner;
	std::pair<int, int> location;

public:
	std::string getOwner() { return this->owner; };
	void setOwner(std::string owner) { this->owner = owner; };
	std::pair<int, int> getLocation() { return this->location; };
	void setLocation() { this->location = location; };

	Piece();
	Piece(std::string owner, int x, int y);
	Piece(std::string owner, std::pair<int, int> location);
	virtual void getValidMoves(int width, int height, std::string owner, std::list<std::pair<std::pair<int, int>, std::pair<int, int>>> &validMoves) = 0;
	
	static Piece* createPiece(PieceType pieceType);
	static Piece* createPiece(PieceType pieceType, std::string owner, int x, int y);
	static Piece* createPiece(PieceType pieceType, std::string owner, std::pair<int, int> location);

};

class King : public Piece {

public:
	King();
	King(std::string owner, int x, int y);
	King(std::string owner, std::pair<int, int> location);
	void getValidMoves(int width, int height, std::string owner, std::list<std::pair<std::pair<int, int>, std::pair<int, int>>> &validMoves) override;

};

class Queen : public Piece {

public:
	Queen();
	Queen(std::string owner, int x, int y);
	Queen(std::string owner, std::pair<int, int> location);
	void getValidMoves(int width, int height, std::string owner, std::list<std::pair<std::pair<int, int>, std::pair<int, int>>> &validMoves) override;

};

class Bishop : public Piece {

public:
	Bishop();
	Bishop(std::string owner, int x, int y);
	Bishop(std::string owner, std::pair<int, int> location);
	void getValidMoves(int width, int height, std::string owner, std::list<std::pair<std::pair<int, int>, std::pair<int, int>>> &validMoves) override;

};

class Knight : public Piece {

public:
	Knight();
	Knight(std::string owner, int x, int y);
	Knight(std::string owner, std::pair<int, int> location);
	void getValidMoves(int width, int height, std::string owner, std::list<std::pair<std::pair<int, int>, std::pair<int, int>>> &validMoves) override;

};

class Rook : public Piece {

public:
	Rook();
	Rook(std::string owner, int x, int y);
	Rook(std::string owner, std::pair<int, int> location);
	void getValidMoves(int width, int height, std::string owner, std::list<std::pair<std::pair<int, int>, std::pair<int, int>>> &validMoves) override;

};

class Pawn : public Piece {

public:
	Pawn();
	Pawn(std::string owner, int x, int y);
	Pawn(std::string owner, std::pair<int, int> location);
	void getValidMoves(int width, int height, std::string owner, std::list<std::pair<std::pair<int, int>, std::pair<int, int>>> &validMoves) override;

};