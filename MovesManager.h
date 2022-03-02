#ifndef PROIECT_FAZA_2_MOVESMANAGER_H
#define PROIECT_FAZA_2_MOVESMANAGER_H


#include "pieces_classes/King.h"
#include "Board.h"
#include "Move.h"

#define MAX_DEPTH 3

class MovesManager {
public:
    void makeMove(Board *board, bool &botIsWhite, bool &isWhiteTurn,
                  ostream &logFile);

    void updateFromOpponentMove(string &commandString, Board *board,
                                bool &isWhiteTurn);

    void removeIllegalMoves(Board *board, vector<Position *> &possibleMoves,
                            Piece *toBeMovedPiece);

    Move* miniMaxroot(Board* board, int depth, bool isWhiteTurn, bool
    isBotWhite);

    double miniMax(Board* board, int depth, bool isWhiteTurn, bool
    isBotWhite, double alpha, double beta);

    double evaluate(Board* board, bool isBotWhite);

    bool isCheckMate(Board *board, bool IsKingWhite);

    void giveCheckBonus(double &eval, Board *copy_board, bool isBotWhite);
};


#endif
