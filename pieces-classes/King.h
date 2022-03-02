#ifndef PROIECT_PA_LOOKING_KING_H
#define PROIECT_PA_LOOKING_KING_H

#include <ostream>
#include "Piece.h"

class King: public Piece {
public:
    double weight = 20000;
    int times_in_check = 0;

    King(King* other_king);
    King(bool isWhite, Position* position);
    King(bool isWhite, bool _hasMoved, Position* position);
    King(bool _isWhite, bool _hasMoved, Position *position, int _times_in_check);

    string getType() override;
    double getPositionScore(bool isWhiteTurn) override;
    int getWeight() override;


    friend ostream &operator<<(ostream &os, const King &king);
    vector<Position*> getAvailableMoves(vector<vector<Piece*>> board) override;
    bool isInCheck(const vector<vector<Piece *>> &boardMatrix);

    bool getHasMoved() const;

    void setHasMoved(bool hasMoved);

    void incrementTimesInCheck();

private:
    bool hasMoved = false;

    double const position_scores_white[8][8] = {
        -30,-40,-40,-50,-50,-40,-40,-30,
        -30,-40,-40,-50,-50,-40,-40,-30,
        -30,-40,-40,-50,-50,-40,-40,-30,
        -30,-40,-40,-50,-50,-40,-40,-30,
        -20,-30,-30,-40,-40,-30,-30,-20,
        -10,-20,-20,-20,-20,-20,-20,-10,
            -10000, -10000,  -10000,  -10000,  -10000,  -10000, -10000, -10000,
            10000, 10000, 10000,  0,  0, 10, 10000, 10000
    };

    double const ending_position_scores_white[8][8] = {
        -50,-40,-30,-20,-20,-30,-40,-50,
        -30,-20,-10,  0,  0,-10,-20,-30,
        -30,-10, 20, 30, 30, 20,-10,-30,
        -30,-10, 30, 40, 40, 30,-10,-30,
        -30,-10, 30, 40, 40, 30,-10,-30,
        -30,-10, 20, 30, 30, 20,-10,-30,
        -30,-30,  0,  0,  0,  0,-30,-30,
        -50,-30,-30,-30,-30,-30,-30,-50
    };

    double const position_scores_black[8][8] = {
            10000, 10000, 10000,  0,  0, 10, 10000, 10000,
            -10000, -10000,  -10000,  -10000,  -10000,  -10000, -10000, -10000,
        -10,-20,-20,-20,-20,-20,-20,-10,
        -20,-30,-30,-40,-40,-30,-30,-20,
        -30,-40,-40,-50,-50,-40,-40,-30,
        -30,-40,-40,-50,-50,-40,-40,-30,
        -30,-40,-40,-50,-50,-40,-40,-30,
        -30,-40,-40,-50,-50,-40,-40,-30
    };

    double const ending_position_scores_black[8][8] = {
        -50,-30,-30,-30,-30,-30,-30,-50,
        -30,-30,  0,  0,  0,  0,-30,-30,
        -30,-10, 20, 30, 30, 20,-10,-30,
        -30,-10, 30, 40, 40, 30,-10,-30,
        -30,-10, 30, 40, 40, 30,-10,-30,
        -30,-10, 20, 30, 30, 20,-10,-30,
        -30,-20,-10,  0,  0,-10,-20,-30,
        -50,-40,-30,-20,-20,-30,-40,-50
    };
	vector<int> dl {-1, -1, -1, 0, 0, 1, 1, 1};
	vector<int> dc {-1, 0, 1, -1, 1, -1, 0, 1};

    bool lineCheck(const vector<vector<Piece *>> &boardMatrix);
    bool diagonalCheck(const vector<vector<Piece *>> &boardMatrix);
    bool cornerCheck(const vector<vector<Piece *>> &boardMatrix);
    bool lCheck(const vector<vector<Piece *>> &boardMatrix);
    bool kissingKingsCheck(const vector<vector<Piece *>> &boardMatrix);
    string checkPossbileThreat(Piece *possbileThreat, const string &threatType);
};


#endif
