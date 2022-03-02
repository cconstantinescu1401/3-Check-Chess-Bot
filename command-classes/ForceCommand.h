#ifndef PA_CHESS_GAME_FORCECOMMAND_H
#define PA_CHESS_GAME_FORCECOMMAND_H

#include "../Game.h"
#include "Command.h"

class ForceCommand : public Command{
public:
    void execute(Game *game, ostream &logFile) override;
};


#endif //PA_CHESS_GAME_FORCECOMMAND_H
