#ifndef PA_CHESS_GAME_COMMAND_H
#define PA_CHESS_GAME_COMMAND_H

#include <stdlib.h>
#include "../Game.h"

class Command {
public:
    virtual void execute(Game *game, ostream &logFile) = 0;
};


#endif
