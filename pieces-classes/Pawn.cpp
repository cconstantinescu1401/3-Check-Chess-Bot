#include "Pawn.h"

Pawn::Pawn(bool _isWhite, Position *position) {
    isWhite = _isWhite;
    currentPos = position;
    twoStepsStart = 0;
}

ostream &operator<<(ostream &os, const Pawn &pawn) {
    os << static_cast<const Piece &>(pawn);
    return os;
}

vector<Position *> Pawn::getAvailableMoves(vector<vector<Piece*>> board) {
    vector<Position*> moves;
    int line = Pawn::getCurrentPos()->getLine() - 1;
    int column = Pawn::getCurrentPos()->getColumn() - 'a';

    // for white pawns
    if(Pawn::getIsWhite()) {
        if (board[line + 1][column]->getType() == "EMPTY") {
            moves.push_back(board[line + 1][column]->getCurrentPos());
            if (line == 1 && board[line + 2][column]->getType() == "EMPTY")
                moves.push_back(board[line + 2][column]->getCurrentPos());
        }

        if (column != 0 && board[line + 1][column - 1]->getType() != "EMPTY" &&
            !board[line + 1][column - 1]->getIsWhite())
            moves.push_back(board[line + 1][column - 1]->getCurrentPos());

        if (column != 7 && board[line + 1][column + 1]->getType() != "EMPTY" &&
            !board[line + 1][column + 1]->getIsWhite())
            moves.push_back(board[line + 1][column + 1]->getCurrentPos());

        // en Passant Part
        // try to do it in the left part
        if (column != 0) {
            Piece *piece = board[line][column - 1];
            if (piece->getType() == "PAWN" && !piece->getIsWhite() &&
                ((Pawn *) piece)->getTwoStepsStart() == 1) {
                moves.push_back(board[line + 1][column - 1]->getCurrentPos());
            }
        }

        // try to do it in the right part
        if (column != 7) {
            Piece *piece = board[line][column + 1];
            if (piece->getType() == "PAWN" && !piece->getIsWhite() &&
                ((Pawn *) piece)->getTwoStepsStart() == 1) {
                moves.push_back(board[line + 1][column + 1]->getCurrentPos());
            }
        }
        // if the pawn is black
    } else {
        if(board[line - 1][column]->getType() == "EMPTY") {
            moves.push_back(board[line - 1][column]->getCurrentPos());
            if (line == 6 && board[line - 2][column]->getType() == "EMPTY")
                moves.push_back(board[line - 2][column]->getCurrentPos());
        }

        if(column != 0 && board[line - 1][column - 1]->getType() != "EMPTY" &&
           board[line - 1][column - 1]->getIsWhite())
            moves.push_back(board[line - 1][column - 1]->getCurrentPos());

        if(column != 7 && board[line - 1][column + 1]->getType() != "EMPTY" &&
           board[line - 1][column + 1]->getIsWhite())
            moves.push_back(board[line - 1][column + 1]->getCurrentPos());

        // en Passant Part
        if (column != 0) {
            Piece *piece = board[line][column - 1];
            if (piece->getType() == "PAWN" && piece->getIsWhite() && ((Pawn *)piece)->getTwoStepsStart() == 1) {
                moves.push_back(board[line - 1][column - 1]->getCurrentPos());
            }
        }

        if (column != 7) {
            Piece *piece = board[line][column + 1];
            if (piece->getType() == "PAWN" && piece->getIsWhite() && ((Pawn *)
            piece)->getTwoStepsStart() == 1) {
                moves.push_back(board[line - 1][column + 1]->getCurrentPos());
            }
        }
    }
    return moves;
}

string Pawn::getType() {
    return "PAWN";
}

double Pawn::getPositionScore(bool isWhiteTurn) {
    if(isWhiteTurn) return weight + position_scores_white[this->getCurrentPos()->getLine() -
    1][this->getCurrentPos()->getColumn() - 'a'];
    return weight + position_scores_black[this->getCurrentPos()->getLine() -
    1][this->getCurrentPos()->getColumn() - 'a'];
}

int Pawn::getTwoStepsStart() {
    return this->twoStepsStart;
}


void Pawn::setTwoStepsStart(int __twoStepsStart) {
    this->twoStepsStart = __twoStepsStart;
}

Pawn::Pawn(bool _isWhite, int _twoStepsStart, Position *position) {
    isWhite = _isWhite;
    currentPos = position;
    twoStepsStart = _twoStepsStart;
}

Pawn::Pawn(Pawn *other_pawn) : Pawn(other_pawn->isWhite, other_pawn->twoStepsStart,
                                              new Position(other_pawn->currentPos)) {}

int Pawn::getWeight() {
    return this->weight;
}