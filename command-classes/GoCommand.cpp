#include "GoCommand.h"

void GoCommand::execute(Game *game, ostream &logFile) {
    game->setIsPaused(false);
    game->setBotIsWhite(game->getIsWhiteTurn());

    game->go();
}