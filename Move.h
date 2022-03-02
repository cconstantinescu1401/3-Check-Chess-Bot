#ifndef PROIECT_PA_LOOKINGATTHECELING_MOVE_H
#define PROIECT_PA_LOOKINGATTHECELING_MOVE_H

#include "Position.h"

class Move {
private:
    Position* oldPos;
    Position* newPos;
public:
    Move(Position *oldPos, Position *newPos);

    Move(Move* other_move);

    Position *getOldPos() const;

    void setOldPos(Position *oldPos);

    Position *getNewPos() const;

    void setNewPos(Position *newPos);


    ~Move();
};


#endif
