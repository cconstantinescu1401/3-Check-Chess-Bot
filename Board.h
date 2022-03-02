#ifndef PA_CHESS_GAME_BOARD
#define PA_CHESS_GAME_BOARD

#include <map>
#include "pieces_classes/Empty.h"
#include "pieces_classes/Piece.h"
#include "pieces_classes/Pawn.h"
#include "pieces_classes/Knight.h"
#include "pieces_classes/King.h"
#include "pieces_classes/Queen.h"
#include "pieces_classes/Bishop.h"
#include "pieces_classes/Rook.h"
#include <vector>
#include <ostream>

using namespace std;

class Board {
private:
    vector<vector<Piece*>> boardMatrix;
    vector<Piece *> whitePiecesList;
    vector<Piece *> blackPiecesList;

    Piece* generateCorrectPiece(Piece* piece);

public:
    Board() {}

    Board(Board* current_board);

    virtual ~Board();

    const vector<Piece *> &getWhitePiecesList() const;
    void setPPListWhite(const vector<Piece *> &pPListWhite);

    const vector<Piece *> &getBlackPiecesList() const;
    void setPPListBlack(const vector<Piece *> &pPListBlack);

    const vector<vector<Piece *>> &getBoardMatrix() const;
    void setBoardMatrix(const vector<vector<Piece *>> &this_board);

    friend ostream &operator<<(ostream &os, const Board &board);

    const vector<Piece *> &getPiecesList(bool isWhite) const;
    void initBoard();
    void initPieceList();

    string printBoard();
    int updateBoard(Position* oldPos, Position* newPos, int pieceSelector);

    string getPieceFromPosition(Position *oldPos);

    void deletePieceFromVector(Piece* piece);
    King* getKing(bool isWhite) const;

private:
    static vector<Piece*> pawnsArrayGen(bool isWhite);
    static vector<Piece*> pieceWhiteLineGen();
    static vector<Piece*> pieceBlackLineGen();

    void resetFlags(Piece* piece);
    bool checkForCastle(Position *oldPos, Position *newPos);
    bool checkForEnPassant(Position *oldPos, Position *newPos);
    int promotePawn(Piece* pawn, Position* pos, int pieceSelector);
};

#endif
