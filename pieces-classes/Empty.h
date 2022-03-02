#ifndef PROIECT_EMPTY_H
#define PROIECT_EMPTY_H

#include "Piece.h"
#define MIN_MAX -1e9

class Empty: public Piece {
    double weight;
    vector<Position*> getAvailableMoves(vector<vector<Piece*>> board) override;
    string getType() override;
    int getWeight() override;

    double getPositionScore(bool isWhiteTurn) override;

public:
    Empty(Empty* old_empty);
    Empty(Position* currentPos);

private:
    double const position_scores[8][8] = {
        { MIN_MAX,  MIN_MAX,  MIN_MAX,  MIN_MAX,  MIN_MAX,  MIN_MAX,  MIN_MAX,  MIN_MAX},
        { MIN_MAX,  MIN_MAX,  MIN_MAX,  MIN_MAX,  MIN_MAX,  MIN_MAX,  MIN_MAX,  MIN_MAX},
        { MIN_MAX,  MIN_MAX,  MIN_MAX,  MIN_MAX,  MIN_MAX,  MIN_MAX,  MIN_MAX,  MIN_MAX},
        { MIN_MAX,  MIN_MAX,  MIN_MAX,  MIN_MAX,  MIN_MAX,  MIN_MAX,  MIN_MAX,  MIN_MAX},
        { MIN_MAX,  MIN_MAX,  MIN_MAX,  MIN_MAX,  MIN_MAX,  MIN_MAX,  MIN_MAX,  MIN_MAX},
        { MIN_MAX,  MIN_MAX,  MIN_MAX,  MIN_MAX,  MIN_MAX,  MIN_MAX,  MIN_MAX,  MIN_MAX},
        { MIN_MAX,  MIN_MAX,  MIN_MAX,  MIN_MAX,  MIN_MAX,  MIN_MAX,  MIN_MAX,  MIN_MAX},
        { MIN_MAX,  MIN_MAX,  MIN_MAX,  MIN_MAX,  MIN_MAX,  MIN_MAX,  MIN_MAX,  MIN_MAX}
    };
};

#endif
