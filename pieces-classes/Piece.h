#ifndef PA_CHESS_GAME_PIECE
#define PA_CHESS_GAME_PIECE

#include <ostream>
#include "../Position.h"
#include <vector>

class Piece{
protected:
	bool isWhite{};
	Position* currentPos{};

public:
    Piece(){}
    Piece(Piece* otherPiece);

    virtual ~Piece();

    virtual std::string getType() = 0;
	virtual double getPositionScore(bool isWhiteTurn) = 0;
    virtual vector<Position*> getAvailableMoves(vector<vector<Piece*>> board) = 0;

    friend ostream &operator<<(ostream &os, const Piece &piece);

	bool getIsWhite();
	void setIsWhite(bool this_isWhite);

    virtual int getWeight() = 0;

    Position *getCurrentPos();
	void setCurrentPos(Position *currentPos);

    Position* move(vector<Position*>);
	int checkPosition(int line, int column, vector<vector<Piece *>> board, bool _isWhite);
	bool isSameColor(Piece* piece) const;
};




#endif