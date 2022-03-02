#ifndef PA_CHESS_GAME_FEATURECOMMAND_H
#define PA_CHESS_GAME_FEATURECOMMAND_H

#include "../Game.h"
#include "Command.h"

class FeatureCommand : public Command{
public:
    void execute(Game *game, ostream &logFile) override;
};


#endif //PA_CHESS_GAME_FEATURECOMMAND_H
