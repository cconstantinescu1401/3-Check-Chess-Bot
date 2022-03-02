#include "XboardCommand.h"

void XboardCommand::execute(Game *game, ostream &logFile) {
    game->setIsRunning(true);
    game->getBoard()->initBoard();

}