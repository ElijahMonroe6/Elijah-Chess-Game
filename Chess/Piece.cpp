#include "Piece.h"
#include "Board.h"
#include "HelperFunctions.h"

using namespace std;

Piece::Piece() : color(1), position(-1, -1) {};
Piece::Piece(int color, int x, int y) : color(color), position(x, y) {};
Piece::Piece(int color, pair<int, int> position) : color(color), position(position) {};

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

Piece* Piece::createPiece(PieceType pieceType, int color, int x, int y) {

	Piece* retVal;

	switch (pieceType) {

	case PieceType::KING:
		retVal = new King(color, x, y);
		break;

	case PieceType::QUEEN:
		retVal = new Queen(color, x, y);
		break;

	case PieceType::BISHOP:
		retVal = new Bishop(color, x, y);
		break;

	case PieceType::KNIGHT:
		retVal = new Knight(color, x, y);
		break;

	case PieceType::ROOK:
		retVal = new Rook(color, x, y);
		break;

	case PieceType::PAWN:
		retVal = new Pawn(color, x, y);
		break;

	default:
		retVal = nullptr;
		break;

	}

	return retVal;

};

Piece* Piece::createPiece(PieceType pieceType, int color, pair<int, int> position) {

	Piece* retVal;

	switch (pieceType) {

	case PieceType::KING:
		retVal = new King(color, position);
		break;

	case PieceType::QUEEN:
		retVal = new Queen(color, position);
		break;

	case PieceType::BISHOP:
		retVal = new Bishop(color, position);
		break;

	case PieceType::KNIGHT:
		retVal = new Knight(color, position);
		break;

	case PieceType::ROOK:
		retVal = new Rook(color, position);
		break;

	case PieceType::PAWN:
		retVal = new Pawn(color, position);
		break;

	default:
		retVal = nullptr;
		break;

	}

	return retVal;

};

King::King() : Piece(), hasMoved(false) {};
King::King(int color, int x, int y) : Piece(color, x, y), hasMoved(false) {};
King::King(int color, std::pair<int, int> position) : Piece(color, position), hasMoved(false) {};

bool King::isValidMove(list<Piece*> board, pair<int, int> endPosition) {

	pair<int, int> curPosition = this->getPosition();
	pair<int, int> deltaEnd = HelperFunctions::delta(curPosition, endPosition);

	if (abs(deltaEnd.first) > 1 || abs(deltaEnd.second) > 1) return false;

	for (Piece* piece : board) {

		if (endPosition == piece->getPosition() && this->getColor() == piece->getColor()) return false;

	}

	return true;

};

Queen::Queen() : Piece() {};
Queen::Queen(int color, int x, int y) : Piece(color, x, y) {};
Queen::Queen(int color, std::pair<int, int> position) : Piece(color, position) {};

bool Queen::isValidMove(list<Piece*> board, pair<int, int> endPosition) {

	pair<int, int> curPosition = this->getPosition();
	pair<int, int> deltaEnd = HelperFunctions::delta(curPosition, endPosition);

	if (abs(deltaEnd.first) != abs(deltaEnd.second) && deltaEnd.first && deltaEnd.second) return false;

	for (Piece* piece : board) {

		pair<int, int> piecePosition = piece->getPosition();
		pair<int, int> deltaPiece = HelperFunctions::delta(curPosition, piecePosition);
		bool isParallel = acos(HelperFunctions::dot(deltaEnd, deltaPiece) / (HelperFunctions::magnitude(deltaEnd) * HelperFunctions::magnitude(deltaPiece))) == 0;//This doesn't really check if it is parallel, it actually checks if the angle between the vectors is zero which is a subset of parallel

		if (endPosition != piecePosition && isParallel) return false;
		if (this->getColor() == piece->getColor() && isParallel) return false;

	}

	return true;

};

Bishop::Bishop() : Piece() {};
Bishop::Bishop(int color, int x, int y) : Piece(color, x, y) {};
Bishop::Bishop(int color, std::pair<int, int> position) : Piece(color, position) {};

bool Bishop::isValidMove(list<Piece*> board, pair<int, int> endPosition) {

	pair<int, int> curPosition = this->getPosition();
	pair<int, int> deltaEnd = HelperFunctions::delta(curPosition, endPosition);

	if (abs(deltaEnd.first) != abs(deltaEnd.second)) return false;

	for (Piece* piece : board) {

		pair<int, int> piecePosition = piece->getPosition();
		pair<int, int> deltaPiece = HelperFunctions::delta(curPosition, piecePosition);
		bool isParallel = acos(HelperFunctions::dot(deltaEnd, deltaPiece) / (HelperFunctions::magnitude(deltaEnd) * HelperFunctions::magnitude(deltaPiece))) == 0;//This doesn't really check if it is parallel, it actually checks if the angle between the vectors is zero which is a subset of parallel

		if (endPosition != piecePosition && isParallel) return false;
		if (this->getColor() == piece->getColor() && isParallel) return false;

	}

	return true;

};

Knight::Knight() : Piece() {};
Knight::Knight(int color, int x, int y) : Piece(color, x, y) {};
Knight::Knight(int color, std::pair<int, int> position) : Piece(color, position) {};

bool Knight::isValidMove(list<Piece*> board, pair<int, int> endPosition) {

	pair<int, int> curPosition = this->getPosition();
	pair<int, int> distEnd = HelperFunctions::distance(curPosition, endPosition);

	if ((distEnd.first != 2 && distEnd.second != 2) || (distEnd.first != 1 && distEnd.second != 1)) return false;

	for (Piece* piece : board) {

		pair<int, int> piecePosition = piece->getPosition();

		if (endPosition == piecePosition && this->getColor() == piece->getColor()) return false;

	}

	return true;

};

Rook::Rook() : Piece(), hasMoved(false) {};
Rook::Rook(int color, int x, int y) : Piece(color, x, y), hasMoved(false) {};
Rook::Rook(int color, std::pair<int, int> position) : Piece(color, position), hasMoved(false) {};

bool Rook::isValidMove(list<Piece*> board, pair<int, int> endPosition) {

	pair<int, int> curPosition = this->getPosition();
	pair<int, int> deltaEnd = HelperFunctions::delta(curPosition, endPosition);

	if (deltaEnd.first != 0 && deltaEnd.second != 0) return false;

	for (Piece* piece : board) {

		pair<int, int> piecePosition = piece->getPosition();
		pair<int, int> deltaPiece = HelperFunctions::delta(curPosition, piecePosition);
		bool isParallel = acos(HelperFunctions::dot(deltaEnd, deltaPiece) / (HelperFunctions::magnitude(deltaEnd) * HelperFunctions::magnitude(deltaPiece))) == 0;//This doesn't really check if it is parallel, it actually checks if the angle between the vectors is zero which is a subset of parallel

		if (endPosition != piecePosition && isParallel) return false;
		if (this->getColor() == piece->getColor() && isParallel) return false;

	}

	return true;

};

Pawn::Pawn() : Piece(), hasMoved(false) {};
Pawn::Pawn(int color, int x, int y) : Piece(color, x, y), hasMoved(false) {};
Pawn::Pawn(int color, std::pair<int, int> position) : Piece(color, position), hasMoved(false) {};

bool Pawn::isValidMove(list<Piece*> board, pair<int, int> endPosition) {

	pair<int, int> curPosition = this->getPosition();
	pair<int, int> deltaEnd = HelperFunctions::delta(curPosition, endPosition);

	if (deltaEnd.first != 0 || deltaEnd.second != this->getColor()) return false;

	for (Piece* piece : board) {

		pair<int, int> piecePosition = piece->getPosition();

		if (endPosition == piecePosition) return false;

	}

	return true;

};