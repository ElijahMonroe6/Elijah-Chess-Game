#include "Piece.h"

using namespace std;

Piece::Piece() : owner("none"), location(-1, -1) {};
Piece::Piece(string owner, int x, int y) : owner("none"), location(x, y) {};
Piece::Piece(string owner, pair<int, int> location) : owner(owner), location(location) {};

Piece* Piece::createPiece(PieceType pieceType) {

	Piece* retVal;

	switch (pieceType) {

	case PieceType::KING:
		retVal = new King();
		break;

	case PieceType::QUEEN:
		retVal = new Queen();
		break;

	case PieceType::BISHOP:
		retVal = new Bishop();
		break;

	case PieceType::KNIGHT:
		retVal = new Knight();
		break;

	case PieceType::ROOK:
		retVal = new Rook();
		break;

	case PieceType::PAWN:
		retVal = new Pawn();
		break;

	default:
		retVal = nullptr;
		break;

	}

	return retVal;

};

Piece* Piece::createPiece(PieceType pieceType, string owner, int x, int y) {

	Piece* retVal;

	switch (pieceType) {

	case PieceType::KING:
		retVal = new King(owner, x, y);
		break;

	case PieceType::QUEEN:
		retVal = new Queen(owner, x, y);
		break;

	case PieceType::BISHOP:
		retVal = new Bishop(owner, x, y);
		break;

	case PieceType::KNIGHT:
		retVal = new Knight(owner, x, y);
		break;

	case PieceType::ROOK:
		retVal = new Rook(owner, x, y);
		break;

	case PieceType::PAWN:
		retVal = new Pawn(owner, x, y);
		break;

	default:
		retVal = nullptr;
		break;

	}

	return retVal;

};

Piece* Piece::createPiece(PieceType pieceType, string owner, pair<int, int> location) {

	Piece* retVal;

	switch (pieceType) {

	case PieceType::KING:
		retVal = new King(owner, location);
		break;

	case PieceType::QUEEN:
		retVal = new Queen(owner, location);
		break;

	case PieceType::BISHOP:
		retVal = new Bishop(owner, location);
		break;

	case PieceType::KNIGHT:
		retVal = new Knight(owner, location);
		break;

	case PieceType::ROOK:
		retVal = new Rook(owner, location);
		break;

	case PieceType::PAWN:
		retVal = new Pawn(owner, location);
		break;

	default:
		retVal = nullptr;
		break;

	}

	return retVal;

};

King::King() : Piece() {};
King::King(std::string owner, int x, int y) : Piece(owner, x, y) {};
King::King(std::string owner, std::pair<int, int> location) : Piece(owner, location) {};

void King::getValidMoves(int width, int height, string player, list<pair<pair<int, int>, pair<int, int>>> &validMoves) {

	int x = this->getLocation().first;
	int y = this->getLocation().second;

	for (int i = -1; i <= 1; i++) {

		for (int j = -1; j <= 1; j++) {

			int newX = x + i;
			int newY = y + j;

			if (newX >= 0 && newY >= 0 && newX < width && newY < height && this->getOwner() == player) {

				validMoves.push_back(make_pair(this->getLocation(), make_pair(newX, newY)));

			}

		}

	}

};

Queen::Queen() : Piece() {};
Queen::Queen(std::string owner, int x, int y) : Piece(owner, x, y) {};
Queen::Queen(std::string owner, std::pair<int, int> location) : Piece(owner, location) {};

void Queen::getValidMoves(int width, int height, string player, list<pair<pair<int, int>, pair<int, int>>>& validMoves) {

	int x = this->getLocation().first;
	int y = this->getLocation().second;
	int deltaX = 1;
	int deltaY = 1;

	while(x + deltaX < width || y + deltaY < height || x - deltaX > 0 || y - deltaY > 0){

		int newX = x + deltaX;
		int newY = y + deltaY;
		
		if (newX >= 0 && newY >= 0 && newX < width && newY < height && this->getOwner() == player) {

			validMoves.push_back(make_pair(this->getLocation(), make_pair(newX, newY)));

		}

	}

};

Bishop::Bishop() : Piece() {};
Bishop::Bishop(std::string owner, int x, int y) : Piece(owner, x, y) {};
Bishop::Bishop(std::string owner, std::pair<int, int> location) : Piece(owner, location) {};

Knight::Knight() : Piece() {};
Knight::Knight(std::string owner, int x, int y) : Piece(owner, x, y) {};
Knight::Knight(std::string owner, std::pair<int, int> location) : Piece(owner, location) {};

Rook::Rook() : Piece() {};
Rook::Rook(std::string owner, int x, int y) : Piece(owner, x, y) {};
Rook::Rook(std::string owner, std::pair<int, int> location) : Piece(owner, location) {};

Pawn::Pawn() : Piece() {};
Pawn::Pawn(std::string owner, int x, int y) : Piece(owner, x, y) {};
Pawn::Pawn(std::string owner, std::pair<int, int> location) : Piece(owner, location) {};