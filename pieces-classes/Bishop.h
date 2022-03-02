#ifndef PROIECT_PA_LOOKING_BISHOP_H
#define PROIECT_PA_LOOKING_BISHOP_H

#include <ostream>
#include "Piece.h"

class Bishop: public Piece {
public:
    double weight = 500;
    Bishop(Bishop* other_bishop);
    explicit Bishop(bool isWhite, Position* position);

    string getType() override;
    int getWeight() override;

    double getPositionScore(bool isWhiteTurn) override;
    friend ostream &operator<<(ostream &os, const Bishop &bishop);
    vector<Position*> getAvailableMoves(vector<vector<Piece*>> board) override;

private:
    double const position_scores_white[8][8] = {
            {-20,-10,-10,-10,-10,-10,-10,-20},
            {-10,  0,  0,  0,  0,  0,  0,-10},
            {-10,  0,  5, 10, 10,  5,  0,-10},
            {-10,  5,  5, 10, 10,  5,  5,-10},
            {-10,  0, 10, 10, 10, 10,  0,-10},
            {-10, 10, 10, 10, 10, 10, 10,-10},
            {-10,  5,  0,  0,  0,  0,  5,-10},
            {-20,-10,-10,-10,-10,-10,-10,-20}
    };
    
    double const position_scores_black[8][8] = {
            {-20,-10,-10,-10,-10,-10,-10,-20},
            {-10,  5,  0,  0,  0,  0,  5,-10},
            {-10, 10, 10, 10, 10, 10, 10,-10},
            {-10,  0, 10, 10, 10, 10,  0,-10},
            {-10,  5,  5, 10, 10,  5,  5,-10},
            {-10,  0,  5, 10, 10,  5,  0,-10},
            {-10,  0,  0,  0,  0,  0,  0,-10},
            {-20,-10,-10,-10,-10,-10,-10,-20}
    };

};

#endif
