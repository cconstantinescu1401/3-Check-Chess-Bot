#include "NewCommand.h"

void NewCommand::execute(Game *game, ostream &logFile) {
    game->getBoard()->initBoard();
    game->setIsWhiteTurn(true);
    game->setBotIsWhite(false);
    game->setIsPaused(false);
}
