#ifndef PA_CHESS_GAME_COMMANDPARSER_H
#define PA_CHESS_GAME_COMMANDPARSER_H

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <iterator>
#include <map>
#include "../Game.h"

#include "Command.h"
#include "XboardCommand.h"
#include "ForceCommand.h"
#include "GoCommand.h"
#include "NewCommand.h"
#include "QuitCommand.h"
#include "FeatureCommand.h"

using namespace std;

class CommandParser {
private:
    map<string, Command*> commandsMap;

public:
    CommandParser();
    ~CommandParser();

    void parseCommand(Game* game, const string& commandString, ostream& logFile);

private:
    void initCommands();
    bool checkIfMoveCommand(string commandString);
};


#endif //PA_CHESS_GAME_COMMANDPARSER_H
