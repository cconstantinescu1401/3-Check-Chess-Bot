#include <iostream>
#include "Board.h"

Piece* Board::generateCorrectPiece(Piece* piece) {
    string type = piece->getType();
    if (type == "BISHOP") {
        return new Bishop((Bishop*)piece);
    }
    else if (type == "KING") {
        return new King((King*)piece);
    }
    else if (type == "KNIGHT") {
        return new Knight((Knight*)piece);
    }
    else if (type == "PAWN") {
        return new Pawn((Pawn*)piece);
    }
    else if (type == "QUEEN") {
        return new Queen((Queen*)piece);
    }
    else if (type == "ROOK") {
        return new Rook((Rook*)piece);
    }
    else if (type == "EMPTY") {
        return new Empty((Empty*)piece);
    }
    return new Empty((Empty*)piece);
}

Board::Board(Board *other_board) {
    for (int i = 0; i < 8; i++) {
        vector<Piece*> newLine;
        for (int j = 0; j < 8; j++) {
            Piece* current_piece = other_board->boardMatrix[i][j];
            Piece* newPiece = generateCorrectPiece(current_piece);
            newLine.push_back(newPiece);

            if (current_piece->getType() != "EMPTY") {
                if (current_piece->getIsWhite()) {
                    whitePiecesList.push_back(newPiece);
                } else {
                    blackPiecesList.push_back(newPiece);
                }
            }
        }
        boardMatrix.push_back(newLine);
    }
}

void Board::initBoard() {
    boardMatrix.clear();

    // generate pieces
    vector<vector<Piece *>> tableGame;
    vector<Piece *> whitePawns = pawnsArrayGen(true);
    vector<Piece *> blackPawns = pawnsArrayGen(false);
    vector<Piece *> whiteLine = pieceWhiteLineGen();
    vector<Piece *> blackLine = pieceBlackLineGen();

    // push white
    boardMatrix.push_back(whiteLine);
    boardMatrix.push_back(whitePawns);

    // push empty spaces
    for (int i = 0; i < 4; i++) {
        vector<Piece *> emptyLine;
        emptyLine.reserve(8);
        for (int j = 0; j < 8; j++)
            emptyLine.push_back(
                    new Empty(new Position((char) ('a' + j), i + 3)));
        boardMatrix.push_back(emptyLine);
    }

    // push black pieces
    boardMatrix.push_back(blackPawns);
    boardMatrix.push_back(blackLine);

    // init pieces vectors
    Board::initPieceList();
}

void Board::initPieceList() {
    whitePiecesList = boardMatrix[1];
    whitePiecesList.insert(whitePiecesList.end(), Board::boardMatrix[0].begin(),
                           boardMatrix[0].end());

    Board::blackPiecesList = Board::boardMatrix[6];
    Board::blackPiecesList
            .insert(Board::blackPiecesList.end(), Board::boardMatrix[7].begin(),
                    Board::boardMatrix[7].end());
}

void Board::setBoardMatrix(const vector<vector<Piece *>> &this_board) {
    Board::boardMatrix = this_board;
}


vector<Piece *> Board::pawnsArrayGen(bool isWhite) {
    vector<Piece *> pawns;
    int WOB = isWhite ? 2 : 7;
    for (int i = 0; i < 8; i++) {
        Pawn *pawn = new Pawn(isWhite, new Position((char) ('a' + i), WOB));
        pawns.push_back(pawn);
    }
    return pawns;
}

vector<Piece *> Board::pieceWhiteLineGen() {
    vector<Piece *> whiteLine;
    whiteLine.push_back(new Rook(true, new Position('a', 1)));
    whiteLine.push_back(new Knight(true, new Position('b', 1)));
    whiteLine.push_back(new Bishop(true, new Position('c', 1)));
    whiteLine.push_back(new Queen(true, new Position('d', 1)));
    whiteLine.push_back(new King(true, new Position('e', 1)));
    whiteLine.push_back(new Bishop(true, new Position('f', 1)));
    whiteLine.push_back(new Knight(true, new Position('g', 1)));
    whiteLine.push_back(new Rook(true, new Position('h', 1)));
    return whiteLine;
}

vector<Piece *> Board::pieceBlackLineGen() {
    vector<Piece *> blackLine;
    blackLine.push_back(new Rook(false, new Position('a', 8)));
    blackLine.push_back(new Knight(false, new Position('b', 8)));
    blackLine.push_back(new Bishop(false, new Position('c', 8)));
    blackLine.push_back(new Queen(false, new Position('d', 8)));
    blackLine.push_back(new King(false, new Position('e', 8)));
    blackLine.push_back(new Bishop(false, new Position('f', 8)));
    blackLine.push_back(new Knight(false, new Position('g', 8)));
    blackLine.push_back(new Rook(false, new Position('h', 8)));
    return blackLine;
}

ostream &operator<<(ostream &os, const Board &board) {

    return os;
}

const vector<Piece *> &Board::getWhitePiecesList() const {
    return whitePiecesList;
}

void Board::setPPListWhite(const vector<Piece *> &pPListWhite) {
    whitePiecesList = pPListWhite;
}

const vector<Piece *> &Board::getBlackPiecesList() const {
    return blackPiecesList;
}

void Board::setPPListBlack(const vector<Piece *> &pPListBlack) {
    blackPiecesList = pPListBlack;
}

const vector<vector<Piece *>> &Board::getBoardMatrix() const {
    return boardMatrix;
}

string Board::printBoard() {
    string board_string = "================Board================\n";
    for (int i = 8 - 1; i >= 0; i--) {
        for (int j = 0; j < 8; j++)
            board_string = board_string + (boardMatrix[i][j]->getType()[0] +
                                           boardMatrix[i][j]->getCurrentPos()
                                                   ->toString() + " ");
        board_string = board_string + "\n";
    }

    board_string = board_string + "===============PieceList=============\n";

    for (auto &i : blackPiecesList) {
        board_string = board_string +
                       (i->getType()[0] + i->getCurrentPos()->toString() + " ");
    }

    board_string = board_string + " == black \n";

    for (auto &i : whitePiecesList) {
        board_string = board_string +
                       (i->getType()[0] + i->getCurrentPos()->toString() + " ");
    }

    board_string = board_string +
                   " == white \n=====================================\n";

    return board_string;
}

void Board::deletePieceFromVector(Piece *piece) {
    // for white pieces
    if (piece->getIsWhite()) {
        for (auto it = whitePiecesList.begin(); it != whitePiecesList.end();
                it++)
            if ((*it)->getCurrentPos()->toString() ==
                piece->getCurrentPos()->toString()) {
                whitePiecesList.erase(it);
                return;
            }
        // for black pieces
    } else {
        for (auto it = blackPiecesList.begin(); it != blackPiecesList.end();
                it++)
            if ((*it)->getCurrentPos()->toString() ==
                piece->getCurrentPos()->toString()) {
                blackPiecesList.erase(it);
                return;
            }
    }
}

int Board::promotePawn(Piece *pawn, Position *pos, int pieceSelector) {
    deletePieceFromVector(pawn);

    int line = pos->getLine() - 1;
    int column = pos->getColumn() - 'a';

    int promoteSelector = -1;
    Piece *newPromote;

    // choose the right piece to promote to, based on piece selector
    switch (pieceSelector) {
        case 0 : {
            newPromote = new Queen(pawn->getIsWhite(), pos);
            promoteSelector = 0;
            break;
        }
        case 1 : {
            newPromote = new Bishop(pawn->getIsWhite(), pos);
            promoteSelector = 1;
            break;
        }
        case 2 : {
            newPromote = new Knight(pawn->getIsWhite(), pos);
            promoteSelector = 2;
            break;
        }
        case 3 : {
            newPromote = new Rook(pawn->getIsWhite(), pos);
            promoteSelector = 3;
            break;
        }
    }

    //Add to board
    boardMatrix[line][column] = newPromote;

    //Add to pieces list
    if (newPromote->getIsWhite()) {
        whitePiecesList.push_back(newPromote);
    } else {
        blackPiecesList.push_back(newPromote);
    }

    return promoteSelector;
}

King *Board::getKing(bool isWhite) const {
    vector<Piece *> pieceVec = isWhite ? getWhitePiecesList() : getBlackPiecesList();
    for (auto piece : pieceVec) {
        if (piece->getType() == "KING")
            return dynamic_cast<King *>(piece);
    }
    cout << "no " << isWhite << " king" << endl;
    return nullptr;
}

const vector<Piece *> &Board::getPiecesList(bool isWhite) const {
    if (isWhite) {
        return whitePiecesList;
    } else {
        return blackPiecesList;
    }
}

int Board::updateBoard(Position *oldPos, Position *newPos, int pieceSelector) {
    int oldLine = oldPos->getLine() - 1;
    int newLine = newPos->getLine() - 1;
    int oldColumn = oldPos->getColumn() - 'a';
    int newColumn = newPos->getColumn() - 'a';
    Piece *piece = boardMatrix[oldLine][oldColumn];
    int promote = -1;

    // check for a castling move
    if(!checkForCastle(oldPos, newPos)) {
        // check if the moved piece was a pawn and it moved 2 squares
        if (piece->getType() == "PAWN" && abs(oldLine - newLine) == 2) {
            ((Pawn *) piece)->setTwoStepsStart(1);
        }

        // check for en passant move
        if(!checkForEnPassant(oldPos, newPos)) {

            // normal move
            piece->setCurrentPos(newPos);
            boardMatrix[oldLine][oldColumn] = new Empty(oldPos);

            if (boardMatrix[newLine][newColumn]->getType() != "EMPTY")
                deletePieceFromVector(boardMatrix[newLine][newColumn]);
            boardMatrix[newLine][newColumn] = piece;

            if(getKing(true)->isInCheck(getBoardMatrix())) {
                getKing(true)->incrementTimesInCheck();
            }
            if(getKing(false)->isInCheck(getBoardMatrix())) {
                getKing(false)->incrementTimesInCheck();
            }

            // try promotion
            if (piece->getType() == "PAWN" && (newLine == 0 || newLine == 7)) {
                promote = promotePawn(piece, newPos, pieceSelector);
            }
        }
    }

    resetFlags(piece);

    return promote;
}

bool Board::checkForCastle(Position *oldPos, Position *newPos) {
    int oldLine = oldPos->getLine() - 1;
    int newLine = newPos->getLine() - 1;
    int oldColumn = oldPos->getColumn() - 'a';
    int newColumn = newPos->getColumn() - 'a';
    Piece* piece = boardMatrix[oldLine][oldColumn];

    if (piece->getType() == "KING" && abs(newColumn - oldColumn) == 2) {
        // move king

        boardMatrix[oldLine][oldColumn] = new Empty(new Position(piece->getCurrentPos()));
        boardMatrix[newLine][newColumn] = piece;
        piece->setCurrentPos(new Position(newPos));

        // small castle
        if (newColumn - oldColumn == 2) {
            // get rook
            Piece* rook = boardMatrix[newLine][7];

            // move rook
            boardMatrix[newLine][5] = rook;
            boardMatrix[newLine][7] = new Empty(new Position('h', newLine + 1));
            rook->setCurrentPos(new Position('f', newLine + 1));

            // big castle
        } else {
            // get rook
            Piece* rook = boardMatrix[newLine][0];

            // move rook
            boardMatrix[newLine][3] = rook;
            boardMatrix[newLine][0] =
                    new Empty(new Position('a', newLine + 1));
            rook->setCurrentPos(new Position('d', newLine + 1));
        }
        return true;
    }
    return false;
}

bool Board::checkForEnPassant(Position *oldPos, Position *newPos) {
    int oldLine = oldPos->getLine() - 1;
    int newLine = newPos->getLine() - 1;
    int oldColumn = oldPos->getColumn() - 'a';
    int newColumn = newPos->getColumn() - 'a';
    Piece *piece = boardMatrix[oldLine][oldColumn];

    // if the move actually is an en passant one
    if (piece->getType() == "PAWN" &&
        boardMatrix[newLine][newColumn]->getType() == "EMPTY" &&
        newColumn != oldColumn) {

        // the pawn is white
        if (piece->getIsWhite()) {
            // take piece
            deletePieceFromVector(boardMatrix[newLine - 1][newColumn]);
            boardMatrix[newLine - 1][newColumn] =
                    new Empty(new Position(newColumn + 'a', newLine));

            // the pawn is black
        } else {
            // take piece
            deletePieceFromVector(boardMatrix[newLine + 1][newColumn]);
            boardMatrix[newLine + 1][newColumn] =
                    new Empty(new Position(newColumn + 'a', newLine + 2));
        }
        // update for the pawn that made the en passant move
        piece->setCurrentPos(newPos);
        boardMatrix[newLine][newColumn] = piece;
        boardMatrix[oldLine][oldColumn] = new Empty(oldPos);
        return true;
    }
    return false;
}

void Board::resetFlags(Piece* piece) {
    // check if the moved piece was a rook
    if (piece->getType() == "ROOK")
        ((Rook *) piece)->setHasMoved(true);

    // check if the moved piece was a king
    if (piece->getType() == "KING")
        ((King *) piece)->setHasMoved(true);

    // RESET PAWN ENPASSANT FLAGS (if needed)
    vector<Piece *> enemyPieces = getPiecesList(!piece->getIsWhite());
    for (auto &_piece: enemyPieces) {
        if (_piece->getType() == "PAWN") {
            ((Pawn *) _piece)->setTwoStepsStart(0);
        }
    }
}


string Board::getPieceFromPosition(Position *oldPos) {
    return this->boardMatrix[oldPos->getLine() - 1][oldPos->getColumn() - 'a']->getType();
}

Board::~Board() {
    for (auto line : boardMatrix) {
        for (auto piece : line) {
            delete(piece);
        }
        line.clear();
    }
    boardMatrix.clear();
    whitePiecesList.clear();
    blackPiecesList.clear();
}
