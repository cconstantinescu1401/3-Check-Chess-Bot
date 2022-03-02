#include "ForceCommand.h"

void ForceCommand::execute(Game *game, ostream &logFile) {
    game->setIsPaused(true);
}
