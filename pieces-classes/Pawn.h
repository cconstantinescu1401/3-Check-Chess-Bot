#ifndef PA_CHESS_GAME_PAWN
#define PA_CHESS_GAME_PAWN

#include <ostream>
#include "Piece.h"

using namespace std;

class Pawn: public Piece {
public:
    double weight = 100;

    Pawn(Pawn* other_pawn);
    Pawn(bool isWhite, int twoStepsStart, Position *position);
    explicit Pawn(bool isWhite, Position* position);
    string getType() override;
    int getWeight() override;

    double getPositionScore(bool isWhiteTurn) override;
    friend ostream &operator<<(ostream &os, const Pawn &pawn);
    vector<Position*> getAvailableMoves(vector<vector<Piece*>> board) override;
    int getTwoStepsStart();
    void setTwoStepsStart(int __twoStepsStart);

private:
    int twoStepsStart = 0;
    double const position_scores_white[8][8] = {
            0,  0,  0,  0,  0,  0,  0,  0,
            50, 50, 50, 50, 50, 50, 50, 50,
            10, 10, 20, 30, 30, 20, 10, 10,
            5,  5, 10, 25, 25, 10,  5,  5,
            0,  0,  0, 20, 10000,  0,  0,  0,
            5, -5,-10,  0,  0,-10, -5,  5,
            5, 10, 10,-20,-20, 10, 10,  5,
            0,  0,  0,  0,  0,  0,  0,  0
    };

    double const position_scores_black[8][8] = {
            0,  0,  0,  0,  0,  0,  0,  0,
            5, 10, 10,-20,-20, 10, 10,  5,
            5, -5,-10,  0,  0,-10, -5,  5,
            0,  0,  0, 20, 10000,  0,  0,  0,
            5,  5, 10, 25, 25, 10,  5,  5,
            10, 10, 20, 30, 30, 20, 10, 10,
            50, 50, 50, 50, 50, 50, 50, 50,
            0,  0,  0,  0,  0,  0,  0,  0
    };
};

#endif
