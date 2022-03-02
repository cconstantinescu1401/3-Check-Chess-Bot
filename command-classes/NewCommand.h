#ifndef PA_CHESS_GAME_NEWCOMMAND_H
#define PA_CHESS_GAME_NEWCOMMAND_H

#include "../Game.h"
#include "Command.h"

class NewCommand : public Command{
public:
    void execute(Game *game, ostream &logFile) override;
};


#endif //PA_CHESS_GAME_NEWCOMMAND_H
