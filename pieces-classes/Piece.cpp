#include "Piece.h"

bool Piece::getIsWhite() {
    return isWhite;
}

Position *Piece::getCurrentPos() {
    return currentPos;
}

void Piece::setCurrentPos(Position *_currentPos) {
    this->currentPos = _currentPos;
}

ostream &operator<<(ostream &os, const Piece &piece) {
    os << "isWhite: " << piece.isWhite << " weight: " << " currentPos: "
       << piece.currentPos;
    return os;
}

void Piece::setIsWhite(bool this_isWhite) {
    Piece::isWhite = this_isWhite;
}

int Piece::checkPosition(int line, int column, vector<vector<Piece *>> board,
                         bool _isWhite) {
    if (!(line >= 0 && column >= 0 && line < 8 && column < 8)) return -1;
    if (board[line][column]->getType() == "EMPTY") return 1;
    if (_isWhite != board[line][column]->getIsWhite()) return 0;
    // should be an if for if there is a piece with the same color as the knight
    return -1;
}

bool Piece::isSameColor(Piece *piece) const {
    return isWhite == piece->getIsWhite();
}

Position *Piece::move(vector<Position *> availableMoves) {
    if (availableMoves.empty()) return nullptr;

    return availableMoves[rand() % (availableMoves.size())];
}

Piece::~Piece() {
    delete currentPos;
}
