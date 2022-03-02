#ifndef PROIECT_PA_LOOKING_HORSE_H
#define PROIECT_PA_LOOKING_HORSE_H

#include <ostream>
#include "Piece.h"

class Knight: public Piece {
public:
    double weight = 320;

    Knight(Knight* other_knight);
    Knight();
    explicit Knight(bool isWhite, Position* position);
    string getType() override;
    int getWeight() override;

    double getPositionScore(bool isWhiteTurn) override;
    friend ostream &operator<<(ostream &os, const Knight &knight);
    vector<Position*> getAvailableMoves(vector<vector<Piece*>> board) override;

    const vector<int> &getDl() const;

    void setDl(const vector<int> &dl);

    const vector<int> &getDc() const;

    void setDc(const vector<int> &dc);

private:
    vector<int> dl = {-1, -1, -2, -2, 1, 1, 2, 2};
    vector<int> dc {-2, 2, -1, 1, -2, 2, -1, 1};

    double const position_scores_white[8][8] = {
        -50,-40,-30,-30,-30,-30,-40,-50,
        -40,-20,  0,  0,  0,  0,-20,-40,
        -30,  0, 10, 15, 15, 10,  0,-30,
        -30,  5, 15, 20, 20, 15,  5,-30,
        -30,  0, 15, 20, 20, 15,  0,-30,
        -30,  5, 10, 15, 15, 10,  5,-30,
        -40,-20,  0,  5,  5,  0,-20,-40,
        -50,-40,-30,-30,-30,-30,-40,-50
    };

    double const position_scores_black[8][8] = {
        -50,-40,-30,-30,-30,-30,-40,-50,
        -40,-20,  0,  5,  5,  0,-20,-40,
        -30,  5, 10, 15, 15, 10,  5,-30,
        -30,  0, 15, 20, 20, 15,  0,-30,
        -30,  5, 15, 20, 20, 15,  5,-30,
        -30,  0, 10, 15, 15, 10,  0,-30,
        -40,-20,  0,  0,  0,  0,-20,-40,
        -50,-40,-30,-30,-30,-30,-40,-50,
    };
};

#endif
