#ifndef PA_CHESS_GAME_QUITCOMMAND_H
#define PA_CHESS_GAME_QUITCOMMAND_H

#include "../Game.h"
#include "Command.h"

class QuitCommand : public Command{
public:
    void execute(Game *game, ostream &logFile) override;
};


#endif //PA_CHESS_GAME_QUITCOMMAND_H
