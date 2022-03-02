#include "Move.h"

Move::Move(Position *_oldPos, Position *_newPos) : oldPos(_oldPos),
                                                 newPos(_newPos) {}

Position *Move::getOldPos() const {
    return oldPos;
}

void Move::setOldPos(Position *_oldPos) {
    Move::oldPos = _oldPos;
}

Position *Move::getNewPos() const {
    return newPos;
}

void Move::setNewPos(Position *_newPos) {
    Move::newPos = _newPos;
}

Move::~Move() {
    delete(oldPos);
    delete(newPos);
}

Move::Move(Move *other_move) : Move(new Position(other_move->oldPos),
                                    new Position(other_move->newPos)){

}
