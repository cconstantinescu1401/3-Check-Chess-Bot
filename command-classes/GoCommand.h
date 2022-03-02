#ifndef PA_CHESS_GAME_GOCOMMAND_H
#define PA_CHESS_GAME_GOCOMMAND_H

#include "../Game.h"
#include "Command.h"

class GoCommand : public Command {
public:
     void execute(Game *game, ostream &logFile) override;
};


#endif //PA_CHESS_GAME_GOCOMMAND_H
