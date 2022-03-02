#include <string>
#include <iostream>
#include <fstream>
#include "command_classes/CommandParser.h"
#include "Game.h"
using namespace std;

int main() {

    Game* game = new Game();
    auto* commandParser = new CommandParser();

    do {
        string command;
        cin >> command;
        commandParser->parseCommand(game, command, (ostream &) game->getLogFile());
    } while (game->getIsRunning());

    delete game;
    delete commandParser;

    return 0;
}
