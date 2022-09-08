#include "Piece.h"
#include "HelperFunctions.h"

using namespace std;

Piece::Piece() : color(0), position(-1, -1) {};
Piece::Piece(int color, int x, int y) : color(color), position(x, y) {};
Piece::Piece(int color, pair<int, int> position) : color(color), position(position) {};

unordered_map<string, PieceType> stringToPieceType = { {"king", PieceType::KING}, {"queen", PieceType::QUEEN}, {"bishop", PieceType::BISHOP}, {"knight", PieceType::KNIGHT}, {"rook", PieceType::ROOK}, {"pawn", PieceType::PAWN}};

Piece* Piece::createPiece(string pieceType) {

	Piece* retVal;

	switch (stringToPieceType[pieceType]) {

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

Piece* Piece::createPiece(string pieceType, int color, int x, int y) {

	Piece* retVal;

	switch (stringToPieceType[pieceType]) {

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

Piece* Piece::createPiece(string pieceType, int color, pair<int, int> position) {

	Piece* retVal;

	switch (stringToPieceType[pieceType]) {

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

King::King() : Piece(), hasMovedPosition(false) {};
King::King(int color, int x, int y) : Piece(color, x, y), hasMovedPosition(false) {};
King::King(int color, pair<int, int> position) : Piece(color, position), hasMovedPosition(false) {};

bool King::isValidMove(list<Piece*> board, pair<int, int> endPosition) {

	pair<int, int> curPosition = this->getPosition();
	pair<int, int> distToEnd = HelperFunctions::distance(curPosition, endPosition);

	if (distToEnd.first > 1 || distToEnd.second > 1) return false;

	for (Piece* piece : board) {

		if (endPosition == piece->getPosition() && this->getColor() == piece->getColor() && this != piece) return false;

	}

	return true;

};

Queen::Queen() : Piece() {};
Queen::Queen(int color, int x, int y) : Piece(color, x, y) {};
Queen::Queen(int color, pair<int, int> position) : Piece(color, position) {};

bool Queen::isValidMove(list<Piece*> board, pair<int, int> endPosition) {

	pair<int, int> curPosition = this->getPosition();
	pair<int, int> deltaToEnd = HelperFunctions::delta(curPosition, endPosition);

	if (abs(deltaToEnd.first) != abs(deltaToEnd.second) && deltaToEnd.first && deltaToEnd.second) return false;

	for (Piece* piece : board) {

		if (this != piece) {

			pair<int, int> piecePosition = piece->getPosition();
			pair<int, int> deltaToPiece = HelperFunctions::delta(curPosition, piecePosition);
			bool isParallel = acos(HelperFunctions::dot(deltaToEnd, deltaToPiece) / (HelperFunctions::magnitude(deltaToEnd) * HelperFunctions::magnitude(deltaToPiece))) == 0;//This doesn't really check if it is parallel, it actually checks if the angle between the vectors is zero which is a subset of parallel

			if (endPosition != piecePosition && isParallel) return false;
			if (this->getColor() == piece->getColor() && isParallel) return false;

		}

	}

	return true;

};

Bishop::Bishop() : Piece() {};
Bishop::Bishop(int color, int x, int y) : Piece(color, x, y) {};
Bishop::Bishop(int color, pair<int, int> position) : Piece(color, position) {};

bool Bishop::isValidMove(list<Piece*> board, pair<int, int> endPosition) {

	pair<int, int> curPosition = this->getPosition();
	pair<int, int> deltaToEnd = HelperFunctions::delta(curPosition, endPosition);

	if (abs(deltaToEnd.first) != abs(deltaToEnd.second)) return false;

	for (Piece* piece : board) {

		if (this != piece) {

			pair<int, int> piecePosition = piece->getPosition();
			pair<int, int> deltaToPiece = HelperFunctions::delta(curPosition, piecePosition);
			bool isParallel = acos(HelperFunctions::dot(deltaToEnd, deltaToPiece) / (HelperFunctions::magnitude(deltaToEnd) * HelperFunctions::magnitude(deltaToPiece))) == 0;//This doesn't really check if it is parallel, it actually checks if the angle between the vectors is zero which is a subset of parallel

			if (endPosition != piecePosition && isParallel) return false;
			if (this->getColor() == piece->getColor() && isParallel) return false;

		}

	}

	return true;

};

Knight::Knight() : Piece() {};
Knight::Knight(int color, int x, int y) : Piece(color, x, y) {};
Knight::Knight(int color, pair<int, int> position) : Piece(color, position) {};

bool Knight::isValidMove(list<Piece*> board, pair<int, int> endPosition) {

	pair<int, int> curPosition = this->getPosition();
	pair<int, int> distEnd = HelperFunctions::distance(curPosition, endPosition);

	if ((distEnd.first != 2 && distEnd.second != 2) || (distEnd.first != 1 && distEnd.second != 1)) return false;

	for (Piece* piece : board) {

		if (this != piece) {

			pair<int, int> piecePosition = piece->getPosition();

			if (endPosition == piecePosition && this->getColor() == piece->getColor()) return false;

		}

	}

	return true;

};

Rook::Rook() : Piece(), hasMovedPosition(false) {};
Rook::Rook(int color, int x, int y) : Piece(color, x, y), hasMovedPosition(false) {};
Rook::Rook(int color, pair<int, int> position) : Piece(color, position), hasMovedPosition(false) {};

bool Rook::isValidMove(list<Piece*> board, pair<int, int> endPosition) {

	pair<int, int> curPosition = this->getPosition();
	pair<int, int> deltaToEnd = HelperFunctions::delta(curPosition, endPosition);

	if (deltaToEnd.first != 0 && deltaToEnd.second != 0) return false;

	for (Piece* piece : board) {

		if (this != piece) {

			pair<int, int> piecePosition = piece->getPosition();
			pair<int, int> deltaToPiece = HelperFunctions::delta(curPosition, piecePosition);
			bool isParallel = acos(HelperFunctions::dot(deltaToEnd, deltaToPiece) / (HelperFunctions::magnitude(deltaToEnd) * HelperFunctions::magnitude(deltaToPiece))) == 0;//This doesn't really check if it is parallel, it actually checks if the angle between the vectors is zero which is a subset of parallel

			if (endPosition != piecePosition && isParallel) return false;
			if (this->getColor() == piece->getColor() && isParallel) return false;

		}

	}

	return true;

};

Pawn::Pawn() : Piece(), hasMovedPosition(false) {};
Pawn::Pawn(int color, int x, int y) : Piece(color, x, y), hasMovedPosition(false) {};
Pawn::Pawn(int color, pair<int, int> position) : Piece(color, position), hasMovedPosition(false) {};

bool Pawn::isValidMove(list<Piece*> board, pair<int, int> endPosition) {

	pair<int, int> curPosition = this->getPosition();
	pair<int, int> deltaToEnd = HelperFunctions::delta(curPosition, endPosition);

	if (deltaToEnd.first != 0 || deltaToEnd.second != this->getColor()) return false;

	for (Piece* piece : board) {

		if (this != piece) {

			pair<int, int> piecePosition = piece->getPosition();

			if (endPosition == piecePosition) return false;

		}

	}

	return true;

};