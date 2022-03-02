#include "Queen.h"

ostream &operator<<(ostream &os, const Queen &queen) {
    os << static_cast<const Piece &>(queen);
    return os;
}

string Queen::getType() {
    return "QUEEN";
}


Queen::Queen(bool _isWhite, Position *position) {
    isWhite = _isWhite;
    currentPos = position;
}

vector<Position *> Queen::getAvailableMoves(vector<vector<Piece *>> board) {
	vector<Position *> moves;
	int line = Queen::getCurrentPos()->getLine() - 1;
	int column = Queen::getCurrentPos()->getColumn() - 'a';

	bool isWhite = Queen::getIsWhite();

	// right up 	=> line + 1 & column + 1
    for(int i = line + 1, j = column + 1; i < 8 && j < 8; i++, j++) {
    	int positionCheck = Piece::checkPosition(i, j, board, isWhite);
    	if(positionCheck >= 0 ) {
    		moves.push_back(board[i][j]->getCurrentPos());
    		if(positionCheck == 0) break;
    	}
    	else break;
    }

    // right down 	=> line - 1 & column + 1
    for(int i = line - 1, j = column + 1; i >= 0 && j < 8; i--, j++) {
    	int positionCheck = Piece::checkPosition(i, j, board, isWhite);
    	if(positionCheck >= 0 ) {
    		moves.push_back(board[i][j]->getCurrentPos());
    		if(positionCheck == 0) break;
    	}
    	else break;
    }

    // left up 		=> line + 1 & column - 1
    for(int i = line + 1, j = column - 1; i < 8 && j >= 0; i++, j--) {
    	int positionCheck = Piece::checkPosition(i, j, board, isWhite);
    	if(positionCheck >= 0 ) {
    		moves.push_back(board[i][j]->getCurrentPos());
    		if(positionCheck == 0) break;
    	}
    	else break;
    }

    // left down 	=> line - 1 & column - 1
    for(int i = line - 1, j = column - 1; i >= 0 && j >= 0; i--, j--) {
    	int positionCheck = Piece::checkPosition(i, j, board, isWhite);
    	if(positionCheck >= 0 ) {
    		moves.push_back(board[i][j]->getCurrentPos());
    		if(positionCheck == 0) break;
    	}
    	else break;
    }

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

double Queen::getPositionScore(bool isWhiteTurn) {
	if(isWhiteTurn) return weight + position_scores_white[this->getCurrentPos()->getLine() -
    1][this->getCurrentPos()->getColumn() - 'a'];
	return weight + position_scores_black[this->getCurrentPos()->getLine() -
    1][this->getCurrentPos()->getColumn() - 'a'];
}

Queen::Queen(Queen *other_queen) : Queen(other_queen->isWhite,
                                    new Position(other_queen->currentPos)) {}

int Queen::getWeight() {
    return this->weight;
}