#ifndef PROIECT_PA_LOOKING_ROOK_H
#define PROIECT_PA_LOOKING_ROOK_H

#include <ostream>
#include "Piece.h"

class Rook: public Piece {
private:
    double weight = 500;
    bool hasMoved = false;

    double const position_scores_white[8][8] = {
         0,  0,  0,  0,  0,  0,  0,  0,
         5, 10, 10, 10, 10, 10, 10,  5,
        -5,  0,  0,  0,  0,  0,  0, -5,
        -5,  0,  0,  0,  0,  0,  0, -5,
        -5,  0,  0,  0,  0,  0,  0, -5,
        -5,  0,  0,  0,  0,  0,  0, -5,
        -5,  0,  0,  0,  0,  0,  0, -5,
         0,  0,  0,  5,  5,  0,  0,  0
    };

    double const position_scores_black[8][8] = {
         0,  0,  0,  5,  5,  0,  0,  0,
        -5,  0,  0,  0,  0,  0,  0, -5,
        -5,  0,  0,  0,  0,  0,  0, -5,
        -5,  0,  0,  0,  0,  0,  0, -5,
        -5,  0,  0,  0,  0,  0,  0, -5,
        -5,  0,  0,  0,  0,  0,  0, -5,
         5, 10, 10, 10, 10, 10, 10,  5,
         0,  0,  0,  0,  0,  0,  0,  0
    };

public:
    bool getHasMoved() const;

    void setHasMoved(bool hasMoved);

public:
    Rook(Rook* other_rook);
    explicit Rook(bool isWhite, Position *position);
    Rook(bool isWhite, bool hasMoved, Position *position);
    string getType() override;
    int getWeight() override;
    double getPositionScore(bool isWhiteTurn) override;
    friend ostream &operator<<(ostream &os, const Rook &rook);
    vector<Position*> getAvailableMoves(vector<vector<Piece*>> board) override;
};

#endif
