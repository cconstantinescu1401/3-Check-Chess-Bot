#ifndef PA_CHESS_GAME_XBOARDCOMMAND_H
#define PA_CHESS_GAME_XBOARDCOMMAND_H

#include "../Game.h"
#include "Command.h"

class XboardCommand : public Command {
public:
    void execute(Game *game, ostream &logFile) override;
};
#endif //PA_CHESS_GAME_XBOARDCOMMAND_
