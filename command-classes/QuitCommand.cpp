#include "QuitCommand.h"

void QuitCommand::execute(Game *game, ostream &logFile) {
    game->setIsRunning(false);
}