#ifndef PROIECT_PA_LOOKING_QUEEN_H
#define PROIECT_PA_LOOKING_QUEEN_H

#include <ostream>
#include "Piece.h"

class Queen: public Piece {
public:
    double weight = 3000;

    double const position_scores_white[8][8] = {
        -20,-10,-10, -5, -5,-10,-10,-20,
        -10,  0,  0,  0,  0,  0,  0,-10,
        -10,  0,  5,  5,  5,  5,  0,-10,
         -5,  0,  5,  5,  5,  5,  0, -5,
          0,  0,  5,  5,  5,  5,  0, -5,
        -10,  5,  5,  5,  5,  5,  0,-10,
        -10,  0,  5,  0,  0,  0,  0,-10,
        -20,-10,-10, -5, -5,-10,-10,-20
    };

    double const position_scores_black[8][8] = {
        -20,-10,-10, -5, -5,-10,-10,-20,
        -10,  0,  5,  0,  0,  0,  0,-10,
        -10,  5,  5,  5,  5,  5,  0,-10,
          0,  0,  5,  5,  5,  5,  0, -5,
         -5,  0,  5,  5,  5,  5,  0, -5,
        -10,  0,  5,  5,  5,  5,  0,-10,
        -10,  0,  0,  0,  0,  0,  0,-10,
        -20,-10,-10, -5, -5,-10,-10,-20
    };

    Queen(Queen* other_queen);
    explicit Queen(bool isWhite, Position *position);
    string getType() override;
    int getWeight() override;

    double getPositionScore(bool isWhiteTurn) override;
    friend ostream &operator<<(ostream &os, const Queen &queen);
    vector<Position*> getAvailableMoves(vector<vector<Piece*>> board) override;
};

#endif
