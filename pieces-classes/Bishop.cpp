#include "Bishop.h"

ostream &operator<<(ostream &os, const Bishop &bishop) {
    os << static_cast<const Piece &>(bishop);
    return os;
}

string Bishop::getType() {
    return "BISHOP";
}

vector<Position *> Bishop::getAvailableMoves(vector<vector<Piece *>> board) {
    vector<Position *> moves;

    int line = Bishop::getCurrentPos()->getLine() - 1;
    int column = Bishop::getCurrentPos()->getColumn() - 'a';

    bool isWhite = Bishop::getIsWhite();
    // right up 	=> line + 1 & column + 1
    for (int i = line + 1, j = column + 1; i < 8 && j < 8; i++, j++) {
        int positionCheck = Piece::checkPosition(i, j, board, isWhite);
        if (positionCheck >= 0) {
            moves.push_back(board[i][j]->getCurrentPos());
            if (positionCheck == 0) break;
        } else break;
    }

    // right down 	=> line - 1 & column + 1
    for (int i = line - 1, j = column + 1; i >= 0 && j < 8; i--, j++) {
        int positionCheck = Piece::checkPosition(i, j, board, isWhite);
        if (positionCheck >= 0) {
            moves.push_back(board[i][j]->getCurrentPos());
            if (positionCheck == 0) break;
        } else break;
    }

    // left up 		=> line + 1 & column - 1
    for (int i = line + 1, j = column - 1; i < 8 && j >= 0; i++, j--) {
        int positionCheck = Piece::checkPosition(i, j, board, isWhite);
        if (positionCheck >= 0) {
            moves.push_back(board[i][j]->getCurrentPos());
            if (positionCheck == 0) break;
        } else break;
    }

    // left down 	=> line - 1 & column - 1
    for (int i = line - 1, j = column - 1; i >= 0 && j >= 0; i--, j--) {
        int positionCheck = Piece::checkPosition(i, j, board, isWhite);
        if (positionCheck >= 0) {
            moves.push_back(board[i][j]->getCurrentPos());
            if (positionCheck == 0) break;
        } else break;
    }

    return moves;
}

Bishop::Bishop(bool _isWhite, Position *position) {
    isWhite = _isWhite;
    currentPos = position;
}

double Bishop::getPositionScore(bool isWhiteTurn) {
    if (isWhiteTurn)
    return weight + position_scores_white[this->getCurrentPos()->getLine() - 1][
            this->getCurrentPos()->getColumn() - 'a'];
    return weight + position_scores_black[this->getCurrentPos()->getLine() - 1][
            this->getCurrentPos()->getColumn() - 'a'];
}

Bishop::Bishop(Bishop *other_bishop) : Bishop(other_bishop->isWhite,
                                              new Position
                                              (other_bishop->getCurrentPos())) {
}

int Bishop::getWeight() {
    return this->weight;
}