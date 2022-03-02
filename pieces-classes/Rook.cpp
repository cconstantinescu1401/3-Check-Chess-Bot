#include "Rook.h"
#include <iostream>

ostream &operator<<(ostream &os, const Rook &rook) {
    os << static_cast<const Piece &>(rook);
    return os;
}

string Rook::getType() {
    return "ROOK";
}

vector<Position *> Rook::getAvailableMoves(vector<vector<Piece *>> board) {
    vector<Position*> moves;

    int line = Rook::getCurrentPos()->getLine() - 1;
    int column = Rook::getCurrentPos()->getColumn() - 'a';

    bool isWhite = Rook::getIsWhite();

    // left 	=> 	column - 1
    for(int j = column - 1; j >= 0; j--) {
    	int positionCheck = Piece::checkPosition(line, j, board, isWhite);
    	if(positionCheck >= 0) {
    		moves.push_back(board[line][j]->getCurrentPos());
    		if(positionCheck == 0) break;
    	}
    	else break;
    }

    // right	=> 	column + 1
    for(int j = column + 1; j < 8; j++) {
    	int positionCheck = Piece::checkPosition(line, j, board, isWhite);
    	if(positionCheck >= 0) {
    		moves.push_back(board[line][j]->getCurrentPos());
    		if(positionCheck == 0) break;
    	}
    	else break;
    }

    // up 		=> 	line + 1
    for(int i = line + 1; i < 8; i++) {
    	int positionCheck = Piece::checkPosition(i, column, board, isWhite);
    	if(positionCheck >= 0) {
    		moves.push_back(board[i][column]->getCurrentPos());
    		if(positionCheck == 0) break;
    	}
    	else break;
    }

    // down 	=> 	line - 1
    for(int i = line - 1; i >= 0; i--) {
    	int positionCheck = Piece::checkPosition(i, column, board, isWhite);
    	if(positionCheck >= 0) {
    		moves.push_back(board[i][column]->getCurrentPos());
    		if(positionCheck == 0) break;
    	}
    	else break;
    }

    return moves;
}

Rook::Rook(bool _isWhite, Position *position) {
    isWhite = _isWhite;
    currentPos = position;
    hasMoved = false;
}

bool Rook::getHasMoved() const {
    return hasMoved;
}

void Rook::setHasMoved(bool _hasMoved) {
    Rook::hasMoved = _hasMoved;
}

double Rook::getPositionScore(bool isWhiteTurn) {
    if(isWhiteTurn) return weight + position_scores_white[this->getCurrentPos()->getLine() -
    1][this->getCurrentPos()->getColumn() - 'a'];
    return weight + position_scores_black[this->getCurrentPos()->getLine() -
    1][this->getCurrentPos()->getColumn() - 'a'];
}

Rook::Rook(bool _isWhite, bool _hasMoved, Position *position) {
    isWhite = _isWhite;
    currentPos = position;
    hasMoved = _hasMoved;
}


Rook::Rook(Rook *other_rook) : Rook(other_rook->isWhite, other_rook->hasMoved,
                                         new Position(other_rook->currentPos)) {}

int Rook::getWeight() {
    return this->weight;
}