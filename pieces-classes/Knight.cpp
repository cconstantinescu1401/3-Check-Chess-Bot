#include "Knight.h"

ostream &operator<<(ostream &os, const Knight &knight) {
    os << static_cast<const Piece &>(knight);
    return os;
}

string Knight::getType() {
    return "KNIGHT";
}

vector<Position *> Knight::getAvailableMoves(vector<vector<Piece *>> board) {
    vector<Position *> moves;
    int line = Knight::getCurrentPos()->getLine() - 1;
    int column = Knight::getCurrentPos()->getColumn() - 'a';

    for(int i = 0; i < 8; i++) {
        if(Piece::checkPosition(line + Knight::dl[i], column + Knight::dc[i], board, Knight::getIsWhite()) >= 0) 
            moves.push_back(board[line + Knight::dl[i]][column + Knight::dc[i]]->getCurrentPos());
    }    

    return moves;
}

Knight::Knight(bool _isWhite, Position* position) {
    isWhite = _isWhite;
    currentPos = position;
}

const vector<int> &Knight::getDl() const {
    return dl;
}

void Knight::setDl(const vector<int> &dl) {
    Knight::dl = dl;
}

const vector<int> &Knight::getDc() const {
    return dc;
}

void Knight::setDc(const vector<int> &dc) {
    Knight::dc = dc;
}

Knight::Knight() = default;

double Knight::getPositionScore(bool isWhiteTurn) {
    if (isWhiteTurn)
    return weight + position_scores_white[this->getCurrentPos()->getLine() -
    1][this->getCurrentPos()->getColumn() - 'a'];
    return weight + position_scores_black[this->getCurrentPos()->getLine() -
    1][this->getCurrentPos()->getColumn() - 'a'];
}

Knight::Knight(Knight *other_knight) : Knight(other_knight->isWhite,
                                  new Position(other_knight->currentPos)) {}

int Knight::getWeight() {
    return this->weight;
}