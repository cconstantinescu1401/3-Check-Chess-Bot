#include "King.h"
#include "Knight.h"
#include "Rook.h"
#include "Empty.h"
#include <iostream>

ostream &operator<<(ostream &os, const King &king) {
    os << static_cast<const Piece &>(king);
    return os;
}

string King::getType() {
    return "KING";
}

King::King(bool _isWhite, Position *position) {
    isWhite = _isWhite;
    currentPos = position;
    hasMoved = false;
}

vector<Position *> King::getAvailableMoves(vector<vector<Piece *>> board) {
    vector<Position *> moves;

    int line = King::getCurrentPos()->getLine() - 1;
    int column = King::getCurrentPos()->getColumn() - 'a';

    // ROCADA
    if (!King::hasMoved && !isInCheck(board)) {
        // rege alb

        if (King::isWhite) {
            
            // rocada mica
            if (board[line][column + 1]->getType() == "EMPTY" &&
                board[line][column + 2]->getType() == "EMPTY") {

                Position *oldpos = this->getCurrentPos();
                
                this->setCurrentPos(new Position(column + 1 + 'a', line + 1));
                
                
                board[line][column + 1] = this;
                board[line][column] =
                        new Empty(new Position(column + 'a', line + 1));    

                    
                if (isInCheck(board)) {
                    board[line][column + 1] =
                            new Empty(new Position(column + 1 + 'a', line + 1));
                    board[line][column] = this;
                    this->setCurrentPos(oldpos);
                } else {
                    this->setCurrentPos(
                            new Position(column + 2 + 'a', line + 1));
                    board[line][column + 2] = this;
                    board[line][column + 1] =
                            new Empty(new Position(column + 1 + 'a', line + 1));
                    bool canMakeCastlingMove = !isInCheck(board);
                    board[line][column + 2] =
                            new Empty(new Position(column + 2 + 'a', line + 1));
                    board[line][column + 1] =
                            new Empty(new Position(column + 1 + 'a', line + 1));
                    this->setCurrentPos(oldpos);
                    board[line][column] = this;

                    
                    if (canMakeCastlingMove &&
                        board[line][column + 3]->getType() == "ROOK" &&
                        board[line][column + 3]->getIsWhite() &&
                        !(((Rook *) board[line][column + 3])->getHasMoved()))
                        moves.push_back(
                                board[line][column + 2]->getCurrentPos());
                }
            }


            // rocada mare
            if (board[line][column - 1]->getType() == "EMPTY" &&
                board[line][column - 2]->getType() == "EMPTY") {
                Position *oldpos = this->getCurrentPos();
                this->setCurrentPos(new Position(column - 1 + 'a', line + 1));
                board[line][column - 1] = this;
                board[line][column] =
                        new Empty(new Position(column + 'a', line + 1));
                if (isInCheck(board)) {
                    board[line][column - 1] =
                            new Empty(new Position(column - 1 + 'a', line + 1));
                    this->setCurrentPos(oldpos);
                    board[line][column] = this;
                } else {
                    this->setCurrentPos(
                            new Position(column - 2 + 'a', line + 1));
                    board[line][column - 2] = this;
                    board[line][column - 1] =
                            new Empty(new Position(column - 1 + 'a', line + 1));
                    bool canMakeCastlingMove = !isInCheck(board);
                    board[line][column - 2] =
                            new Empty(new Position(column - 2 + 'a', line + 1));
                    board[line][column - 1] =
                            new Empty(new Position(column - 1 + 'a', line + 1));
                    this->setCurrentPos(oldpos);
                    board[line][column] = this;

                    if (canMakeCastlingMove &&
                        board[line][column - 3]->getType() == "EMPTY" &&
                        board[line][column - 4]->getType() == "ROOK" &&
                        board[line][column - 4]->getIsWhite() &&
                        !(((Rook *) board[line][column - 4])->getHasMoved()))
                        moves.push_back(
                                board[line][column - 2]->getCurrentPos());
                }
            }

            // rege negru
        } else {

            // rocada mica
            if (board[line][column + 1]->getType() == "EMPTY" &&
                board[line][column + 2]->getType() == "EMPTY") {
                Position *oldpos = this->getCurrentPos();
                this->setCurrentPos(new Position(column + 1 + 'a', line + 1));
                board[line][column + 1] = this;
                board[line][column] =
                        new Empty(new Position(column + 'a', line + 1));
                if (isInCheck(board)) {
                    board[line][column + 1] =
                            new Empty(new Position(column + 1 + 'a', line + 1));
                    board[line][column] = this;
                    this->setCurrentPos(oldpos);
                } else {
                    this->setCurrentPos(
                            new Position(column + 2 + 'a', line + 1));
                    board[line][column + 2] = this;
                    board[line][column + 1] =
                            new Empty(new Position(column + 1 + 'a', line + 1));
                    bool canMakeCastlingMove = !isInCheck(board);
                    board[line][column + 2] =
                            new Empty(new Position(column + 2 + 'a', line + 1));
                    board[line][column + 1] =
                            new Empty(new Position(column + 1 + 'a', line + 1));
                    this->setCurrentPos(oldpos);
                    board[line][column] = this;

                    if (canMakeCastlingMove &&
                        board[line][column + 3]->getType() == "ROOK" &&
                        !(board[line][column + 3]->getIsWhite()) &&
                        !(((Rook *) board[line][column + 3])->getHasMoved()))
                        moves.push_back(
                                board[line][column + 2]->getCurrentPos());
                }
            }


            // rocada mare
            if (board[line][column - 1]->getType() == "EMPTY" &&
                board[line][column - 2]->getType() == "EMPTY") {
                Position *oldpos = this->getCurrentPos();
                this->setCurrentPos(new Position(column - 1 + 'a', line + 1));
                board[line][column - 1] = this;
                board[line][column] =
                        new Empty(new Position(column + 'a', line + 1));
                if (isInCheck(board)) {
                    board[line][column - 1] =
                            new Empty(new Position(column - 1 + 'a', line + 1));
                    this->setCurrentPos(oldpos);
                    board[line][column] = this;
                } else {
                    this->setCurrentPos(
                            new Position(column - 2 + 'a', line + 1));
                    board[line][column - 2] = this;
                    board[line][column - 1] =
                            new Empty(new Position(column - 1 + 'a', line + 1));
                    bool canMakeCastlingMove = !isInCheck(board);
                    board[line][column - 2] =
                            new Empty(new Position(column - 2 + 'a', line + 1));
                    board[line][column - 1] =
                            new Empty(new Position(column - 1 + 'a', line + 1));
                    this->setCurrentPos(oldpos);
                    board[line][column] = this;

                    if (canMakeCastlingMove &&
                        board[line][column - 3]->getType() == "EMPTY" &&
                        board[line][column - 4]->getType() == "ROOK" &&
                        !(board[line][column - 4]->getIsWhite()) &&
                        !(((Rook *) board[line][column - 4])->getHasMoved()))
                        moves.push_back(
                                board[line][column - 2]->getCurrentPos());
                }
            }
        }
    }

    // OTHER MOVES
    for (int i = 0; i < 8; i++) {
        if (Piece::checkPosition(line + King::dl[i], column + King::dc[i],
                                 board, King::getIsWhite()) >= 0)
            moves.push_back(board[line + King::dl[i]][column + King::dc[i]]
                                    ->getCurrentPos());
    }

    return moves;
}

bool King::isInCheck(const vector<vector<Piece *>> &boardMatrix) {
    return lineCheck(boardMatrix) || diagonalCheck(boardMatrix) ||
           cornerCheck(boardMatrix) || lCheck(boardMatrix) ||
           kissingKingsCheck(boardMatrix);
}

bool King::lineCheck(const vector<vector<Piece *>> &boardMatrix) {
    int kingLine = getCurrentPos()->getLine() - 1;
    int kingColumn = getCurrentPos()->getColumn() - 'a';

    //find first piece up
    for (int i = kingLine + 1; i < 8; i++) {
        Piece *currentPiece = boardMatrix[i][kingColumn];
        if (checkPossbileThreat(currentPiece, "") == "DEFENDER" ||
            (checkPossbileThreat(currentPiece, "ROOK") == "NON-THREAT" &&
             checkPossbileThreat(currentPiece, "QUEEN") == "NON-THREAT"))
            break;
        else if (checkPossbileThreat(currentPiece, "ROOK") == "THREAT" ||
                 checkPossbileThreat(currentPiece, "QUEEN") == "THREAT")
            return true;
    }

    //find first piece down
    for (int i = kingLine - 1; i >= 0; i--) {
        Piece *currentPiece = boardMatrix[i][kingColumn];
        if (checkPossbileThreat(currentPiece, "") == "DEFENDER" ||
            (checkPossbileThreat(currentPiece, "ROOK") == "NON-THREAT" &&
             checkPossbileThreat(currentPiece, "QUEEN") == "NON-THREAT"))
            break;
        else if (checkPossbileThreat(currentPiece, "ROOK") == "THREAT" ||
                 checkPossbileThreat(currentPiece, "QUEEN") == "THREAT")
            return true;
    }

    //find first piece left
    for (int j = kingColumn - 1; j >= 0; j--) {
        Piece *currentPiece = boardMatrix[kingLine][j];
        if (checkPossbileThreat(currentPiece, "") == "DEFENDER" ||
            (checkPossbileThreat(currentPiece, "ROOK") == "NON-THREAT" &&
             checkPossbileThreat(currentPiece, "QUEEN") == "NON-THREAT"))
            break;
        else if (checkPossbileThreat(currentPiece, "ROOK") == "THREAT" ||
                 checkPossbileThreat(currentPiece, "QUEEN") == "THREAT")
            return true;
    }

    //find first piece right
    for (int j = kingColumn + 1; j < 8; j++) {
        Piece *currentPiece = boardMatrix[kingLine][j];
        if (checkPossbileThreat(currentPiece, "") == "DEFENDER" ||
            (checkPossbileThreat(currentPiece, "ROOK") == "NON-THREAT" &&
             checkPossbileThreat(currentPiece, "QUEEN") == "NON-THREAT"))
            break;
        else if (checkPossbileThreat(currentPiece, "ROOK") == "THREAT" ||
                 checkPossbileThreat(currentPiece, "QUEEN") == "THREAT")
            return true;
    }

    return false;
}

bool King::diagonalCheck(const vector<vector<Piece *>> &boardMatrix) {
    int kingLine = getCurrentPos()->getLine() - 1;
    int kingColumn = getCurrentPos()->getColumn() - 'a';

    //find first piece up right
    for (int i = kingLine + 1, j = kingColumn + 1; i < 8 && j < 8; i++, j++) {
        Piece *currentPiece = boardMatrix[i][j];
        if (checkPossbileThreat(currentPiece, "") == "DEFENDER" ||
            (checkPossbileThreat(currentPiece, "BISHOP") == "NON-THREAT" &&
             checkPossbileThreat(currentPiece, "QUEEN") == "NON-THREAT"))
            break;
        else if (checkPossbileThreat(currentPiece, "BISHOP") == "THREAT" ||
                 checkPossbileThreat(currentPiece, "QUEEN") == "THREAT")
            return true;
    }

    //find first piece up left
    for (int i = kingLine + 1, j = kingColumn - 1; i < 8 && j >= 0; i++, j--) {
        Piece *currentPiece = boardMatrix[i][j];
        if (checkPossbileThreat(currentPiece, "") == "DEFENDER" ||
            (checkPossbileThreat(currentPiece, "BISHOP") == "NON-THREAT" &&
             checkPossbileThreat(currentPiece, "QUEEN") == "NON-THREAT"))
            break;
        else if (checkPossbileThreat(currentPiece, "BISHOP") == "THREAT" ||
                 checkPossbileThreat(currentPiece, "QUEEN") == "THREAT")
            return true;
    }

    //find first piece down right
    for (int i = kingLine - 1, j = kingColumn + 1; i >= 0 && j < 8; i--, j++) {
        Piece *currentPiece = boardMatrix[i][j];
        if (checkPossbileThreat(currentPiece, "") == "DEFENDER" ||
            (checkPossbileThreat(currentPiece, "BISHOP") == "NON-THREAT" &&
             checkPossbileThreat(currentPiece, "QUEEN") == "NON-THREAT"))
            break;
        else if (checkPossbileThreat(currentPiece, "BISHOP") == "THREAT" ||
                 checkPossbileThreat(currentPiece, "QUEEN") == "THREAT")
            return true;
    }

    //find first piece down left
    for (int i = kingLine - 1, j = kingColumn - 1; i >= 0 && j >= 0; i--, j--) {
        Piece *currentPiece = boardMatrix[i][j];
        if (checkPossbileThreat(currentPiece, "") == "DEFENDER" ||
            (checkPossbileThreat(currentPiece, "BISHOP") == "NON-THREAT" &&
             checkPossbileThreat(currentPiece, "QUEEN") == "NON-THREAT"))
            break;
        else if (checkPossbileThreat(currentPiece, "BISHOP") == "THREAT" ||
                 checkPossbileThreat(currentPiece, "QUEEN") == "THREAT")
            return true;
    }

    return false;
}

bool King::cornerCheck(const vector<vector<Piece *>> &boardMatrix) {
    int kingLine = getCurrentPos()->getLine() - 1;
    int kingColumn = getCurrentPos()->getColumn() - 'a';

    //up right corner
    if (kingLine != 7 && kingColumn != 7) {
        Piece *currentPiece = boardMatrix[kingLine + 1][kingColumn + 1];
        if (checkPossbileThreat(currentPiece, "PAWN") == "THREAT" ||
            checkPossbileThreat(currentPiece, "KING") == "THREAT")
            return true;
    }

    //up left corner
    if (kingLine != 7 && kingColumn != 0) {
        Piece *currentPiece = boardMatrix[kingLine + 1][kingColumn - 1];
        if (checkPossbileThreat(currentPiece, "PAWN") == "THREAT" ||
            checkPossbileThreat(currentPiece, "KING") == "THREAT")
            return true;
    }

    //down right corner
    if (kingLine != 0 && kingColumn != 7) {
        Piece *currentPiece = boardMatrix[kingLine - 1][kingColumn + 1];
        if (checkPossbileThreat(currentPiece, "PAWN") == "THREAT" ||
            checkPossbileThreat(currentPiece, "KING") == "THREAT")
            return true;
    }

    //down left corner
    if (kingLine != 0 && kingColumn != 0) {
        Piece *currentPiece = boardMatrix[kingLine - 1][kingColumn - 1];
        if (checkPossbileThreat(currentPiece, "PAWN") == "THREAT" ||
            checkPossbileThreat(currentPiece, "KING") == "THREAT")
            return true;
    }

    return false;
}

bool King::kissingKingsCheck(const vector<vector<Piece *>> &boardMatrix) {
    int kingLine = getCurrentPos()->getLine() - 1;
    int kingColumn = getCurrentPos()->getColumn() - 'a';

    //up
    if (kingLine != 7) {
        Piece *currentPiece = boardMatrix[kingLine + 1][kingColumn];
        if (checkPossbileThreat(currentPiece, "KING") == "THREAT")
            return true;
    }

    //down
    if (kingLine != 0) {
        Piece *currentPiece = boardMatrix[kingLine - 1][kingColumn];
        if (checkPossbileThreat(currentPiece, "KING") == "THREAT")
            return true;
    }

    //left
    if (kingColumn != 0) {
        Piece *currentPiece = boardMatrix[kingLine][kingColumn - 1];
        if (checkPossbileThreat(currentPiece, "KING") == "THREAT")
            return true;
    }

    //right
    if (kingColumn != 7) {
        Piece *currentPiece = boardMatrix[kingLine][kingColumn + 1];
        if (checkPossbileThreat(currentPiece, "KING") == "THREAT")
            return true;
    }

    return false;
}

bool King::lCheck(const vector<vector<Piece *>> &boardMatrix) {
    int kingLine = getCurrentPos()->getLine() - 1;
    int kingColumn = getCurrentPos()->getColumn() - 'a';

    for (int i = 0; i < 8; i++) {
        int possibleKnightLine = kingLine + Knight().getDl()[i];
        int possibleKnightColumn = kingColumn + Knight().getDc()[i];

        if (checkPosition(possibleKnightLine, possibleKnightColumn, boardMatrix,
                          getIsWhite()) >= 0) {
            Piece *currentPiece =
                    boardMatrix[possibleKnightLine][possibleKnightColumn];
            if (checkPossbileThreat(currentPiece, "KNIGHT") == "THREAT")
                return true;
        }
    }

    return false;
}

string
King::checkPossbileThreat(Piece *possbileThreat, const string &threatType) {
    if (possbileThreat->getType() == "EMPTY") {
        return "EMPTY";
    }
    if (possbileThreat->isSameColor(this)) {
        return "DEFENDER";
    }
    if (possbileThreat->getType() == threatType) {
        return "THREAT";
    }
    return "NON-THREAT";
}

bool King::getHasMoved() const {
    return hasMoved;
}

void King::setHasMoved(bool _hasMoved) {
    King::hasMoved = _hasMoved;
}

double King::getPositionScore(bool isWhiteTurn) {
    if (isWhiteTurn) return weight + position_scores_white[this->getCurrentPos()->getLine() - 1][
    this->getCurrentPos()->getColumn() - 'a'];
    
    return weight + position_scores_black[this->getCurrentPos()->getLine() - 1][
            this->getCurrentPos()->getColumn() - 'a'];
}

King::King(bool _isWhite, bool _hasMoved, Position *position) {
    isWhite = _isWhite;
    currentPos = position;
    hasMoved = _hasMoved;
}

King::King(bool _isWhite, bool _hasMoved, Position *position, int _times_in_check) {
    isWhite = _isWhite;
    currentPos = position;
    hasMoved = _hasMoved;
    times_in_check = _times_in_check;
}


King::King(King *other_king) : King(other_king->isWhite, other_king->hasMoved,
                                  new Position(other_king->currentPos),
                                  other_king->times_in_check) {}

int King::getWeight() {
    return this->weight;
}

void King::incrementTimesInCheck() {
    times_in_check = times_in_check + 1;
}