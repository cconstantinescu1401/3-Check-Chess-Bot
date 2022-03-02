#include "Empty.h"

vector<Position *> Empty::getAvailableMoves(vector<vector<Piece *>> board) {
    return vector<Position *>();
}

string Empty::getType() {
    return "EMPTY";
}

Empty::Empty(Position* currentPos) {
    isWhite = true;
    this->setCurrentPos(currentPos);
    weight = MIN_MAX;
}

double Empty::getPositionScore(bool isWhiteTurn) {
    return 0;
}

Empty::Empty(Empty *old_empty) : Empty(new Position(old_empty->currentPos)){}

int Empty::getWeight() {
    return 0;
}